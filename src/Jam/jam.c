/* 
Nama : Bryan Rinaldo 
Nim : 13519103
Tanggal : 2 september2020 
Topik Praktikum : bahasa c 
deskripsi : Definisi ABSTRACT DATA TYPE POINT  
*/
#include <stdio.h>
#include "jam.h"

boolean IsJAMValid (int H, int M, int S){
   return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59));
}

/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM){
   JAM J;
   J.HH = HH;
   J.MM = MM;
   return J;
}
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */

void TulisJAM (JAM J){
   printf("%d:%d\n", J.HH,J.MM);
}
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
int JAMToMenit (JAM J){
   return (Hour(J)*60 + Minute(J)*1);
}
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

JAM MenitToJAM (int N){
   {
      JAM J;
      int h,m;
      m = N%60;
      h = N/60;
      J.HH=h; J.MM=m;
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
   return(JAMToMenit(J1) == JAMToMenit(J2));
}
/* Mengirimkan true jika J1=J2, false jika tidak */
boolean JNEQ (JAM J1, JAM J2){
   return(JAMToMenit(J1) != JAMToMenit(J2));
}
/* Mengirimkan true jika J1 tidak sama dengan J2 */
boolean JLT (JAM J1, JAM J2){
   return(JAMToMenit(J1) < JAMToMenit(J2));
}
/* Mengirimkan true jika J1<J2, false jika tidak */
boolean JGT (JAM J1, JAM J2){
   return(JAMToMenit(J1) > JAMToMenit(J2));
}

/* Mengirim N detik sebelum J dalam bentuk JAM */
int Durasi (JAM JAw, JAM JAkh)
{
   if (JGT(JAw,JAkh)){
      return JAMToMenit(MakeJAM(24,0)) - JAMToMenit(JAw) + JAMToMenit(JAkh);
   }else{
      return JAMToMenit(JAkh) - JAMToMenit(JAw);
   }
}

void NextMenit (JAM * J)
{
   (*J).MM += 1;
   if ((*J).MM==60){
      (*J).HH+=1;
      (*J).MM = (*J).MM%60;
   }
   if ((*J).HH==24){
      (*J).HH = (*J).HH%24;
   }
}

void addJam(JAM *J, int menit){
   (*J).MM += menit;
   if ((*J).MM>=60){
      (*J).HH += (*J).MM/60;
      if ((*J).HH>=24){
         (*J).HH = (*J).HH % 24;
      }
      (*J).MM = (*J).MM%60;
   }
}