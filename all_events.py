import requests
import sys
from typing import Dict
from datetime import datetime


def get(endpoint: str):
    api_key = {'X-TBA-Auth-Key': 'WL5yiW88bhMroRhNwGbszMUEVB6ucWmLi7DrAmANVZxCdih41PCOuYLxNZU0HQke'}
    return requests.get(f'https://www.thebluealliance.com/api/v3/{endpoint}', headers=api_key).json()


def get_oprs(event_key: str) -> Dict[int, float]:
    oprs = get(f'event/{event_key}/oprs')
    return {int(k[3:]): v for k, v in oprs['oprs'].items()}


def get_all_events_in_progress():
    events = get(f'events/2018/simple')
    ret = []
    for event in events:
        start = datetime.strptime(event['start_date'], '%Y-%m-%d')
        end = datetime.strptime(event['end_date'], '%Y-%m-%d')
        if start < datetime.now() < end:
            ret.append(event)

    return ret


def print_rankings(event_key: str, filename='rankings.csv'):
    rankings = get(f'event/{event_key}/rankings')

    with open(filename, 'w+') as f:
        for rank in rankings['rankings']:
            team = rank['team_key'][3:]
            rp = rank['extra_stats'][0]
            things = (str(int(rank['sort_orders'][i])) for i in range(1, 5))

            f.write(f'{team},{rp},{",".join(things)}\n')


def get_balance(red, blue, oprs):
    red_oprs = sum([oprs[r] for r in red])
    blue_oprs = sum([oprs[b] for b in blue])
    return max(0, min(1, round(red_oprs / (red_oprs + blue_oprs), 3)))


def print_schedule(event_key: str, filename='schedule.csv'):
    matches = get(f'event/{event_key}/matches/simple')

    # will fail if the event isn't actually started
    oprs = get_oprs(event_key)
    if all([opr == 0.0 for opr in oprs.values()]):
        raise TypeError()

    with open(filename, 'w+') as f:
        for match in matches:
            if match['actual_time'] is None:
                red = [int(t[3:]) for t in match['alliances']['red']['team_keys']]
                blue = [int(t[3:]) for t in match['alliances']['blue']['team_keys']]
                f.write(f'{",".join([str(r) for r in red])},{",".join([str(b) for b in blue])},'
                        f'{get_balance(red, blue, oprs)}\n')


def main():
    args = sys.argv

    if len(args) != 2:
        print('./run [event_key|all]')
        exit(0)

    event_key = args[1]
    if event_key == 'all':
        event_keys = [e['key'] for e in get_all_events_in_progress()]
        for event in event_keys:
            try:
                print_schedule(event, filename=f'{event}_schedule.csv')
                print_rankings(event, filename=f'{event}_rankings.csv')
            except TypeError:  # if the event hasn't started quals, getting OPRs will fail, so just continue silently
                pass
    else:
        if '2018' not in event_key:
            event_key = '2018' + event_key

        try:
            print_schedule(event_key)
            print_rankings(event_key)
        except TypeError:  # if the event hasn't started quals, getting OPRs will fail, so just continue silently
            pass


if __name__ == '__main__':
    main()
