#ifndef ADMIN_H
#define ADMIN_H

#define Password 1234
struct PatientSlot * searchforid(u8);
void Admin_voidAddPatient(void);
void Admin_voidEditPatient(void);
void AvailableSlots(void);
void Admin_voidReserveSlot(u8,u8);
void Admin_voidCancelReservation(void);
int Admin_u8Login(void);
void Admin_voidMode(void);
void User_voidPatientRecord(void);
void User_voidTodayReservation(void);
void User_voidMode(void);

#endif