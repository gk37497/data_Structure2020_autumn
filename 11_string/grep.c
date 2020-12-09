#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#define BLUE "\x1b[34m"
int case_insensitive = 0;
/*
  Функц нь buf доторх тэмдэгтэн цуваанаас index байрлалаас эхлэн
  pattern тэмдэгтийг хайна. Олдвол олдсон индексийг буцанаа.
  Олдохгүй бол -1 утгыг буцаана.
  case_insensitive = 1 бол том жижиг гэж ялгалгүйгээр тааруулна.
  Мөн мөрний мэдээллийг давхар хариуцаж явна.
  Мөр шилжих үед (*pline)++

  buf     :    Хайлт хийх тэмдэгтэн цуваа
  index   :    Хайлтыг эхлэх индекс
  pattern :    Хайх үг
  pline   :    Мөрийн мэдээлэл хадгалах хувьсагчийн хаяг
 */
int find(const char *buf, int index, const char *pattern, int *pline)
{
        /*
          Функцыг гүйцээ
         */
        int n = strlen(buf);
        int m = strlen(pattern);
        int ascii;
        for (int i = index; i <= n - m; i++)
        {
                int j;
                for (j = 0; j < m; j++)
                {
                        ascii = pattern[j];
                        if (pattern[j] <= 90)
                                ascii += 32;
                        else if (pattern[j] >= 97)
                                ascii -= 32;

                        if ((buf[i + j] != pattern[j]) && (buf[i + j] != ascii))
                                break;
                }
                if (j == m)
                {
                        // printf("i: %d   mur : ", i);
                        return i;
                }
                if (buf[i] == '\n')
                        (*pline)++;
        }
        return -1;
}

int main(int argc, char *argv[])
{
        // Аргументийн тоо ядаж 3 байх ёстой.
        if (argc < 3)
        {
                printf("%s [-i] pattern file", argv[0]);
                exit(-1);
        }

        if (argc > 3 && strcmp("-i", argv[1]) == 0)
                case_insensitive = 1; // Том жижгийг хайхрахгүй адил гэж үзнэ.

        const char *pattern = argv[2];
        FILE *fin;
        fin = fopen(argv[argc - 1], "r");
        if (fin == NULL)
        {
                printf("Error openning %s file", argv[argc - 1]);
                exit(-1);
        }
        int len = 0;
        char ch;
        while (!feof(fin))
        {
                ch = fgetc(fin);
                len++; // Файлд доторх тэмдэгтүүдийг тоолъё.
        }
        char *buf;
        buf = (char *)malloc(sizeof(char) * (len + 1)); // Энд тэмдэгтүүдийг хадгална
        fseek(fin, 0, SEEK_SET);                        // Файл заагчийг буцаад эхлэлд нь аваачна.
        int i = 0;
        while (!feof(fin))
                buf[i++] = fgetc(fin); // Өгөглийг уншиж байна.
        buf[len - 1] = 0;              /* тэмдэгт мөр төгсгөл заагч */
        int ret = -1;
        int line = 0;
        int haha = strlen(pattern);
        do
        {
                ret = find(buf, ret + 1, pattern, &line);
                if (ret != -1)
                {
                        printf(BLUE "%d: " RESET, line);
                        /*
                          Олдсон газраас доошоо 5
                          дээшээ 5 тэмдэгтийг хэвлэнэ.
                         */
                        int L = ret - 30;
                        int R = ret + strlen(pattern) + 30;
                        for (i = L; i <= R; i++)
                        {
                                if (i >= 0 && (i < ret || i > ret + haha))
                                        printf("%c", buf[i]);
                                if (i == ret)
                                        for (int j = ret; j < ret + haha; j++)
                                                printf(RED "%c" RESET, buf[j]);
                        }
                        printf("\n");
                }

        } while (ret != -1);

        return 0;
}
