#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include <string.h>

int splitter(char* path)
{
    int count = 0;
    int ans = 0;
	char* line = NULL;
	size_t len;
	FILE* dest[2];
	dest[0] = fopen("./R1.fq", "wb");
	dest[1] = fopen("./R2.fq", "wb");
    FILE* source = fopen(path, "rb");
    if (source == NULL){exit(EXIT_FAILURE);}
    int n = getline(&line, &len, source);
    while (n != -1){
        while (count <= 3){
            fwrite(line, 1, strlen(line), dest[ans]);
            count++;
            n = getline(&line, &len, source);}
        ans = abs(ans-1);
        count = 0;}
    fclose(source);
    fclose(dest[0]);
    fclose(dest[1]);
    return 0;
}

int gzipSplitter(char* path)
{
    char buffer[1024];
    int count = 0;
    int ans = 0;
    gzFile ban = gzopen(path, "rb");
    gzFile dest[2];
    dest[0] = gzopen("R1.fq.gz", "rw");
    dest[1] = gzopen("R2.fq.gz", "rw");
    if (ban == NULL){exit(1);}

    while (!gzeof(ban)){
        while ((count <= 3) & (!gzeof(ban))){
            if (!gzeof(ban)){
                gzgets(ban, buffer, sizeof(char)*1024);
                gzwrite(dest[ans], buffer, strlen(buffer));
                count++;}
            else{break;}}
        ans = abs(ans-1);
        count = 0;}
    gzclose_r(ban);
    gzclose_w(dest[0]);
    gzclose_w(dest[1]);
    return 0;
}

int main(int argc, char** argv)
{
    //'./S_S001__genomes_30__insert_180_reads_anonymous.fq.gz'
    //printf("%d\n", strcmp(argv[1]+strlen(argv[1])-3, ".gz"));
    //printf("%d\n", strcmp(argv[1]+strlen(argv[1])-3, ".gzip"));
    if ((strcmp(argv[1]+strlen(argv[1])-3, ".gz") == 0) | (strcmp(argv[1]+strlen(argv[1])-3, ".gzip") == 0)){
        printf("Gzip splitter\n");
        gzipSplitter(argv[1]);
    }else{
        printf("No Gzip splitter\n");
        splitter(argv[1]);
        }
    exit(EXIT_SUCCESS);
}
