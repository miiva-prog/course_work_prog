#include <ctest.h>
#include <libtranslate/libtranslate.h>
#define _USE_MATH_DEFINES

CTEST(all_upper,test_upper)
{
    char str[] = "тест";
    char *test = all_upper(str,9);

    ASSERT_STR(test,"ТЕСТ");
}

CTEST(punctuation_in_word,test_punctuation)
{
    char test[] = "test.";
    char test2[] = "test!";
    char test3[] = "test";

    ASSERT_EQUAL(punctuation_in_word(test),'.');
    ASSERT_EQUAL(punctuation_in_word(test2),'!');
    ASSERT_EQUAL(punctuation_in_word(test3),'\0');
}

CTEST(write_in_arr,test_write)
{
    char str[] = "1234";
    char str2[] = "12345678";
    char test[10],test2[10];

    write_in_arr(test,str,2);
    write_in_arr(test2,str2,5);

    ASSERT_STR(test,"12");
    ASSERT_STR(test2,"12345");
}