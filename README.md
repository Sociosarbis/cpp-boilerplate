# cpp-boilerplate
This repo is for saving solutions of LeetCode questions implemented with C++ and written by me.

## run certain test
```bash
mingw32-make run_<test-name>
```

## makefile rules

### Automatic-Variable
`$@`: The file name of the target of the rule
`$<`: The name of the first prerequisite

### function
`$(subst from,to,text)`: Performs a textual replacement on the text text: each occurrence of from is replaced by to.
