#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CMD_FILE "comandos"
#define OUT_FILE "resultados"
#define SHELL    "./leaks.sh"

int main(void)
{
    FILE *cmds = fopen(CMD_FILE, "r");
    FILE *out = fopen(OUT_FILE, "w");
    if (!cmds || !out)
    {
        perror("fopen");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), cmds))
    {
        // Quita salto de línea
        line[strcspn(line, "\n")] = 0;

        // Prepara el comando para minishell
        char shell_cmd[512];
        snprintf(shell_cmd, sizeof(shell_cmd), "echo \"%s\" | %s", line, SHELL);

        // Ejecuta el comando y captura el output
        FILE *pipe = popen(shell_cmd, "r");
        if (!pipe)
        {
            fprintf(out, "Error ejecutando: %s\n", line);
            continue;
        }

        // Escribe el comando en el archivo de salida
        fprintf(out, "Comando: %s\nOutput:\n", line);

        // Guarda el output
        char output[512];
        while (fgets(output, sizeof(output), pipe))
            fputs(output, out);

        fprintf(out, "----------------------\n");
        pclose(pipe);
    }

    fclose(cmds);
    fclose(out);
    return 0;
}