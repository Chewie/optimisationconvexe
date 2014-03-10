
INCLUDE_DIRECTORIES( ../prof .)

FILE(GLOB src *.h *.cc)

ADD_EXECUTABLE( barfoo ${src} )
ADD_LIBRARY(  foobar STATIC ${src} )
TARGET_LINK_LIBRARIES(foobar optimisationconvexe)
