#include <stdlib.h>

#include "app.h"

int main(int argc, char* argv[])
{
    App* app = app_new();
    app_run(app);
    app_free(app);

    return 0;
}
