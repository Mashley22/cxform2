# cxform2
CXFORM 2: Fork of the nasa cxform software, provided with cmake and some 
improved and fixed functionality

# original source
https://spdf.gsfc.nasa.gov/pub/software/old/coordinate_transform/
see the readme.txt for the original readme

# forked from
https://github.com/bsd-conqueror/cxform

# overview
Provides coordinate transforms for various astronomical coordinate systems, 
updated up to IGRF 12. Two options are provided for the interaction, either via
the c api, or via a cli application (see usage cli app). The api has been 
extended with a cxform2 function which allows the coordinate systems to be 
selected via enums instead of strings. 

# usage
## cli app
Build with cmake as usual, simply add the BUILD_CLI opt. (something like cmake 
-DBUILD_CLI=on and then build with your chosen generator)
The cli takes nine arguements. The first size are unsigned integers 
representing the time. Year, month, day, hour, minute, seconds. The next three
are doubles representing the input coordinates. At the moment its kinda useless,
providing the result of the input (taken as from the J2000 coordinate system)
to GEO, GSE, GSM, SM.

## c api
Add as a subdirectory and add link against the cxform library. The two 
important functions are cxform and cxform2. Both take an two systems and
coordinates, one for the input and output, and a time as ephemeris seconds past
J2000. A converter function is provided in date2es. cxform takes the systems
as string, whereas cxfrom2 takes them as enum values.

## samples and tests
The original source provides a main.c file which has been provided as an
example with the option BUILD_EXAMPLE.
Likewise the tester file can be built with BUILD_TEST, see build/test.
A copy of the output tests results I found are in the tests directory.

# compatibility
I am currently running on Linux kernel 6.19. I've tested with both clang
(ver 21.1.8) and gcc (ver 15.2.1). It should work out of the box with msvc,
but no promises. I'm also not exactly sure which minimum c standard this needs.
