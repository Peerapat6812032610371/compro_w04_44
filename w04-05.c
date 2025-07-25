#include <stdio.h>

// ฟังก์ชันที่ใช้ static variable
void countCallStatic() {
    static int counter = 0;  // ค่าจะไม่ถูกรีเซ็ตเมื่อเรียกฟังก์ชันซ้ำ
    counter++;
    printf("Static Function: Counter = %d\n", counter);
}

// ฟังก์ชันที่ใช้ non-static variable
void countCallNonStatic() {
    int counter = 0;         // ค่าจะถูกรีเซ็ตเป็น 0 ทุกครั้งที่เรียก
    counter++;
    printf("Non-Static Function: Counter = %d\n", counter);
}

int main() {
    printf("== เรียกฟังก์ชันแบบ Static ==\n");
    countCallStatic(); // ครั้งที่ 1 → ได้ 1
    countCallStatic(); // ครั้งที่ 2 → ได้ 2 เพราะไม่รีเซ็ต

    printf("\n== เรียกฟังก์ชันแบบ Non-Static ==\n");
    countCallNonStatic(); // ครั้งที่ 1 → ได้ 1
    countCallNonStatic(); // ครั้งที่ 2 → ได้ 1 อีกครั้ง (เพราะรีเซ็ต)

    return 0;
}
//คำถามท้ายโจทย์
//1. ต่างกัน 1 เพราะ อีกตัว เพิ่มขึ้นเรื่อยๆ อีกตัว เริ่มนับใหม่เรื่อยๆ
//2. ความแตกต่าง Static-Non-Static  Staticเพิ่มขึ้นไปเรื่อยๆเช่น 1 -> 2 -> 3  เพราะจะจำค่าครั้งล่าสุดไว้ 
//   แต่ของ Non-Static รีเซ็ตตัวเองทุกครั้งก็จะเริ่มนับ 1 -> 1 -> 1 ไปเรื่อยๆ จะเริ่มใหม่ทุกครั้งที่เรียกใช้ฟังชั้น
//3. ใช้ static เมื่อเราต้องการ เก็บสถานะข้ามการเรียกฟังก์ชัน ใช้ตัวแปรปกติ (non-static)เมื่อต้องการให้เรืมใหม่ทุกครั้ง