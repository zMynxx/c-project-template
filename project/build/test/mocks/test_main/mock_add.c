/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_add.h"

static const char* CMockString_a = "a";
static const char* CMockString_add = "add";
static const char* CMockString_b = "b";

typedef struct _CMOCK_add_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  int ReturnVal;
  int CallOrder;
  int Expected_a;
  int Expected_b;

} CMOCK_add_CALL_INSTANCE;

static struct mock_addInstance
{
  char add_IgnoreBool;
  int add_FinalReturn;
  char add_CallbackBool;
  CMOCK_add_CALLBACK add_CallbackFunctionPointer;
  int add_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE add_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_add_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.add_CallInstance;
  if (Mock.add_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_add);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.add_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void mock_add_Init(void)
{
  mock_add_Destroy();
}

void mock_add_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

int add(int a, int b)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_add_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_add);
  cmock_call_instance = (CMOCK_add_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.add_CallInstance);
  Mock.add_CallInstance = CMock_Guts_MemNext(Mock.add_CallInstance);
  if (Mock.add_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.add_FinalReturn;
    Mock.add_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.add_CallbackBool &&
      Mock.add_CallbackFunctionPointer != NULL)
  {
    int cmock_cb_ret = Mock.add_CallbackFunctionPointer(a, b, Mock.add_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_add,CMockString_a);
    UNITY_TEST_ASSERT_EQUAL_INT(cmock_call_instance->Expected_a, a, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_add,CMockString_b);
    UNITY_TEST_ASSERT_EQUAL_INT(cmock_call_instance->Expected_b, b, cmock_line, CMockStringMismatch);
  }
  if (Mock.add_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.add_CallbackFunctionPointer(a, b, Mock.add_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_add(CMOCK_add_CALL_INSTANCE* cmock_call_instance, int a, int b);
void CMockExpectParameters_add(CMOCK_add_CALL_INSTANCE* cmock_call_instance, int a, int b)
{
  cmock_call_instance->Expected_a = a;
  cmock_call_instance->Expected_b = b;
}

void add_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_add_CALL_INSTANCE));
  CMOCK_add_CALL_INSTANCE* cmock_call_instance = (CMOCK_add_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.add_CallInstance = CMock_Guts_MemChain(Mock.add_CallInstance, cmock_guts_index);
  Mock.add_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.add_IgnoreBool = (char)1;
}

void add_CMockStopIgnore(void)
{
  if(Mock.add_IgnoreBool)
    Mock.add_CallInstance = CMock_Guts_MemNext(Mock.add_CallInstance);
  Mock.add_IgnoreBool = (char)0;
}

void add_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int a, int b, int cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_add_CALL_INSTANCE));
  CMOCK_add_CALL_INSTANCE* cmock_call_instance = (CMOCK_add_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.add_CallInstance = CMock_Guts_MemChain(Mock.add_CallInstance, cmock_guts_index);
  Mock.add_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_add(cmock_call_instance, a, b);
  cmock_call_instance->ReturnVal = cmock_to_return;
}

void add_AddCallback(CMOCK_add_CALLBACK Callback)
{
  Mock.add_IgnoreBool = (char)0;
  Mock.add_CallbackBool = (char)1;
  Mock.add_CallbackFunctionPointer = Callback;
}

void add_Stub(CMOCK_add_CALLBACK Callback)
{
  Mock.add_IgnoreBool = (char)0;
  Mock.add_CallbackBool = (char)0;
  Mock.add_CallbackFunctionPointer = Callback;
}

