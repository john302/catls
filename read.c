#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
 
#define unlikely(x)     __builtin_expect((x),0)
#define min(x,y)    (x<y?x:y)
 
ssize_t read(int fildes, void *buf, size_t nbyte)
{
	struct stat statbuf;
	ssize_t r;
 
	fstat(fildes, &statbuf);
 
	if (unlikely(S_ISDIR(statbuf.st_mode))) {
		DIR *fdir;
		struct dirent *dent;
		char *dbuf;
		ssize_t bytes;
 
		fdir = fdopendir(fildes);
		if (!fdir) {
			perror("failed to fdopendir()");
			goto out;
		}
 
		dbuf = malloc(nbyte);
		if (!dbuf) {
			perror("failed to create buffer");
			closedir(fdir);
			goto out;
		}
		memset(dbuf, 0, nbyte);
 
		bytes = 0;
		do {
			size_t sbytes;
 
			if ((dent = readdir(fdir)) != NULL) {
				if (strcmp(dent->d_name, ".") == 0
				    || strcmp(dent->d_name, "..") == 0)
					continue;
 
				sbytes = strlen(dent->d_name);

				/* fprintf(stderr,"nbyte=%zu\tbytes=%zu\tsbytes=%zu\n",
				   nbyte, bytes, sbytes); */

				if (bytes + sbytes > nbyte)
					break;
				else
					bytes += sbytes;
 
				sprintf(dbuf, "%s %s\n", dbuf, dent->d_name);
			}
		} while (dent != NULL);
 
		r = min(bytes, nbyte);
		strncpy(buf, dbuf, r);
 
		free(dbuf);
	} else {
		r = __read(fildes, buf, nbyte);
	}
	printf("\n");
out:
	return r;
}
