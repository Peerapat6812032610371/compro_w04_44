#include <stdio.h>

// ประกาศตัวแปร constant แบบ Global
const int GLOBAL_RATE = 10;

void calculate() {
    // ประกาศตัวแปร constant แบบ Local (ใช้ได้เฉพาะในฟังก์ชันนี้เท่านั้น)
    const int LOCAL_BONUS = 50;

    printf("GLOBAL_RATE = %d\n", GLOBAL_RATE);    // เข้าถึงตัวแปร global ได้
    printf("LOCAL_BONUS = %d\n", LOCAL_BONUS);    // เข้าถึงตัวแปร local ได้
}

int main() {
    calculate();

    // เข้าถึงตัวแปร global ได้จาก main
    printf("GLOBAL_RATE in main = %d\n", GLOBAL_RATE);

    // * ข้อผิดพลาด: LOCAL_BONUS ถูกประกาศใน calculate() เท่านั้น *
    // ไม่สามารถใช้ LOCAL_BONUS ใน main ได้
    // ถ้าเปิดบรรทัดนี้จะ compile error
    // printf("LOCAL_BONUS in main = %d\n", LOCAL_BONUS); 

    return 0;
}