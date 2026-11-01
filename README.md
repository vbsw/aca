# aca

## About
aca stands for Abstract C Application. It is a C library to be used to develop desktop applications. aca is published on <https://github.com/vbsw/aca>.

## Copyright
Copyright 2026, Vitali Baumtrok (vbsw@mailbox.org).

libvb is distributed under the Boost Software License, version 1.0. (See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)

libvb is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the Boost Software License for more details.

## Version
0.0.0 [experimental]

## Usage
These C files are not ment to be compiled to a library. Instead each file is its own module and should be used in a binding.

## Compile to library
If you want to compile this code to a library, you can do this.

Switch to this project directory and execute

	make

You find the static labrary (libvb.a) and dynamic labrary (libvb.so) in

	./build/release.linux

**Tests**  
Switch to your project directory and check out the "development" branch with

	git switch development

Then compile and run tests

	make test BUILD_MODE=debug
