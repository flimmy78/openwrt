/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf 17821 2009-11-11 09:00:00Z dts12 $
 */
#ifndef JWSSTATICMCASTTABLE_H
#define JWSSTATICMCASTTABLE_H

/* function declarations */
void init_jwsStaticMcastTable(void);
void initialize_table_jwsStaticMcastTable(void);
Netsnmp_Node_Handler jwsStaticMcastTable_handler;
Netsnmp_First_Data_Point  jwsStaticMcastTable_get_first_data_point;
Netsnmp_Next_Data_Point   jwsStaticMcastTable_get_next_data_point;

/* column number definitions for table jwsStaticMcastTable */
       #define COLUMN_JWSSTATICMCASTINDEX		1
       #define COLUMN_JWSSTATICMCASTADDRESS		2
       #define COLUMN_JWSSTATICMCASTMEMBERS		3
       #define COLUMN_JWSSTATICMCASTROWSTATUS		4
#endif /* JWSSTATICMCASTTABLE_H */