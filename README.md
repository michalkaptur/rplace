# rplace

[reddit.com/r/place](reddit.com/r/place) inspired system to refresh some boost::asio knowledge

![build](https://github.com/michalkaptur/rplace/actions/workflows/build_and_test.yaml/badge.svg)

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


## development

### how to build

```shell
virtualenv .venv
source .venv/bin/activate
pip install conan~=2.0
conan profile detect
conan install . --output-folder build # --build missing
cmake . -GNinja -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release -B build
cmake --build build
```

### how to run tests

```shell
cd testing
virtualenv .venv
source .venv/bin/activate
pip install -r requirements.txt
pytest -v
```

### how to lint and format the code

```shell
pre-commit run --all
pre-commit install
```

### troubleshooting

#### vscode integration

Set `Cmake: Use CMake Presets` to `always` to force preset usage and make the conan-provided deps available.
