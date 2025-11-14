/* 
 * Writer Script for Assignment 2
 * Author: Josh Lalonde
 */

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int ret = 0;
    FILE *fp;
    const char *write_file;
    const char *write_str;

    /* Open syslog logging using LOG_USER */
    openlog(NULL, 0, LOG_USER);

    /* Check if arguments are provided */
    if (argc != 3) {
        syslog(LOG_ERR, "Error: <WRITE_FILE> and <WRITE_STR> arguments are required\n");
        ret = -1;
        goto exit;
    }

    write_file = argv[1];
    write_str = argv[2];

    /* Open file for writing */
    fp = fopen(write_file, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Failed to open file '%s' for writing", write_file);
        ret = -1;
        goto exit;
    }

    /* Write string to file */
    if (fprintf(fp, "%s\n", write_str) < 0) {
        syslog(LOG_ERR, "Failed to write to file '%s'", write_file);
        ret = -1;
        goto exit_file;
    }

    /* Log successful write to syslog */
    syslog(LOG_DEBUG, "Writing %s to %s", write_str, write_file);

exit_file:
    if (fclose(fp) != 0) {
        syslog(LOG_ERR, "Failed to close file '%s'", write_file);
        ret = -1;
    }
exit:
    closelog();
    return ret;
}