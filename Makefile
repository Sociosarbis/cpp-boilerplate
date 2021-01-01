COMMON_OPTIONS=-Wall -g -Og -static-libgcc -std=c++17
CLANG_FLAGS=-fcolor-diagnostics --target=x86_64-w64-mingw
GTEST_HOME=lib/gtest/googletest
GTEST_OPTIONS=-I${GTEST_HOME}/include -L${GTEST_HOME}/build/lib -lgtest -lgtest_main
.PHONY: gtest
dist/%.exe: src/%.cpp dist
	g++ -o $@ $< ${GTEST_OPTIONS} ${COMMON_OPTIONS}
run_%: dist/%.exe
	$<
${GTEST_HOME}/include:
	git submodule sync --recursive lib/gtest
	git submodule update --init --recursive lib/gtest
${GTEST_HOME}/build/lib/libgtest.a ${GTEST_HOME}/build/lib/libgtest_main.a: ${GTEST_HOME}/include
	cmake -S ${GTEST_HOME} -B ${GTEST_HOME}/build "-DGOOGLETEST_VERSION=3.19.1" -G "MinGW Makefiles"
	mingw32-make -C ${GTEST_HOME}/build
gtest: ${GTEST_HOME}/build/lib/libgtest_main.a ${GTEST_HOME}/build/lib/libgtest.a
dist:
	mkdir dist