
#ifndef _SHARED_FUNC_H
#define _SHARED_FUNC_H

#ifdef __cplusplus
extern "C" {
#endif


void SW_Debug(const char *fmt,...);

#define SW_PRINTFL(lev, fmt, args...)\
do{\
	SW_Debug("%s:%s,%d \n",__FILE__,__FUNCTION__,__LINE__);\
	SW_Debug(fmt, ##args);\
}while(0)

#define SW_RTN_ON_ERROR(rtn)  do { if (rtn != SW_OK) return(rtn); } while(0)
#define SW_OUT_ON_ERROR(rtn) \
    do { \
        if (rtn != SW_OK) { \
            rv = rtn; \
            goto out;\
        } \
    } while(0)

#define SW_OUT_ON_ERROR_FL(rtn) \
    do { \
        if (rtn != SW_OK) { \
            SW_PRINTFL(WARN,"error occurs %d\n", rv);\
            goto out;\
        } \
    } while(0)

#define SW_RTN_ON_ERROR_EXCEPT_COND1(rtn, cond1) \
    do { \
        if ((rtn != SW_OK) && (rtn != cond1)) \
            return rtn; \
    }while(0)

#define SW_RTN_ON_NULL(op)  \
    do { \
        if ((op) == NULL) \
            return SW_NOT_INITIALIZED;\
    }while(0)

/* register functions */
#define SW_BIT_MASK_U32(nr) (~(0xFFFFFFFF << (nr)))
#define SW_FIELD_MASK_U32(offset, len)  ((SW_BIT_MASK_U32(len) << (offset)))
#define SW_FIELD_MASK_NOT_U32(offset,len) (~(SW_BIT_MASK_U32(len) << (offset)))
#define SW_FIELD_2_REG(field_val, bit_offset)  (field_val << (bit_offset) )
#define SW_REG_2_FIELD(reg_val, bit_offset, field_len) (((reg_val) >> (bit_offset)) & ((1 << (field_len)) - 1))
#define SW_REG_SET_BY_FIELD_U32(reg_value, field_value, bit_offset, field_len)\
	do { \
        (reg_value) = \
            (((reg_value) & SW_FIELD_MASK_NOT_U32((bit_offset),(field_len))) \
              | (((field_value) & SW_BIT_MASK_U32(field_len)) << (bit_offset)));\
    } while (0)

#define SW_FIELD_GET_BY_REG_U32(reg_value, field_value, bit_offset, field_len)\
	do { \
        (field_value) = \
            (((reg_value) >> (bit_offset)) & SW_BIT_MASK_U32(field_len)); \
    } while (0)

#define SW_SWAP_BITS_U8(x)         \
    ((((x)&0x80)>>7) | (((x)&0x40)>>5) | (((x)&0x20)>>3) | (((x)&0x10)>>1) | (((x)&0x1)<<7) | (((x)&0x2)<<5) | (((x)&0x4)<<3) |(((x)&0x8)<<1) )


#define SW_OFFSET_U8_2_U16(byte_offset)   ((byte_offset) >> 1)
#define SW_OFFSET_U16_2_U8(word16_offset)   ((word16_offset) << 1)
#define SW_OFFSET_BIT_2_U8_ALIGN16(bit_offset)   (((bit_offset) / 16) * 2)

#define SW_SET_REG_BY_FIELD(reg, field, field_value, reg_value) \
    SW_REG_SET_BY_FIELD_U32(reg_value, field_value, reg##_##field##_BOFFSET, reg##_##field##_BLEN)

#define SW_GET_FIELD_BY_REG(reg, field, field_value, reg_value) \
    SW_FIELD_GET_BY_REG_U32(reg_value, field_value, reg##_##field##_BOFFSET, reg##_##field##_BLEN)
		                 
/* port bitmap functions */
#define SW_IS_PBMP_MEMBER(pbm, port)  ((pbm & (1 << port)) ? A_TRUE: A_FALSE)
#define SW_IS_PBMP_EQ(pbm0, pbm1)  ((pbm0 == pbm1) ? A_TRUE: A_FALSE)

#define SW_PBMP_AND(pbm0, pbm1)  ((pbm0) &= (pbm1))
#define SW_PBMP_OR(pbm0, pbm1)  ((pbm0) |= (pbm1))
#define SW_IS_PBMP_INCLUDE(pbm0, pbm1) \
    ((pbm1 == SW_PBMP_AND(pbm0, pbm1)) ? A_TRUE: A_FALSE)

#define SW_PBMP_CLEAR(pbm) ((pbm) = 0)
#define SW_PBMP_ADD_PORT(pbm, port) ((pbm) |= (1U << (port)))
#define SW_PBMP_DEL_PORT(pbm,port) ((pbm) &= ~(1U << (port)))

enum
{
    FATAL = 1, /**<KIT_DEBUG_LEVEL_FATAL*/
    WARN,      /**<KIT_DEBUG_LEVEL_WARNING*/
    TRACE,     /**<KIT_DEBUG_LEVEL_TRACE*/
    DETAIL,    /**<KIT_DEBUG_LEVEL_DETAIL*/
    FORCE,     /**<KIT_DEBUG_LEVEL_FORCE*/
};

#ifdef __cplusplus
}
#endif
#endif

