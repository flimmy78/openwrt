/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.scalar.conf 11805 2005-01-07 09:37:18Z dts12 $
 */
#ifndef JWSDEVSNMPCONFIG_H
#define JWSDEVSNMPCONFIG_H

/* function declarations */
void init_jwsDevSnmpConfig(void);
Netsnmp_Node_Handler handle_jwsSnmpEnable;
Netsnmp_Node_Handler handle_jwsSnmpReadOnlyCommunity;
Netsnmp_Node_Handler handle_jwsSnmpReadWriteCommunity;
Netsnmp_Node_Handler handle_jwsSnmpPort;
Netsnmp_Node_Handler handle_jwsSnmpTrapEnable;
Netsnmp_Node_Handler handle_jwsSnmpTrapPort;
Netsnmp_Node_Handler handle_jwsSnmpTrapServerIP;

#endif /* JWSDEVSNMPCONFIG_H */
