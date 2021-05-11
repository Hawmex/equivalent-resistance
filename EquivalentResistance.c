#include "stdio.h"

int main()
{
    size_t series;
    size_t parallel;

    scanf("%zu%zu", &series, &parallel);

    unsigned int resistors[series][parallel];

    for (size_t p = 0; p < parallel; p++)
        for (size_t s = 0; s < series; s++)
            scanf("%u", &resistors[s][p]);

    double totalResistance = 0;

    for (size_t s = 0; s < series; s++)
    {
        double inversedLocalResistance = 0;

        for (size_t p = 0; p < parallel; p++)
        {
            const double partResistance = resistors[s][p];

            if (partResistance != 0)
                inversedLocalResistance += 1 / partResistance;
        }

        if (inversedLocalResistance != 0)
            totalResistance += 1 / inversedLocalResistance;
    }

    printf("%.1lf", totalResistance);

    return 0;
}
