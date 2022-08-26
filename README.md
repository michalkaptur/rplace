# rplace

reddit.com/r/place inspired system to refresh some boost::asio knowledge

![build](https://github.com/michalkaptur/rplace/actions/workflows/build_and_test/badge.svg)

## how to build

```shell
pip3 install conan
mkdir build && cd build
conan profile update settings.compiler.libcxx=libstdc++11 default
conan install .. # --build missing
cmake .. -GNinja
ninja
```

## tech stack

c++20, cmake, boost::asio, UDP, json, conan, async python3, gtest

## MVP goals
- [ ] single server, multiple clients
- [ ] no map persistance on server
- [ ] no user identification
- [ ] API allows: set pixel color, get pixel color, get complete map
- [ ] client able to render the map
- [ ] 16 colors
- [x] built easily with dependencies
- [ ] tested on component level
- [ ] CI configuration
- [ ] hardcoded 16x16 size

## further features
- [ ] user auth
- [ ] time limited edit slots
- [ ] pixel map as client input to draw automatically
- [ ] multiple maps support
- [ ] variable map size