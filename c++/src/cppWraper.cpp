#include <stdio.h>
#include "field.hpp"
#include "imgAlgsGpu.hpp"
#include "NpyArrayFuncs.hpp"
#include "robot.hpp"
#include "vectorFuncs.hpp"

extern "C"{

	Field* newField(const char *path) {

        return new Field(path);

    }
	
	void runField(Field* f){ 

        f -> run();

    }
	
}