/* 
Nama : Bryan Rinaldo 
Nim : 13519103
Tanggal : 2 september2020 
Topik Praktikum : bahasa c 
deskripsi : Definisi ABSTRACT DATA TYPE POINT  
*/
#include <stdio.h>
#include "jam.h"
#include <math.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
#define Hour(J) (J).HH
#define Minute(J) (J).MM
#define Second(J) (J).SS
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S){
   return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59));
}

/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS){
   JAM J;
   J.HH = HH;
   J.MM = MM;
   J.SS = SS;
   return J;
}
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
{ 
   int H,M,S;
   scanf("%d %d %d", &H, &M, &S);
   while (!IsJAMValid(H,M,S)){
      printf("Jam tidak valid\n");
      scanf("%d %d %d", &H, &M, &S);
      }
   *J = MakeJAM(H,M,S);
}

/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */

void TulisJAM (JAM J){
   printf("%d:%d:%d\n", J.HH,J.MM,J.SS);
}
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J){
   return (Hour(J)*3600 + Minute(J)*60 + Second(J));
}
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

JAM DetikToJAM (long N){
   {
      JAM J;
      int mod,h,m,s,N1;
      N1 = N%86400;
      h = N1/3600;
      mod=N1%3600;
      m=mod/60;
      s=mod%60;
      J.HH=h; J.MM=m; J.SS=s;
      return J;
      }
}
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2){
   return(JAMToDetik(J1) == JAMToDetik(J2));
}
/* Mengirimkan true jika J1=J2, false jika tidak */
boolean JNEQ (JAM J1, JAM J2){
   return(JAMToDetik(J1) != JAMToDetik(J2));
}
/* Mengirimkan true jika J1 tidak sama dengan J2 */
boolean JLT (JAM J1, JAM J2){
   return(JAMToDetik(J1) < JAMToDetik(J2));
}
/* Mengirimkan true jika J1<J2, false jika tidak */
boolean JGT (JAM J1, JAM J2){
   return(JAMToDetik(J1) > JAMToDetik(J2));
}

/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
{
   return(DetikToJAM(JAMToDetik(J)+1));
}
/* Mengirim 1 detik setelah J dalam bentuk JAM */
JAM NextNDetik (JAM J, int N)
{
   return(DetikToJAM(JAMToDetik(J)+N));
}
/* Mengirim N detik setelah J dalam bentuk JAM */
JAM PrevDetik (JAM J)
{
   return(DetikToJAM(JAMToDetik(J)-1));
}
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
JAM PrevNDetik (JAM J, int N)
{
   return(DetikToJAM(JAMToDetik(J)-N));
}

/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh)
{
   if(JAMToDetik(JAkh) > JAMToDetik(JAw)){
      return(JAMToDetik(JAkh)-JAMToDetik(JAw));
      }
      else {
      return((JAMToDetik(JAkh)+86400)-JAMToDetik(JAw));
    }
}
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */