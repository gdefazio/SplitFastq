# SplitFastq
It splits a fastq file containing R1 and R2 reads.

Compile: $gcc main.c -g -o SplitFastq.

Then: $chmod +rx SplitFastq.

Exec mode 1: SplitFastq ./path_to_fastq.fq.

Exec mode 2: SplitFastq ./path_to_gzipped_fastq.fq.gz.

Return: ./R1.fq & ./R2.fq | (./R1.fq.gz & ./R2.fq.gz).

Warning: You can use this program if the input fastq file has the following format

@S|S1|R0/1<br>
sequence<br>
+<br>
quality<br>
@S|S1|R0/2<br>
sequence<br>
+<br>
quality<br>
@S|S1|R1/1<br>
sequence<br>
+<br>
quality<br>
@S|S1|R1/2<br>
sequence<br>
+<br>
quality<br>
