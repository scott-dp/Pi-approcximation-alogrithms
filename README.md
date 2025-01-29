For running on a windows system:
To use the gmp library download the gmp files using https://www.msys2.org/ and use the command: "pacman -S mingw-w64-x86_64-gmp". The gmp files will now be in your mingw bundle, and in the cmake file set the absolute path to your mingw/include and mingw/lib folders on line 6 and 7. If using an editor like clion, make sure the toolchain is set up to the bundle with gmp files downloaded.

For running on unix based system gmp.h will be available without any action.
