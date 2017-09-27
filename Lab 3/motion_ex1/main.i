#line 1 "F:\Sysc Labs\2006-C\Lab 3\motion_ex1\main.c"
#line 1 "C:\Program Files\PellesC\Include\stdio.h"









#line 1 "C:\Program Files\PellesC\Include\crtdef.h"

































#line 11 "C:\Program Files\PellesC\Include\stdio.h"














































typedef struct mbstate_t {
    unsigned long wchar;
    unsigned short rsrv, state;
} mbstate_t;







typedef unsigned int size_t;





typedef unsigned short wchar_t;




typedef char *va_list;







typedef long _off_t;











typedef struct FILE {

    unsigned int mode;




    int fh;
    unsigned char *buf, *bufend, *ptr;
    unsigned char *getend, *putend, *backptr;
    wchar_t *wbackptr, wbackbuf[2];
    unsigned char *getback, *wgetend, *wputend;
    mbstate_t wstate;
    char *tmpnam;
    unsigned char backbuf[8], cbuf;

    int locknum;

} FILE;

typedef struct fpos_t {

    long long off;



    mbstate_t wstate;
} fpos_t;






extern int __cdecl remove(const char *);
extern int __cdecl rename(const char *, const char *);

extern FILE * __cdecl tmpfile(void);
extern char * __cdecl tmpnam(char *);
extern wchar_t * __cdecl _wtmpnam(wchar_t *);



extern __declspec(release(1)) int __cdecl fclose(FILE *);
extern int __cdecl fflush(FILE *);
extern FILE * __cdecl fopen(const char * restrict, const char * restrict);
extern int __cdecl setvbuf(FILE * restrict, char * restrict, int, size_t);

extern FILE * __cdecl freopen(const char * restrict, const char * restrict, FILE * restrict);
extern void __cdecl setbuf(FILE * restrict, char * restrict);



extern __declspec(vaformat(printf,2,3)) int __cdecl fprintf(FILE * restrict, const char * restrict, ...);
extern __declspec(vaformat(scanf,2,3)) int __cdecl fscanf(FILE * restrict, const char * restrict, ...);
extern __declspec(vaformat(printf,2,3)) int __cdecl sprintf(char * restrict, const char * restrict, ...);
extern __declspec(vaformat(scanf,2,3)) int __cdecl sscanf(const char * restrict, const char * restrict, ...);
extern int __cdecl vfprintf(FILE * restrict, const char * restrict, va_list);
extern int __cdecl vsprintf(char * restrict, const char * restrict, va_list);
extern __declspec(noretchk) int __cdecl vprintf(const char * restrict, va_list);
extern __declspec(vaformat(printf,1,2))__declspec(noretchk) int __cdecl printf(const char * restrict, ...);
extern __declspec(vaformat(scanf,1,2)) int __cdecl scanf(const char * restrict, ...);

extern int __cdecl vfscanf(FILE * restrict, const char * restrict, va_list);
extern int __cdecl vsscanf(const char * restrict, const char * restrict, va_list);
extern int __cdecl vscanf(const char * restrict, va_list);
extern __declspec(vaformat(printf,3,4)) int __cdecl snprintf(char * restrict, size_t, const char * restrict, ...);
extern int __cdecl vsnprintf(char * restrict, size_t, const char * restrict, va_list);






extern int __cdecl fgetc(FILE *);
extern char * __cdecl fgets(char * restrict, int, FILE * restrict);
extern int __cdecl fputc(int, FILE *);
extern int __cdecl fputs(const char * restrict, FILE * restrict);
extern int __cdecl getchar(void);

extern __declspec(deprecated) char * __cdecl gets(char *);

extern __declspec(noretchk) int __cdecl putchar(int);
extern __declspec(noretchk) int __cdecl puts(const char *);
extern int __cdecl ungetc(int, FILE *);

extern int __cdecl getc(FILE *);
extern int __cdecl putc(int, FILE *);






extern size_t __cdecl fread(void * restrict, size_t, size_t, FILE * restrict);
extern size_t __cdecl fwrite(const void * restrict, size_t, size_t, FILE * restrict);


extern int __cdecl fgetpos(FILE * restrict, fpos_t * restrict);
extern int __cdecl fseek(FILE *, long, int);
extern int __cdecl fsetpos(FILE *, const fpos_t *);
extern long __cdecl ftell(FILE *);
extern void __cdecl rewind(FILE *);


extern void __cdecl clearerr(FILE *);
extern int __cdecl feof(FILE *);
extern int __cdecl ferror(FILE *);

extern void __cdecl perror(const char *);
extern void __cdecl _wperror(const wchar_t *);



extern int __cdecl _fileno(FILE *);
extern int __cdecl _fcloseall(void);
extern FILE * __cdecl _wfopen(const wchar_t * restrict, const wchar_t * restrict);
extern FILE * __cdecl _wfreopen(const wchar_t * restrict, const wchar_t * restrict, FILE * restrict);

extern FILE * __cdecl _fdopen(int, const char *);
extern FILE * __cdecl _wfdopen(int, const wchar_t *);
extern FILE * __cdecl _popen(const char *, const char *);
extern __declspec(release(1)) int __cdecl _pclose(FILE *);



extern __declspec(vaformat(printf,3,4)) int __cdecl _snprintf(char * restrict, size_t, const char * restrict, ...);
extern int __cdecl _vsnprintf(char * restrict, size_t, const char * restrict, va_list);
extern int __cdecl _wremove(const wchar_t *);
extern int __cdecl _wrename(const wchar_t *, const wchar_t *);

extern int __cdecl _fseeko(FILE *, _off_t, int);
extern _off_t __cdecl _ftello(FILE *);





extern FILE __stdin, __stdout, __stderr;

extern FILE *__filetab[256];
















































































































#line 2 "F:\Sysc Labs\2006-C\Lab 3\motion_ex1\main.c"
#line 1 "F:\Sysc Labs\2006-C\Lab 3\motion_ex1\motion.h"


double calculate_velocity(double initial_v, double accel, double time);
#line 3 "F:\Sysc Labs\2006-C\Lab 3\motion_ex1\main.c"

int main(void)
{
	double initial_velocity = 10.0;
	double time = 100.0;
	double acceleration = 3.5;

	printf("Calculating final velocity of an object with:\n");
	printf("\tinitial velocity = %.2f m/s\n", initial_velocity);
	printf("\tconstant acceleration = %.2f m/s^2\n", acceleration);
	printf("\telapsed time = %.2f s\n\n", time);
	printf("\tExpected result = 360.0 m/s\n");
	printf("\tActual result = %.2f m/s\n",
		   calculate_velocity(initial_velocity, acceleration, time));
}


