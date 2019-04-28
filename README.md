augur-cpp
=========

FRC rankings predictions.

Usage
-----
`augur <teams.csv> <matches.csv> <depth> [numMonteCarloSims]`

Augur expects well-formatted CSV files that detail the team rankings and matches 
to simulate.  Augur defaults to brute forcing the search space for thoroughness.
If the number of Monte Carlo simulations is specified, it will randomly search and
aggregate the number of trials you specify.

Performance Notes
-----------------

Tests done on a system with an Intel® Core™ i5-3230M CPU @ 2.60GHz with 7.7 GiB of 
memory, single threaded.
* Time - `2.844731013×10-7 * 2 ^ n` (minutes)
* Space - `0.410394×10-4 * 2 ^ n` (GiB)

Currently, this implementation is capped to about 27 matches - analysis will take 
~38 min and 6 GiB (6.44245 GB) of memory.  Analyses requiring more matches should
try to use a Monte Carlo simulation or a supercomputer.

This is approximately 60 times faster than the Python implementation and about 5
times more efficient with memory.

Building / Installing
---------------------

This native version of augur is not currently distributed in a binary format.  This
means that you will need to build it from source.

Windows _should_ work, but hasn't been tested yet.

### Debian-based Linux

```shell
sudo apt install build-essential cmake git
git clone https://github.com/brennonbrimhall/augur-cpp.git
mkdir augur-build && cd augur-build
cmake -DCMAKE_BUILD_TYPE=Release ../augur-cpp/
make && make install
```

You'll need to verify that you have a compiler, a recent CMake, and git installed.
If you're looking for performance, make sure that you build a release binary as
shown and that CMake has found OpenMP.

### macOS

```shell
brew install cmake git
git clone https://github.com/brennonbrimhall/augur-cpp.git
mkdir augur-build && cd augur-build
cmake -DCMAKE_BUILD_TYPE=Release ../augur-cpp/
make && make install
```

You'll need to verify that you have a compiler, a recent CMake, and git installed.
If you haven't installed a compiler, a window may come up to help you install
everything and you may need to rerun some commands.

#### OpenMP Support

AppleClang does not support OpenMP, so this software will not take advantage of
multiple cores.  There have been blog posts that claim that they have figured out
how to install and link against `libomp`, but I haven't been able to replicate
them.


## Contributing

If you'd like to contribute, please fork the repository and use a feature
branch. Pull requests are welcome, as are questions.

The GitHub issues tracker is used to track progress and enhancement requests.
If you're looking for a good place to start, feel free to tackle an issue
marked "help wanted."


## Licensing

See [the attached license](https://github.com/brennonbrimhall/augur-cpp/blob/master/LICENSE.txt).

Please note that the GPLv2 license requires that derivative works also be licensed under GPLv2; this is an intentional choice on my part.  If anyone in the FRC community uses it and improves it, I'd like to see those improvements propagated to the repository so everyone can benefit.  This means that if you use this software in your private scouting system, that scouting system will need to be released under a GPLv2 license.

If you feel that this license is not compatible with your use case, feel free to reach out.  We might be able to work together on an alternative license for you or your team.
