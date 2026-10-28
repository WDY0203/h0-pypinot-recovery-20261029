#include "../H0PP_shim.hpp"

// ------------------------------------------------------------------
// IDX 1  00104f00  FUN_00104f00
// ------------------------------------------------------------------
void rea_FUN_00104f00(void)
{
  (*(code *)PTR_00312010)();
  return;
}





// ------------------------------------------------------------------
// IDX 3  00104f20  std__string__append
// ------------------------------------------------------------------
undefined8 rea_std__string__append(char * param_1, ulong param_2)
{
  (*(code *)PTR_append_00312020)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 5  00104f40  std__getline_char_std__char_traits_char_std__allocator_char
// ------------------------------------------------------------------
istream * rea_std__getline_char_std__char_traits_char_std__allocator_char(istream * param_1, string * param_2, char param_3)
{
  istream *piVar1;
  
  piVar1 = (istream *)
           (*(code *)PTR_getline_char_std_char_traits_char_std_allocator_char_00312030)();
  return piVar1;
}





// ------------------------------------------------------------------
// IDX 12  00104fb0  std____throw_bad_cast
// ------------------------------------------------------------------
undefined8 rea_std____throw_bad_cast(void)
{
  (*(code *)PTR___throw_bad_cast_00312068)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 13  00104fc0  PyLong_FromVoidPtr
// ------------------------------------------------------------------
undefined8 rea_PyLong_FromVoidPtr(...)
{
  (*(code *)PTR_PyLong_FromVoidPtr_00312070)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 14  00104fd0  std__ios_base__ios_base
// ------------------------------------------------------------------
void rea_std__ios_base__ios_base(ios_base * this_ptr)
{
  (*(code *)PTR_ios_base_00312078)();
  return;
}





// ------------------------------------------------------------------
// IDX 15  00104fe0  PyLong_AsVoidPtr
// ------------------------------------------------------------------
undefined8 rea_PyLong_AsVoidPtr(...)
{
  (*(code *)PTR_PyLong_AsVoidPtr_00312080)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 16  00104ff0  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string(void * this_ptr, char * param_1, ulong param_2, allocator * param_3)
{
  (*(code *)PTR_string_00312088)();
  return;
}





// ------------------------------------------------------------------
// IDX 18  00105010  getClosePrice
// ------------------------------------------------------------------
double rea_getClosePrice(string * gid, int date)
{
  double dVar1;
  SecInfo SStack_19;
  
  rea_SecInfo__SecInfo(&SStack_19);
  dVar1 = rea_SecInfo__getClosePrice(&SStack_19,gid,date);
  return dVar1;
}





// ------------------------------------------------------------------
// IDX 20  00105030  operator_new__
// ------------------------------------------------------------------
void * rea_operator__new(ulong param_1)
{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_operator_new___003120a8)();
  return pvVar1;
}





// ------------------------------------------------------------------
// IDX 22  00105050  operator_delete
// ------------------------------------------------------------------
void rea_operator__delete(void * param_1)
{
  (*(code *)PTR_operator_delete_003120b8)();
  return;
}





// ------------------------------------------------------------------
// IDX 25  00105080  std__string__reserve
// ------------------------------------------------------------------
void rea_std__string__reserve(ulong param_1)
{
  (*(code *)PTR_reserve_003120d0)();
  return;
}





// ------------------------------------------------------------------
// IDX 26  00105090  std__string___Rep___M_dispose
// ------------------------------------------------------------------
void rea_std__string___Rep___M_dispose(allocator * param_1)
{
  (*(code *)PTR__M_dispose_003120d8)();
  return;
}





// ------------------------------------------------------------------
// IDX 27  001050a0  PyBytes_Size
// ------------------------------------------------------------------
undefined8 rea_PyBytes_Size(void)
{
  (*(code *)PTR_PyBytes_Size_003120e0)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 28  001050b0  std__ctype_char___M_widen_init
// ------------------------------------------------------------------
void rea_std__ctype_char___M_widen_init(void)
{
  (*(code *)PTR__M_widen_init_003120e8)();
  return;
}





// ------------------------------------------------------------------
// IDX 29  001050c0  getRescale
// ------------------------------------------------------------------
double rea_getRescale(string * gid, int date)
{
  double dVar1;
  SecInfo SStack_19;
  
  rea_SecInfo__SecInfo(&SStack_19);
  dVar1 = rea_SecInfo__getRescale(&SStack_19,gid,date);
  return dVar1;
}





// ------------------------------------------------------------------
// IDX 32  001050f0  getPreClosePrice
// ------------------------------------------------------------------
double rea_getPreClosePrice(string * gid, int date)
{
  double dVar1;
  SecInfo SStack_19;
  
  rea_SecInfo__SecInfo(&SStack_19);
  dVar1 = rea_SecInfo__getPreClosePrice(&SStack_19,gid,date);
  return dVar1;
}





// ------------------------------------------------------------------
// IDX 33  00105100  __cxa_rethrow
// ------------------------------------------------------------------
undefined8 rea___cxa_rethrow(void)
{
  (*(code *)PTR___cxa_rethrow_00312110)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 35  00105120  fopen
// ------------------------------------------------------------------
FILE * rea_fopen(char * __filename, char * __modes)
{
  FILE *pFVar1;
  
  pFVar1 = (FILE *)(*(code *)PTR_fopen_00312120)();
  return pFVar1;
}





// ------------------------------------------------------------------
// IDX 38  00105150  std___Rb_tree_decrement
// ------------------------------------------------------------------
undefined8 rea_std___Rb_tree_decrement(_Rb_tree_node_base * param_1)
{
  (*(code *)PTR__Rb_tree_decrement_00312138)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 39  00105160  std__string___Rep___S_create
// ------------------------------------------------------------------
undefined8 rea_std__string___Rep___S_create(ulong param_1, ulong param_2, allocator * param_3)
{
  (*(code *)PTR__S_create_00312140)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 41  00105180  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup2(void * this_ptr, string * param_1)
{
  (*(code *)PTR_string_00312150)();
  return;
}





// ------------------------------------------------------------------
// IDX 42  00105190  __cxa_atexit
// ------------------------------------------------------------------
void rea___cxa_atexit(...)
{
  (*(code *)PTR___cxa_atexit_00312158)();
  return;
}





// ------------------------------------------------------------------
// IDX 43  001051a0  dlsym
// ------------------------------------------------------------------
undefined8 rea_dlsym(...)
{
  (*(code *)PTR_dlsym_00312160)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 44  001051b0  std__filebuf__open
// ------------------------------------------------------------------
undefined8 rea_std__filebuf__open(char * param_1, _Ios_Openmode param_2)
{
  (*(code *)PTR_open_00312168)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 45  001051c0  PyLong_AsLong
// ------------------------------------------------------------------
undefined8 rea_PyLong_AsLong(...)
{
  (*(code *)PTR_PyLong_AsLong_00312170)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 48  001051f0  PyArg_ParseTuple
// ------------------------------------------------------------------
undefined8 rea_PyArg_ParseTuple(...)
{
  (*(code *)PTR_PyArg_ParseTuple_00312188)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 50  00105210  std__string___Rep___M_destroy
// ------------------------------------------------------------------
void rea_std__string___Rep___M_destroy(allocator * param_1)
{
  (*(code *)PTR__M_destroy_00312198)();
  return;
}





// ------------------------------------------------------------------
// IDX 54  00105250  PyBytes_AsString
// ------------------------------------------------------------------
undefined8 rea_PyBytes_AsString(...)
{
  (*(code *)PTR_PyBytes_AsString_003121b8)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 59  001052a0  std__string__insert
// ------------------------------------------------------------------
undefined8 rea_std__string__insert(ulong param_1, char * param_2, ulong param_3)
{
  (*(code *)PTR_insert_003121e0)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 61  001052c0  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup3(void * this_ptr, char * param_1, allocator * param_2)
{
  (*(code *)PTR_string_003121f0)();
  return;
}





// ------------------------------------------------------------------
// IDX 62  001052d0  std__string__find
// ------------------------------------------------------------------
undefined8 rea_std__string__find(char * param_1, ulong param_2, ulong param_3)
{
  (*(code *)PTR_find_003121f8)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 64  001052f0  getLastClosePrice
// ------------------------------------------------------------------
double rea_getLastClosePrice(string * gid, int date)
{
  double dVar1;
  SecInfo SStack_19;
  
  rea_SecInfo__SecInfo(&SStack_19);
  dVar1 = rea_SecInfo__getLastClosePrice(&SStack_19,gid,date);
  return dVar1;
}





// ------------------------------------------------------------------
// IDX 67  00105320  memmove
// ------------------------------------------------------------------
void * rea_memmove(void * __dest, void * __src, size_t __n)
{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memmove_00312220)();
  return pvVar1;
}





// ------------------------------------------------------------------
// IDX 68  00105330  fread
// ------------------------------------------------------------------
size_t rea_fread(void * __ptr, size_t __size, size_t __n, FILE * __stream)
{
  size_t sVar1;
  
  sVar1 = (*(code *)PTR_fread_00312228)();
  return sVar1;
}





// ------------------------------------------------------------------
// IDX 71  00105360  getenv
// ------------------------------------------------------------------
char * rea_getenv(char * __name)
{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_getenv_00312240)();
  return pcVar1;
}





// ------------------------------------------------------------------
// IDX 72  00105370  std__ios__init
// ------------------------------------------------------------------
void rea_std__ios__init(streambuf * param_1)
{
  (*(code *)PTR_init_00312248)();
  return;
}





// ------------------------------------------------------------------
// IDX 75  001053a0  Py_BuildValue
// ------------------------------------------------------------------
undefined8 rea_Py_BuildValue(...)
{
  (*(code *)PTR_Py_BuildValue_00312260)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 77  001053c0  std___Rb_tree_insert_and_rebalance________________
// ------------------------------------------------------------------
void rea_std___Rb_tree_insert_and_rebalance(bool param_1, _Rb_tree_node_base * param_2, _Rb_tree_node_base * param_3, _Rb_tree_node_base * param_4)
{
  (*(code *)PTR__Rb_tree_insert_and_rebalance_00312270)();
  return;
}





// ------------------------------------------------------------------
// IDX 81  00105400  std__ios_base__dtor_ios_base
// ------------------------------------------------------------------
void rea_std__ios_base__dtor_ios_base(ios_base * this_ptr)
{
  (*(code *)PTR__ios_base_00312290)();
  return;
}





// ------------------------------------------------------------------
// IDX 82  00105410  strcmp
// ------------------------------------------------------------------
int rea_strcmp(char * __s1, char * __s2)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_strcmp_00312298)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 84  00105430  PyBytes_FromStringAndSize
// ------------------------------------------------------------------
undefined8 rea_PyBytes_FromStringAndSize(...)
{
  (*(code *)PTR_PyBytes_FromStringAndSize_003122a8)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 85  00105440  strcpy
// ------------------------------------------------------------------
char * rea_strcpy(char * __dest, char * __src)
{
  char *pcVar1;
  
  pcVar1 = (char *)(*(code *)PTR_strcpy_003122b0)();
  return pcVar1;
}





// ------------------------------------------------------------------
// IDX 86  00105450  std__string__assign
// ------------------------------------------------------------------
void rea_std__string__assign(string * param_1)
{
  (*(code *)PTR_assign_003122b8)();
  return;
}





// ------------------------------------------------------------------
// IDX 87  00105460  operator_delete__
// ------------------------------------------------------------------
void rea_operator__delete__dup2(void * param_1)
{
  (*(code *)PTR_operator_delete___003122c0)();
  return;
}





// ------------------------------------------------------------------
// IDX 89  00105480  memcmp
// ------------------------------------------------------------------
int rea_memcmp(void * __s1, void * __s2, size_t __n)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_memcmp_003122d0)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 90  00105490  std__ios__clear
// ------------------------------------------------------------------
void rea_std__ios__clear(_Ios_Iostate param_1)
{
  (*(code *)PTR_clear_003122d8)();
  return;
}





// ------------------------------------------------------------------
// IDX 91  001054a0  fclose
// ------------------------------------------------------------------
int rea_fclose(FILE * __stream)
{
  int iVar1;
  
  iVar1 = (*(code *)PTR_fclose_003122e0)();
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 94  001054d0  PyModule_Create2
// ------------------------------------------------------------------
undefined8 rea_PyModule_Create2(...)
{
  (*(code *)PTR_PyModule_Create2_003122f8)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 95  001054e0  PyTuple_New
// ------------------------------------------------------------------
undefined8 rea_PyTuple_New(...)
{
  (*(code *)PTR_PyTuple_New_00312300)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 96  001054f0  std__filebuf__filebuf
// ------------------------------------------------------------------
void rea_std__filebuf__filebuf(filebuf * this_ptr)
{
  (*(code *)PTR_filebuf_00312308)();
  return;
}





// ------------------------------------------------------------------
// IDX 97  00105500  std___Rb_tree_increment
// ------------------------------------------------------------------
undefined8 rea_std___Rb_tree_increment(_Rb_tree_node_base * param_1)
{
  (*(code *)PTR__Rb_tree_increment_00312310)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 98  00105510  __cxa_end_catch
// ------------------------------------------------------------------
void rea___cxa_end_catch(void)
{
  (*(code *)PTR___cxa_end_catch_00312318)();
  return;
}





// ------------------------------------------------------------------
// IDX 99  00105520  std____throw_bad_alloc
// ------------------------------------------------------------------
undefined8 rea_std____throw_bad_alloc(void)
{
  (*(code *)PTR___throw_bad_alloc_00312320)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 100  00105530  std__filebuf__dtor_filebuf
// ------------------------------------------------------------------
void rea_std__filebuf__dtor_filebuf(filebuf * this_ptr)
{
  (*(code *)PTR__filebuf_00312328)();
  return;
}





// ------------------------------------------------------------------
// IDX 101  00105540  PyList_SetItem
// ------------------------------------------------------------------
void rea_PyList_SetItem(...)
{
  (*(code *)PTR_PyList_SetItem_00312330)();
  return;
}





// ------------------------------------------------------------------
// IDX 102  00105550  __cxa_begin_catch
// ------------------------------------------------------------------
void rea___cxa_begin_catch(...)
{
  (*(code *)PTR___cxa_begin_catch_00312338)();
  return;
}





// ------------------------------------------------------------------
// IDX 107  001055a0  operator_new
// ------------------------------------------------------------------
void * rea_operator__new__dup2(ulong param_1)
{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_operator_new_00312360)();
  return pvVar1;
}





// ------------------------------------------------------------------
// IDX 108  001055b0  _Unwind_Resume
// ------------------------------------------------------------------
void rea__Unwind_Resume(...)
{
  (*(code *)PTR__Unwind_Resume_00312368)();
  return;
}





// ------------------------------------------------------------------
// IDX 109  001055c0  dlopen
// ------------------------------------------------------------------
undefined8 rea_dlopen(...)
{
  (*(code *)PTR_dlopen_00312370)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 110  001055d0  PyList_New
// ------------------------------------------------------------------
undefined8 rea_PyList_New(...)
{
  (*(code *)PTR_PyList_New_00312378)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 111  001055e0  PyUnicode_AsUTF8
// ------------------------------------------------------------------
undefined8 rea_PyUnicode_AsUTF8(void)
{
  (*(code *)PTR_PyUnicode_AsUTF8_00312380)();
  return 0;
}





// ------------------------------------------------------------------
// IDX 112  001055f0  memcpy
// ------------------------------------------------------------------
void * rea_memcpy(void * __dest, void * __src, size_t __n)
{
  void *pvVar1;
  
  pvVar1 = (void *)(*(code *)PTR_memcpy_00312388)();
  return pvVar1;
}





// ------------------------------------------------------------------
// IDX 113  00105600  std__string__append
// ------------------------------------------------------------------
void rea_std__string__append__dup2(string * param_1)
{
  (*(code *)PTR_append_00312390)();
  return;
}





// ------------------------------------------------------------------
// IDX 118  00105650  __gmon_start__
// ------------------------------------------------------------------
void rea___gmon_start(void)
{
  (*(code *)PTR___gmon_start___00311f78)();
  return;
}





// ------------------------------------------------------------------
// IDX 119  00105658  __cxa_finalize
// ------------------------------------------------------------------
void rea___cxa_finalize(...)
{
  (*(code *)PTR___cxa_finalize_00311fb8)();
  return;
}





// ------------------------------------------------------------------
// IDX 120  00105660  std__default_delete_SecInfo__GroupData2__operator_call___________
// ------------------------------------------------------------------
void rea_std__default_delete_SecInfo__GroupData2__operator__call(default_delete_SecInfo__GroupData2 * this_ptr, GroupData2 * __ptr)
{
  if (this_ptr != (default_delete_SecInfo__GroupData2 *)0x0) {
    *(undefined4 *)this_ptr = 0;
    *(undefined4 *)(this_ptr + 4) = 0;
    if (*(void **)(this_ptr + 8) != (void *)0x0) {
      rea_operator_delete(*(void **)(this_ptr + 8));
      *(undefined8 *)(this_ptr + 8) = 0;
    }
    if (*(void **)(this_ptr + 0x10) != (void *)0x0) {
      rea_operator_delete(*(void **)(this_ptr + 0x10));
      *(undefined8 *)(this_ptr + 0x10) = 0;
    }
    rea_operator_delete(this_ptr);
    return;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 121  001056ae  std__default_delete_SecInfo__GroupData1__operator_call___________
// ------------------------------------------------------------------
void rea_std__default_delete_SecInfo__GroupData1__operator__call(default_delete_SecInfo__GroupData1 * this_ptr, GroupData1 * __ptr)
{
  if (this_ptr != (default_delete_SecInfo__GroupData1 *)0x0) {
    *(undefined4 *)this_ptr = 0;
    *(undefined4 *)(this_ptr + 4) = 0;
    if (*(void **)(this_ptr + 8) != (void *)0x0) {
      rea_operator_delete(*(void **)(this_ptr + 8));
      *(undefined8 *)(this_ptr + 8) = 0;
    }
    if (*(void **)(this_ptr + 0x10) != (void *)0x0) {
      rea_operator_delete(*(void **)(this_ptr + 0x10));
      *(undefined8 *)(this_ptr + 0x10) = 0;
    }
    rea_operator_delete(this_ptr);
    return;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 122  00105700  _GLOBAL__sub_I__pypinot_cpp
// ------------------------------------------------------------------
void rea__GLOBAL__sub_I__pypinot_cpp(void)
{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  rea___cxa_atexit(PTR__unique_ptr_00311fe8,PTR_data_00311fc8,(void *)&__dso_handle);
  puVar3 = PTR__map_00311fa0;
  puVar2 = PTR_data_store2_00311f70;
  puVar1 = PTR_data_store2_00311f70 + 8;
  *(undefined4 *)(PTR_data_store2_00311f70 + 8) = 0;
  *(undefined8 *)(puVar2 + 0x10) = 0;
  *(undefined8 *)(puVar2 + 0x28) = 0;
  *(undefined **)(puVar2 + 0x18) = puVar1;
  *(undefined **)(puVar2 + 0x20) = puVar1;
  rea___cxa_atexit(puVar3,puVar2,(void *)&__dso_handle);
  puVar3 = PTR_group_data_store1_00311fc0;
  puVar2 = PTR__map_00311f88;
  puVar1 = PTR_group_data_store1_00311fc0 + 8;
  *(undefined4 *)(PTR_group_data_store1_00311fc0 + 8) = 0;
  *(undefined8 *)(puVar3 + 0x10) = 0;
  *(undefined8 *)(puVar3 + 0x28) = 0;
  *(undefined **)(puVar3 + 0x18) = puVar1;
  *(undefined **)(puVar3 + 0x20) = puVar1;
  rea___cxa_atexit(puVar2,puVar3,(void *)&__dso_handle);
  puVar3 = PTR_group_data_store2_00311ff8;
  puVar2 = PTR__map_00311f90;
  puVar1 = PTR_group_data_store2_00311ff8 + 8;
  *(undefined4 *)(PTR_group_data_store2_00311ff8 + 8) = 0;
  *(undefined8 *)(puVar3 + 0x10) = 0;
  *(undefined8 *)(puVar3 + 0x28) = 0;
  *(undefined **)(puVar3 + 0x18) = puVar1;
  *(undefined **)(puVar3 + 0x20) = puVar1;
  rea___cxa_atexit(puVar2,puVar3,(void *)&__dso_handle);
  return;
}





// ------------------------------------------------------------------
// IDX 123  001057e0  deregister_tm_clones
// ------------------------------------------------------------------
void rea_deregister_tm_clones(void)
{
  return;
}





// ------------------------------------------------------------------
// IDX 124  00105810  register_tm_clones
// ------------------------------------------------------------------
void rea_register_tm_clones(void)
{
  return;
}





// ------------------------------------------------------------------
// IDX 143  00106fc0  PyInit__pypinot
// ------------------------------------------------------------------
PyObject * rea_PyInit__pypinot(void)
{
  PyObject *pPVar1;
  
  pPVar1 = (PyObject *)rea_PyModule_Create2((void *)&module__pypinot,0x3f5);
  return pPVar1;
}





// ------------------------------------------------------------------
// IDX 146  00107500  getPreClosePrice
// ------------------------------------------------------------------
double rea_getPreClosePrice__dup2(string * gid, int date)
{
  double dVar1;
  SecInfo info;
  
  rea_SecInfo__SecInfo(&info);
  dVar1 = rea_SecInfo__getPreClosePrice(&info,gid,date);
  return dVar1;
}





// ------------------------------------------------------------------
// IDX 147  00107540  getLastClosePrice
// ------------------------------------------------------------------
double rea_getLastClosePrice__dup2(string * gid, int date)
{
  double dVar1;
  SecInfo info;
  
  rea_SecInfo__SecInfo(&info);
  dVar1 = rea_SecInfo__getLastClosePrice(&info,gid,date);
  return dVar1;
}





// ------------------------------------------------------------------
// IDX 148  00107580  getClosePrice
// ------------------------------------------------------------------
double rea_getClosePrice__dup2(string * gid, int date)
{
  double dVar1;
  SecInfo info;
  
  rea_SecInfo__SecInfo(&info);
  dVar1 = rea_SecInfo__getClosePrice(&info,gid,date);
  return dVar1;
}





// ------------------------------------------------------------------
// IDX 149  001075c0  getRescale
// ------------------------------------------------------------------
double rea_getRescale__dup2(string * gid, int date)
{
  double dVar1;
  SecInfo info;
  
  rea_SecInfo__SecInfo(&info);
  dVar1 = rea_SecInfo__getRescale(&info,gid,date);
  return dVar1;
}





