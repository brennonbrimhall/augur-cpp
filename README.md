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

As I've been the only contributor and this has been a private repository, I've 
not found it necessary to specify an open source license.  Because of interest by
others, that will change in the near future.  Contributions will likley be stalled
until a license is determined (input welcome).
