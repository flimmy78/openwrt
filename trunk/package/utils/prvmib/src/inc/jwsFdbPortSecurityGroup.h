/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 17821 2009-11-11 09:00:00Z dts12 $
 */
#ifndef JWSFDBPORTSECURITYGROUP_H
#define JWSFDBPORTSECURITYGROUP_H

/* function declarations */
void init_jwsFdbPortSecurityGroup(void);
Netsnmp_Node_Handler handle_jwsFdbSecureAddrNumber;
void initialize_table_jwsFdbSecurePortTable(void);
Netsnmp_Node_Handler jwsFdbSecurePortTable_handler;
Netsnmp_First_Data_Point  jwsFdbSecurePortTable_get_first_data_point;
Netsnmp_Next_Data_Point   jwsFdbSecurePortTable_get_next_data_point;
void initialize_table_jwsFdbSecureAddrTable(void);
Netsnmp_Node_Handler jwsFdbSecureAddrTable_handler;
Netsnmp_First_Data_Point  jwsFdbSecureAddrTable_get_first_data_point;
Netsnmp_Next_Data_Point   jwsFdbSecureAddrTable_get_next_data_point;

/* column number definitions for table jwsFdbSecurePortTable */
       #define COLUMN_JWSFDBSECUREPORTINDEX		1
       #define COLUMN_JWSFDBSECUREPORTENABLE		2

/* column number definitions for table jwsFdbSecureAddrTable */
       #define COLUMN_JWSFDBSECUREADDRINDEX		1
       #define COLUMN_JWSFDBSECUREADDRPORTID		2
       #define COLUMN_JWSFDBSECUREADDRMACADDRESS		3
       #define COLUMN_JWSFDBSECUREADDRROWSTATUS		4
#endif /* JWSFDBPORTSECURITYGROUP_H */