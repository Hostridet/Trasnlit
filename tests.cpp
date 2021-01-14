#include "gtest/gtest.h"
#include "Translate.h"

TEST(Translation, t1)
{
const char* text = GetTranslate("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890 .!??*%;№@^:()-+=");
const char* actual = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890 .!??*%;№@^:()-+=";
EXPECT_STREQ(actual, text);
delete[] text;
}

TEST(Translation, t2)
{
const char* text = GetTranslate("а б в г д е ё ж з и й к л м н о п р с т у ф х ц ч ш щ ъ ы ь э ю я");
const char* actual = "a b v g d e jo zh z i j k l m n o p r s t u f kh ts ch sh shch \" y \' eh ju ja";
EXPECT_STREQ(actual, text);
delete [] text;
}

TEST(Translation, t3)
{

const char* text = GetTranslate("А Б В Г Д Е Ё Ж З И Й К Л М Н О П Р С Т У Ф Х Ц Ч Ш Щ Ы Э Ю Я");
const char* actual = "A B V G D E Jo Zh Z I J K L M N O P R S T U F Kh Ts Ch Sh Shch Y Eh Ju Ja";
EXPECT_STREQ(actual, text);
delete [] text;
}

TEST(Translation, t4)
{
const int N = 100;
const char* text = GetTranslate("ьъЬЪ");
const char* actual = "\'\"";
EXPECT_STREQ(actual, text);
delete [] text;
}

TEST(Translation, t5)
{
const char* text = GetTranslate("Привет!");
const char* actual = "Privet!";
EXPECT_STREQ(actual, text);
delete [] text;
}

TEST(Translation, t6)
{
const char* text = GetTranslate("Сегодня прекрасная weather. - Сказал Somebody...");
const char* actual = "Segodnja prekrasnaja weather. - Skazal Somebody...";
EXPECT_STREQ(actual, text);
delete [] text;
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}