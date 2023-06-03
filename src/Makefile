CC=gcc
CFLAGS=-Wall -Werror -Wextra
MAIN_FILES=main_functions/*.c
TEST_FILES=tests/*.c
CHECK_LINK=$(shell pkg-config --libs --cflags check)
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

all: run

s21_math.a:
	$(CC) $(CFLAGS) -c $(MAIN_FILES)
	ar rc s21_math.a *.o
	ranlib s21_math.a

test: s21_math.a
	$(CC) $(CFLAGS) $(TEST_FILES) s21_math.a $(CHECK_LINK) -o s21_math_tests.o

run: test
	./s21_math_tests.o

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.gcno
	rm -f *.gcba
	rm -f *.info
	rm -f *.gcda
	rm -f ./icovOutput
	rm -f *.html
	rm -f *.css
	rm -f *.png
	rm -f tests/*.o
	rm -f tests/*.a
	rm -f tests/*.gcno
	rm -f tests/*.gcba
	rm -f tests/*.info
	rm -f tests/*.gcda
	rm -f tests/*.html
	rm -f tests/*.css
	rm -f tests/*.png
	rm -f main_functions/*.o
	rm -f main_functions/*.a
	rm -f main_functions/*.gcno
	rm -f main_functions/*.gcba
	rm -f main_functions/*.info
	rm -f main_functions/*.gcda
	rm -f main_functions/*.html
	rm -f main_functions/*.css
	rm -f main_functions/*.png
	rm -rf ./Aplication

r: clean all

style:
	clang-format -i $(MAIN_FILES) $(TEST_FILES)

docker:
	docker build . -t s21_decimal --platform linux/amd64
	docker run s21_decimal


#gcov_report
gcov_report: s21_mathGR grBuild grRun icov htmlGen open

s21_mathGR:
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $(MAIN_FILES)
	ar rc s21_math.a *.o
	ranlib s21_math.a

grBuild:
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(TEST_FILES) $(CHECK_LINK) s21_math.a -o icovOutput

grRun:
	./icovOutput

icov:
	lcov -t "test" -o icovOutput.info -c -d ./

htmlGen:
	genhtml  icovOutput.info

open:
	open ./index.html
