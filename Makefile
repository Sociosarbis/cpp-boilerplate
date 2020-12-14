COMMON_OPTIONS=-Wall -g -Og -static-libgcc -std=c++17
CLANG_FLAGS=-fcolor-diagnostics --target=x86_64-w64-mingw 
GTEST_OPTIONS=-Ilib/googletest/include -Llib/googletest/build/lib -lgtest -lgtest_main
.PHONY:run_groupAnagrams run_wiggleMaxLength
dist/groupAnagrams.exe: src/groupAnagrams.cpp dist
	g++ -o dist/groupAnagrams.exe src/groupAnagrams.cpp ${GTEST_OPTIONS} ${COMMON_OPTIONS}
dist/wiggleMaxLength.exe: src/groupAnagrams.cpp dist
	g++ -o dist/wiggleMaxLength.exe src/wiggleMaxLength.cpp ${GTEST_OPTIONS} ${COMMON_OPTIONS}
run_groupAnagrams: dist/groupAnagrams.exe
	dist/groupAnagrams.exe
run_wiggleMaxLength: dist/wiggleMaxLength.exe
	dist/wiggleMaxLength.exe
dist:
	mkdir dist