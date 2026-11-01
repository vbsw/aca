# ACA

## About
ACA stands for Abstract C Application. It is a C library to develop desktop applications. ACA is published on <https://github.com/vbsw/aca>.

## Copyright
Copyright 2026, Vitali Baumtrok (vbsw@mailbox.org).

ACA is distributed under the Boost Software License, version 1.0. (See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

ACA is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the Boost Software License for more details.

## Version
0.0.0 [experimental]

## Usage
These C files are ment to be used in a binding. Each file is its own module and should be used in its own binding.

## Compile to library
If you want, you can compile ACA to a library. (Only Linux is supported for now.)

Switch to this project directory and execute

	make

You find the static labrary (libaca.a) and dynamic labrary (libaca.so) in

	./build/release.linux

**Tests**  
Switch to this project directory and check out the "development" branch with

	git switch development

Then compile and run tests

	make test BUILD_MODE=debug
