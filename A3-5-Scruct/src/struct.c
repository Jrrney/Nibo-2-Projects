/**
 @file struct.c
 @author Jenny Dietrich
 @date 1.0
 @brief struct equals
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct article
{
    char headline[30];
    int page;
    int number;

} article_t;

/**
 * compares 2 articles
 *
 * @param a1 one article
 * @param a2 other article
 *
 * @return true, if they equals otherwise false
 */
int equals_article(const article_t *a1, const article_t *a2)
{
    int diff = strcmp(a1->headline, a2->headline);
    if (diff)
    {
        return false;
    }

    diff = a1->number - a2->number;
    if (diff)
    {
        return false;
    }

    diff = a1->page - a2->page;
    if (diff)
    {
        return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    article_t art1 = {"Die Schlagzeile schlechthin", 244, 33};
    article_t art2 = {"Die Schlagzeile schlechthin", 244, 33};
    article_t art3 = {"Die Schlagzeile_schlechthin", 244, 33};

    printf("1 %s 2\n", equals_article(&art1, &art2) ? "equals" : "not equals");
    printf("2 %s 3\n", equals_article(&art2, &art3) ? "equals" : "not equals");

    return 0;
}
