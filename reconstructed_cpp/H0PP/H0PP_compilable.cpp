#include "H0PP_shim.hpp"

// ------------------------------------------------------------------
// IDX 0  00104ed8  _init
// ------------------------------------------------------------------
int rea__init(EVP_PKEY_CTX * ctx)
{
  int iVar1;
  
  iVar1 = 0;
  if (PTR___gmon_start___00311f78 != (undefined *)0x0) {
    iVar1 = __gmon_start__();
  }
  return iVar1;
}





// ------------------------------------------------------------------
// IDX 1  00104f00  FUN_00104f00
// ------------------------------------------------------------------
void rea_FUN_00104f00(void)
{
  (*(code *)PTR_00312010)();
  return;
}





// ------------------------------------------------------------------
// IDX 2  00104f10  pinot_open
// ------------------------------------------------------------------
void * rea_pinot_open(string file)
{
  undefined *puVar1;
  char *pcVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 *puVar5;
  void *pvVar6;
  long *plVar7;
  long lVar8;
  
  pcVar2 = *(char **)file._M_dataplus._M_p;
  puVar5 = rea_operator_new(8);
  if (pinot_reader_handle == (void *)0x0) {
    pvVar6 = (void *)rea_dlopen("/opt/bbcluster/alpha/pinot/bin/libpinot_reader.so",2);
    if (pvVar6 != (void *)0x0) {
      pinot_reader_handle = pvVar6;
      pinot_reader_open = (code *)rea_dlsym(pvVar6,"pinot_reader_open");
      pinot_reader_close = (code *)rea_dlsym(pvVar6,"pinot_reader_close");
      pinot_reader_is_open = (code *)rea_dlsym(pvVar6,"pinot_reader_is_open");
      pinot_reader_getline = (code *)rea_dlsym(pvVar6,"pinot_reader_getline");
      pinot_reader_read = (code *)rea_dlsym(pvVar6,"pinot_reader_read");
    }
    if (pinot_reader_handle == (void *)0x0) {
      plVar7 = rea_operator_new(0x208);
      rea_std__ios_base__ios_base((ios_base *)(plVar7 + 0x20));
      puVar1 = PTR_vtable_00311f68;
      *(undefined1 *)(plVar7 + 0x3c) = 0;
      plVar7[0x3b] = 0;
      *(undefined1 *)((long)plVar7 + 0x1e1) = 0;
      plVar7[0x3d] = 0;
      plVar7[0x3e] = 0;
      plVar7[0x3f] = 0;
      plVar7[0x40] = 0;
      plVar7[0x20] = (long)(puVar1 + 0x10);
      lVar8 = *(long *)(PTR_VTT_00311fe0 + 8);
      uVar3 = *(undefined8 *)(PTR_VTT_00311fe0 + 0x10);
      lVar4 = *(long *)(lVar8 + -0x18);
      *plVar7 = lVar8;
      *(undefined8 *)((long)plVar7 + lVar4) = uVar3;
      plVar7[1] = 0;
      rea_std__ios__init((streambuf *)((long)plVar7 + *(long *)(lVar8 + -0x18)));
      puVar1 = PTR_vtable_00311fb0 + 0x18;
      plVar7[0x20] = (long)(PTR_vtable_00311fb0 + 0x40);
      *plVar7 = (long)puVar1;
      rea_std__filebuf__filebuf((filebuf *)(plVar7 + 2));
      rea_std__ios__init((streambuf *)(plVar7 + 0x20));
      lVar8 = rea_std__filebuf__open((char *)(plVar7 + 2),(_Ios_Openmode)pcVar2);
      if (lVar8 == 0) {
        rea_std__ios__clear((int)plVar7 + (int)*(undefined8 *)(*plVar7 + -0x18));
      }
      else {
        rea_std__ios__clear((int)plVar7 + (int)*(undefined8 *)(*plVar7 + -0x18));
      }
      *puVar5 = plVar7;
      return puVar5;
    }
  }
  pvVar6 = (*pinot_reader_open)(pcVar2);
  *puVar5 = pvVar6;
  return puVar5;
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
// IDX 4  00104f30  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_insert__const_std__pair_std__basic_string_char__double____________
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_insert__const_std__pair_std__basic_string_char__double(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, _Base_ptr __x, _Base_ptr __p, pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double * __v)
{
  size_type *psVar1;
  char *__s1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  _Rb_tree_node_base *p_Var5;
  ulong __n;
  bool bVar6;
  long lVar7;
  
  bVar6 = true;
  if ((__x == (_Base_ptr)0x0) && (__p != &(this_ptr->_M_impl)._M_header)) {
    __s1 = (__v->first)._M_dataplus._M_p;
    uVar2 = *(ulong *)((long)*(void **)(__p + 1) + -0x18);
    uVar3 = *(ulong *)(__s1 + -0x18);
    __n = uVar3;
    if (uVar2 <= uVar3) {
      __n = uVar2;
    }
    iVar4 = rea_memcmp(__s1,*(void **)(__p + 1),__n);
    if (iVar4 == 0) {
      lVar7 = uVar3 - uVar2;
      bVar6 = false;
      if ((0x7fffffff < lVar7) || (bVar6 = true, lVar7 < -0x80000000)) goto LAB_0010eb42;
      iVar4 = (int)lVar7;
    }
    bVar6 = SUB41((uint)iVar4 >> 0x1f,0);
  }
LAB_0010eb42:
  p_Var5 = rea_operator_new(0x30);
  if (p_Var5 != (_Rb_tree_node_base *)0x0) {
    p_Var5->_M_color = _S_red;
    p_Var5->_M_parent = (_Base_ptr)0x0;
    p_Var5->_M_left = (_Base_ptr)0x0;
    p_Var5->_M_right = (_Base_ptr)0x0;
    rea_std__string__string(p_Var5 + 1,&__v->first);
    p_Var5[1]._M_parent = (_Base_ptr)__v->second;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar6,p_Var5,__p,&(this_ptr->_M_impl)._M_header);
  psVar1 = &(this_ptr->_M_impl)._M_node_count;
  *psVar1 = *psVar1 + 1;
  return (iterator)p_Var5;
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
// IDX 6  00104f50  IndexedData_GIDKey__Item__free
// ------------------------------------------------------------------
void rea_IndexedData_GIDKey__Item__free(IndexedData_GIDKey__Item * this_ptr)
{
  this_ptr->num_idxs = 0;
  this_ptr->num_items = 0;
  if (this_ptr->idxs != (Index *)0x0) {
    rea_operator_delete(this_ptr->idxs);
    this_ptr->idxs = (Index *)0x0;
  }
  if (this_ptr->items != (Item *)0x0) {
    rea_operator_delete(this_ptr->items);
    this_ptr->items = (Item *)0x0;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 7  00104f60  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_erase(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, _Link_type __x)
{
  _Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_ _Var1;
  _Link_type p_Var2;
  
  while (__x != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(__x->super__Rb_tree_node_base)._M_right);
    _Var1 = (__x->_M_value_field).second._M_t.
            super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_>;
    p_Var2 = (_Link_type)(__x->super__Rb_tree_node_base)._M_left;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long)_Var1 + 4) = 0;
      if (*(void **)((long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 8));
        *(undefined8 *)((long)_Var1 + 8) = 0;
      }
      if (*(void **)((long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 0x10));
        *(undefined8 *)((long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (__x->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_> =
         (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
    rea_operator_delete(__x);
    __x = p_Var2;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 8  00104f70  _Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____M___parse
// ------------------------------------------------------------------
undefined8 rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____M___parse(vector_unsigned_char__std__allocator_unsigned_char_ * b, size_t p, map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * v)
{
  ulong uVar1;
  _Rb_tree_node_base *__p;
  bool bVar2;
  basic_string_char__std__char_traits_char__std__allocator_char_ __s1;
  string sVar3;
  uint uVar4;
  int iVar5;
  pointer puVar6;
  ulong *puVar7;
  _Link_type p_Var8;
  _Link_type p_Var9;
  ulong uVar10;
  size_t __n;
  _Alloc_hider _Var11;
  _Link_type p_Var12;
  pointer pdVar13;
  pointer puVar14;
  char *__s2;
  ulong uVar15;
  long lVar16;
  ulong uVar17;
  _Alloc_hider _Stack_148;
  ulong uStack_140;
  ulong *puStack_130;
  allocator aStack_e1;
  ulong *puStack_e0;
  ulong *apuStack_d8 [2];
  vector_double__std__allocator_double_ vStack_c8;
  pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__
  pStack_a8;
  string sStack_88;
  vector_double__std__allocator_double_ vStack_80;
  _Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
  _Stack_68;
  
  puVar6 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl._M_finish;
  puVar14 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl._M_start;
  _Stack_68._M_impl._M_header._M_color = _S_red;
  _Stack_68._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  _Stack_68._M_impl._M_header._M_left = &_Stack_68._M_impl._M_header;
  _Stack_68._M_impl._M_node_count = 0;
  _Stack_148._M_p = (char *)(p + 8);
  _Stack_68._M_impl._M_header._M_right = _Stack_68._M_impl._M_header._M_left;
  if ((ulong)((long)puVar6 - (long)puVar14) < _Stack_148._M_p) {
    p_Var12 = (_Link_type)0x0;
    uStack_140 = p;
  }
  else {
    rea_memcpy(&sStack_88,puVar14 + p,8);
    sVar3._M_dataplus._M_p = sStack_88._M_dataplus._M_p;
    uStack_140 = (ulong)_Stack_148._M_p;
    if (sStack_88._M_dataplus._M_p != (char *)0x0) {
      puStack_130 = (ulong *)0x0;
      do {
        pStack_a8.second.super__Vector_base_double__std__allocator_double_._M_impl._M_start =
             (pointer)0x0;
        pStack_a8.second.super__Vector_base_double__std__allocator_double_._M_impl._M_finish =
             (pointer)0x0;
        pStack_a8.second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_end_of_storage = (pointer)0x0;
        vStack_80.super__Vector_base_double__std__allocator_double_._M_impl._M_start =
             (pointer)0x0;
        vStack_80.super__Vector_base_double__std__allocator_double_._M_impl._M_finish =
             (pointer)0x0;
        _Var11._M_p = PTR__S_empty_rep_storage_00311ff0 + 0x18;
        vStack_80.super__Vector_base_double__std__allocator_double_._M_impl._M_end_of_storage =
             (pointer)0x0;
        uVar10 = (long)_Stack_148._M_p + 8;
        pStack_a8.first._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var11._M_p;
        sStack_88._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var11._M_p;
        if ((ulong)((long)puVar6 - (long)puVar14) < uVar10) {
LAB_0010f7e8:
          uStack_140 = (ulong)_Stack_148._M_p;
        }
        else {
          rea_memcpy(&vStack_c8,puVar14 + (long)_Stack_148._M_p,8);
          uVar15 = uVar10 + (long)vStack_c8.super__Vector_base_double__std__allocator_double_.
                                  _M_impl._M_start;
          if ((ulong)((long)puVar6 - (long)puVar14) < uVar15) goto LAB_0010f7e8;
          puVar14 = puVar14 + uVar10;
          if (puVar14 !=
              puVar14 + (long)vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl.
                              _M_start) {
            uVar17 = (long)(puVar14 +
                           (long)vStack_c8.super__Vector_base_double__std__allocator_double_.
                                 _M_impl._M_start) - (long)puVar14;
            puVar7 = (ulong *)rea_std__string___Rep___S_create(uVar17,0,&aStack_e1);
            _Var11._M_p = (char *)(puVar7 + 3);
            uVar10 = 0;
            do {
              *(uchar *)((long)_Var11._M_p + uVar10) = puVar14[uVar10];
              uVar10 = uVar10 + 1;
            } while (uVar10 != uVar17);
            if (puVar7 != (ulong *)PTR__S_empty_rep_storage_00311ff0) {
              *(undefined4 *)(puVar7 + 2) = 0;
              *puVar7 = uVar17;
              *(undefined1 *)((long)puVar7 + uVar17 + 0x18) = 0;
            }
          }
          apuStack_d8[0] = (ulong *)_Var11._M_p;
          rea_std__string__assign(&sStack_88);
          if ((allocator *)(apuStack_d8[0] + -3) != (allocator *)PTR__S_empty_rep_storage_00311ff0)
          {
            puVar7 = apuStack_d8[0] + -1;
            if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
              iVar5 = (int)apuStack_d8[0][-1];
              *(int *)(apuStack_d8[0] + -1) = iVar5 + -1;
            }
            else {
              LOCK();
              iVar5 = (int)*puVar7;
              *(int *)puVar7 = (int)*puVar7 + -1;
              UNLOCK();
            }
            if (iVar5 < 1) {
              rea_std__string___Rep___M_destroy((allocator *)(apuStack_d8[0] + -3));
            }
          }
          if (_Stack_148._M_p == (char *)uVar15) {
LAB_0010f880:
            uStack_140 = (ulong)_Stack_148._M_p;
          }
          else {
            puVar6 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                     _M_start;
            vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl._M_start =
                 (pointer)0x0;
            vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl._M_finish =
                 (pointer)0x0;
            vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl._M_end_of_storage
                 = (pointer)0x0;
            uVar10 = uVar15 + 8;
            uVar17 = (long)(b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>).
                           _M_impl._M_finish - (long)puVar6;
            if (uVar17 < uVar10) goto LAB_0010f880;
            rea_memcpy(apuStack_d8,puVar6 + uVar15,8);
            puVar7 = apuStack_d8[0];
            if (apuStack_d8[0] == (ulong *)0x0) {
LAB_0010f7c0:
              std__vector_double__std__allocator_double___operator_assign(&vStack_80,&vStack_c8);
              pdVar13 = vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl.
                        _M_start;
              uStack_140 = uVar10;
            }
            else {
              uStack_140 = uVar15;
              if (uVar17 < uVar15 + 0x10) {
                pdVar13 = (pointer)0x0;
              }
              else {
                lVar16 = 0;
                uVar17 = uVar10;
                uVar10 = uVar15 + 0x10;
                do {
                  rea_memcpy(apuStack_d8,puVar6 + uVar17,8);
                  puStack_e0 = apuStack_d8[0];
                  pdVar13 = vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl.
                            _M_start;
                  if (uVar17 == uVar10) break;
                  if (vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl.
                      _M_finish ==
                      vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl.
                      _M_end_of_storage) {
                    std__vector_double__std__allocator_double____M_emplace_back_aux_double_const________________________________(&vStack_c8);
                    pdVar13 = vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl.
                              _M_start;
                  }
                  else {
                    if (vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl.
                        _M_finish != (pointer)0x0) {
                      *vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl.
                       _M_finish = (double)apuStack_d8[0];
                    }
                    vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl._M_finish
                         = vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl.
                           _M_finish + 1;
                  }
                  vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl._M_start =
                       pdVar13;
                  if ((ulong *)(lVar16 + 1) == puVar7) goto LAB_0010f7c0;
                  lVar16 = lVar16 + 1;
                  puVar6 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>).
                           _M_impl._M_start;
                  uVar1 = uVar10 + 8;
                  uVar17 = uVar10;
                  uVar10 = uVar1;
                } while (uVar1 <= (ulong)((long)(b->
                                                super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>
                                                )._M_impl._M_finish - (long)puVar6));
              }
            }
            if (pdVar13 != (pointer)0x0) {
              rea_operator_delete(pdVar13);
            }
            if (uVar15 == uStack_140) goto LAB_0010f880;
            rea_std__string__assign(&pStack_a8.first);
            std__vector_double__std__allocator_double___operator_assign(&pStack_a8.second,&vStack_80);
          }
          if (vStack_80.super__Vector_base_double__std__allocator_double_._M_impl._M_start !=
              (pointer)0x0) {
            rea_operator_delete(vStack_80.super__Vector_base_double__std__allocator_double_._M_impl.
                            _M_start);
          }
        }
        if ((allocator *)((long)sStack_88._M_dataplus._M_p + -0x18) !=
            (allocator *)PTR__S_empty_rep_storage_00311ff0) {
          puVar7 = (ulong *)((long)sStack_88._M_dataplus._M_p + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
            iVar5 = *(int *)((long)sStack_88._M_dataplus._M_p + -8);
            *(int *)((long)sStack_88._M_dataplus._M_p + -8) = iVar5 + -1;
          }
          else {
            LOCK();
            iVar5 = *(int *)puVar7;
            *(int *)puVar7 = *(int *)puVar7 + -1;
            UNLOCK();
          }
          if (iVar5 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)((long)sStack_88._M_dataplus._M_p + -0x18));
          }
        }
        __s1._M_dataplus._M_p = pStack_a8.first._M_dataplus._M_p;
        if (_Stack_148._M_p == (char *)uStack_140) {
          if (pStack_a8.second.super__Vector_base_double__std__allocator_double_._M_impl._M_start
              != (pointer)0x0) {
            rea_operator_delete(pStack_a8.second.super__Vector_base_double__std__allocator_double_.
                            _M_impl._M_start);
          }
          p_Var12 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
          uStack_140 = p;
          if ((allocator *)((long)pStack_a8.first._M_dataplus._M_p + -0x18) !=
              (allocator *)PTR__S_empty_rep_storage_00311ff0) {
            puVar7 = (ulong *)((long)pStack_a8.first._M_dataplus._M_p + -8);
            if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
              iVar5 = *(int *)((long)pStack_a8.first._M_dataplus._M_p + -8);
              *(int *)((long)pStack_a8.first._M_dataplus._M_p + -8) = iVar5 + -1;
            }
            else {
              LOCK();
              iVar5 = *(int *)puVar7;
              *(int *)puVar7 = *(int *)puVar7 + -1;
              UNLOCK();
            }
            if (iVar5 < 1) {
              std__string___Rep___M_destroy_________________________((allocator *)((long)pStack_a8.first._M_dataplus._M_p + -0x18));
              p_Var12 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
            }
          }
          goto LAB_0010f8d7;
        }
        if ((_Link_type)_Stack_68._M_impl._M_header._M_parent == (_Link_type)0x0) {
          p_Var8 = (_Link_type)&_Stack_68._M_impl._M_header;
LAB_0010f800:
          if ((_Link_type)_Stack_68._M_impl._M_header._M_left != p_Var8) {
            lVar16 = rea_std___Rb_tree_decrement(&p_Var8->super__Rb_tree_node_base);
            __s2 = *(char **)(lVar16 + 0x20);
            _Stack_148 = pStack_a8.first._M_dataplus._M_p;
            uVar15 = *(ulong *)(__s2 + -0x18);
            uVar10 = *(ulong *)((long)pStack_a8.first._M_dataplus._M_p + -0x18);
            __n = uVar10;
            if (uVar15 <= uVar10) {
              __n = uVar15;
            }
            goto LAB_0010f70c;
          }
LAB_0010f849:
          std______________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__________________M_insert__const_std__pair_std__basic_string_char__std__vector_double_______________________(&_Stack_68,(_Base_ptr)0x0,&p_Var8->super__Rb_tree_node_base,&pStack_a8);
        }
        else {
          _Stack_148 = pStack_a8.first._M_dataplus._M_p;
          uVar10 = *(ulong *)((long)pStack_a8.first._M_dataplus._M_p + -0x18);
          p_Var12 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
          do {
            p_Var8 = p_Var12;
            __s2 = (p_Var8->_M_value_field).first._M_dataplus._M_p;
            uVar15 = *(ulong *)(__s2 + -0x18);
            __n = uVar15;
            if (uVar10 <= uVar15) {
              __n = uVar10;
            }
            uVar4 = rea_memcmp((void *)__s1._M_dataplus._M_p,__s2,__n);
            uVar17 = (ulong)uVar4;
            if (uVar4 == 0) {
              uVar17 = uVar10 - uVar15;
              if ((long)uVar17 < 0x80000000) {
                if (-0x80000001 < (long)uVar17) goto LAB_0010f6a8;
                goto LAB_0010f6ac;
              }
LAB_0010f6f0:
              p_Var12 = (_Link_type)(p_Var8->super__Rb_tree_node_base)._M_right;
              bVar2 = false;
            }
            else {
LAB_0010f6a8:
              if (-1 < (int)uVar17) goto LAB_0010f6f0;
LAB_0010f6ac:
              p_Var12 = (_Link_type)(p_Var8->super__Rb_tree_node_base)._M_left;
              bVar2 = true;
            }
          } while (p_Var12 != (_Link_type)0x0);
          if (bVar2) goto LAB_0010f800;
LAB_0010f70c:
          iVar5 = rea_memcmp(__s2,_Stack_148._M_p,__n);
          if (iVar5 == 0) {
            lVar16 = uVar15 - uVar10;
            if (lVar16 < 0x80000000) {
              if (-0x80000001 < lVar16) {
                iVar5 = (int)lVar16;
                goto LAB_0010f739;
              }
              goto LAB_0010f840;
            }
          }
          else {
LAB_0010f739:
            if (iVar5 < 0) {
LAB_0010f840:
              if (p_Var8 != (_Link_type)0x0) goto LAB_0010f849;
            }
          }
        }
        if (pStack_a8.second.super__Vector_base_double__std__allocator_double_._M_impl._M_start !=
            (pointer)0x0) {
          rea_operator_delete(pStack_a8.second.super__Vector_base_double__std__allocator_double_.
                          _M_impl._M_start);
        }
        if ((allocator *)((long)pStack_a8.first._M_dataplus._M_p + -0x18) !=
            (allocator *)PTR__S_empty_rep_storage_00311ff0) {
          puVar7 = (ulong *)((long)pStack_a8.first._M_dataplus._M_p + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
            iVar5 = *(int *)((long)pStack_a8.first._M_dataplus._M_p + -8);
            *(int *)((long)pStack_a8.first._M_dataplus._M_p + -8) = iVar5 + -1;
          }
          else {
            LOCK();
            iVar5 = *(int *)puVar7;
            *(int *)puVar7 = *(int *)puVar7 + -1;
            UNLOCK();
          }
          if (iVar5 < 1) {
            std__string___Rep___M_destroy_______________________((allocator *)((long)pStack_a8.first._M_dataplus._M_p + -0x18));
          }
        }
        puStack_130 = (ulong *)((long)puStack_130 + 1);
        if ((_Alloc_hider)puStack_130 == sVar3._M_dataplus._M_p) break;
        puVar14 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                  _M_start;
        puVar6 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                 _M_finish;
        _Stack_148._M_p = (char *)uStack_140;
      } while( true );
    }
    p_Var12 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
    if (v != (map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
              *)0x0) {
      std__________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______________M_erase(&v->_M_t,(_Link_type)(v->_M_t)._M_impl._M_header._M_parent);
      __p = &(v->_M_t)._M_impl._M_header;
      (v->_M_t)._M_impl._M_header._M_parent = (_Base_ptr)0x0;
      (v->_M_t)._M_impl._M_node_count = 0;
      (v->_M_t)._M_impl._M_header._M_left = __p;
      (v->_M_t)._M_impl._M_header._M_right = __p;
      if ((_Const_Link_type)_Stack_68._M_impl._M_header._M_parent == (_Const_Link_type)0x0) {
        p_Var12 = (_Link_type)0x0;
      }
      else {
        p_Var8 = std_____________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_________________________M_copy(&v->_M_t,(_Const_Link_type)_Stack_68._M_impl._M_header._M_parent,
                           (_Link_type)__p);
        (v->_M_t)._M_impl._M_header._M_parent = &p_Var8->super__Rb_tree_node_base;
        p_Var12 = p_Var8;
        do {
          p_Var9 = p_Var12;
          p_Var12 = (_Link_type)(p_Var9->super__Rb_tree_node_base)._M_left;
        } while (p_Var12 != (_Link_type)0x0);
        (v->_M_t)._M_impl._M_header._M_left = &p_Var9->super__Rb_tree_node_base;
        do {
          p_Var12 = p_Var8;
          p_Var8 = (_Link_type)(p_Var12->super__Rb_tree_node_base)._M_right;
        } while (p_Var8 != (_Link_type)0x0);
        (v->_M_t)._M_impl._M_header._M_right = &p_Var12->super__Rb_tree_node_base;
        (v->_M_t)._M_impl._M_node_count = _Stack_68._M_impl._M_node_count;
        p_Var12 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
      }
    }
  }
LAB_0010f8d7:
  std______Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__________M_erase(&_Stack_68,p_Var12);
  return uStack_140;
}





// ------------------------------------------------------------------
// IDX 9  00104f80  SecInfo__getRescale
// ------------------------------------------------------------------
double rea_SecInfo__getRescale(SecInfo * this_ptr, string * gid, int date)
{
  int date_00;
  double dVar1;
  double dVar2;
  
  dVar1 = rea_getPreClosePrice(this_ptr,gid,date);
  if (((!NAN(dVar1)) && (date_00 = getPreDate(this_ptr,gid,date), date_00 != 0)) &&
     (dVar2 = rea_getClosePrice(this_ptr,gid,date_00), !NAN(dVar2))) {
    return dVar1 / dVar2;
  }
  return DAT_0010fd18;
}





// ------------------------------------------------------------------
// IDX 10  00104f90  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_unique_pos(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, key_type * __k)
{
  _Rb_tree_node_base *p_Var1;
  int iVar2;
  _Rb_tree_color _Var3;
  _Rb_tree_node_base *p_Var4;
  _Rb_tree_node_base *p_Var5;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar6;
  
  p_Var1 = (this_ptr->_M_impl)._M_header._M_parent;
  if (p_Var1 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = &(this_ptr->_M_impl)._M_header;
LAB_0010d7d0:
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
    if ((this_ptr->_M_impl)._M_header._M_left == p_Var5) goto LAB_0010d7bf;
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var5);
    iVar2 = *__k;
    _Var3 = p_Var1[1]._M_color;
  }
  else {
    iVar2 = *__k;
    do {
      p_Var5 = p_Var1;
      _Var3 = p_Var5[1]._M_color;
      if (iVar2 < (int)_Var3) {
        p_Var1 = p_Var5->_M_left;
      }
      else {
        p_Var1 = p_Var5->_M_right;
      }
    } while (p_Var1 != (_Base_ptr)0x0);
    p_Var1 = p_Var5;
    if (iVar2 < (int)_Var3) goto LAB_0010d7d0;
  }
  p_Var4 = (_Rb_tree_node_base *)0x0;
  if ((int)_Var3 < iVar2) {
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
  }
LAB_0010d7bf:
  pVar6.second = p_Var4;
  pVar6.first = p_Var1;
  return pVar6;
}





// ------------------------------------------------------------------
// IDX 11  00104fa0  SecInfo__find_group_data2
// ------------------------------------------------------------------
GroupData2 * rea_SecInfo__find_group_data2(SecInfo * this_ptr, int date)
{
  _Base_ptr *pp_Var1;
  int *piVar2;
  _Base_ptr p_Var3;
  _Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_ this_00;
  undefined *this_01;
  undefined *puVar4;
  string sVar5;
  int iVar6;
  iterator iVar7;
  _Link_type __z;
  iterator __position;
  long *plVar8;
  FILE *__stream;
  size_t sVar9;
  _Alloc_hider _Var10;
  void *pvVar11;
  _Base_ptr p_Var12;
  _Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____
  *this_02;
  ulong uVar13;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar14;
  uint auStack_7c [5];
  long alStack_68 [2];
  long alStack_58 [2];
  string asStack_48 [3];
  
  this_01 = PTR_group_data_store1_00311fc0;
  auStack_7c[0] = date;
  iVar7 = std______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________find((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____
                  *)PTR_group_data_store1_00311fc0,(int *)auStack_7c);
  this_02 = (_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____
             *)PTR_group_data_store2_00311ff8;
  if (iVar7._M_node == (_Base_ptr)(this_01 + 8)) {
    rea___gnu_cxx____to_xstring_std__basic_string_char__char
              ((code *)
               alStack_68,(size_t)PTR_vsnprintf_00311fd0,(char *)0x10,(void *)&DAT_0010fc03,
               (ulong)auStack_7c[0]);
    plVar8 = (long *)rea_std__string__insert((ulong)alStack_68,(char *)0x0,0x10fc13);
    puVar4 = PTR__S_empty_rep_storage_00311ff0;
    alStack_58[0] = *plVar8;
    *plVar8 = (long)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    plVar8 = (long *)rea_std__string__append((char *)alStack_58,0x10fbfd);
    asStack_48[0]._M_dataplus._M_p = (_Alloc_hider)*plVar8;
    *plVar8 = (long)(puVar4 + 0x18);
    __stream = rea_open_file(asStack_48);
    if ((allocator *)((long)asStack_48[0]._M_dataplus._M_p + -0x18) != (allocator *)puVar4) {
      piVar2 = (int *)((long)asStack_48[0]._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar6 = *(int *)((long)asStack_48[0]._M_dataplus._M_p + -8);
        *(int *)((long)asStack_48[0]._M_dataplus._M_p + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long)asStack_48[0]._M_dataplus._M_p + -0x18));
      }
    }
    if ((allocator *)(alStack_58[0] + -0x18) != (allocator *)puVar4) {
      piVar2 = (int *)(alStack_58[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar6 = *(int *)(alStack_58[0] + -8);
        *(int *)(alStack_58[0] + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(alStack_58[0] + -0x18));
      }
    }
    if ((allocator *)(alStack_68[0] + -0x18) != (allocator *)puVar4) {
      piVar2 = (int *)(alStack_68[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar6 = *(int *)(alStack_68[0] + -8);
        *(int *)(alStack_68[0] + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(alStack_68[0] + -0x18));
      }
    }
    if (((__stream == (FILE *)0x0) || (sVar9 = rea_fread(alStack_58,4,1,(FILE *)__stream), sVar9 != 1))
       || ((int)alStack_58[0] != 0)) {
      return (GroupData2 *)0x0;
    }
    _Var10._M_p = rea_operator_new(0x18);
    _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)(_Var10._M_p + 4) < 0xaa0000000000001) {
        uVar13 = (long)*(int *)(_Var10._M_p + 4) * 0xc;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long)*(int *)_Var10._M_p) ||
         (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),0xc,(long)*(int *)(_Var10._M_p + 4),
                        (FILE *)__stream), sVar9 != (long)*(int *)(_Var10._M_p + 4)))
      goto LAB_00108b30;
    }
    else {
LAB_00108b30:
      _Var10._M_p[0] = '\0';
      _Var10._M_p[1] = '\0';
      _Var10._M_p[2] = '\0';
      _Var10._M_p[3] = '\0';
      *(int *)(_Var10._M_p + 4) = 0;
      if (*(void **)(_Var10._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 8));
        *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    asStack_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____
                *)this_01);
    sVar5._M_dataplus._M_p = asStack_48[0]._M_dataplus._M_p;
    if (asStack_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)asStack_48[0]._M_dataplus._M_p = 0;
      *(int *)((long)asStack_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long)asStack_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)asStack_48[0]._M_dataplus._M_p + 8));
        ((int *)((long)sVar5._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long)sVar5._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long)sVar5._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)sVar5._M_dataplus._M_p + 0x10));
        ((int *)((long)sVar5._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long)sVar5._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar5._M_dataplus._M_p);
    }
    _Var10._M_p = rea_operator_new(0x18);
    _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)(_Var10._M_p + 4) < 0x3f80000000000001) {
        uVar13 = (long)*(int *)(_Var10._M_p + 4) * 2;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long)*(int *)_Var10._M_p) ||
         (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),2,(long)*(int *)(_Var10._M_p + 4),
                        (FILE *)__stream), sVar9 != (long)*(int *)(_Var10._M_p + 4)))
      goto LAB_00108c18;
    }
    else {
LAB_00108c18:
      _Var10._M_p[0] = '\0';
      _Var10._M_p[1] = '\0';
      _Var10._M_p[2] = '\0';
      _Var10._M_p[3] = '\0';
      *(int *)(_Var10._M_p + 4) = 0;
      if (*(void **)(_Var10._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 8));
        *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    this_02 = (_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____
               *)PTR_group_data_store2_00311ff8;
    asStack_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____
                *)PTR_group_data_store2_00311ff8);
    sVar5._M_dataplus._M_p = asStack_48[0]._M_dataplus._M_p;
    if (asStack_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)asStack_48[0]._M_dataplus._M_p = 0;
      *(int *)((long)asStack_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long)asStack_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)asStack_48[0]._M_dataplus._M_p + 8));
        ((int *)((long)sVar5._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long)sVar5._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long)sVar5._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)sVar5._M_dataplus._M_p + 0x10));
        ((int *)((long)sVar5._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long)sVar5._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar5._M_dataplus._M_p);
    }
    rea_fclose((FILE *)__stream);
  }
  p_Var3 = (this_02->_M_impl)._M_header._M_parent;
  if (p_Var3 == (_Base_ptr)0x0) {
    __position._M_node = &(this_02->_M_impl)._M_header;
  }
  else {
    p_Var12 = &(this_02->_M_impl)._M_header;
    do {
      while (__position._M_node = p_Var3, (int)__position._M_node[1]._M_color < (int)auStack_7c[0])
      {
        pp_Var1 = &(__position._M_node)->_M_right;
        p_Var3 = *pp_Var1;
        __position._M_node = p_Var12;
        if (*pp_Var1 == (_Base_ptr)0x0) goto LAB_0010894a;
      }
      p_Var3 = (__position._M_node)->_M_left;
      p_Var12 = __position._M_node;
    } while ((__position._M_node)->_M_left != (_Base_ptr)0x0);
LAB_0010894a:
    if ((__position._M_node != &(this_02->_M_impl)._M_header) &&
       ((int)__position._M_node[1]._M_color <= (int)auStack_7c[0])) goto LAB_00108958;
  }
  __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_> =
         (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
    (__z->_M_value_field).first = auStack_7c[0];
  }
  pVar14 = std_______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2___________________M_get_insert_hint_unique_pos______________________(this_02,(const_iterator)__position._M_node,&(__z->_M_value_field).first);
  __position._M_node = pVar14.first;
  if (pVar14.second == (_Base_ptr)0x0) {
    this_00 = (__z->_M_value_field).second._M_t.
              super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_>
    ;
    if (this_00 !=
        (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0) {
      IndexedData_GIDKey__GroupBackwardItem__free_________________((IndexedData_GIDKey__GroupBackwardItem *)this_00);
      rea_operator_delete((void *)this_00);
    }
    (__z->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_> =
         (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
    rea_operator_delete(__z);
  }
  else {
    __position = std_____________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________________M_insert_node(this_02,__position._M_node,pVar14.second,__z);
  }
LAB_00108958:
  return (GroupData2 *)__position._M_node[1]._M_parent;
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
// IDX 17  00105000  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_______M_emplace_hint_unique_const_std__piecewise_construct_t___std__tuple_const_std__basic_string_char__std__char_traits_char__std__allocator_char____std__tuple_____________
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_______M_emplace_hint_unique_const_std__piecewise_construct_t___std__tuple_const_std__basic_string_char__std__char_traits_char__std__allocator_char____std__tuple(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, const_iterator __pos)
{
  _Rb_tree_node_base *p_Var1;
  size_type *psVar2;
  int *piVar3;
  string *psVar4;
  ulong uVar5;
  ulong uVar6;
  int iVar7;
  _Rb_tree_node_base *p_Var8;
  undefined8 *in_RCX;
  ulong __n;
  bool bVar9;
  _Rb_tree_node_base *p_Var10;
  long lVar11;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar12;
  
  p_Var10 = (_Rb_tree_node_base *)0x20;
  p_Var8 = rea_operator_new(0x30);
  if (p_Var8 != (_Rb_tree_node_base *)0x0) {
    p_Var10 = p_Var8 + 1;
    psVar4 = (string *)*in_RCX;
    p_Var8->_M_color = _S_red;
    p_Var8->_M_parent = (_Base_ptr)0x0;
    p_Var8->_M_left = (_Base_ptr)0x0;
    p_Var8->_M_right = (_Base_ptr)0x0;
    rea_std__string__string(p_Var10,psVar4);
    p_Var8[1]._M_parent = (_Base_ptr)0x0;
  }
  pVar12 = _M_get_insert_hint_unique_pos(this_ptr,__pos,(key_type *)p_Var10);
  p_Var10 = pVar12.second;
  if (p_Var10 == (_Rb_tree_node_base *)0x0) {
    lVar11 = *(long *)(p_Var8 + 1);
    if ((allocator *)(lVar11 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar3 = (int *)(lVar11 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar7 = *(int *)(lVar11 + -8);
        *(int *)(lVar11 + -8) = iVar7 + -1;
      }
      else {
        LOCK();
        iVar7 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
      }
      if (iVar7 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(lVar11 + -0x18));
      }
    }
    rea_operator_delete(p_Var8);
    return (iterator)pVar12.first;
  }
  p_Var1 = &(this_ptr->_M_impl)._M_header;
  if ((pVar12.first == (_Base_ptr)0x0) && (p_Var10 != p_Var1)) {
    uVar5 = *(ulong *)((long)*(void **)(p_Var8 + 1) + -0x18);
    uVar6 = *(ulong *)((long)*(void **)(p_Var10 + 1) + -0x18);
    __n = uVar5;
    if (uVar6 <= uVar5) {
      __n = uVar6;
    }
    iVar7 = rea_memcmp(*(void **)(p_Var8 + 1),*(void **)(p_Var10 + 1),__n);
    if (iVar7 == 0) {
      lVar11 = uVar5 - uVar6;
      bVar9 = false;
      if (0x7fffffff < lVar11) goto LAB_0010e136;
      if (lVar11 < -0x80000000) goto LAB_0010e131;
      iVar7 = (int)lVar11;
    }
    if (-1 < iVar7) {
      bVar9 = false;
      goto LAB_0010e136;
    }
  }
LAB_0010e131:
  bVar9 = true;
LAB_0010e136:
  rea_std___Rb_tree_insert_and_rebalance(bVar9,p_Var8,p_Var10,p_Var1);
  psVar2 = &(this_ptr->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)p_Var8;
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
// IDX 19  00105020  std__vector_double__std__allocator_double____M_emplace_back_aux_double_const____________
// ------------------------------------------------------------------
void rea_std__vector_double__std__allocator_double____M_emplace_back_aux_double_const(vector_double__std__allocator_double_ * this_ptr)
{
  pointer __dest;
  long lVar1;
  ulong uVar2;
  double *in_RSI;
  pointer __src;
  ulong uVar3;
  pointer pdVar4;
  
  uVar2 = (long)(this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish -
          (long)(this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start >> 3;
  uVar3 = 8;
  if (uVar2 != 0) {
    if (uVar2 * 2 < uVar2) {
      uVar3 = 0xfffffffffffffff8;
    }
    else {
      uVar3 = 0xfffffffffffffff8;
      if (uVar2 * 2 < 0x2000000000000000) {
        uVar3 = uVar2 << 4;
      }
    }
  }
  __dest = rea_operator_new(uVar3);
  __src = (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
  lVar1 = (long)(this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish -
          (long)__src >> 3;
  pdVar4 = __dest + lVar1;
  if (pdVar4 != (pointer)0x0) {
    *pdVar4 = *in_RSI;
  }
  if (lVar1 != 0) {
    rea_memmove(__dest,__src,lVar1 * 8);
    __src = (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
  }
  if (__src != (pointer)0x0) {
    rea_operator_delete(__src);
  }
  (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start = __dest;
  (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish = pdVar4 + 1;
  (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_end_of_storage =
       (pointer)((long)__dest + uVar3);
  return;
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
// IDX 21  00105040  IndexedData_GIDKey__GroupBackwardItem__free
// ------------------------------------------------------------------
void rea_IndexedData_GIDKey__GroupBackwardItem__free(IndexedData_GIDKey__GroupBackwardItem * this_ptr)
{
  this_ptr->num_idxs = 0;
  this_ptr->num_items = 0;
  if (this_ptr->idxs != (Index *)0x0) {
    rea_operator_delete(this_ptr->idxs);
    this_ptr->idxs = (Index *)0x0;
  }
  if (this_ptr->items != (GroupBackwardItem *)0x0) {
    rea_operator_delete(this_ptr->items);
    this_ptr->items = (GroupBackwardItem *)0x0;
  }
  return;
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
// IDX 23  00105060  std___pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char______pair
// ------------------------------------------------------------------
void rea_std___pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char______pair(pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char__ * this_ptr, int __in_chrg)
{
  int *piVar1;
  char *pcVar2;
  undefined *puVar3;
  int iVar4;
  pointer pbVar5;
  pointer pbVar6;
  
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
  pcVar2 = (this_ptr->second)._M_dataplus._M_p;
  if ((allocator *)(pcVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar1 = (int *)(pcVar2 + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
      iVar4 = *(int *)(pcVar2 + -8);
      *(int *)(pcVar2 + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
    }
  }
  pbVar6 = (this_ptr->first).
           super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
           ._M_impl._M_finish;
  pbVar5 = (this_ptr->first).
           super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
           ._M_impl._M_start;
  if (pbVar6 != pbVar5) {
    do {
      pcVar2 = (pbVar5->_M_dataplus)._M_p;
      if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar3) {
        piVar1 = (int *)(pcVar2 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
          iVar4 = *(int *)(pcVar2 + -8);
          *(int *)(pcVar2 + -8) = iVar4 + -1;
        }
        else {
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar4 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
        }
      }
      pbVar5 = pbVar5 + 1;
    } while (pbVar6 != pbVar5);
    pbVar6 = (this_ptr->first).
             super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
             ._M_impl._M_start;
  }
  if (pbVar6 != (pointer)0x0) {
    rea_operator_delete(pbVar6);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 24  00105070  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_erase(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, _Link_type __x)
{
  _Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_ _Var1;
  _Link_type p_Var2;
  
  while (__x != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(__x->super__Rb_tree_node_base)._M_right);
    _Var1 = (__x->_M_value_field).second._M_t.
            super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_>;
    p_Var2 = (_Link_type)(__x->super__Rb_tree_node_base)._M_left;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)
                 0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long)_Var1 + 4) = 0;
      if (*(void **)((long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 8));
        *(undefined8 *)((long)_Var1 + 8) = 0;
      }
      if (*(void **)((long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 0x10));
        *(undefined8 *)((long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (__x->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_> =
         (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
    rea_operator_delete(__x);
    __x = p_Var2;
  }
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
// IDX 30  001050d0  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_insert__const_std__pair_std__basic_string_char__std__vector_double_____________
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_insert__const_std__pair_std__basic_string_char__std__vector_double(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * this_ptr, _Base_ptr __x, _Base_ptr __p, pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__ * __v)
{
  size_type *psVar1;
  pointer pdVar2;
  pointer pdVar3;
  char *__s1;
  int iVar4;
  _Rb_tree_node_base *p_Var5;
  _Base_ptr __dest;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  ulong __n;
  size_t __n_00;
  bool bVar9;
  ulong uVar10;
  
  bVar9 = true;
  if ((__x == (_Base_ptr)0x0) && (__p != &(this_ptr->_M_impl)._M_header)) {
    __s1 = (__v->first)._M_dataplus._M_p;
    uVar10 = *(ulong *)((long)*(void **)(__p + 1) + -0x18);
    uVar7 = *(ulong *)(__s1 + -0x18);
    __n = uVar7;
    if (uVar10 <= uVar7) {
      __n = uVar10;
    }
    iVar4 = rea_memcmp(__s1,*(void **)(__p + 1),__n);
    if (iVar4 == 0) {
      lVar8 = uVar7 - uVar10;
      bVar9 = false;
      if ((0x7fffffff < lVar8) || (bVar9 = true, lVar8 < -0x80000000)) goto LAB_0010e956;
      iVar4 = (int)lVar8;
    }
    bVar9 = SUB41((uint)iVar4 >> 0x1f,0);
  }
LAB_0010e956:
  p_Var5 = rea_operator_new(0x40);
  if (p_Var5 != (_Rb_tree_node_base *)0x0) {
    p_Var5->_M_color = _S_red;
    p_Var5->_M_parent = (_Base_ptr)0x0;
    p_Var5->_M_left = (_Base_ptr)0x0;
    p_Var5->_M_right = (_Base_ptr)0x0;
    rea_std__string__string(p_Var5 + 1,&__v->first);
    pdVar2 = (__v->second).super__Vector_base_double__std__allocator_double_._M_impl._M_finish;
    pdVar3 = (__v->second).super__Vector_base_double__std__allocator_double_._M_impl._M_start;
    uVar10 = 0;
    __dest = (_Base_ptr)0x0;
    p_Var5[1]._M_parent = (_Base_ptr)0x0;
    p_Var5[1]._M_left = (_Base_ptr)0x0;
    p_Var5[1]._M_right = (_Base_ptr)0x0;
    uVar7 = (long)pdVar2 - (long)pdVar3 >> 3;
    if (uVar7 != 0) {
      if (0x1fffffffffffffff < uVar7) {
        uVar6 = rea_std____throw_bad_alloc();
        rea_std__string___Rep___M_dispose((allocator *)(*(long *)(p_Var5 + 1) + -0x18));
        do {
          rea___cxa_begin_catch(uVar6);
          rea_operator_delete(p_Var5);
          uVar6 = rea___cxa_rethrow();
        } while( true );
      }
      uVar10 = uVar7 * 8;
      __dest = rea_operator_new(uVar10);
    }
    p_Var5[1]._M_parent = __dest;
    p_Var5[1]._M_left = __dest;
    p_Var5[1]._M_right = (_Base_ptr)((long)&__dest->_M_color + uVar10);
    pdVar2 = (__v->second).super__Vector_base_double__std__allocator_double_._M_impl._M_start;
    __n_00 = 0;
    lVar8 = (long)(__v->second).super__Vector_base_double__std__allocator_double_._M_impl.
                  _M_finish - (long)pdVar2 >> 3;
    if (lVar8 != 0) {
      __n_00 = lVar8 * 8;
      __dest = rea_memmove(__dest,pdVar2,__n_00);
    }
    p_Var5[1]._M_left = (_Base_ptr)((long)&__dest->_M_color + __n_00);
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar9,p_Var5,__p,&(this_ptr->_M_impl)._M_header);
  psVar1 = &(this_ptr->_M_impl)._M_node_count;
  *psVar1 = *psVar1 + 1;
  return (iterator)p_Var5;
}





// ------------------------------------------------------------------
// IDX 31  001050e0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____________
// ------------------------------------------------------------------
pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____bool rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr)
{
  _Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_ _Var1;
  _Link_type __z;
  _Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_ *in_RDX;
  int *in_RSI;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar2;
  pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____bool
  pVar3;
  pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____bool
  pVar4;
  
  __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->_M_value_field).first = *in_RSI;
    _Var1 = *in_RDX;
    *in_RDX = (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0
    ;
    (__z->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_> = _Var1;
  }
  pVar2 = _M_get_insert_unique_pos(this_ptr,&(__z->_M_value_field).first);
  pVar4.first._M_node = pVar2.first;
  if (pVar2.second == (_Base_ptr)0x0) {
    _Var1 = (__z->_M_value_field).second._M_t.
            super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_>;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)
                 0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long)_Var1 + 4) = 0;
      if (*(void **)((long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 8));
        *(undefined8 *)((long)_Var1 + 8) = 0;
      }
      if (*(void **)((long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 0x10));
        *(undefined8 *)((long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (__z->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_> =
         (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
    rea_operator_delete(__z);
    (*(undefined8 *)((uint8_t *)&pVar4 + 0x8)) = 0;
    return pVar4;
  }
  pVar3.first._M_node = _M_insert_node(this_ptr,pVar4.first._M_node,pVar2.second,__z);
  (*(undefined8 *)((uint8_t *)&pVar3 + 0x8)) = 1;
  return pVar3;
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
// IDX 34  00105110  _Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse
// ------------------------------------------------------------------
undefined8 rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse(vector_unsigned_char__std__allocator_unsigned_char_ * b, size_t p, map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * v)
{
  _Rb_tree_node_base *__p;
  pointer puVar1;
  undefined *puVar2;
  string sVar3;
  int iVar4;
  pointer puVar5;
  ulong uVar6;
  ulong *puVar7;
  string sVar8;
  _Link_type p_Var9;
  pointer puVar10;
  _Link_type p_Var11;
  long lVar12;
  pointer puVar13;
  pointer puVar14;
  _Link_type p_Var15;
  _Alloc_hider _Var16;
  pointer puVar17;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar18;
  ulong *puStack_108;
  allocator aaStack_9a [2];
  ulong *apuStack_98 [2];
  pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double pStack_88;
  string sStack_78;
  ulong *puStack_70;
  _Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__
  _Stack_68;
  
  puVar13 = (pointer)(p + 8);
  puVar5 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl._M_finish;
  puVar10 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl._M_start;
  _Stack_68._M_impl._M_header._M_color = _S_red;
  _Stack_68._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  _Stack_68._M_impl._M_header._M_left = &_Stack_68._M_impl._M_header;
  _Stack_68._M_impl._M_node_count = 0;
  _Stack_68._M_impl._M_header._M_right = _Stack_68._M_impl._M_header._M_left;
  if (puVar13 <= puVar5 + -(long)puVar10) {
    rea_memcpy(&sStack_78,puVar10 + p,8);
    sVar3._M_dataplus._M_p = sStack_78._M_dataplus._M_p;
    puVar2 = PTR__S_empty_rep_storage_00311ff0;
    if (sStack_78._M_dataplus._M_p != (char *)0x0) {
      puStack_108 = (ulong *)0x0;
      do {
        puVar14 = puVar13 + 8;
        _Var16._M_p = puVar2 + 0x18;
        pStack_88.second = 0.0;
        puStack_70 = (ulong *)0x0;
        pStack_88.first._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var16._M_p;
        sStack_78._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var16._M_p;
        puVar17 = puVar13;
        if (puVar5 + -(long)puVar10 < puVar14) {
LAB_0010ef10:
          sVar8._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)(puVar2 + 0x18);
        }
        else {
          rea_memcpy(apuStack_98,puVar13 + (long)puVar10,8);
          puVar1 = puVar14 + (long)apuStack_98[0];
          if (puVar5 + -(long)puVar10 < puVar1) goto LAB_0010ef10;
          puVar14 = puVar14 + (long)puVar10;
          puVar5 = puVar14 + (long)apuStack_98[0];
          if (puVar14 != puVar5) {
            uVar6 = (long)puVar5 - (long)puVar14;
            puVar7 = (ulong *)rea_std__string___Rep___S_create(uVar6,0,aaStack_9a);
            _Var16._M_p = (char *)(puVar7 + 3);
            lVar12 = 0;
            do {
              *(uchar *)((long)_Var16._M_p + lVar12) = puVar14[lVar12];
              lVar12 = lVar12 + 1;
            } while (lVar12 != (long)puVar5 - (long)puVar14);
            if (puVar7 != (ulong *)puVar2) {
              *(undefined4 *)(puVar7 + 2) = 0;
              *puVar7 = uVar6;
              *(undefined1 *)((long)puVar7 + uVar6 + 0x18) = 0;
            }
          }
          apuStack_98[0] = (ulong *)_Var16._M_p;
          rea_std__string__assign(&sStack_78);
          if ((allocator *)(apuStack_98[0] + -3) != (allocator *)puVar2) {
            puVar7 = apuStack_98[0] + -1;
            if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
              iVar4 = (int)apuStack_98[0][-1];
              *(int *)(apuStack_98[0] + -1) = iVar4 + -1;
            }
            else {
              LOCK();
              iVar4 = (int)*puVar7;
              *(int *)puVar7 = (int)*puVar7 + -1;
              UNLOCK();
            }
            if (iVar4 < 1) {
              rea_std__string___Rep___M_destroy((allocator *)(apuStack_98[0] + -3));
            }
          }
          sVar8._M_dataplus._M_p = sStack_78._M_dataplus._M_p;
          if (puVar13 != puVar1) {
            puVar5 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                     _M_start;
            if (puVar1 + 8 <=
                (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                _M_finish + -(long)puVar5) {
              rea_memcpy(apuStack_98,puVar1 + (long)puVar5,8);
              puStack_70 = apuStack_98[0];
              rea_std__string__assign(&pStack_88.first);
              pStack_88.second = (double)puStack_70;
              sVar8._M_dataplus._M_p = sStack_78._M_dataplus._M_p;
              puVar17 = puVar1 + 8;
            }
          }
        }
        if ((allocator *)((long)sVar8._M_dataplus._M_p + -0x18) != (allocator *)puVar2) {
          puVar7 = (ulong *)((long)sVar8._M_dataplus._M_p + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
            iVar4 = (int)*(ulong *)((long)sVar8._M_dataplus._M_p + -8);
            *(int *)((long)sVar8._M_dataplus._M_p + -8) = iVar4 + -1;
          }
          else {
            LOCK();
            iVar4 = (int)*puVar7;
            *(int *)puVar7 = (int)*puVar7 + -1;
            UNLOCK();
          }
          if (iVar4 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)((long)sVar8._M_dataplus._M_p + -0x18));
          }
        }
        if (puVar13 == puVar17) {
          p_Var15 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
          if ((allocator *)((long)pStack_88.first._M_dataplus._M_p + -0x18) != (allocator *)puVar2)
          {
            puVar7 = (ulong *)((long)pStack_88.first._M_dataplus._M_p + -8);
            if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
              iVar4 = *(int *)((long)pStack_88.first._M_dataplus._M_p + -8);
              *(int *)((long)pStack_88.first._M_dataplus._M_p + -8) = iVar4 + -1;
            }
            else {
              LOCK();
              iVar4 = *(int *)puVar7;
              *(int *)puVar7 = *(int *)puVar7 + -1;
              UNLOCK();
            }
            if (iVar4 < 1) {
              std__string___Rep___M_destroy_________________________((allocator *)((long)pStack_88.first._M_dataplus._M_p + -0x18));
              p_Var15 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
            }
          }
          goto LAB_0010efd9;
        }
        pVar18 = std_____________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_______________________M_get_insert_unique_pos(&_Stack_68,&pStack_88.first);
        if (pVar18.second != (_Base_ptr)0x0) {
          std______________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double________________M_insert__const_std__pair_std__basic_string_char__double______________________(&_Stack_68,pVar18.first,pVar18.second,&pStack_88);
        }
        if ((allocator *)((long)pStack_88.first._M_dataplus._M_p + -0x18) != (allocator *)puVar2) {
          puVar7 = (ulong *)((long)pStack_88.first._M_dataplus._M_p + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
            iVar4 = *(int *)((long)pStack_88.first._M_dataplus._M_p + -8);
            *(int *)((long)pStack_88.first._M_dataplus._M_p + -8) = iVar4 + -1;
          }
          else {
            LOCK();
            iVar4 = *(int *)puVar7;
            *(int *)puVar7 = *(int *)puVar7 + -1;
            UNLOCK();
          }
          if (iVar4 < 1) {
            std__string___Rep___M_destroy_______________________((allocator *)((long)pStack_88.first._M_dataplus._M_p + -0x18));
          }
        }
        puStack_108 = (ulong *)((long)puStack_108 + 1);
        puVar13 = puVar17;
        if ((_Alloc_hider)puStack_108 == sVar3._M_dataplus._M_p) break;
        puVar10 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                  _M_start;
        puVar5 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                 _M_finish;
      } while( true );
    }
    p = (size_t)puVar13;
    p_Var15 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
    if (v == (map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__
              *)0x0) goto LAB_0010efd9;
    std________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__________M_erase(&v->_M_t,(_Link_type)(v->_M_t)._M_impl._M_header._M_parent);
    __p = &(v->_M_t)._M_impl._M_header;
    (v->_M_t)._M_impl._M_header._M_parent = (_Base_ptr)0x0;
    (v->_M_t)._M_impl._M_node_count = 0;
    (v->_M_t)._M_impl._M_header._M_left = __p;
    (v->_M_t)._M_impl._M_header._M_right = __p;
    if ((_Const_Link_type)_Stack_68._M_impl._M_header._M_parent != (_Const_Link_type)0x0) {
      p_Var9 = std___________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_____________________M_copy(&v->_M_t,(_Const_Link_type)_Stack_68._M_impl._M_header._M_parent,
                         (_Link_type)__p);
      (v->_M_t)._M_impl._M_header._M_parent = &p_Var9->super__Rb_tree_node_base;
      p_Var15 = p_Var9;
      do {
        p_Var11 = p_Var15;
        p_Var15 = (_Link_type)(p_Var11->super__Rb_tree_node_base)._M_left;
      } while (p_Var15 != (_Link_type)0x0);
      (v->_M_t)._M_impl._M_header._M_left = &p_Var11->super__Rb_tree_node_base;
      do {
        p_Var15 = p_Var9;
        p_Var9 = (_Link_type)(p_Var15->super__Rb_tree_node_base)._M_right;
      } while (p_Var9 != (_Link_type)0x0);
      (v->_M_t)._M_impl._M_header._M_right = &p_Var15->super__Rb_tree_node_base;
      (v->_M_t)._M_impl._M_node_count = _Stack_68._M_impl._M_node_count;
      p_Var15 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
      goto LAB_0010efd9;
    }
  }
  p_Var15 = (_Link_type)0x0;
LAB_0010efd9:
  std______Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double________M_erase(&_Stack_68,p_Var15);
  return (size_t)(pointer)p;
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
// IDX 36  00105130  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_insert_node
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_insert_node(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, _Base_ptr __x, _Base_ptr __p, _Link_type __z)
{
  _Rb_tree_node_base *p_Var1;
  size_type *psVar2;
  bool bVar3;
  
  p_Var1 = &(this_ptr->_M_impl)._M_header;
  if ((__x == (_Base_ptr)0x0) && (p_Var1 != __p)) {
    bVar3 = (__z->_M_value_field).first < (int)__p[1]._M_color;
  }
  else {
    bVar3 = true;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar3,&__z->super__Rb_tree_node_base,__p,p_Var1);
  psVar2 = &(this_ptr->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)&__z->super__Rb_tree_node_base;
}





// ------------------------------------------------------------------
// IDX 37  00105140  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_unique_pos(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, key_type * __k)
{
  _Rb_tree_node_base *p_Var1;
  int iVar2;
  _Rb_tree_color _Var3;
  _Rb_tree_node_base *p_Var4;
  _Rb_tree_node_base *p_Var5;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar6;
  
  p_Var1 = (this_ptr->_M_impl)._M_header._M_parent;
  if (p_Var1 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = &(this_ptr->_M_impl)._M_header;
LAB_0010d5d0:
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
    if ((this_ptr->_M_impl)._M_header._M_left == p_Var5) goto LAB_0010d5bf;
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var5);
    iVar2 = *__k;
    _Var3 = p_Var1[1]._M_color;
  }
  else {
    iVar2 = *__k;
    do {
      p_Var5 = p_Var1;
      _Var3 = p_Var5[1]._M_color;
      if (iVar2 < (int)_Var3) {
        p_Var1 = p_Var5->_M_left;
      }
      else {
        p_Var1 = p_Var5->_M_right;
      }
    } while (p_Var1 != (_Base_ptr)0x0);
    p_Var1 = p_Var5;
    if (iVar2 < (int)_Var3) goto LAB_0010d5d0;
  }
  p_Var4 = (_Rb_tree_node_base *)0x0;
  if ((int)_Var3 < iVar2) {
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
  }
LAB_0010d5bf:
  pVar6.second = p_Var4;
  pVar6.first = p_Var1;
  return pVar6;
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
// IDX 40  00105170  SecInfo__find_group_data1
// ------------------------------------------------------------------
GroupData1 * rea_SecInfo__find_group_data1(SecInfo * this_ptr, int date)
{
  _Base_ptr *pp_Var1;
  int *piVar2;
  _Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_ this_00;
  undefined *this_01;
  undefined *puVar3;
  string sVar4;
  _Base_ptr p_Var5;
  int iVar6;
  iterator iVar7;
  _Link_type __z;
  long *plVar8;
  FILE *__stream;
  size_t sVar9;
  _Alloc_hider _Var10;
  void *pvVar11;
  _Base_ptr p_Var12;
  ulong uVar13;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar14;
  uint auStack_7c [5];
  long alStack_68 [2];
  long alStack_58 [2];
  string asStack_48 [3];
  
  this_01 = PTR_group_data_store1_00311fc0;
  auStack_7c[0] = date;
  iVar7 = std______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________find((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____
                  *)PTR_group_data_store1_00311fc0,(int *)auStack_7c);
  if (iVar7._M_node == (_Base_ptr)(this_01 + 8)) {
    rea___gnu_cxx____to_xstring_std__basic_string_char__char
              ((code *)
               alStack_68,(size_t)PTR_vsnprintf_00311fd0,(char *)0x10,(void *)&DAT_0010fc03,
               (ulong)auStack_7c[0]);
    plVar8 = (long *)rea_std__string__insert((ulong)alStack_68,(char *)0x0,0x10fc13);
    puVar3 = PTR__S_empty_rep_storage_00311ff0;
    alStack_58[0] = *plVar8;
    *plVar8 = (long)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    plVar8 = (long *)rea_std__string__append((char *)alStack_58,0x10fbfd);
    asStack_48[0]._M_dataplus._M_p = (_Alloc_hider)*plVar8;
    *plVar8 = (long)(puVar3 + 0x18);
    __stream = rea_open_file(asStack_48);
    if ((allocator *)((long)asStack_48[0]._M_dataplus._M_p + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)((long)asStack_48[0]._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar6 = *(int *)((long)asStack_48[0]._M_dataplus._M_p + -8);
        *(int *)((long)asStack_48[0]._M_dataplus._M_p + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long)asStack_48[0]._M_dataplus._M_p + -0x18));
      }
    }
    if ((allocator *)(alStack_58[0] + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)(alStack_58[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar6 = *(int *)(alStack_58[0] + -8);
        *(int *)(alStack_58[0] + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(alStack_58[0] + -0x18));
      }
    }
    if ((allocator *)(alStack_68[0] + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)(alStack_68[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar6 = *(int *)(alStack_68[0] + -8);
        *(int *)(alStack_68[0] + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(alStack_68[0] + -0x18));
      }
    }
    if (((__stream == (FILE *)0x0) || (sVar9 = rea_fread(alStack_58,4,1,(FILE *)__stream), sVar9 != 1))
       || ((int)alStack_58[0] != 0)) {
      return (GroupData1 *)0x0;
    }
    _Var10._M_p = rea_operator_new(0x18);
    _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)(_Var10._M_p + 4) < 0xaa0000000000001) {
        uVar13 = (long)*(int *)(_Var10._M_p + 4) * 0xc;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long)*(int *)_Var10._M_p) ||
         (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),0xc,(long)*(int *)(_Var10._M_p + 4),
                        (FILE *)__stream), sVar9 != (long)*(int *)(_Var10._M_p + 4)))
      goto LAB_00108410;
    }
    else {
LAB_00108410:
      _Var10._M_p[0] = '\0';
      _Var10._M_p[1] = '\0';
      _Var10._M_p[2] = '\0';
      _Var10._M_p[3] = '\0';
      *(int *)(_Var10._M_p + 4) = 0;
      if (*(void **)(_Var10._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 8));
        *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    asStack_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____
                *)this_01);
    sVar4._M_dataplus._M_p = asStack_48[0]._M_dataplus._M_p;
    if (asStack_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)asStack_48[0]._M_dataplus._M_p = 0;
      *(int *)((long)asStack_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long)asStack_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)asStack_48[0]._M_dataplus._M_p + 8));
        ((int *)((long)sVar4._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long)sVar4._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long)sVar4._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)sVar4._M_dataplus._M_p + 0x10));
        ((int *)((long)sVar4._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long)sVar4._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar4._M_dataplus._M_p);
    }
    _Var10._M_p = rea_operator_new(0x18);
    _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)(_Var10._M_p + 4) < 0x3f80000000000001) {
        uVar13 = (long)*(int *)(_Var10._M_p + 4) * 2;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long)*(int *)_Var10._M_p) ||
         (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),2,(long)*(int *)(_Var10._M_p + 4),
                        (FILE *)__stream), sVar9 != (long)*(int *)(_Var10._M_p + 4)))
      goto LAB_00108500;
    }
    else {
LAB_00108500:
      _Var10._M_p[0] = '\0';
      _Var10._M_p[1] = '\0';
      _Var10._M_p[2] = '\0';
      _Var10._M_p[3] = '\0';
      *(int *)(_Var10._M_p + 4) = 0;
      if (*(void **)(_Var10._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 8));
        *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    asStack_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____
                *)PTR_group_data_store2_00311ff8);
    sVar4._M_dataplus._M_p = asStack_48[0]._M_dataplus._M_p;
    if (asStack_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)asStack_48[0]._M_dataplus._M_p = 0;
      *(int *)((long)asStack_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long)asStack_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)asStack_48[0]._M_dataplus._M_p + 8));
        ((int *)((long)sVar4._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long)sVar4._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long)sVar4._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)sVar4._M_dataplus._M_p + 0x10));
        ((int *)((long)sVar4._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long)sVar4._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar4._M_dataplus._M_p);
    }
    rea_fclose((FILE *)__stream);
  }
  if (*(_Base_ptr *)(this_01 + 0x10) == (_Base_ptr)0x0) {
    iVar7._M_node = (_Base_ptr)(this_01 + 8);
  }
  else {
    p_Var5 = *(_Base_ptr *)(this_01 + 0x10);
    p_Var12 = (_Base_ptr)(this_01 + 8);
    do {
      while (iVar7._M_node = p_Var5, (int)iVar7._M_node[1]._M_color < (int)auStack_7c[0]) {
        pp_Var1 = &(iVar7._M_node)->_M_right;
        p_Var5 = *pp_Var1;
        iVar7._M_node = p_Var12;
        if (*pp_Var1 == (_Base_ptr)0x0) goto LAB_0010822a;
      }
      p_Var5 = (iVar7._M_node)->_M_left;
      p_Var12 = iVar7._M_node;
    } while ((iVar7._M_node)->_M_left != (_Base_ptr)0x0);
LAB_0010822a:
    if ((iVar7._M_node != (_Base_ptr)(this_01 + 8)) &&
       ((int)iVar7._M_node[1]._M_color <= (int)auStack_7c[0])) goto LAB_00108238;
  }
  __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_> =
         (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
    (__z->_M_value_field).first = auStack_7c[0];
  }
  pVar14 = std_______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1___________________M_get_insert_hint_unique_pos______________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____
                       *)this_01,(const_iterator)iVar7._M_node,&(__z->_M_value_field).first);
  iVar7._M_node = pVar14.first;
  if (pVar14.second == (_Base_ptr)0x0) {
    this_00 = (__z->_M_value_field).second._M_t.
              super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_>
    ;
    if (this_00 !=
        (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0) {
      IndexedData_GroupKey__GroupForwardItem__free_________________((IndexedData_GroupKey__GroupForwardItem *)this_00);
      rea_operator_delete((void *)this_00);
    }
    (__z->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_> =
         (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
    rea_operator_delete(__z);
  }
  else {
    iVar7 = std________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____________________M_insert_node((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____
                              *)this_01,iVar7._M_node,pVar14.second,__z);
  }
LAB_00108238:
  return (GroupData1 *)iVar7._M_node[1]._M_parent;
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
// IDX 46  001051d0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_insert_node
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_insert_node(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, _Base_ptr __x, _Base_ptr __p, _Link_type __z)
{
  _Rb_tree_node_base *p_Var1;
  size_type *psVar2;
  bool bVar3;
  
  p_Var1 = &(this_ptr->_M_impl)._M_header;
  if ((__x == (_Base_ptr)0x0) && (p_Var1 != __p)) {
    bVar3 = (__z->_M_value_field).first < (int)__p[1]._M_color;
  }
  else {
    bVar3 = true;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar3,&__z->super__Rb_tree_node_base,__p,p_Var1);
  psVar2 = &(this_ptr->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)&__z->super__Rb_tree_node_base;
}





// ------------------------------------------------------------------
// IDX 47  001051e0  SecInfo__getLastClosePrice
// ------------------------------------------------------------------
double rea_SecInfo__getLastClosePrice(SecInfo * this_ptr, string * gid, int date)
{
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  long lVar4;
  int iVar5;
  size_t __n;
  long lVar6;
  int *piVar7;
  char *pcVar8;
  long lVar9;
  double dVar10;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  
  dVar10 = rea_getPreClosePrice(this_ptr,gid,date);
  if ((NAN(dVar10)) &&
     (piVar7 = *(int **)PTR_data_00311fc8, dVar10 = DAT_0010fd10,
     *(ulong *)((gid->_M_dataplus)._M_p + -0x18) < 0x10)) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar8 = (gid->_M_dataplus)._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar8 + -0x18);
    }
    rea_memcpy(&uStack_68,pcVar8,__n);
    lVar6 = (long)*piVar7;
    *(undefined1 *)((long)&uStack_68 + __n) = 0;
    pcVar8 = *(char **)(piVar7 + 2);
    uStack_48 = 0;
    uStack_58 = uStack_68;
    uStack_50 = uStack_60;
    pcVar1 = pcVar8 + lVar6 * 0x18;
    for (; 0 < lVar6; lVar6 = (lVar6 - lVar9) + -1) {
      while( true ) {
        lVar9 = lVar6 >> 1;
        iVar5 = rea_strcmp(pcVar8 + lVar9 * 0x18,(char *)&uStack_58);
        if (iVar5 < 0) break;
        lVar6 = lVar9;
        if (lVar9 == 0) goto LAB_00105ec0;
      }
      pcVar8 = pcVar8 + lVar9 * 0x18 + 0x18;
    }
LAB_00105ec0:
    dVar10 = DAT_0010fd10;
    if (((pcVar1 != pcVar8) &&
        (iVar5 = rea_strcmp(pcVar8,(char *)&uStack_58), dVar10 = DAT_0010fd10, iVar5 == 0)) &&
       (pcVar8 != (char *)0x0)) {
      piVar2 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      (long)*(int *)(pcVar8 + 0x10) * 0x18);
      piVar7 = piVar2;
      for (lVar6 = ((*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                    ((long)*(int *)(pcVar8 + 0x10) + (long)*(int *)(pcVar8 + 0x14)) * 0x18) -
                    (long)piVar2 >> 3) * -0x5555555555555555; 0 < lVar6;
          lVar6 = (lVar6 - lVar4) + -1) {
        piVar3 = piVar7 + (lVar6 >> 1) * 6;
        iVar5 = *piVar3;
        lVar9 = lVar6 >> 1;
        while (lVar4 = lVar9, date <= iVar5) {
          if (lVar4 == 0) goto LAB_00105f62;
          piVar3 = piVar7 + (lVar4 >> 1) * 6;
          lVar9 = lVar4 >> 1;
          lVar6 = lVar4;
          iVar5 = *piVar3;
        }
        piVar7 = piVar3 + 6;
      }
LAB_00105f62:
      if ((piVar7 != piVar2) && (piVar7 != (int *)0x18)) {
        dVar10 = *(double *)(piVar7 + -2);
      }
    }
  }
  return dVar10;
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
// IDX 49  00105200  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_erase(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, _Link_type __x)
{
  int *piVar1;
  char *pcVar2;
  _Link_type p_Var3;
  undefined *puVar4;
  int iVar5;
  
  puVar4 = PTR__S_empty_rep_storage_00311ff0;
  while (__x != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(__x->super__Rb_tree_node_base)._M_right);
    pcVar2 = (__x->_M_value_field).first._M_dataplus._M_p;
    p_Var3 = (_Link_type)(__x->super__Rb_tree_node_base)._M_left;
    if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar4) {
      piVar1 = (int *)(pcVar2 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar5 = *(int *)(pcVar2 + -8);
        *(int *)(pcVar2 + -8) = iVar5 + -1;
      }
      else {
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar5 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
      }
    }
    rea_operator_delete(__x);
    __x = p_Var3;
  }
  return;
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
// IDX 51  00105220  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_unique_pos(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, key_type * __k)
{
  _Rb_tree_node_base *p_Var1;
  int iVar2;
  _Rb_tree_color _Var3;
  _Rb_tree_node_base *p_Var4;
  _Rb_tree_node_base *p_Var5;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar6;
  
  p_Var1 = (this_ptr->_M_impl)._M_header._M_parent;
  if (p_Var1 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = &(this_ptr->_M_impl)._M_header;
LAB_0010d3f0:
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
    if ((this_ptr->_M_impl)._M_header._M_left == p_Var5) goto LAB_0010d3df;
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var5);
    iVar2 = *__k;
    _Var3 = p_Var1[1]._M_color;
  }
  else {
    iVar2 = *__k;
    do {
      p_Var5 = p_Var1;
      _Var3 = p_Var5[1]._M_color;
      if (iVar2 < (int)_Var3) {
        p_Var1 = p_Var5->_M_left;
      }
      else {
        p_Var1 = p_Var5->_M_right;
      }
    } while (p_Var1 != (_Base_ptr)0x0);
    p_Var1 = p_Var5;
    if (iVar2 < (int)_Var3) goto LAB_0010d3f0;
  }
  p_Var4 = (_Rb_tree_node_base *)0x0;
  if ((int)_Var3 < iVar2) {
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
  }
LAB_0010d3df:
  pVar6.second = p_Var4;
  pVar6.first = p_Var1;
  return pVar6;
}





// ------------------------------------------------------------------
// IDX 52  00105230  SecInfo__getClosePrice
// ------------------------------------------------------------------
double rea_SecInfo__getClosePrice(SecInfo * this_ptr, string * gid, int date)
{
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  long lVar5;
  int iVar6;
  size_t __n;
  long lVar7;
  int *piVar8;
  long lVar9;
  undefined1 auStack_68 [16];
  char acStack_58 [16];
  undefined8 uStack_48;
  
  piVar8 = *(int **)PTR_data_00311fc8;
  if (*(ulong *)((gid->_M_dataplus)._M_p + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar4 = (gid->_M_dataplus)._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar4 + -0x18);
    }
    rea_memcpy(auStack_68,pcVar4,__n);
    lVar7 = (long)*piVar8;
    auStack_68[__n] = 0;
    pcVar4 = *(char **)(piVar8 + 2);
    uStack_48 = 0;
    pcVar1 = pcVar4 + lVar7 * 0x18;
    for (; 0 < lVar7; lVar7 = (lVar7 - lVar9) + -1) {
      while( true ) {
        lVar9 = lVar7 >> 1;
        iVar6 = rea_strcmp(pcVar4 + lVar9 * 0x18,acStack_58);
        if (iVar6 < 0) break;
        lVar7 = lVar9;
        if (lVar9 == 0) goto LAB_001060ab;
      }
      pcVar4 = pcVar4 + lVar9 * 0x18 + 0x18;
    }
LAB_001060ab:
    if (((pcVar1 != pcVar4) && (iVar6 = rea_strcmp(pcVar4,acStack_58), iVar6 == 0)) &&
       (pcVar4 != (char *)0x0)) {
      piVar8 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      (long)*(int *)(pcVar4 + 0x10) * 0x18);
      piVar2 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      ((long)*(int *)(pcVar4 + 0x10) + (long)*(int *)(pcVar4 + 0x14)) * 0x18);
      for (lVar7 = ((long)piVar2 - (long)piVar8 >> 3) * -0x5555555555555555; 0 < lVar7;
          lVar7 = (lVar7 - lVar5) + -1) {
        piVar3 = piVar8 + (lVar7 >> 1) * 6;
        iVar6 = *piVar3;
        lVar9 = lVar7 >> 1;
        while (lVar5 = lVar9, date <= iVar6) {
          if (lVar5 == 0) goto LAB_0010614a;
          piVar3 = piVar8 + (lVar5 >> 1) * 6;
          lVar9 = lVar5 >> 1;
          lVar7 = lVar5;
          iVar6 = *piVar3;
        }
        piVar8 = piVar3 + 6;
      }
LAB_0010614a:
      if ((piVar8 != piVar2) && (date == *piVar8)) {
        return *(double *)(piVar8 + 4);
      }
    }
  }
  return DAT_0010fd10;
}





// ------------------------------------------------------------------
// IDX 53  00105240  SecInfo__getPreDate
// ------------------------------------------------------------------
int rea_SecInfo__getPreDate(SecInfo * this_ptr, string * gid, int date)
{
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  long lVar7;
  int iVar8;
  size_t __n;
  long lVar9;
  int *piVar10;
  long lVar11;
  undefined8 auStack_68 [2];
  char acStack_58 [16];
  undefined8 uStack_48;
  
  piVar10 = *(int **)PTR_data_00311fc8;
  iVar8 = 0;
  if (*(ulong *)((gid->_M_dataplus)._M_p + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar6 = (gid->_M_dataplus)._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar6 + -0x18);
    }
    rea_memcpy(auStack_68,pcVar6,__n);
    lVar9 = (long)*piVar10;
    *(undefined1 *)((long)auStack_68 + __n) = 0;
    pcVar6 = *(char **)(piVar10 + 2);
    uStack_48 = 0;
    pcVar1 = pcVar6 + lVar9 * 0x18;
    for (; 0 < lVar9; lVar9 = (lVar9 - lVar11) + -1) {
      while( true ) {
        lVar11 = lVar9 >> 1;
        iVar8 = rea_strcmp(pcVar6 + lVar11 * 0x18,acStack_58);
        if (iVar8 < 0) break;
        lVar9 = lVar11;
        if (lVar11 == 0) goto LAB_001062ab;
      }
      pcVar6 = pcVar6 + lVar11 * 0x18 + 0x18;
    }
LAB_001062ab:
    if ((pcVar1 == pcVar6) || (iVar8 = rea_strcmp(pcVar6,acStack_58), iVar8 != 0)) {
      return 0;
    }
    iVar8 = 0;
    if (pcVar6 != (char *)0x0) {
      piVar2 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      (long)*(int *)(pcVar6 + 0x10) * 0x18);
      piVar3 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      ((long)*(int *)(pcVar6 + 0x10) + (long)*(int *)(pcVar6 + 0x14)) * 0x18);
      piVar10 = piVar2;
      for (lVar9 = ((long)piVar3 - (long)piVar2 >> 3) * -0x5555555555555555; 0 < lVar9;
          lVar9 = (lVar9 - lVar7) + -1) {
        piVar4 = piVar10 + (lVar9 >> 1) * 6;
        iVar5 = *piVar4;
        lVar11 = lVar9 >> 1;
        while (lVar7 = lVar11, date <= iVar5) {
          if (lVar7 == 0) goto LAB_00106352;
          piVar4 = piVar10 + (lVar7 >> 1) * 6;
          lVar11 = lVar7 >> 1;
          lVar9 = lVar7;
          iVar5 = *piVar4;
        }
        piVar10 = piVar4 + 6;
      }
LAB_00106352:
      if (((piVar10 != piVar3) && (date == *piVar10)) && (piVar2 <= piVar10 + -6)) {
        iVar8 = piVar10[-6];
      }
    }
  }
  return iVar8;
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
// IDX 55  00105260  std__vector_double__std__allocator_double___operator_assign___________
// ------------------------------------------------------------------
vector_double__std__allocator_double_ * rea_std__vector_double__std__allocator_double___operator__assign(vector_double__std__allocator_double_ * this_ptr, vector_double__std__allocator_double_ * __x)
{
  _Rb_tree_color _Var1;
  _Const_Link_type p_Var2;
  double dVar3;
  double dVar4;
  ulong uVar5;
  pointer pdVar6;
  _Link_type __p;
  _Link_type p_Var7;
  _Link_type p_Var8;
  pointer pdVar9;
  pointer pdVar10;
  undefined8 uVar11;
  long lVar12;
  _Base_ptr extraout_RDX;
  ulong uVar13;
  pointer __src;
  _Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
  *this_00;
  size_t sVar14;
  
  if (__x == this_ptr) {
    return this_ptr;
  }
  pdVar6 = (__x->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish;
  pdVar9 = (__x->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
  this_00 = (_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
             *)(this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
  uVar13 = (long)pdVar6 - (long)pdVar9 >> 3;
  if (uVar13 <= (ulong)((long)(this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl.
                              _M_end_of_storage - (long)this_00 >> 3)) {
    pdVar10 = (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish;
    uVar5 = (long)pdVar10 - (long)this_00 >> 3;
    if (uVar5 < uVar13) {
      __src = pdVar9 + uVar5;
      if (uVar5 == 0) {
        lVar12 = (long)pdVar6 - (long)__src;
        this_00 = (_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
                   *)((long)&this_00->_M_impl + uVar13 * 8);
      }
      else {
        rea_memmove(this_00,pdVar9,uVar5 * 8);
        pdVar10 = (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish;
        pdVar6 = (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
        this_00 = (_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
                   *)(pdVar6 + uVar13);
        __src = (pointer)(((long)pdVar10 - (long)pdVar6 & 0xfffffffffffffff8U) +
                         (long)(__x->super__Vector_base_double__std__allocator_double_)._M_impl.
                               _M_start);
        lVar12 = (long)(__x->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish
                 - (long)__src;
      }
      if (lVar12 >> 3 != 0) {
        rea_memmove(pdVar10,__src,(lVar12 >> 3) * 8);
        (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish =
             (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start + uVar13;
        return this_ptr;
      }
    }
    else if (uVar13 != 0) {
      rea_memmove(this_00,pdVar9,uVar13 * 8);
      (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish =
           (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start + uVar13;
      return this_ptr;
    }
    (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish = (pointer)this_00
    ;
    return this_ptr;
  }
  if (uVar13 == 0) {
    uVar5 = 0;
    pdVar6 = (pointer)0x0;
  }
  else {
    if (0x1fffffffffffffff < uVar13) {
      rea_std____throw_bad_alloc();
      __p = rea_operator_new(0x40);
      if (__p != (_Link_type)0x0) {
        (__p->super__Rb_tree_node_base)._M_color = _S_red;
        (__p->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
        (__p->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
        (__p->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
        rea_std__string__string(&__p->_M_value_field,
                            (string *)
                            &__x[1].super__Vector_base_double__std__allocator_double_._M_impl.
                             _M_finish);
        pdVar6 = __x[2].super__Vector_base_double__std__allocator_double_._M_impl._M_start;
        pdVar9 = __x[1].super__Vector_base_double__std__allocator_double_._M_impl.
                 _M_end_of_storage;
        uVar13 = 0;
        pdVar10 = (pointer)0x0;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_start = (pointer)0x0;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_finish = (pointer)0x0;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_end_of_storage = (pointer)0x0;
        uVar5 = (long)pdVar6 - (long)pdVar9 >> 3;
        if (uVar5 != 0) {
          if (0x1fffffffffffffff < uVar5) {
            p_Var8 = (_Link_type)rea_std____throw_bad_alloc();
            std__string___Rep___M_dispose_______________________((allocator *)((__p->_M_value_field).first._M_dataplus._M_p + -0x18));
            p_Var7 = p_Var8;
            goto LAB_0010e6ea;
          }
          uVar13 = uVar5 * 8;
          pdVar10 = rea_operator_new(uVar13);
        }
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_start = pdVar10;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_finish = pdVar10;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_end_of_storage = (pointer)(uVar13 + (long)pdVar10);
        pdVar6 = __x[1].super__Vector_base_double__std__allocator_double_._M_impl.
                 _M_end_of_storage;
        sVar14 = 0;
        lVar12 = (long)__x[2].super__Vector_base_double__std__allocator_double_._M_impl._M_start -
                 (long)pdVar6 >> 3;
        if (lVar12 != 0) {
          sVar14 = lVar12 * 8;
          pdVar10 = rea_memmove(pdVar10,pdVar6,sVar14);
        }
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_finish = (pointer)((long)pdVar10 + sVar14);
      }
      _Var1 = *(_Rb_tree_color *)
               &(__x->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
      (__p->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
      p_Var2 = (_Const_Link_type)
               __x[1].super__Vector_base_double__std__allocator_double_._M_impl._M_start;
      (__p->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
      (__p->super__Rb_tree_node_base)._M_parent = extraout_RDX;
      (__p->super__Rb_tree_node_base)._M_color = _Var1;
      if (p_Var2 != (_Const_Link_type)0x0) {
        p_Var7 = _Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_________________________M_copy(this_00,p_Var2,__p);
        (__p->super__Rb_tree_node_base)._M_right = &p_Var7->super__Rb_tree_node_base;
      }
      pdVar6 = (__x->super__Vector_base_double__std__allocator_double_)._M_impl._M_end_of_storage;
      p_Var8 = __p;
      do {
        if (pdVar6 == (pointer)0x0) {
          return (vector_double__std__allocator_double_ *)__p;
        }
        p_Var7 = rea_operator_new(0x40);
        if (p_Var7 != (_Link_type)0x0) {
          (p_Var7->super__Rb_tree_node_base)._M_color = _S_red;
          (p_Var7->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
          (p_Var7->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
          (p_Var7->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
          rea_std__string__string(&p_Var7->_M_value_field,(string *)(pdVar6 + 4));
          dVar3 = pdVar6[6];
          dVar4 = pdVar6[5];
          uVar13 = 0;
          pdVar9 = (pointer)0x0;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
          _M_impl._M_start = (pointer)0x0;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
          _M_impl._M_finish = (pointer)0x0;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
          _M_impl._M_end_of_storage = (pointer)0x0;
          uVar5 = (long)dVar3 - (long)dVar4 >> 3;
          if (uVar5 != 0) {
            if (0x1fffffffffffffff < uVar5) {
              uVar11 = rea_std____throw_bad_alloc();
              do {
                std__string___Rep___M_dispose___________________________((allocator *)((p_Var7->_M_value_field).first._M_dataplus._M_p + -0x18));
                rea___cxa_begin_catch(uVar11);
                rea_operator_delete(p_Var7);
                p_Var8 = (_Link_type)rea___cxa_rethrow();
LAB_0010e6ea:
                rea___cxa_begin_catch(p_Var8);
                rea_operator_delete(__p);
                uVar11 = rea___cxa_rethrow();
              } while( true );
            }
            uVar13 = uVar5 * 8;
            pdVar9 = rea_operator_new(uVar13);
          }
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
          _M_impl._M_start = pdVar9;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
          _M_impl._M_finish = pdVar9;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
          _M_impl._M_end_of_storage = (pointer)(uVar13 + (long)pdVar9);
          sVar14 = 0;
          lVar12 = (long)pdVar6[6] - (long)pdVar6[5] >> 3;
          if (lVar12 != 0) {
            sVar14 = lVar12 * 8;
            pdVar9 = rea_memmove(pdVar9,(void *)pdVar6[5],sVar14);
          }
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
          _M_impl._M_finish = (pointer)((long)pdVar9 + sVar14);
        }
        _Var1 = *(_Rb_tree_color *)pdVar6;
        (p_Var7->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
        p_Var2 = (_Const_Link_type)pdVar6[3];
        (p_Var7->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
        (p_Var7->super__Rb_tree_node_base)._M_color = _Var1;
        (p_Var8->super__Rb_tree_node_base)._M_left = &p_Var7->super__Rb_tree_node_base;
        (p_Var7->super__Rb_tree_node_base)._M_parent = &p_Var8->super__Rb_tree_node_base;
        if (p_Var2 != (_Const_Link_type)0x0) {
          p_Var8 = _Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___________________________M_copy(this_00,p_Var2,p_Var7);
          (p_Var7->super__Rb_tree_node_base)._M_right = &p_Var8->super__Rb_tree_node_base;
        }
        pdVar6 = (pointer)pdVar6[2];
        p_Var8 = p_Var7;
      } while( true );
    }
    uVar5 = uVar13 * 8;
    pdVar6 = rea_operator_new(uVar5);
    if (uVar13 != 0) {
      rea_memmove(pdVar6,pdVar9,uVar5);
      pdVar9 = (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
      goto joined_r0x0010e356;
    }
  }
  pdVar9 = (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
joined_r0x0010e356:
  if (pdVar9 != (pointer)0x0) {
    rea_operator_delete(pdVar9);
  }
  (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start = pdVar6;
  (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_end_of_storage =
       (pointer)((long)pdVar6 + uVar5);
  (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish =
       (pointer)((long)pdVar6 + uVar5);
  return this_ptr;
}





// ------------------------------------------------------------------
// IDX 56  00105270  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_copy
// ------------------------------------------------------------------
_Link_type rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_copy(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * this_ptr, _Const_Link_type __x, _Link_type __p)
{
  _Rb_tree_color _Var1;
  pointer pdVar2;
  _Const_Link_type p_Var3;
  _Base_ptr p_Var4;
  _Base_ptr p_Var5;
  _Base_ptr p_Var6;
  _Link_type __p_00;
  _Link_type p_Var7;
  _Link_type p_Var8;
  pointer pdVar9;
  pointer __dest;
  undefined8 uVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  size_t sVar14;
  
  __p_00 = rea_operator_new(0x40);
  if (__p_00 != (_Link_type)0x0) {
    (__p_00->super__Rb_tree_node_base)._M_color = _S_red;
    (__p_00->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    rea_std__string__string(&__p_00->_M_value_field,&(__x->_M_value_field).first);
    pdVar9 = (__x->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
             _M_impl._M_finish;
    pdVar2 = (__x->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
             _M_impl._M_start;
    uVar13 = 0;
    __dest = (pointer)0x0;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
    _M_start = (pointer)0x0;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
    _M_finish = (pointer)0x0;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
    _M_end_of_storage = (pointer)0x0;
    uVar11 = (long)pdVar9 - (long)pdVar2 >> 3;
    if (uVar11 != 0) {
      if (0x1fffffffffffffff < uVar11) {
        p_Var8 = (_Link_type)rea_std____throw_bad_alloc();
        std__string___Rep___M_dispose___________________((allocator *)((__p_00->_M_value_field).first._M_dataplus._M_p + -0x18));
        p_Var7 = p_Var8;
        goto LAB_0010e6ea;
      }
      uVar13 = uVar11 * 8;
      __dest = rea_operator_new(uVar13);
    }
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
    _M_start = __dest;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
    _M_finish = __dest;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
    _M_end_of_storage = (pointer)(uVar13 + (long)__dest);
    pdVar9 = (__x->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
             _M_impl._M_start;
    sVar14 = 0;
    lVar12 = (long)(__x->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
                   _M_impl._M_finish - (long)pdVar9 >> 3;
    if (lVar12 != 0) {
      sVar14 = lVar12 * 8;
      __dest = rea_memmove(__dest,pdVar9,sVar14);
    }
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
    _M_finish = (pointer)((long)__dest + sVar14);
  }
  _Var1 = (__x->super__Rb_tree_node_base)._M_color;
  (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
  p_Var3 = (_Const_Link_type)(__x->super__Rb_tree_node_base)._M_right;
  (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
  (__p_00->super__Rb_tree_node_base)._M_parent = &__p->super__Rb_tree_node_base;
  (__p_00->super__Rb_tree_node_base)._M_color = _Var1;
  if (p_Var3 != (_Const_Link_type)0x0) {
    p_Var7 = _M_copy(this_ptr,p_Var3,__p_00);
    (__p_00->super__Rb_tree_node_base)._M_right = &p_Var7->super__Rb_tree_node_base;
  }
  p_Var4 = (__x->super__Rb_tree_node_base)._M_left;
  p_Var8 = __p_00;
  do {
    if (p_Var4 == (_Base_ptr)0x0) {
      return __p_00;
    }
    p_Var7 = rea_operator_new(0x40);
    if (p_Var7 != (_Link_type)0x0) {
      (p_Var7->super__Rb_tree_node_base)._M_color = _S_red;
      (p_Var7->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
      (p_Var7->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
      (p_Var7->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
      rea_std__string__string(&p_Var7->_M_value_field,(string *)(p_Var4 + 1));
      p_Var5 = p_Var4[1]._M_left;
      p_Var6 = p_Var4[1]._M_parent;
      uVar13 = 0;
      pdVar9 = (pointer)0x0;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
      _M_start = (pointer)0x0;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
      _M_finish = (pointer)0x0;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
      _M_end_of_storage = (pointer)0x0;
      uVar11 = (long)p_Var5 - (long)p_Var6 >> 3;
      if (uVar11 != 0) {
        if (0x1fffffffffffffff < uVar11) {
          uVar10 = rea_std____throw_bad_alloc();
          do {
            std__string___Rep___M_dispose_______________________((allocator *)((p_Var7->_M_value_field).first._M_dataplus._M_p + -0x18));
            rea___cxa_begin_catch(uVar10);
            rea_operator_delete(p_Var7);
            p_Var8 = (_Link_type)rea___cxa_rethrow();
LAB_0010e6ea:
            rea___cxa_begin_catch(p_Var8);
            rea_operator_delete(__p_00);
            uVar10 = rea___cxa_rethrow();
          } while( true );
        }
        uVar13 = uVar11 * 8;
        pdVar9 = rea_operator_new(uVar13);
      }
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
      _M_start = pdVar9;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
      _M_finish = pdVar9;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
      _M_end_of_storage = (pointer)(uVar13 + (long)pdVar9);
      sVar14 = 0;
      lVar12 = (long)p_Var4[1]._M_left - (long)p_Var4[1]._M_parent >> 3;
      if (lVar12 != 0) {
        sVar14 = lVar12 * 8;
        pdVar9 = rea_memmove(pdVar9,p_Var4[1]._M_parent,sVar14);
      }
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
      _M_finish = (pointer)((long)pdVar9 + sVar14);
    }
    _Var1 = p_Var4->_M_color;
    (p_Var7->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    p_Var3 = (_Const_Link_type)p_Var4->_M_right;
    (p_Var7->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (p_Var7->super__Rb_tree_node_base)._M_color = _Var1;
    (p_Var8->super__Rb_tree_node_base)._M_left = &p_Var7->super__Rb_tree_node_base;
    (p_Var7->super__Rb_tree_node_base)._M_parent = &p_Var8->super__Rb_tree_node_base;
    if (p_Var3 != (_Const_Link_type)0x0) {
      p_Var8 = _M_copy(this_ptr,p_Var3,p_Var7);
      (p_Var7->super__Rb_tree_node_base)._M_right = &p_Var8->super__Rb_tree_node_base;
    }
    p_Var4 = p_Var4->_M_left;
    p_Var8 = p_Var7;
  } while( true );
}





// ------------------------------------------------------------------
// IDX 57  00105280  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_insert_node
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_insert_node(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, _Base_ptr __x, _Base_ptr __p, _Link_type __z)
{
  _Rb_tree_node_base *p_Var1;
  size_type *psVar2;
  bool bVar3;
  
  p_Var1 = &(this_ptr->_M_impl)._M_header;
  if ((__x == (_Base_ptr)0x0) && (p_Var1 != __p)) {
    bVar3 = (__z->_M_value_field).first < (int)__p[1]._M_color;
  }
  else {
    bVar3 = true;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar3,&__z->super__Rb_tree_node_base,__p,p_Var1);
  psVar2 = &(this_ptr->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)&__z->super__Rb_tree_node_base;
}





// ------------------------------------------------------------------
// IDX 58  00105290  SecInfo__find_data2
// ------------------------------------------------------------------
Data2 * rea_SecInfo__find_data2(SecInfo * this_ptr, int date)
{
  _Base_ptr *pp_Var1;
  int *piVar2;
  _Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_ this_00;
  undefined *this_01;
  undefined *puVar3;
  int iVar4;
  _Link_type p_Var5;
  iterator __position;
  long *plVar6;
  _Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_ _Var7;
  FILE *__stream;
  size_t sVar8;
  void *pvVar9;
  _Base_ptr p_Var10;
  _Base_ptr p_Var11;
  _Base_ptr p_Var12;
  _Base_ptr p_Var13;
  ulong uVar14;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar15;
  long alStack_68 [2];
  long alStack_58 [2];
  string asStack_48 [3];
  
  this_01 = PTR_data_store2_00311f70;
  p_Var12 = *(_Base_ptr *)(PTR_data_store2_00311f70 + 0x10);
  if (p_Var12 == (_Base_ptr)0x0) {
LAB_00107720:
    rea___gnu_cxx____to_xstring_std__basic_string_char__char
              ((code *)
               alStack_68,(size_t)PTR_vsnprintf_00311fd0,(char *)0x10,(void *)&DAT_0010fc03,date);
    plVar6 = (long *)rea_std__string__insert((ulong)alStack_68,(char *)0x0,0x10fc06);
    puVar3 = PTR__S_empty_rep_storage_00311ff0;
    alStack_58[0] = *plVar6;
    *plVar6 = (long)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    plVar6 = (long *)rea_std__string__append((char *)alStack_58,0x10fbfd);
    asStack_48[0]._M_dataplus._M_p = (_Alloc_hider)*plVar6;
    *plVar6 = (long)(puVar3 + 0x18);
    _Var7 = (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)
            rea_operator_new(0x18);
    *(int *)_Var7 = 0;
    *(int *)((long)_Var7 + 4) = 0;
    ((int *)((long)_Var7 + 8))[0] = 0;
    ((int *)((long)_Var7 + 8))[1] = 0;
    ((int *)((long)_Var7 + 0x10))[0] = 0;
    ((int *)((long)_Var7 + 0x10))[1] = 0;
    __stream = rea_open_file(asStack_48);
    if (__stream != (FILE *)0x0) {
      sVar8 = rea_fread((void *)_Var7,4,1,(FILE *)__stream);
      if ((sVar8 == 1) && (sVar8 = rea_fread((int *)((long)_Var7 + 4),4,1,(FILE *)__stream), sVar8 == 1)
         ) {
        uVar14 = 0xffffffffffffffff;
        if ((ulong)(long)*(int *)_Var7 < 0x550000000000001) {
          uVar14 = (long)*(int *)_Var7 * 0x18;
        }
        pvVar9 = rea_operator_new(uVar14);
        *(void **)((long)_Var7 + 8) = pvVar9;
        uVar14 = 0xffffffffffffffff;
        if ((ulong)(long)*(int *)((long)_Var7 + 4) < 0x1c4000000000001) {
          uVar14 = (long)*(int *)((long)_Var7 + 4) * 0x48;
        }
        pvVar9 = rea_operator_new(uVar14);
        *(void **)((long)_Var7 + 0x10) = pvVar9;
        sVar8 = rea_fread(*(void **)((long)_Var7 + 8),0x18,(long)*(int *)_Var7,(FILE *)__stream);
        if ((sVar8 != (long)*(int *)_Var7) ||
           (sVar8 = rea_fread(*(void **)((long)_Var7 + 0x10),0x48,(long)*(int *)((long)_Var7 + 4),
                          (FILE *)__stream), sVar8 != (long)*(int *)((long)_Var7 + 4)))
        goto LAB_001077f4;
      }
      else {
LAB_001077f4:
        *(int *)_Var7 = 0;
        *(int *)((long)_Var7 + 4) = 0;
        if (*(void **)((long)_Var7 + 8) != (void *)0x0) {
          rea_operator_delete(*(void **)((long)_Var7 + 8));
          ((int *)((long)_Var7 + 8))[0] = 0;
          ((int *)((long)_Var7 + 8))[1] = 0;
        }
        if (*(void **)((long)_Var7 + 0x10) != (void *)0x0) {
          rea_operator_delete(*(void **)((long)_Var7 + 0x10));
          ((int *)((long)_Var7 + 0x10))[0] = 0;
          ((int *)((long)_Var7 + 0x10))[1] = 0;
        }
      }
      rea_fclose((FILE *)__stream);
    }
    p_Var5 = rea_operator_new(0x30);
    if (p_Var5 != (_Link_type)0x0) {
      (p_Var5->_M_value_field).second._M_t.
      super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_> = _Var7;
      (p_Var5->super__Rb_tree_node_base)._M_color = _S_red;
      _Var7 = (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
      (p_Var5->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
      (p_Var5->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
      (p_Var5->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
      (p_Var5->_M_value_field).first = date;
    }
    pVar15 = std_________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____________________M_get_insert_unique_pos________________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____
                         *)this_01,&(p_Var5->_M_value_field).first);
    if (pVar15.second == (_Base_ptr)0x0) {
      this_00 = (p_Var5->_M_value_field).second._M_t.
                super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_>;
      if (this_00 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
        rea_IndexedData_GIDKey__Item2__free((IndexedData_GIDKey__Item2 *)this_00);
        rea_operator_delete((void *)this_00);
      }
      (p_Var5->_M_value_field).second._M_t.
      super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_> =
           (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
      rea_operator_delete(p_Var5);
    }
    else {
      std__________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2______________M_insert_node((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____
                        *)this_01,pVar15.first,pVar15.second,p_Var5);
    }
    if (_Var7 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
      *(int *)_Var7 = 0;
      *(int *)((long)_Var7 + 4) = 0;
      if (*(void **)((long)_Var7 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var7 + 8));
        ((int *)((long)_Var7 + 8))[0] = 0;
        ((int *)((long)_Var7 + 8))[1] = 0;
      }
      if (*(void **)((long)_Var7 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var7 + 0x10));
        ((int *)((long)_Var7 + 0x10))[0] = 0;
        ((int *)((long)_Var7 + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)_Var7);
    }
    if ((allocator *)((long)asStack_48[0]._M_dataplus._M_p + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)((long)asStack_48[0]._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar4 = *(int *)((long)asStack_48[0]._M_dataplus._M_p + -8);
        *(int *)((long)asStack_48[0]._M_dataplus._M_p + -8) = iVar4 + -1;
      }
      else {
        LOCK();
        iVar4 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar4 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long)asStack_48[0]._M_dataplus._M_p + -0x18));
      }
    }
    if ((allocator *)(alStack_58[0] + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)(alStack_58[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar4 = *(int *)(alStack_58[0] + -8);
        *(int *)(alStack_58[0] + -8) = iVar4 + -1;
      }
      else {
        LOCK();
        iVar4 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar4 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(alStack_58[0] + -0x18));
      }
    }
    if ((allocator *)(alStack_68[0] + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)(alStack_68[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar4 = *(int *)(alStack_68[0] + -8);
        *(int *)(alStack_68[0] + -8) = iVar4 + -1;
      }
      else {
        LOCK();
        iVar4 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar4 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(alStack_68[0] + -0x18));
      }
    }
    p_Var12 = *(_Base_ptr *)(this_01 + 0x10);
    if (p_Var12 != (_Base_ptr)0x0) goto LAB_00107661;
    __position._M_node = (_Base_ptr)(this_01 + 8);
  }
  else {
    p_Var13 = p_Var12;
    p_Var10 = (_Base_ptr)(PTR_data_store2_00311f70 + 8);
    do {
      while (p_Var11 = p_Var13, date <= (int)p_Var11[1]._M_color) {
        p_Var13 = p_Var11->_M_left;
        p_Var10 = p_Var11;
        if (p_Var11->_M_left == (_Base_ptr)0x0) goto LAB_0010764a;
      }
      pp_Var1 = &p_Var11->_M_right;
      p_Var13 = *pp_Var1;
      p_Var11 = p_Var10;
    } while (*pp_Var1 != (_Base_ptr)0x0);
LAB_0010764a:
    if ((p_Var11 == (_Base_ptr)(PTR_data_store2_00311f70 + 8)) || (date < (int)p_Var11[1]._M_color))
    goto LAB_00107720;
LAB_00107661:
    p_Var13 = (_Base_ptr)(this_01 + 8);
    do {
      while (__position._M_node = p_Var12, date <= (int)__position._M_node[1]._M_color) {
        p_Var12 = (__position._M_node)->_M_left;
        p_Var13 = __position._M_node;
        if ((__position._M_node)->_M_left == (_Base_ptr)0x0) goto LAB_0010768a;
      }
      pp_Var1 = &(__position._M_node)->_M_right;
      p_Var12 = *pp_Var1;
      __position._M_node = p_Var13;
    } while (*pp_Var1 != (_Base_ptr)0x0);
LAB_0010768a:
    if ((__position._M_node != (_Base_ptr)(this_01 + 8)) &&
       ((int)__position._M_node[1]._M_color <= date)) goto LAB_00107703;
  }
  p_Var5 = rea_operator_new(0x30);
  if (p_Var5 != (_Link_type)0x0) {
    (p_Var5->super__Rb_tree_node_base)._M_color = _S_red;
    (p_Var5->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (p_Var5->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (p_Var5->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (p_Var5->_M_value_field).first = date;
    (p_Var5->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_> =
         (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
  }
  pVar15 = std_______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2___________________M_get_insert_hint_unique_pos______________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____
                       *)this_01,(const_iterator)__position._M_node,&(p_Var5->_M_value_field).first)
  ;
  __position._M_node = pVar15.first;
  if (pVar15.second == (_Base_ptr)0x0) {
    _Var7 = (p_Var5->_M_value_field).second._M_t.
            super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_>;
    if (_Var7 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
      rea_IndexedData_GIDKey__Item2__free((IndexedData_GIDKey__Item2 *)_Var7);
      rea_operator_delete((void *)_Var7);
    }
    (p_Var5->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_> =
         (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
    rea_operator_delete(p_Var5);
  }
  else {
    __position = std_____________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_________________________M_insert_node((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____
                                   *)this_01,__position._M_node,pVar15.second,p_Var5);
  }
LAB_00107703:
  return (Data2 *)__position._M_node[1]._M_parent;
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
// IDX 60  001052b0  IndexedData_GroupKey__GroupForwardItem__free
// ------------------------------------------------------------------
void rea_IndexedData_GroupKey__GroupForwardItem__free(IndexedData_GroupKey__GroupForwardItem * this_ptr)
{
  this_ptr->num_idxs = 0;
  this_ptr->num_items = 0;
  if (this_ptr->idxs != (Index *)0x0) {
    rea_operator_delete(this_ptr->idxs);
    this_ptr->idxs = (Index *)0x0;
  }
  if (this_ptr->items != (GroupForwardItem *)0x0) {
    rea_operator_delete(this_ptr->items);
    this_ptr->items = (GroupForwardItem *)0x0;
  }
  return;
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
// IDX 63  001052e0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____________
// ------------------------------------------------------------------
pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____bool rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr)
{
  _Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_ _Var1;
  _Link_type __z;
  _Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_ *in_RDX;
  int *in_RSI;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar2;
  pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____bool
  pVar3;
  pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____bool
  pVar4;
  
  __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->_M_value_field).first = *in_RSI;
    _Var1 = *in_RDX;
    *in_RDX = (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0
    ;
    (__z->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_> = _Var1;
  }
  pVar2 = _M_get_insert_unique_pos(this_ptr,&(__z->_M_value_field).first);
  pVar4.first._M_node = pVar2.first;
  if (pVar2.second == (_Base_ptr)0x0) {
    _Var1 = (__z->_M_value_field).second._M_t.
            super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_>;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)
                 0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long)_Var1 + 4) = 0;
      if (*(void **)((long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 8));
        *(undefined8 *)((long)_Var1 + 8) = 0;
      }
      if (*(void **)((long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 0x10));
        *(undefined8 *)((long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (__z->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_> =
         (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
    rea_operator_delete(__z);
    (*(undefined8 *)((uint8_t *)&pVar4 + 0x8)) = 0;
    return pVar4;
  }
  pVar3.first._M_node = _M_insert_node(this_ptr,pVar4.first._M_node,pVar2.second,__z);
  (*(undefined8 *)((uint8_t *)&pVar3 + 0x8)) = 1;
  return pVar3;
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
// IDX 65  00105300  SecInfo__getPreClosePrice
// ------------------------------------------------------------------
double rea_SecInfo__getPreClosePrice(SecInfo * this_ptr, string * gid, int date)
{
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  long lVar5;
  int iVar6;
  size_t __n;
  long lVar7;
  int *piVar8;
  long lVar9;
  undefined1 auStack_68 [16];
  char acStack_58 [16];
  undefined8 uStack_48;
  
  piVar8 = *(int **)PTR_data_00311fc8;
  if (*(ulong *)((gid->_M_dataplus)._M_p + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar4 = (gid->_M_dataplus)._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar4 + -0x18);
    }
    rea_memcpy(auStack_68,pcVar4,__n);
    lVar7 = (long)*piVar8;
    auStack_68[__n] = 0;
    pcVar4 = *(char **)(piVar8 + 2);
    uStack_48 = 0;
    pcVar1 = pcVar4 + lVar7 * 0x18;
    for (; 0 < lVar7; lVar7 = (lVar7 - lVar9) + -1) {
      while( true ) {
        lVar9 = lVar7 >> 1;
        iVar6 = rea_strcmp(pcVar4 + lVar9 * 0x18,acStack_58);
        if (iVar6 < 0) break;
        lVar7 = lVar9;
        if (lVar9 == 0) goto LAB_00105cab;
      }
      pcVar4 = pcVar4 + lVar9 * 0x18 + 0x18;
    }
LAB_00105cab:
    if (((pcVar1 != pcVar4) && (iVar6 = rea_strcmp(pcVar4,acStack_58), iVar6 == 0)) &&
       (pcVar4 != (char *)0x0)) {
      piVar8 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      (long)*(int *)(pcVar4 + 0x10) * 0x18);
      piVar2 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      ((long)*(int *)(pcVar4 + 0x10) + (long)*(int *)(pcVar4 + 0x14)) * 0x18);
      for (lVar7 = ((long)piVar2 - (long)piVar8 >> 3) * -0x5555555555555555; 0 < lVar7;
          lVar7 = (lVar7 - lVar5) + -1) {
        piVar3 = piVar8 + (lVar7 >> 1) * 6;
        iVar6 = *piVar3;
        lVar9 = lVar7 >> 1;
        while (lVar5 = lVar9, date <= iVar6) {
          if (lVar5 == 0) goto LAB_00105d4a;
          piVar3 = piVar8 + (lVar5 >> 1) * 6;
          lVar9 = lVar5 >> 1;
          lVar7 = lVar5;
          iVar6 = *piVar3;
        }
        piVar8 = piVar3 + 6;
      }
LAB_00105d4a:
      if ((piVar8 != piVar2) && (date == *piVar8)) {
        return *(double *)(piVar8 + 2);
      }
    }
  }
  return DAT_0010fd10;
}





// ------------------------------------------------------------------
// IDX 66  00105310  pinot_close
// ------------------------------------------------------------------
void rea_pinot_close(void * fp)
{
  long *plVar1;
  
  if (fp == (void *)0x0) {
    return;
  }
  plVar1 = *(long **)fp;
  if (pinot_reader_handle == (void *)0x0) {
    if (plVar1 != (long *)0x0) {
      (**(code **)(*plVar1 + 8))();
      rea_operator_delete(fp);
      return;
    }
  }
  else {
    (*pinot_reader_close)(plVar1);
  }
  rea_operator_delete(fp);
  return;
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
// IDX 69  00105340  pinot_getline
// ------------------------------------------------------------------
pair_int__std__basic_string_char__std__char_traits_char__std__allocator_char__ rea_pinot_getline(void * fp)
{
  long *plVar1;
  undefined *puVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  istream *piVar6;
  undefined8 uVar7;
  _Alloc_hider extraout_RDX;
  _Alloc_hider extraout_RDX_00;
  basic_string_char__std__char_traits_char__std__allocator_char_ bVar8;
  undefined8 *in_RSI;
  pair_int__std__basic_string_char__std__char_traits_char__std__allocator_char__ pVar9;
  string asStack_38 [3];
  
  puVar2 = PTR__S_empty_rep_storage_00311ff0;
  asStack_38[0]._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
  if (pinot_reader_handle == (void *)0x0) {
    piVar6 = (istream *)*in_RSI;
    plVar1 = *(long **)(piVar6 + *(long *)(*(long *)piVar6 + -0x18) + 0xf0);
    if (plVar1 == (long *)0x0) {
      uVar7 = rea_std____throw_bad_cast();
      rea_std__string___Rep___M_dispose((allocator *)((long)asStack_38[0]._M_dataplus._M_p + -0x18));
                    /* WARNING: Subroutine does not return */
      rea__Unwind_Resume(uVar7);
    }
    if ((char)plVar1[7] == '\0') {
      rea_std__ctype_char___M_widen_init();
      cVar4 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
    }
    else {
      cVar4 = *(char *)((long)plVar1 + 0x43);
    }
    piVar6 = rea_std__getline_char_std__char_traits_char_std__allocator_char(piVar6,asStack_38,cVar4)
    ;
    bVar3 = ((byte)piVar6[*(long *)(*(long *)piVar6 + -0x18) + 0x20] & 5) == 0;
  }
  else {
    bVar3 = (*pinot_reader_getline)((void *)*in_RSI,asStack_38);
  }
  *(uint *)fp = (uint)bVar3;
  rea_std__string__string((void *)((long)fp + 8),asStack_38);
  bVar8._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)extraout_RDX._M_p;
  if ((allocator *)((long)asStack_38[0]._M_dataplus._M_p + -0x18) != (allocator *)puVar2) {
    bVar8._M_dataplus._M_p = (_Alloc_hider)((long)asStack_38[0]._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
      uVar5 = *(uint *)((long)asStack_38[0]._M_dataplus._M_p + -8);
      bVar8._M_dataplus._M_p = (_Alloc_hider)(ulong)uVar5;
      *(uint *)((long)asStack_38[0]._M_dataplus._M_p + -8) = uVar5 - 1;
    }
    else {
      LOCK();
      uVar5 = *(uint *)bVar8._M_dataplus._M_p;
      *(uint *)bVar8._M_dataplus._M_p = *(uint *)bVar8._M_dataplus._M_p - 1;
      UNLOCK();
    }
    if ((int)uVar5 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long)asStack_38[0]._M_dataplus._M_p + -0x18));
      bVar8._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)extraout_RDX_00._M_p;
    }
  }
  pVar9.second._M_dataplus._M_p = bVar8._M_dataplus._M_p;
  (*(undefined8 *)((uint8_t *)&pVar9 + 0x0)) = fp;
  return pVar9;
}





// ------------------------------------------------------------------
// IDX 70  00105350  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_hint_unique_pos(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, const_iterator __position, key_type * __k)
{
  void *__s2;
  char *pcVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  const_iterator cVar7;
  _Base_ptr p_Var8;
  ulong uVar9;
  long lVar10;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar11;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar12;
  
  if (__position._M_node == &(this_ptr->_M_impl)._M_header) {
    if ((this_ptr->_M_impl)._M_node_count == 0) goto LAB_0010e000;
    __position._M_node = (this_ptr->_M_impl)._M_header._M_right;
    pcVar1 = (__k->_M_dataplus)._M_p;
    uVar2 = *(ulong *)(pcVar1 + -0x18);
    uVar3 = *(ulong *)((long)*(void **)(__position._M_node + 1) + -0x18);
    uVar9 = uVar3;
    if (uVar2 <= uVar3) {
      uVar9 = uVar2;
    }
    iVar5 = rea_memcmp(*(void **)(__position._M_node + 1),pcVar1,uVar9);
    if (iVar5 == 0) {
      lVar10 = uVar3 - uVar2;
      if (0x7fffffff < lVar10) goto LAB_0010e000;
      if (-0x80000001 < lVar10) {
        iVar5 = (int)lVar10;
        goto LAB_0010e065;
      }
    }
    else {
LAB_0010e065:
      if (-1 < iVar5) goto LAB_0010e000;
    }
LAB_0010e069:
    cVar7._M_node = (_Base_ptr)0x0;
    goto LAB_0010deff;
  }
  __s2 = *(void **)(__position._M_node + 1);
  pcVar1 = (__k->_M_dataplus)._M_p;
  uVar2 = *(ulong *)((long)__s2 + -0x18);
  uVar3 = *(ulong *)(pcVar1 + -0x18);
  uVar9 = uVar3;
  if (uVar2 <= uVar3) {
    uVar9 = uVar2;
  }
  uVar4 = rea_memcmp(pcVar1,__s2,uVar9);
  uVar6 = (ulong)uVar4;
  cVar7._M_node = __position._M_node;
  if (uVar4 == 0) {
    uVar6 = uVar3 - uVar2;
    if ((long)uVar6 < 0x80000000) {
      if (-0x80000001 < (long)uVar6) goto LAB_0010dfa0;
      goto LAB_0010df1c;
    }
  }
  else {
LAB_0010dfa0:
    if ((int)uVar6 < 0) {
LAB_0010df1c:
      if ((this_ptr->_M_impl)._M_header._M_left != __position._M_node) {
        p_Var8 = (_Base_ptr)rea_std___Rb_tree_decrement(__position._M_node);
        uVar2 = *(ulong *)((long)*(void **)(p_Var8 + 1) + -0x18);
        uVar9 = uVar3;
        if (uVar2 <= uVar3) {
          uVar9 = uVar2;
        }
        iVar5 = rea_memcmp(*(void **)(p_Var8 + 1),pcVar1,uVar9);
        if (iVar5 == 0) {
          lVar10 = uVar2 - uVar3;
          if (0x7fffffff < lVar10) goto LAB_0010e000;
          if (lVar10 < -0x80000000) goto LAB_0010df7c;
          iVar5 = (int)lVar10;
        }
        if (iVar5 < 0) {
LAB_0010df7c:
          if (p_Var8->_M_right == (_Base_ptr)0x0) {
            __position._M_node = p_Var8;
            cVar7._M_node = (_Base_ptr)0x0;
          }
          pVar12.second = __position._M_node;
          pVar12.first = cVar7._M_node;
          return pVar12;
        }
        goto LAB_0010e000;
      }
      goto LAB_0010deff;
    }
  }
  iVar5 = rea_memcmp(__s2,pcVar1,uVar9);
  if (iVar5 == 0) {
    lVar10 = uVar2 - uVar3;
    if (lVar10 < 0x80000000) {
      if (-0x80000001 < lVar10) {
        iVar5 = (int)lVar10;
        goto LAB_0010def2;
      }
      goto LAB_0010dfb0;
    }
  }
  else {
LAB_0010def2:
    if (iVar5 < 0) {
LAB_0010dfb0:
      if ((this_ptr->_M_impl)._M_header._M_right == __position._M_node) goto LAB_0010e069;
      p_Var8 = (_Base_ptr)rea_std___Rb_tree_increment(__position._M_node);
      uVar2 = *(ulong *)((long)*(void **)(p_Var8 + 1) + -0x18);
      uVar9 = uVar3;
      if (uVar2 <= uVar3) {
        uVar9 = uVar2;
      }
      iVar5 = rea_memcmp(pcVar1,*(void **)(p_Var8 + 1),uVar9);
      if (iVar5 == 0) {
        lVar10 = uVar3 - uVar2;
        if (0x7fffffff < lVar10) goto LAB_0010e000;
        if (-0x80000001 < lVar10) {
          iVar5 = (int)lVar10;
          goto LAB_0010e083;
        }
      }
      else {
LAB_0010e083:
        if (-1 < iVar5) {
LAB_0010e000:
          pVar12 = _M_get_insert_unique_pos(this_ptr,__k);
          return pVar12;
        }
      }
      cVar7._M_node = (_Base_ptr)0x0;
      if ((__position._M_node)->_M_right != (_Base_ptr)0x0) {
        cVar7._M_node = p_Var8;
        __position._M_node = p_Var8;
      }
      goto LAB_0010deff;
    }
  }
  __position._M_node = (_Base_ptr)0x0;
LAB_0010deff:
  pVar11.second = __position._M_node;
  pVar11.first = cVar7._M_node;
  return pVar11;
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
// IDX 73  00105380  std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______pair
// ------------------------------------------------------------------
void rea_std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______pair(pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__ * this_ptr, int __in_chrg)
{
  int *piVar1;
  pointer pdVar2;
  char *pcVar3;
  int iVar4;
  
  pdVar2 = (this_ptr->second).super__Vector_base_double__std__allocator_double_._M_impl._M_start;
  if (pdVar2 != (pointer)0x0) {
    rea_operator_delete(pdVar2);
  }
  pcVar3 = (this_ptr->first)._M_dataplus._M_p;
  if ((allocator *)(pcVar3 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar1 = (int *)(pcVar3 + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
      iVar4 = *(int *)(pcVar3 + -8);
      *(int *)(pcVar3 + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(pcVar3 + -0x18));
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 74  00105390  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_unique_pos(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, key_type * __k)
{
  undefined1 auVar1 [16];
  bool bVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  _Rb_tree_node_base *p_Var6;
  size_t __n;
  _Rb_tree_node_base *p_Var7;
  ulong uVar8;
  long lVar9;
  char *__s1;
  void *__s2;
  ulong uVar10;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar11;
  
  p_Var6 = (this_ptr->_M_impl)._M_header._M_parent;
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
    p_Var7 = &(this_ptr->_M_impl)._M_header;
LAB_0010de00:
    if ((this_ptr->_M_impl)._M_header._M_left == p_Var7) {
      p_Var6 = (_Rb_tree_node_base *)0x0;
      goto LAB_0010ddbd;
    }
    p_Var6 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var7);
    __s2 = *(void **)(p_Var6 + 1);
    __s1 = (__k->_M_dataplus)._M_p;
    uVar8 = *(ulong *)((long)__s2 + -0x18);
    uVar10 = *(ulong *)(__s1 + -0x18);
    __n = uVar10;
    if (uVar8 <= uVar10) {
      __n = uVar8;
    }
  }
  else {
    __s1 = (__k->_M_dataplus)._M_p;
    uVar10 = *(ulong *)(__s1 + -0x18);
    do {
      p_Var7 = p_Var6;
      __s2 = *(void **)(p_Var7 + 1);
      uVar8 = *(ulong *)((long)__s2 + -0x18);
      __n = uVar8;
      if (uVar10 <= uVar8) {
        __n = uVar10;
      }
      uVar3 = rea_memcmp(__s1,__s2,__n);
      uVar5 = (ulong)uVar3;
      if (uVar3 == 0) {
        uVar5 = uVar10 - uVar8;
        if ((long)uVar5 < 0x80000000) {
          if (-0x80000001 < (long)uVar5) goto LAB_0010dd40;
          goto LAB_0010dd44;
        }
LAB_0010dd87:
        p_Var6 = p_Var7->_M_right;
        bVar2 = false;
      }
      else {
LAB_0010dd40:
        if (-1 < (int)uVar5) goto LAB_0010dd87;
LAB_0010dd44:
        p_Var6 = p_Var7->_M_left;
        bVar2 = true;
      }
    } while (p_Var6 != (_Base_ptr)0x0);
    p_Var6 = p_Var7;
    if (bVar2) goto LAB_0010de00;
  }
  iVar4 = rea_memcmp(__s2,__s1,__n);
  if (iVar4 == 0) {
    lVar9 = uVar8 - uVar10;
    if (lVar9 < 0x80000000) {
      if (lVar9 < -0x80000000) goto LAB_0010dde0;
      iVar4 = (int)lVar9;
      goto LAB_0010dddb;
    }
  }
  else {
LAB_0010dddb:
    if (iVar4 < 0) {
LAB_0010dde0:
      (*(undefined8 *)((uint8_t *)&auVar1 + 0x8)) = 0;
      (*(undefined8 *)((uint8_t *)&auVar1 + 0x0)) = p_Var7;
      return (pair_std___Rb_tree_node_base___std___Rb_tree_node_base_)(auVar1 << 0x40);
    }
  }
  p_Var7 = (_Rb_tree_node_base *)0x0;
LAB_0010ddbd:
  pVar11.second = p_Var7;
  pVar11.first = p_Var6;
  return pVar11;
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
// IDX 76  001053b0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_hint_unique_pos(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, const_iterator __position, key_type * __k)
{
  int iVar1;
  _Base_ptr p_Var2;
  const_iterator cVar3;
  const_iterator cVar4;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar5;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar6;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar7;
  
  if (__position._M_node == &(this_ptr->_M_impl)._M_header) {
    if (((this_ptr->_M_impl)._M_node_count == 0) ||
       (cVar3._M_node = (this_ptr->_M_impl)._M_header._M_right, *__k <= (int)cVar3._M_node[1]._M_color))
    {
LAB_0010db08:
      pVar7 = _M_get_insert_unique_pos(this_ptr,__k);
      return pVar7;
    }
  }
  else {
    iVar1 = *__k;
    if (iVar1 < (int)__position._M_node[1]._M_color) {
      cVar4._M_node = (this_ptr->_M_impl)._M_header._M_left;
      cVar3._M_node = cVar4._M_node;
      if (cVar4._M_node != __position._M_node) {
        cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_decrement(__position._M_node);
        if (iVar1 <= (int)cVar3._M_node[1]._M_color) goto LAB_0010db08;
        cVar4._M_node = (_Base_ptr)0x0;
        if ((cVar3._M_node)->_M_right != (_Base_ptr)0x0) {
          cVar4._M_node = __position._M_node;
          cVar3._M_node = __position._M_node;
        }
      }
      goto LAB_0010daa5;
    }
    if (iVar1 <= (int)__position._M_node[1]._M_color) {
      pVar7.second = (_Rb_tree_node_base *)0x0;
      pVar7.first = __position._M_node;
      return pVar7;
    }
    cVar3._M_node = (this_ptr->_M_impl)._M_header._M_right;
    if (cVar3._M_node != __position._M_node) {
      cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_increment(__position._M_node);
      if (iVar1 < (int)cVar3._M_node[1]._M_color) {
        p_Var2 = cVar3._M_node;
        if ((__position._M_node)->_M_right == (_Base_ptr)0x0) {
          cVar3._M_node = __position._M_node;
          p_Var2 = (_Base_ptr)0x0;
        }
        pVar6.second = cVar3._M_node;
        pVar6.first = p_Var2;
        return pVar6;
      }
      goto LAB_0010db08;
    }
  }
  cVar4._M_node = (_Base_ptr)0x0;
LAB_0010daa5:
  pVar5.second = cVar3._M_node;
  pVar5.first = cVar4._M_node;
  return pVar5;
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
// IDX 78  001053d0  std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______M_emplace_back_aux_const_std__basic_string_char__std__char_traits_char__std__allocator_char_____________
// ------------------------------------------------------------------
void rea_std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______M_emplace_back_aux_const_std__basic_string_char__std__char_traits_char__std__allocator_char(vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___ * this_ptr)
{
  char *pcVar1;
  int *piVar2;
  undefined *puVar3;
  ulong uVar4;
  int iVar5;
  ulong uVar6;
  pointer pbVar7;
  void *this_00;
  pointer pbVar8;
  pointer pbVar9;
  pointer pbVar10;
  string *in_RSI;
  pointer pbVar11;
  ulong uVar12;
  pointer pbVar13;
  
  uVar6 = (long)(this_ptr->
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                )._M_impl._M_finish -
          (long)(this_ptr->
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                )._M_impl._M_start >> 3;
  if (uVar6 == 0) {
    uVar4 = 1;
  }
  else {
    uVar4 = uVar6 * 2;
    if (uVar4 < uVar6) {
      uVar6 = 0xfffffffffffffff8;
      uVar12 = 0x1fffffffffffffff;
      goto LAB_0010cf83;
    }
    uVar12 = 0x1fffffffffffffff;
    if (0x1fffffffffffffff < uVar4) {
      uVar6 = 0xfffffffffffffff8;
      goto LAB_0010cf83;
    }
  }
  uVar12 = uVar4;
  uVar6 = uVar12 * 8;
LAB_0010cf83:
  pbVar7 = rea_operator_new(uVar6);
  pbVar13 = (this_ptr->
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            )._M_impl._M_finish;
  pbVar11 = (this_ptr->
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            )._M_impl._M_start;
  this_00 = (void *)((long)&(pbVar7->_M_dataplus)._M_p +
                    ((long)pbVar13 - (long)pbVar11 & 0xfffffffffffffff8U));
  if (this_00 != (void *)0x0) {
    rea_std__string__string(this_00,in_RSI);
    pbVar13 = (this_ptr->
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              )._M_impl._M_finish;
    pbVar11 = (this_ptr->
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              )._M_impl._M_start;
  }
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
  if (pbVar11 == pbVar13) {
    pbVar8 = pbVar7 + 1;
  }
  else {
    pcVar1 = PTR__S_empty_rep_storage_00311ff0 + 0x18;
    pbVar8 = pbVar7;
    pbVar9 = pbVar11;
    do {
      if (pbVar8 != (pointer)0x0) {
        (pbVar8->_M_dataplus)._M_p = (pbVar9->_M_dataplus)._M_p;
        (pbVar9->_M_dataplus)._M_p = pcVar1;
      }
      pbVar9 = pbVar9 + 1;
      pbVar8 = pbVar8 + 1;
    } while (pbVar9 != pbVar13);
    pbVar8 = (pointer)((long)&pbVar7[2]._M_dataplus._M_p +
                      ((long)pbVar13 - (long)(pbVar11 + 1) & 0xfffffffffffffff8U));
    pbVar9 = pbVar11 + 1;
    while( true ) {
      pbVar10 = pbVar9;
      pcVar1 = (pbVar11->_M_dataplus)._M_p;
      if ((allocator *)(pcVar1 + -0x18) != (allocator *)puVar3) {
        piVar2 = (int *)(pcVar1 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
          iVar5 = *(int *)(pcVar1 + -8);
          *(int *)(pcVar1 + -8) = iVar5 + -1;
        }
        else {
          LOCK();
          iVar5 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
        }
        if (iVar5 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(pcVar1 + -0x18));
        }
      }
      if (pbVar10 == pbVar13) break;
      pbVar9 = pbVar10 + 1;
      pbVar11 = pbVar10;
    }
    pbVar11 = (this_ptr->
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              )._M_impl._M_start;
  }
  if (pbVar11 != (pointer)0x0) {
    rea_operator_delete(pbVar11);
  }
  (this_ptr->
  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
  )._M_impl._M_start = pbVar7;
  (this_ptr->
  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
  )._M_impl._M_finish = pbVar8;
  (this_ptr->
  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
  )._M_impl._M_end_of_storage = pbVar7 + uVar12;
  return;
}





// ------------------------------------------------------------------
// IDX 79  001053e0  detail__P_std__basic_string_char__std__char_traits_char__std__allocator_char____parse__________________
// ------------------------------------------------------------------
size_t rea_detail__P_std__basic_string_char__std__char_traits_char__std__allocator_char____parse(vector_unsigned_char__std__allocator_unsigned_char_ * b, size_t p, string * ps)
{
  ulong uVar1;
  int iVar2;
  ulong *puVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  allocator *paVar7;
  pointer puVar8;
  allocator aStack_49;
  ulong *apuStack_48 [3];
  
  uVar5 = p + 8;
  puVar8 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl._M_start;
  uVar6 = (long)(b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                _M_finish - (long)puVar8;
  if (uVar5 <= uVar6) {
    rea_memcpy(apuStack_48,puVar8 + p,8);
    uVar1 = uVar5 + (long)apuStack_48[0];
    if (uVar1 <= uVar6) {
      if (ps != (string *)0x0) {
        puVar8 = puVar8 + uVar5;
        if (puVar8 == puVar8 + (long)apuStack_48[0]) {
          apuStack_48[0] = (ulong *)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
          paVar7 = (allocator *)PTR__S_empty_rep_storage_00311ff0;
        }
        else {
          uVar6 = (long)(puVar8 + (long)apuStack_48[0]) - (long)puVar8;
          puVar3 = (ulong *)rea_std__string___Rep___S_create(uVar6,0,&aStack_49);
          apuStack_48[0] = puVar3 + 3;
          uVar5 = 0;
          do {
            uVar4 = uVar5;
            *(uchar *)((long)apuStack_48[0] + uVar4) = puVar8[uVar4];
            paVar7 = (allocator *)PTR__S_empty_rep_storage_00311ff0;
            uVar5 = uVar4 + 1;
          } while (uVar5 != uVar6);
          if (puVar3 != (ulong *)PTR__S_empty_rep_storage_00311ff0) {
            *(undefined4 *)(puVar3 + 2) = 0;
            *puVar3 = uVar5;
            *(undefined1 *)((long)puVar3 + uVar4 + 0x19) = 0;
          }
        }
        rea_std__string__assign(ps);
        if ((allocator *)(apuStack_48[0] + -3) != paVar7) {
          puVar3 = apuStack_48[0] + -1;
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
            iVar2 = (int)apuStack_48[0][-1];
            *(int *)(apuStack_48[0] + -1) = iVar2 + -1;
          }
          else {
            LOCK();
            iVar2 = (int)*puVar3;
            *(int *)puVar3 = (int)*puVar3 + -1;
            UNLOCK();
          }
          if (iVar2 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)(apuStack_48[0] + -3));
          }
        }
      }
      return uVar1;
    }
  }
  return p;
}





// ------------------------------------------------------------------
// IDX 80  001053f0  std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char_______pair
// ------------------------------------------------------------------
void rea_std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char_______pair(pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___ * this_ptr, int __in_chrg)
{
  int *piVar1;
  char *pcVar2;
  undefined *puVar3;
  int iVar4;
  pointer pbVar5;
  pointer pbVar6;
  
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
  pcVar2 = (this_ptr->second).second._M_dataplus._M_p;
  if ((allocator *)(pcVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar1 = (int *)(pcVar2 + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
      iVar4 = *(int *)(pcVar2 + -8);
      *(int *)(pcVar2 + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
    }
  }
  pbVar6 = (this_ptr->second).first.
           super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
           ._M_impl._M_finish;
  pbVar5 = (this_ptr->second).first.
           super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
           ._M_impl._M_start;
  if (pbVar6 != pbVar5) {
    do {
      pcVar2 = (pbVar5->_M_dataplus)._M_p;
      if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar3) {
        piVar1 = (int *)(pcVar2 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
          iVar4 = *(int *)(pcVar2 + -8);
          *(int *)(pcVar2 + -8) = iVar4 + -1;
        }
        else {
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar4 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
        }
      }
      pbVar5 = pbVar5 + 1;
    } while (pbVar6 != pbVar5);
    pbVar6 = (this_ptr->second).first.
             super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
             ._M_impl._M_start;
  }
  if (pbVar6 != (pointer)0x0) {
    rea_operator_delete(pbVar6);
  }
  pcVar2 = (this_ptr->first)._M_dataplus._M_p;
  if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar3) {
    piVar1 = (int *)(pcVar2 + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
      iVar4 = *(int *)(pcVar2 + -8);
      *(int *)(pcVar2 + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
    }
  }
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
// IDX 83  00105420  std___vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double_______vector
// ------------------------------------------------------------------
void rea_std___vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double_______vector(vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double___ * this_ptr, int __in_chrg)
{
  pointer pdVar1;
  pointer pvVar2;
  pointer pvVar3;
  
  pvVar3 = (this_ptr->
           super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
           )._M_impl._M_finish;
  pvVar2 = (this_ptr->
           super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
           )._M_impl._M_start;
  if (pvVar3 != pvVar2) {
    do {
      pdVar1 = (pvVar2->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
      if (pdVar1 != (pointer)0x0) {
        rea_operator_delete(pdVar1);
      }
      pvVar2 = pvVar2 + 1;
    } while (pvVar3 != pvVar2);
    pvVar3 = (this_ptr->
             super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
             )._M_impl._M_start;
  }
  if (pvVar3 == (pointer)0x0) {
    return;
  }
  rea_operator_delete(pvVar3);
  return;
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
// IDX 88  00105470  IndexedData_GIDKey__Item2__free
// ------------------------------------------------------------------
void rea_IndexedData_GIDKey__Item2__free(IndexedData_GIDKey__Item2 * this_ptr)
{
  this_ptr->num_idxs = 0;
  this_ptr->num_items = 0;
  if (this_ptr->idxs != (Index *)0x0) {
    rea_operator_delete(this_ptr->idxs);
    this_ptr->idxs = (Index *)0x0;
  }
  if (this_ptr->items != (Item2 *)0x0) {
    rea_operator_delete(this_ptr->items);
    this_ptr->items = (Item2 *)0x0;
  }
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
// IDX 92  001054b0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_______find
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_______find(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, int * __k)
{
  _Rb_tree_node_base *p_Var1;
  _Base_ptr *pp_Var2;
  _Base_ptr p_Var3;
  _Base_ptr p_Var4;
  iterator iVar5;
  
  p_Var3 = (this_ptr->_M_impl)._M_header._M_parent;
  p_Var1 = &(this_ptr->_M_impl)._M_header;
  if (p_Var3 != (_Base_ptr)0x0) {
    p_Var4 = p_Var1;
    do {
      while (iVar5._M_node = p_Var3, *__k <= (int)iVar5._M_node[1]._M_color) {
        p_Var4 = iVar5._M_node;
        p_Var3 = (iVar5._M_node)->_M_left;
        if ((iVar5._M_node)->_M_left == (_Base_ptr)0x0) goto LAB_0010ce72;
      }
      pp_Var2 = &(iVar5._M_node)->_M_right;
      iVar5._M_node = p_Var4;
      p_Var3 = *pp_Var2;
    } while (*pp_Var2 != (_Base_ptr)0x0);
LAB_0010ce72:
    if ((p_Var1 != iVar5._M_node) && ((int)iVar5._M_node[1]._M_color <= *__k)) {
      return (iterator)iVar5._M_node;
    }
  }
  return (iterator)p_Var1;
}





// ------------------------------------------------------------------
// IDX 93  001054c0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_erase(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, _Link_type __x)
{
  _Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_ _Var1;
  _Link_type p_Var2;
  
  while (__x != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(__x->super__Rb_tree_node_base)._M_right);
    _Var1 = (__x->_M_value_field).second._M_t.
            super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_>;
    p_Var2 = (_Link_type)(__x->super__Rb_tree_node_base)._M_left;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)
                 0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long)_Var1 + 4) = 0;
      if (*(void **)((long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 8));
        *(undefined8 *)((long)_Var1 + 8) = 0;
      }
      if (*(void **)((long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 0x10));
        *(undefined8 *)((long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (__x->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_> =
         (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
    rea_operator_delete(__x);
    __x = p_Var2;
  }
  return;
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
// IDX 103  00105560  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_____find
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_____find(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, basic_string_char__std__char_traits_char__std__allocator_char_ * __k)
{
  _Rb_tree_node_base *p_Var1;
  _Base_ptr *pp_Var2;
  _Base_ptr p_Var3;
  char *__s2;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  _Base_ptr p_Var9;
  _Base_ptr p_Var10;
  
  p_Var1 = &(this_ptr->_M_impl)._M_header;
  p_Var3 = (this_ptr->_M_impl)._M_header._M_parent;
  if (p_Var3 != (_Base_ptr)0x0) {
    __s2 = (__k->_M_dataplus)._M_p;
    uVar4 = *(ulong *)(__s2 + -0x18);
    p_Var9 = p_Var1;
    do {
      while( true ) {
        p_Var10 = p_Var3;
        uVar5 = *(ulong *)((long)*(void **)(p_Var10 + 1) + -0x18);
        uVar7 = uVar5;
        if (uVar4 <= uVar5) {
          uVar7 = uVar4;
        }
        iVar6 = rea_memcmp(*(void **)(p_Var10 + 1),__s2,uVar7);
        if (iVar6 != 0) break;
        lVar8 = uVar5 - uVar4;
        if (0x7fffffff < lVar8) goto LAB_0010d216;
        if (-0x80000001 < lVar8) {
          iVar6 = (int)lVar8;
          break;
        }
LAB_0010d255:
        pp_Var2 = &p_Var10->_M_right;
        p_Var3 = *pp_Var2;
        p_Var10 = p_Var9;
        if (*pp_Var2 == (_Base_ptr)0x0) goto LAB_0010d25e;
      }
      if (iVar6 < 0) goto LAB_0010d255;
LAB_0010d216:
      p_Var3 = p_Var10->_M_left;
      p_Var9 = p_Var10;
    } while (p_Var10->_M_left != (_Base_ptr)0x0);
LAB_0010d25e:
    if (p_Var1 == p_Var10) {
      return (iterator)p_Var1;
    }
    uVar5 = *(ulong *)((long)*(void **)(p_Var10 + 1) + -0x18);
    uVar7 = uVar5;
    if (uVar4 <= uVar5) {
      uVar7 = uVar4;
    }
    iVar6 = rea_memcmp(__s2,*(void **)(p_Var10 + 1),uVar7);
    if (iVar6 == 0) {
      lVar8 = uVar4 - uVar5;
      if (0x7fffffff < lVar8) {
        return (iterator)p_Var10;
      }
      if (lVar8 < -0x80000000) {
        return (iterator)p_Var1;
      }
      iVar6 = (int)lVar8;
    }
    if (-1 < iVar6) {
      return (iterator)p_Var10;
    }
  }
  return (iterator)p_Var1;
}





// ------------------------------------------------------------------
// IDX 104  00105570  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_hint_unique_pos(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, const_iterator __position, key_type * __k)
{
  int iVar1;
  _Base_ptr p_Var2;
  const_iterator cVar3;
  const_iterator cVar4;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar5;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar6;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar7;
  
  if (__position._M_node == &(this_ptr->_M_impl)._M_header) {
    if (((this_ptr->_M_impl)._M_node_count == 0) ||
       (cVar3._M_node = (this_ptr->_M_impl)._M_header._M_right, *__k <= (int)cVar3._M_node[1]._M_color))
    {
LAB_0010d528:
      pVar7 = _M_get_insert_unique_pos(this_ptr,__k);
      return pVar7;
    }
  }
  else {
    iVar1 = *__k;
    if (iVar1 < (int)__position._M_node[1]._M_color) {
      cVar4._M_node = (this_ptr->_M_impl)._M_header._M_left;
      cVar3._M_node = cVar4._M_node;
      if (cVar4._M_node != __position._M_node) {
        cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_decrement(__position._M_node);
        if (iVar1 <= (int)cVar3._M_node[1]._M_color) goto LAB_0010d528;
        cVar4._M_node = (_Base_ptr)0x0;
        if ((cVar3._M_node)->_M_right != (_Base_ptr)0x0) {
          cVar4._M_node = __position._M_node;
          cVar3._M_node = __position._M_node;
        }
      }
      goto LAB_0010d4c5;
    }
    if (iVar1 <= (int)__position._M_node[1]._M_color) {
      pVar7.second = (_Rb_tree_node_base *)0x0;
      pVar7.first = __position._M_node;
      return pVar7;
    }
    cVar3._M_node = (this_ptr->_M_impl)._M_header._M_right;
    if (cVar3._M_node != __position._M_node) {
      cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_increment(__position._M_node);
      if (iVar1 < (int)cVar3._M_node[1]._M_color) {
        p_Var2 = cVar3._M_node;
        if ((__position._M_node)->_M_right == (_Base_ptr)0x0) {
          cVar3._M_node = __position._M_node;
          p_Var2 = (_Base_ptr)0x0;
        }
        pVar6.second = cVar3._M_node;
        pVar6.first = p_Var2;
        return pVar6;
      }
      goto LAB_0010d528;
    }
  }
  cVar4._M_node = (_Base_ptr)0x0;
LAB_0010d4c5:
  pVar5.second = cVar3._M_node;
  pVar5.first = cVar4._M_node;
  return pVar5;
}





// ------------------------------------------------------------------
// IDX 105  00105580  std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______vector
// ------------------------------------------------------------------
void rea_std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______vector(vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___ * this_ptr, int __in_chrg)
{
  int *piVar1;
  char *pcVar2;
  undefined *puVar3;
  int iVar4;
  pointer pbVar5;
  pointer pbVar6;
  
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
  pbVar6 = (this_ptr->
           super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
           )._M_impl._M_finish;
  pbVar5 = (this_ptr->
           super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
           )._M_impl._M_start;
  if (pbVar6 != pbVar5) {
    do {
      pcVar2 = (pbVar5->_M_dataplus)._M_p;
      if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar3) {
        piVar1 = (int *)(pcVar2 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
          iVar4 = *(int *)(pcVar2 + -8);
          *(int *)(pcVar2 + -8) = iVar4 + -1;
        }
        else {
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar4 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
        }
      }
      pbVar5 = pbVar5 + 1;
    } while (pbVar6 != pbVar5);
    pbVar6 = (this_ptr->
             super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
             )._M_impl._M_start;
  }
  if (pbVar6 != (pointer)0x0) {
    rea_operator_delete(pbVar6);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 106  00105590  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_erase(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * this_ptr, _Link_type __x)
{
  int *piVar1;
  pointer pdVar2;
  _Link_type p_Var3;
  char *pcVar4;
  undefined *puVar5;
  int iVar6;
  
  puVar5 = PTR__S_empty_rep_storage_00311ff0;
  while (__x != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(__x->super__Rb_tree_node_base)._M_right);
    pdVar2 = (__x->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
             _M_impl._M_start;
    p_Var3 = (_Link_type)(__x->super__Rb_tree_node_base)._M_left;
    if (pdVar2 != (pointer)0x0) {
      rea_operator_delete(pdVar2);
    }
    pcVar4 = (__x->_M_value_field).first._M_dataplus._M_p;
    if ((allocator *)(pcVar4 + -0x18) != (allocator *)puVar5) {
      piVar1 = (int *)(pcVar4 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar6 = *(int *)(pcVar4 + -8);
        *(int *)(pcVar4 + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(pcVar4 + -0x18));
      }
    }
    rea_operator_delete(__x);
    __x = p_Var3;
  }
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
// IDX 114  00105610  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_hint_unique_pos(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, const_iterator __position, key_type * __k)
{
  int iVar1;
  _Base_ptr p_Var2;
  const_iterator cVar3;
  const_iterator cVar4;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar5;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar6;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar7;
  
  if (__position._M_node == &(this_ptr->_M_impl)._M_header) {
    if (((this_ptr->_M_impl)._M_node_count == 0) ||
       (cVar3._M_node = (this_ptr->_M_impl)._M_header._M_right, *__k <= (int)cVar3._M_node[1]._M_color))
    {
LAB_0010da18:
      pVar7 = _M_get_insert_unique_pos(this_ptr,__k);
      return pVar7;
    }
  }
  else {
    iVar1 = *__k;
    if (iVar1 < (int)__position._M_node[1]._M_color) {
      cVar4._M_node = (this_ptr->_M_impl)._M_header._M_left;
      cVar3._M_node = cVar4._M_node;
      if (cVar4._M_node != __position._M_node) {
        cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_decrement(__position._M_node);
        if (iVar1 <= (int)cVar3._M_node[1]._M_color) goto LAB_0010da18;
        cVar4._M_node = (_Base_ptr)0x0;
        if ((cVar3._M_node)->_M_right != (_Base_ptr)0x0) {
          cVar4._M_node = __position._M_node;
          cVar3._M_node = __position._M_node;
        }
      }
      goto LAB_0010d9b5;
    }
    if (iVar1 <= (int)__position._M_node[1]._M_color) {
      pVar7.second = (_Rb_tree_node_base *)0x0;
      pVar7.first = __position._M_node;
      return pVar7;
    }
    cVar3._M_node = (this_ptr->_M_impl)._M_header._M_right;
    if (cVar3._M_node != __position._M_node) {
      cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_increment(__position._M_node);
      if (iVar1 < (int)cVar3._M_node[1]._M_color) {
        p_Var2 = cVar3._M_node;
        if ((__position._M_node)->_M_right == (_Base_ptr)0x0) {
          cVar3._M_node = __position._M_node;
          p_Var2 = (_Base_ptr)0x0;
        }
        pVar6.second = cVar3._M_node;
        pVar6.first = p_Var2;
        return pVar6;
      }
      goto LAB_0010da18;
    }
  }
  cVar4._M_node = (_Base_ptr)0x0;
LAB_0010d9b5:
  pVar5.second = cVar3._M_node;
  pVar5.first = cVar4._M_node;
  return pVar5;
}





// ------------------------------------------------------------------
// IDX 115  00105620  SecInfo__SecInfo
// ------------------------------------------------------------------
void rea_SecInfo__SecInfo(SecInfo * this_ptr)
{
  undefined4 *puVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  FILE *__stream;
  size_t sVar5;
  void *pvVar6;
  ulong uVar7;
  allocator aaStack_3a [2];
  string asStack_38 [3];
  
  puVar2 = PTR_data_00311fc8;
  if (*(long *)PTR_data_00311fc8 != 0) goto LAB_0010728a;
  rea_std__string__string(asStack_38,"SecInfo.dump",aaStack_3a);
  piVar4 = rea_operator_new(0x18);
  *piVar4 = 0;
  piVar4[1] = 0;
  piVar4[2] = 0;
  piVar4[3] = 0;
  piVar4[4] = 0;
  piVar4[5] = 0;
  __stream = rea_open_file(asStack_38);
  if (__stream != (FILE *)0x0) {
    sVar5 = rea_fread(piVar4,4,1,(FILE *)__stream);
    if ((sVar5 == 1) && (sVar5 = rea_fread(piVar4 + 1,4,1,(FILE *)__stream), sVar5 == 1)) {
      uVar7 = 0xffffffffffffffff;
      if ((ulong)(long)*piVar4 < 0x550000000000001) {
        uVar7 = (long)*piVar4 * 0x18;
      }
      pvVar6 = rea_operator_new(uVar7);
      *(void **)(piVar4 + 2) = pvVar6;
      uVar7 = 0xffffffffffffffff;
      if ((ulong)(long)piVar4[1] < 0x550000000000001) {
        uVar7 = (long)piVar4[1] * 0x18;
      }
      pvVar6 = rea_operator_new(uVar7);
      *(void **)(piVar4 + 4) = pvVar6;
      sVar5 = rea_fread(*(void **)(piVar4 + 2),0x18,(long)*piVar4,(FILE *)__stream);
      if ((sVar5 != (long)*piVar4) ||
         (sVar5 = rea_fread(*(void **)(piVar4 + 4),0x18,(long)piVar4[1],(FILE *)__stream),
         sVar5 != (long)piVar4[1])) goto LAB_00107312;
    }
    else {
LAB_00107312:
      *piVar4 = 0;
      piVar4[1] = 0;
      if (*(void **)(piVar4 + 2) != (void *)0x0) {
        rea_operator_delete(*(void **)(piVar4 + 2));
        piVar4[2] = 0;
        piVar4[3] = 0;
      }
      if (*(void **)(piVar4 + 4) != (void *)0x0) {
        rea_operator_delete(*(void **)(piVar4 + 4));
        piVar4[4] = 0;
        piVar4[5] = 0;
      }
    }
    rea_fclose((FILE *)__stream);
  }
  puVar1 = *(undefined4 **)puVar2;
  *(int **)puVar2 = piVar4;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    if (*(void **)(puVar1 + 2) != (void *)0x0) {
      rea_operator_delete(*(void **)(puVar1 + 2));
      *(undefined8 *)(puVar1 + 2) = 0;
    }
    if (*(void **)(puVar1 + 4) != (void *)0x0) {
      rea_operator_delete(*(void **)(puVar1 + 4));
      *(undefined8 *)(puVar1 + 4) = 0;
    }
    rea_operator_delete(puVar1);
  }
  if ((allocator *)((long)asStack_38[0]._M_dataplus._M_p + -0x18) !=
      (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar4 = (int *)((long)asStack_38[0]._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
      iVar3 = *(int *)((long)asStack_38[0]._M_dataplus._M_p + -8);
      *(int *)((long)asStack_38[0]._M_dataplus._M_p + -8) = iVar3 + -1;
    }
    else {
      LOCK();
      iVar3 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
    }
    if (iVar3 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long)asStack_38[0]._M_dataplus._M_p + -0x18));
    }
  }
LAB_0010728a:
  this_ptr->no_check = false;
  return;
}





// ------------------------------------------------------------------
// IDX 116  00105630  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_copy
// ------------------------------------------------------------------
_Link_type rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_copy(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, _Const_Link_type __x, _Link_type __p)
{
  _Rb_tree_color _Var1;
  _Const_Link_type p_Var2;
  _Base_ptr p_Var3;
  _Link_type __p_00;
  _Link_type p_Var4;
  _Link_type __p_01;
  
  __p_00 = rea_operator_new(0x30);
  if (__p_00 != (_Link_type)0x0) {
    (__p_00->super__Rb_tree_node_base)._M_color = _S_red;
    (__p_00->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    rea_std__string__string(&__p_00->_M_value_field,&(__x->_M_value_field).first);
    (__p_00->_M_value_field).second = (__x->_M_value_field).second;
  }
  _Var1 = (__x->super__Rb_tree_node_base)._M_color;
  (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
  p_Var2 = (_Const_Link_type)(__x->super__Rb_tree_node_base)._M_right;
  (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
  (__p_00->super__Rb_tree_node_base)._M_parent = &__p->super__Rb_tree_node_base;
  (__p_00->super__Rb_tree_node_base)._M_color = _Var1;
  if (p_Var2 != (_Const_Link_type)0x0) {
    p_Var4 = _M_copy(this_ptr,p_Var2,__p_00);
    (__p_00->super__Rb_tree_node_base)._M_right = &p_Var4->super__Rb_tree_node_base;
  }
  p_Var4 = __p_00;
  for (p_Var3 = (__x->super__Rb_tree_node_base)._M_left; p_Var3 != (_Base_ptr)0x0;
      p_Var3 = p_Var3->_M_left) {
    __p_01 = rea_operator_new(0x30);
    if (__p_01 != (_Link_type)0x0) {
      (__p_01->super__Rb_tree_node_base)._M_color = _S_red;
      (__p_01->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
      (__p_01->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
      (__p_01->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
      rea_std__string__string(&__p_01->_M_value_field,(string *)(p_Var3 + 1));
      (__p_01->_M_value_field).second = (double)p_Var3[1]._M_parent;
    }
    _Var1 = p_Var3->_M_color;
    (__p_01->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    p_Var2 = (_Const_Link_type)p_Var3->_M_right;
    (__p_01->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__p_01->super__Rb_tree_node_base)._M_color = _Var1;
    (p_Var4->super__Rb_tree_node_base)._M_left = &__p_01->super__Rb_tree_node_base;
    (__p_01->super__Rb_tree_node_base)._M_parent = &p_Var4->super__Rb_tree_node_base;
    if (p_Var2 != (_Const_Link_type)0x0) {
      p_Var4 = _M_copy(this_ptr,p_Var2,__p_01);
      (__p_01->super__Rb_tree_node_base)._M_right = &p_Var4->super__Rb_tree_node_base;
    }
    p_Var4 = __p_01;
  }
  return __p_00;
}





// ------------------------------------------------------------------
// IDX 117  00105640  __gnu_cxx____to_xstring_std__basic_string_char__char
// ------------------------------------------------------------------
basic_string_char__std__char_traits_char__std__allocator_char_ rea___gnu_cxx____to_xstring_std__basic_string_char__char(code * __convf, size_t __n, char * __fmt, undefined8 param_x3)
{
  undefined8 stack0x00000008;
  undefined1 *__src;
  long lVar1;
  char in_AL;
  int iVar2;
  ulong *puVar3;
  ulong *__dest;
  undefined8 in_RCX;
  undefined8 in_R8;
  undefined8 in_R9;
  ulong __n_00;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM1_Qa;
  undefined8 in_XMM2_Qa;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM4_Qa;
  undefined8 in_XMM5_Qa;
  undefined8 in_XMM6_Qa;
  undefined8 in_XMM7_Qa;
  undefined8 uStack_100;
  allocator aStack_f1;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined1 *puStack_e8;
  undefined1 *puStack_e0;
  undefined1 auStack_d8 [32];
  undefined8 uStack_b8;
  undefined8 uStack_b0;
  undefined8 uStack_a8;
  undefined8 uStack_98;
  undefined8 uStack_88;
  undefined8 uStack_78;
  undefined8 uStack_68;
  undefined8 uStack_58;
  undefined8 uStack_48;
  undefined8 uStack_38;
  
  if (in_AL != '\0') {
    uStack_a8 = in_XMM0_Qa;
    uStack_98 = in_XMM1_Qa;
    uStack_88 = in_XMM2_Qa;
    uStack_78 = in_XMM3_Qa;
    uStack_68 = in_XMM4_Qa;
    uStack_58 = in_XMM5_Qa;
    uStack_48 = in_XMM6_Qa;
    uStack_38 = in_XMM7_Qa;
  }
  puStack_e8 = (void *)&stack0x00000008;
  lVar1 = -((ulong)(__fmt + 0x1e) & 0xfffffffffffffff0);
  puStack_e0 = auStack_d8;
  __src = (undefined1 *)((long)&uStack_f0 + lVar1);
  uStack_f0 = 0x20;
  uStack_ec = 0x30;
  uStack_b8 = in_R8;
  uStack_b0 = in_R9;
  *(undefined8 *)((long)&uStack_100 + lVar1) = 0x10c604;
  iVar2 = (*(code *)__n)(__src,__fmt,in_RCX,&uStack_f0);
  if (__src == __src + iVar2) {
    __dest = (ulong *)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
  }
  else {
    __n_00 = (long)(__src + iVar2) - (long)__src;
    *(undefined8 *)((long)&uStack_100 + lVar1) = 0x10c623;
    puVar3 = (ulong *)rea_std__string___Rep___S_create(__n_00,0,&aStack_f1);
    __dest = puVar3 + 3;
    if (__n_00 == 1) {
      *(undefined1 *)(puVar3 + 3) = *__src;
    }
    else {
      *(undefined8 *)((long)&uStack_100 + lVar1) = 0x10c63e;
      __dest = rea_memcpy(__dest,__src,__n_00);
    }
    if (puVar3 != (ulong *)PTR__S_empty_rep_storage_00311ff0) {
      *(undefined4 *)(puVar3 + 2) = 0;
      *puVar3 = __n_00;
      *(undefined1 *)((long)puVar3 + __n_00 + 0x18) = 0;
    }
  }
  *(ulong **)__convf = __dest;
  return (basic_string_char__std__char_traits_char__std__allocator_char_)(_Alloc_hider)__convf;
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
// IDX 125  00105850  __do_global_dtors_aux
// ------------------------------------------------------------------
void rea___do_global_dtors_aux(void)
{
  if (completed_6355 == '\0') {
    if (PTR___cxa_finalize_00311fb8 != (undefined *)0x0) {
      rea___cxa_finalize((void *)&__dso_handle);
    }
    rea_deregister_tm_clones();
    completed_6355 = '\x01';
  }
  return;
}





// ------------------------------------------------------------------
// IDX 126  00105890  frame_dummy
// ------------------------------------------------------------------
void rea_frame_dummy(void)
{
  if ((__JCR_END__ != 0) && (PTR__Jv_RegisterClasses_00311f80 != (undefined *)0x0)) {
    (*(code *)PTR__Jv_RegisterClasses_00311f80)((void *)&__JCR_END__);
    rea_register_tm_clones();
    return;
  }
  rea_register_tm_clones();
  return;
}





// ------------------------------------------------------------------
// IDX 127  001058d0  open_file
// ------------------------------------------------------------------
FILE * rea_open_file(string * path)
{
  int *piVar1;
  char *pcVar2;
  long *plVar3;
  FILE *pFVar4;
  int iVar5;
  allocator *paVar6;
  allocator local_4a [2];
  long local_48 [2];
  string local_38 [3];
  
                    /* Unresolved local var: char * prefix@[???]
                       Unresolved local var: FILE * fp@[???] */
  pcVar2 = rea_getenv("SECINFO_PREFIX");
  paVar6 = (allocator *)PTR__S_empty_rep_storage_00311ff0;
  if (pcVar2 != (char *)0x0) {
    rea_std__string__string(local_48,pcVar2,local_4a);
    plVar3 = (long *)rea_std__string__append((char *)local_48,0x10fb8d);
    paVar6 = (allocator *)PTR__S_empty_rep_storage_00311ff0;
    local_38[0]._M_dataplus._M_p = (_Alloc_hider)*plVar3;
    *plVar3 = (long)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    plVar3 = (long *)rea_std__string__append(local_38);
    pcVar2 = (char *)*plVar3;
    *plVar3 = (long)(paVar6 + 0x18);
    pFVar4 = rea_fopen(pcVar2,"rb");
    if ((allocator *)(pcVar2 + -0x18) != paVar6) {
      piVar1 = (int *)(pcVar2 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar5 = *(int *)(pcVar2 + -8);
        *(int *)(pcVar2 + -8) = iVar5 + -1;
      }
      else {
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar5 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
      }
    }
    if ((allocator *)((long)local_38[0]._M_dataplus._M_p + -0x18) != paVar6) {
      piVar1 = (int *)((long)local_38[0]._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar5 = *(int *)((long)local_38[0]._M_dataplus._M_p + -8);
        *(int *)((long)local_38[0]._M_dataplus._M_p + -8) = iVar5 + -1;
      }
      else {
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar5 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long)local_38[0]._M_dataplus._M_p + -0x18));
      }
    }
    if ((allocator *)(local_48[0] + -0x18) != paVar6) {
      piVar1 = (int *)(local_48[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar5 = *(int *)(local_48[0] + -8);
        *(int *)(local_48[0] + -8) = iVar5 + -1;
      }
      else {
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar5 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_48[0] + -0x18));
      }
    }
    if (pFVar4 != (FILE *)0x0) {
      return (FILE *)pFVar4;
    }
  }
                    /* Unresolved local var: __size_type __len@[???]
                       Unresolved local var: __string_type __str@[???] */
  local_38[0]._M_dataplus._M_p = (_Alloc_hider)(paVar6 + 0x18);
  rea_std__string__reserve((ulong)local_38);
  rea_std__string__append((char *)local_38,0x10fb7a);
  rea_std__string__append(local_38);
  pFVar4 = rea_fopen((char *)local_38[0]._M_dataplus._M_p,"rb");
  if ((allocator *)((long)local_38[0]._M_dataplus._M_p + -0x18) != paVar6) {
    paVar6 = (allocator *)((long)local_38[0]._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg2(RCX)] */
      iVar5 = *(int *)((long)local_38[0]._M_dataplus._M_p + -8);
      *(int *)((long)local_38[0]._M_dataplus._M_p + -8) = iVar5 + -1;
    }
    else {
      LOCK();
      iVar5 = *(int *)paVar6;
      *(int *)paVar6 = *(int *)paVar6 + -1;
      UNLOCK();
    }
    if (iVar5 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long)local_38[0]._M_dataplus._M_p + -0x18));
    }
  }
  return (FILE *)pFVar4;
}





// ------------------------------------------------------------------
// IDX 128  00105bb0  SecInfo__getPreClosePrice
// ------------------------------------------------------------------
double rea_SecInfo__getPreClosePrice__dup2(SecInfo * this_ptr, string * gid, int date)
{
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  long lVar5;
  int iVar6;
  size_t __n;
  long lVar7;
  int *piVar8;
  long lVar9;
  GIDKey key;
  Index idx;
  
                    /* Unresolved local var: Index * idx@[???] */
  piVar8 = *(int **)PTR_data_00311fc8;
                    /* Unresolved local var: ulong pos@[???] */
  if (*(ulong *)((gid->_M_dataplus)._M_p + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar4 = (gid->_M_dataplus)._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar4 + -0x18);
    }
    rea_memcpy(&key,pcVar4,__n);
    lVar7 = (long)*piVar8;
    key.gid[__n] = '\0';
                    /* Unresolved local var: Index * it@[???] */
    pcVar4 = *(char **)(piVar8 + 2);
    idx.start = 0;
    idx.size = 0;
                    /* Unresolved local var: _DistanceType __len@[???] */
    pcVar1 = pcVar4 + lVar7 * 0x18;
    for (; 0 < lVar7; lVar7 = (lVar7 - lVar9) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Index * __middle@[???] */
        lVar9 = lVar7 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */
        iVar6 = rea_strcmp(pcVar4 + lVar9 * 0x18,(char *)&idx);
        if (iVar6 < 0) break;
        lVar7 = lVar9;
        if (lVar9 == 0) goto LAB_00105cab;
      }
      pcVar4 = pcVar4 + lVar9 * 0x18 + 0x18;
    }
LAB_00105cab:
    if (((pcVar1 != pcVar4) && (iVar6 = rea_strcmp(pcVar4,(char *)&idx), iVar6 == 0)) &&
       (pcVar4 != (char *)0x0)) {
                    /* Unresolved local var: Item * item@[???]
                       Unresolved local var: Item key@[???]
                       Unresolved local var: Item * begin@[???]
                       Unresolved local var: Item * end@[???]
                       Unresolved local var: Item * it@[???] */
      piVar8 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      (long)*(int *)(pcVar4 + 0x10) * 0x18);
      piVar2 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      ((long)*(int *)(pcVar4 + 0x10) + (long)*(int *)(pcVar4 + 0x14)) * 0x18);
                    /* Unresolved local var: _DistanceType __len@[???] */
      for (lVar7 = ((long)piVar2 - (long)piVar8 >> 3) * -0x5555555555555555; 0 < lVar7;
          lVar7 = (lVar7 - lVar5) + -1) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Item * __middle@[???] */
                    /* Unresolved local var: difference_type __d@[???] */
        piVar3 = piVar8 + (lVar7 >> 1) * 6;
        iVar6 = *piVar3;
        lVar9 = lVar7 >> 1;
        while (lVar5 = lVar9, date <= iVar6) {
          if (lVar5 == 0) goto LAB_00105d4a;
          piVar3 = piVar8 + (lVar5 >> 1) * 6;
          lVar9 = lVar5 >> 1;
          lVar7 = lVar5;
          iVar6 = *piVar3;
        }
        piVar8 = piVar3 + 6;
      }
LAB_00105d4a:
      if ((piVar8 != piVar2) && (date == *piVar8)) {
        return *(double *)(piVar8 + 2);
      }
    }
  }
  return DAT_0010fd10;
}





// ------------------------------------------------------------------
// IDX 129  00105db0  SecInfo__getLastClosePrice
// ------------------------------------------------------------------
double rea_SecInfo__getLastClosePrice__dup2(SecInfo * this_ptr, string * gid, int date)
{
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  long lVar4;
  int iVar5;
  size_t __n;
  long lVar6;
  int *piVar7;
  char *pcVar8;
  long lVar9;
  double dVar10;
  GIDKey key;
  Index idx;
  
                    /* Unresolved local var: double preclose@[???] */
  dVar10 = rea_getPreClosePrice(this_ptr,gid,date);
                    /* Unresolved local var: Index * idx@[???] */
                    /* Unresolved local var: ulong pos@[???] */
  if ((NAN(dVar10)) &&
     (piVar7 = *(int **)PTR_data_00311fc8, dVar10 = DAT_0010fd10,
     *(ulong *)((gid->_M_dataplus)._M_p + -0x18) < 0x10)) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar8 = (gid->_M_dataplus)._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar8 + -0x18);
    }
    rea_memcpy(&key,pcVar8,__n);
    lVar6 = (long)*piVar7;
    key.gid[__n] = '\0';
                    /* Unresolved local var: Index * it@[???] */
    pcVar8 = *(char **)(piVar7 + 2);
    idx.start = 0;
    idx.size = 0;
    idx.key.gid[0] = key.gid[0];
    idx.key.gid[1] = key.gid[1];
    idx.key.gid[2] = key.gid[2];
    idx.key.gid[3] = key.gid[3];
    idx.key.gid[4] = key.gid[4];
    idx.key.gid[5] = key.gid[5];
    idx.key.gid[6] = key.gid[6];
    idx.key.gid[7] = key.gid[7];
                    /* Unresolved local var: _DistanceType __len@[???] */
    idx.key.gid[8] = key.gid[8];
    idx.key.gid[9] = key.gid[9];
    idx.key.gid[10] = key.gid[10];
    idx.key.gid[0xb] = key.gid[0xb];
    idx.key.gid[0xc] = key.gid[0xc];
    idx.key.gid[0xd] = key.gid[0xd];
    idx.key.gid[0xe] = key.gid[0xe];
    idx.key.gid[0xf] = key.gid[0xf];
    pcVar1 = pcVar8 + lVar6 * 0x18;
    for (; 0 < lVar6; lVar6 = (lVar6 - lVar9) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Index * __middle@[???] */
        lVar9 = lVar6 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */
        iVar5 = rea_strcmp(pcVar8 + lVar9 * 0x18,(char *)&idx);
        if (iVar5 < 0) break;
        lVar6 = lVar9;
        if (lVar9 == 0) goto LAB_00105ec0;
      }
      pcVar8 = pcVar8 + lVar9 * 0x18 + 0x18;
    }
LAB_00105ec0:
    dVar10 = DAT_0010fd10;
    if (((pcVar1 != pcVar8) &&
        (iVar5 = rea_strcmp(pcVar8,(char *)&idx), dVar10 = DAT_0010fd10, iVar5 == 0)) &&
       (pcVar8 != (char *)0x0)) {
                    /* Unresolved local var: Item * item@[???]
                       Unresolved local var: Item key@[???]
                       Unresolved local var: Item * begin@[???]
                       Unresolved local var: Item * end@[???]
                       Unresolved local var: Item * it@[???] */
      piVar2 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      (long)*(int *)(pcVar8 + 0x10) * 0x18);
                    /* Unresolved local var: _DistanceType __len@[???] */
      piVar7 = piVar2;
      for (lVar6 = ((*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                    ((long)*(int *)(pcVar8 + 0x10) + (long)*(int *)(pcVar8 + 0x14)) * 0x18) -
                    (long)piVar2 >> 3) * -0x5555555555555555; 0 < lVar6;
          lVar6 = (lVar6 - lVar4) + -1) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Item * __middle@[???] */
                    /* Unresolved local var: difference_type __d@[???] */
        piVar3 = piVar7 + (lVar6 >> 1) * 6;
        iVar5 = *piVar3;
        lVar9 = lVar6 >> 1;
        while (lVar4 = lVar9, date <= iVar5) {
          if (lVar4 == 0) goto LAB_00105f62;
          piVar3 = piVar7 + (lVar4 >> 1) * 6;
          lVar9 = lVar4 >> 1;
          lVar6 = lVar4;
          iVar5 = *piVar3;
        }
        piVar7 = piVar3 + 6;
      }
LAB_00105f62:
      if ((piVar7 != piVar2) && (piVar7 != (int *)0x18)) {
        dVar10 = *(double *)(piVar7 + -2);
      }
    }
  }
  return dVar10;
}





// ------------------------------------------------------------------
// IDX 130  00105fb0  SecInfo__getClosePrice
// ------------------------------------------------------------------
double rea_SecInfo__getClosePrice__dup2(SecInfo * this_ptr, string * gid, int date)
{
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  long lVar5;
  int iVar6;
  size_t __n;
  long lVar7;
  int *piVar8;
  long lVar9;
  GIDKey key;
  Index idx;
  
                    /* Unresolved local var: Index * idx@[???] */
  piVar8 = *(int **)PTR_data_00311fc8;
                    /* Unresolved local var: ulong pos@[???] */
  if (*(ulong *)((gid->_M_dataplus)._M_p + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar4 = (gid->_M_dataplus)._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar4 + -0x18);
    }
    rea_memcpy(&key,pcVar4,__n);
    lVar7 = (long)*piVar8;
    key.gid[__n] = '\0';
                    /* Unresolved local var: Index * it@[???] */
    pcVar4 = *(char **)(piVar8 + 2);
    idx.start = 0;
    idx.size = 0;
                    /* Unresolved local var: _DistanceType __len@[???] */
    pcVar1 = pcVar4 + lVar7 * 0x18;
    for (; 0 < lVar7; lVar7 = (lVar7 - lVar9) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Index * __middle@[???] */
        lVar9 = lVar7 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */
        iVar6 = rea_strcmp(pcVar4 + lVar9 * 0x18,(char *)&idx);
        if (iVar6 < 0) break;
        lVar7 = lVar9;
        if (lVar9 == 0) goto LAB_001060ab;
      }
      pcVar4 = pcVar4 + lVar9 * 0x18 + 0x18;
    }
LAB_001060ab:
    if (((pcVar1 != pcVar4) && (iVar6 = rea_strcmp(pcVar4,(char *)&idx), iVar6 == 0)) &&
       (pcVar4 != (char *)0x0)) {
                    /* Unresolved local var: Item * item@[???]
                       Unresolved local var: Item key@[???]
                       Unresolved local var: Item * begin@[???]
                       Unresolved local var: Item * end@[???]
                       Unresolved local var: Item * it@[???] */
      piVar8 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      (long)*(int *)(pcVar4 + 0x10) * 0x18);
      piVar2 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      ((long)*(int *)(pcVar4 + 0x10) + (long)*(int *)(pcVar4 + 0x14)) * 0x18);
                    /* Unresolved local var: _DistanceType __len@[???] */
      for (lVar7 = ((long)piVar2 - (long)piVar8 >> 3) * -0x5555555555555555; 0 < lVar7;
          lVar7 = (lVar7 - lVar5) + -1) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Item * __middle@[???] */
                    /* Unresolved local var: difference_type __d@[???] */
        piVar3 = piVar8 + (lVar7 >> 1) * 6;
        iVar6 = *piVar3;
        lVar9 = lVar7 >> 1;
        while (lVar5 = lVar9, date <= iVar6) {
          if (lVar5 == 0) goto LAB_0010614a;
          piVar3 = piVar8 + (lVar5 >> 1) * 6;
          lVar9 = lVar5 >> 1;
          lVar7 = lVar5;
          iVar6 = *piVar3;
        }
        piVar8 = piVar3 + 6;
      }
LAB_0010614a:
      if ((piVar8 != piVar2) && (date == *piVar8)) {
        return *(double *)(piVar8 + 4);
      }
    }
  }
  return DAT_0010fd10;
}





// ------------------------------------------------------------------
// IDX 131  001061b0  SecInfo__getPreDate
// ------------------------------------------------------------------
int rea_SecInfo__getPreDate__dup2(SecInfo * this_ptr, string * gid, int date)
{
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  long lVar7;
  int iVar8;
  size_t __n;
  long lVar9;
  int *piVar10;
  long lVar11;
  GIDKey key;
  Index idx;
  
                    /* Unresolved local var: Index * idx@[???] */
                    /* Unresolved local var: ulong pos@[???] */
  piVar10 = *(int **)PTR_data_00311fc8;
  iVar8 = 0;
  if (*(ulong *)((gid->_M_dataplus)._M_p + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar6 = (gid->_M_dataplus)._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar6 + -0x18);
    }
    rea_memcpy(&key,pcVar6,__n);
    lVar9 = (long)*piVar10;
    key.gid[__n] = '\0';
                    /* Unresolved local var: Index * it@[???] */
    pcVar6 = *(char **)(piVar10 + 2);
    idx.start = 0;
    idx.size = 0;
                    /* Unresolved local var: _DistanceType __len@[???] */
    pcVar1 = pcVar6 + lVar9 * 0x18;
    for (; 0 < lVar9; lVar9 = (lVar9 - lVar11) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Index * __middle@[???] */
        lVar11 = lVar9 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */
        iVar8 = rea_strcmp(pcVar6 + lVar11 * 0x18,(char *)&idx);
        if (iVar8 < 0) break;
        lVar9 = lVar11;
        if (lVar11 == 0) goto LAB_001062ab;
      }
      pcVar6 = pcVar6 + lVar11 * 0x18 + 0x18;
    }
LAB_001062ab:
    if ((pcVar1 == pcVar6) || (iVar8 = rea_strcmp(pcVar6,(char *)&idx), iVar8 != 0)) {
      return 0;
    }
    iVar8 = 0;
    if (pcVar6 != (char *)0x0) {
                    /* Unresolved local var: Item * item@[???]
                       Unresolved local var: Item key@[???]
                       Unresolved local var: Item * begin@[???]
                       Unresolved local var: Item * end@[???]
                       Unresolved local var: Item * it@[???] */
      piVar2 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      (long)*(int *)(pcVar6 + 0x10) * 0x18);
                    /* Unresolved local var: _DistanceType __len@[???] */
      piVar3 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      ((long)*(int *)(pcVar6 + 0x10) + (long)*(int *)(pcVar6 + 0x14)) * 0x18);
      piVar10 = piVar2;
      for (lVar9 = ((long)piVar3 - (long)piVar2 >> 3) * -0x5555555555555555; 0 < lVar9;
          lVar9 = (lVar9 - lVar7) + -1) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Item * __middle@[???] */
                    /* Unresolved local var: difference_type __d@[???] */
        piVar4 = piVar10 + (lVar9 >> 1) * 6;
        iVar5 = *piVar4;
        lVar11 = lVar9 >> 1;
        while (lVar7 = lVar11, date <= iVar5) {
          if (lVar7 == 0) goto LAB_00106352;
          piVar4 = piVar10 + (lVar7 >> 1) * 6;
          lVar11 = lVar7 >> 1;
          lVar9 = lVar7;
          iVar5 = *piVar4;
        }
        piVar10 = piVar4 + 6;
      }
LAB_00106352:
      if (((piVar10 != piVar3) && (date == *piVar10)) && (piVar2 <= piVar10 + -6)) {
        iVar8 = piVar10[-6];
      }
    }
  }
  return iVar8;
}





// ------------------------------------------------------------------
// IDX 132  001063c0  SecInfo__getNextDate
// ------------------------------------------------------------------
int rea_SecInfo__getNextDate(SecInfo * this_ptr, string * gid, int date)
{
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  long lVar6;
  int iVar7;
  size_t __n;
  long lVar8;
  int *piVar9;
  long lVar10;
  GIDKey key;
  Index idx;
  
                    /* Unresolved local var: Index * idx@[???] */
                    /* Unresolved local var: ulong pos@[???] */
  piVar9 = *(int **)PTR_data_00311fc8;
  iVar7 = 0;
  if (*(ulong *)((gid->_M_dataplus)._M_p + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar5 = (gid->_M_dataplus)._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar5 + -0x18);
    }
    rea_memcpy(&key,pcVar5,__n);
    lVar8 = (long)*piVar9;
    key.gid[__n] = '\0';
                    /* Unresolved local var: Index * it@[???] */
    pcVar5 = *(char **)(piVar9 + 2);
    idx.start = 0;
    idx.size = 0;
                    /* Unresolved local var: _DistanceType __len@[???] */
    pcVar1 = pcVar5 + lVar8 * 0x18;
    for (; 0 < lVar8; lVar8 = (lVar8 - lVar10) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Index * __middle@[???] */
        lVar10 = lVar8 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */
        iVar7 = rea_strcmp(pcVar5 + lVar10 * 0x18,(char *)&idx);
        if (iVar7 < 0) break;
        lVar8 = lVar10;
        if (lVar10 == 0) goto LAB_001064bb;
      }
      pcVar5 = pcVar5 + lVar10 * 0x18 + 0x18;
    }
LAB_001064bb:
    if ((pcVar1 == pcVar5) || (iVar7 = rea_strcmp(pcVar5,(char *)&idx), iVar7 != 0)) {
      return 0;
    }
    iVar7 = 0;
    if (pcVar5 != (char *)0x0) {
                    /* Unresolved local var: Item * item@[???]
                       Unresolved local var: Item key@[???]
                       Unresolved local var: Item * begin@[???]
                       Unresolved local var: Item * end@[???]
                       Unresolved local var: Item * it@[???] */
      piVar9 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      (long)*(int *)(pcVar5 + 0x10) * 0x18);
      piVar2 = (int *)(*(long *)(*(long *)PTR_data_00311fc8 + 0x10) +
                      ((long)*(int *)(pcVar5 + 0x10) + (long)*(int *)(pcVar5 + 0x14)) * 0x18);
                    /* Unresolved local var: _DistanceType __len@[???] */
      for (lVar8 = ((long)piVar2 - (long)piVar9 >> 3) * -0x5555555555555555; 0 < lVar8;
          lVar8 = (lVar8 - lVar6) + -1) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Item * __middle@[???] */
                    /* Unresolved local var: difference_type __d@[???] */
        piVar3 = piVar9 + (lVar8 >> 1) * 6;
        iVar4 = *piVar3;
        lVar10 = lVar8 >> 1;
        while (lVar6 = lVar10, date <= iVar4) {
          if (lVar6 == 0) goto LAB_0010655a;
          piVar3 = piVar9 + (lVar6 >> 1) * 6;
          lVar10 = lVar6 >> 1;
          lVar8 = lVar6;
          iVar4 = *piVar3;
        }
        piVar9 = piVar3 + 6;
      }
LAB_0010655a:
      if (((piVar9 != piVar2) && (date == *piVar9)) && (piVar9 + 6 < piVar2)) {
        iVar7 = piVar9[6];
      }
    }
  }
  return iVar7;
}





// ------------------------------------------------------------------
// IDX 133  001065c0  SecInfo__getRescale
// ------------------------------------------------------------------
double rea_SecInfo__getRescale__dup2(SecInfo * this_ptr, string * gid, int date)
{
  int date_00;
  double dVar1;
  double dVar2;
  
                    /* Unresolved local var: double preclose@[???]
                       Unresolved local var: int predate@[???]
                       Unresolved local var: double preclose0@[???] */
  dVar1 = rea_getPreClosePrice(this_ptr,gid,date);
  if (!NAN(dVar1)) {
    date_00 = getPreDate(this_ptr,gid,date);
    if (date_00 != 0) {
      dVar2 = rea_getClosePrice(this_ptr,gid,date_00);
      if (!NAN(dVar2)) {
        return dVar1 / dVar2;
      }
    }
  }
  return DAT_0010fd18;
}





// ------------------------------------------------------------------
// IDX 134  00106640  SecInfo__GroupsIterator__deref
// ------------------------------------------------------------------
char * rea_SecInfo__GroupsIterator__deref(GroupsIterator * this_ptr)
{
                    /* Unresolved local var: Index * idxs@[DW_OP_breg5(RDI): 0]
                       Unresolved local var: GroupBackwardItem * p@[DW_OP_breg5(RDI): +8] */
  return (char *)((long)(this_ptr->super_Iterator).idxbase +
                 (long)*(short *)((long)(this_ptr->super_Iterator).base +
                                 (long)(this_ptr->super_Iterator).curr * 2) * 0x18);
}





// ------------------------------------------------------------------
// IDX 135  00106660  SecInfo__Set_SecInfo__GroupsIterator__contains
// ------------------------------------------------------------------
bool rea_SecInfo__Set_SecInfo__GroupsIterator__contains(Set_SecInfo__GroupsIterator * this_ptr, char * member)
{
  int *piVar1;
  short *psVar2;
  short *psVar3;
  short sVar4;
  GroupData1 *pGVar5;
  Index *__s1;
  short sVar6;
  long lVar7;
  int iVar8;
  long lVar9;
  short *psVar10;
  long lVar11;
  Index *pIVar12;
  allocator local_79;
  char *local_78 [2];
  GroupKey key;
  Index idx;
  
  if ((this_ptr->data1 != (GroupData1 *)0x0) && (this_ptr->data2 != (GroupData2 *)0x0)) {
                    /* Unresolved local var: Index * group_idx@[???]
                       Unresolved local var: GroupBackwardItem key@[???]
                       Unresolved local var: GroupBackwardItem * begin@[???]
                       Unresolved local var: GroupBackwardItem * end@[???]
                       Unresolved local var: GroupBackwardItem * it@[???] */
    rea_std__string__string(local_78,member,&local_79);
    pGVar5 = this_ptr->data1;
    pIVar12 = (Index *)0x0;
    if (*(ulong *)(local_78[0] + -0x18) < 0x10) {
      rea_strcpy(key.group_name,local_78[0]);
      lVar9 = (long)(pGVar5->super_IndexedData<GroupKey,_GroupForwardItem>).num_idxs;
                    /* Unresolved local var: Index * it@[???] */
      __s1 = (pGVar5->super_IndexedData<GroupKey,_GroupForwardItem>).idxs;
      idx.start = 0;
      idx.size = 0;
                    /* Unresolved local var: _DistanceType __len@[???] */
      pIVar12 = __s1 + lVar9;
      for (; 0 < lVar9; lVar9 = (lVar9 - lVar11) + -1) {
        while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Index * __middle@[???] */
          lVar11 = lVar9 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */
          iVar8 = rea_strcmp((char *)(__s1 + lVar11),(char *)&idx);
          if (iVar8 < 0) break;
          lVar9 = lVar11;
          if (lVar11 == 0) goto LAB_00106753;
        }
        __s1 = __s1 + lVar11 + 1;
      }
LAB_00106753:
      if (__s1 == pIVar12) {
        pIVar12 = (Index *)0x0;
      }
      else {
        iVar8 = rea_strcmp((char *)__s1,(char *)&idx);
        pIVar12 = (Index *)0x0;
        if (iVar8 == 0) {
          pIVar12 = __s1;
        }
      }
    }
    if ((allocator *)(local_78[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar1 = (int *)(local_78[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg0(RAX)] */
        iVar8 = *(int *)(local_78[0] + -8);
        *(int *)(local_78[0] + -8) = iVar8 + -1;
      }
      else {
        LOCK();
        iVar8 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar8 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_78[0] + -0x18));
      }
    }
    if (pIVar12 != (Index *)0x0) {
      lVar9 = (long)this_ptr->size_;
      psVar10 = this_ptr->base;
                    /* Unresolved local var: _DistanceType __len@[???] */
      psVar2 = psVar10 + lVar9;
      sVar6 = (short)((long)pIVar12 -
                      (long)(this_ptr->data1->super_IndexedData<GroupKey,_GroupForwardItem>).idxs >> 3)
              * -0x5555;
      for (; 0 < lVar9; lVar9 = (lVar9 - lVar7) + -1) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: GroupBackwardItem * __middle@[???] */
                    /* Unresolved local var: difference_type __d@[???] */
        psVar3 = psVar10 + (lVar9 >> 1);
        sVar4 = *psVar3;
        lVar11 = lVar9 >> 1;
        while (lVar7 = lVar11, sVar6 <= sVar4) {
          if (lVar7 == 0) goto LAB_001067f7;
          psVar3 = psVar10 + (lVar7 >> 1);
          lVar11 = lVar7 >> 1;
          lVar9 = lVar7;
          sVar4 = *psVar3;
        }
        psVar10 = psVar3 + 1;
      }
LAB_001067f7:
      if (psVar2 != psVar10) {
        return sVar6 == *psVar10;
      }
    }
  }
  return false;
}





// ------------------------------------------------------------------
// IDX 136  00106890  SecInfo__MembersIterator__deref
// ------------------------------------------------------------------
char * rea_SecInfo__MembersIterator__deref(MembersIterator * this_ptr)
{
                    /* Unresolved local var: Index * idxs@[DW_OP_breg5(RDI): 0]
                       Unresolved local var: GroupForwardItem * p@[DW_OP_breg5(RDI): +8] */
  return (char *)((long)(this_ptr->super_Iterator).idxbase +
                 (long)*(int *)((long)(this_ptr->super_Iterator).base +
                               (long)(this_ptr->super_Iterator).curr * 0xc) * 0x18);
}





// ------------------------------------------------------------------
// IDX 137  001068b0  SecInfo__MembersIterator__getForecastWeight
// ------------------------------------------------------------------
double rea_SecInfo__MembersIterator__getForecastWeight(MembersIterator * this_ptr)
{
                    /* Unresolved local var: Index * idxs@[DW_OP_breg5(RDI): 0]
                       Unresolved local var: GroupForwardItem * p@[DW_OP_breg5(RDI): +8] */
  return (double)*(float *)((long)(this_ptr->super_Iterator).base +
                           (long)(this_ptr->super_Iterator).curr * 0xc + 4);
}





// ------------------------------------------------------------------
// IDX 138  001068d0  SecInfo__MembersIterator__getWeight
// ------------------------------------------------------------------
double rea_SecInfo__MembersIterator__getWeight(MembersIterator * this_ptr)
{
                    /* Unresolved local var: Index * idxs@[???]
                       Unresolved local var: GroupForwardItem * p@[???] */
  if (this_ptr->mask_eod_values == false) {
    return (double)*(float *)((long)(this_ptr->super_Iterator).base +
                             (long)(this_ptr->super_Iterator).curr * 0xc + 8);
  }
  return DAT_0010fd10;
}





// ------------------------------------------------------------------
// IDX 139  00106900  SecInfo__Set_SecInfo__MembersIterator__contains
// ------------------------------------------------------------------
bool rea_SecInfo__Set_SecInfo__MembersIterator__contains(Set_SecInfo__MembersIterator * this_ptr, char * member)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  GroupData2 *pGVar4;
  Index *__s1;
  long lVar5;
  int iVar6;
  size_t __n;
  long lVar7;
  Index *pIVar8;
  int *piVar9;
  long lVar10;
  void *local_98;
  allocator local_79;
  void *local_78 [2];
  GIDKey key;
  Index idx;
  
  if (this_ptr->data1 == (GroupData1 *)0x0) {
    return false;
  }
  if (this_ptr->data2 == (GroupData2 *)0x0) {
    return false;
  }
                    /* Unresolved local var: Index * gid_idx@[???]
                       Unresolved local var: GroupForwardItem key@[???]
                       Unresolved local var: GroupForwardItem * begin@[???]
                       Unresolved local var: GroupForwardItem * end@[???]
                       Unresolved local var: GroupForwardItem * it@[???] */
  rea_std__string__string(local_78,member,&local_79);
                    /* Unresolved local var: ulong pos@[???] */
  pGVar4 = this_ptr->data2;
  local_98 = local_78[0];
  if (*(ulong *)((long)local_78[0] + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)local_78,0x10fb8f,0);
    local_98 = local_78[0];
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)((long)local_78[0] + -0x18);
    }
    rea_memcpy(&key,local_78[0],__n);
    lVar7 = (long)(pGVar4->super_IndexedData<GIDKey,_GroupBackwardItem>).num_idxs;
    key.gid[__n] = '\0';
                    /* Unresolved local var: Index * it@[???] */
    __s1 = (pGVar4->super_IndexedData<GIDKey,_GroupBackwardItem>).idxs;
    idx.start = 0;
    idx.size = 0;
                    /* Unresolved local var: _DistanceType __len@[???] */
    pIVar8 = __s1 + lVar7;
    for (; 0 < lVar7; lVar7 = (lVar7 - lVar10) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Index * __middle@[???] */
        lVar10 = lVar7 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */
        iVar6 = rea_strcmp((char *)(__s1 + lVar10),(char *)&idx);
        if (iVar6 < 0) break;
        lVar7 = lVar10;
        if (lVar10 == 0) goto LAB_00106a2b;
      }
      __s1 = __s1 + lVar10 + 1;
    }
LAB_00106a2b:
    if (__s1 != pIVar8) {
      iVar6 = rea_strcmp((char *)__s1,(char *)&idx);
      pIVar8 = (Index *)0x0;
      if (iVar6 == 0) {
        pIVar8 = __s1;
      }
      goto LAB_00106a4b;
    }
  }
  pIVar8 = (Index *)0x0;
LAB_00106a4b:
  if ((allocator *)((long)local_98 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar9 = (int *)((long)local_98 + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg0(RAX)] */
      iVar6 = *(int *)((long)local_98 + -8);
      *(int *)((long)local_98 + -8) = iVar6 + -1;
    }
    else {
      LOCK();
      iVar6 = *piVar9;
      *piVar9 = *piVar9 + -1;
      UNLOCK();
    }
    if (iVar6 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long)local_98 + -0x18));
    }
  }
  if (pIVar8 != (Index *)0x0) {
    lVar7 = (long)this_ptr->size_;
    piVar9 = this_ptr->base;
                    /* Unresolved local var: _DistanceType __len@[???] */
    piVar1 = piVar9 + lVar7 * 3;
    iVar6 = (int)((long)pIVar8 -
                  (long)(this_ptr->data2->super_IndexedData<GIDKey,_GroupBackwardItem>).idxs >> 3) *
            -0x55555555;
    for (; 0 < lVar7; lVar7 = (lVar7 - lVar5) + -1) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: GroupForwardItem * __middle@[???] */
                    /* Unresolved local var: difference_type __d@[???] */
      piVar2 = piVar9 + (lVar7 >> 1) * 3;
      iVar3 = *piVar2;
      lVar10 = lVar7 >> 1;
      while (lVar5 = lVar10, iVar6 <= iVar3) {
        if (lVar5 == 0) goto LAB_00106ada;
        piVar2 = piVar9 + (lVar5 >> 1) * 3;
        lVar10 = lVar5 >> 1;
        lVar7 = lVar5;
        iVar3 = *piVar2;
      }
      piVar9 = piVar2 + 3;
    }
LAB_00106ada:
    if (piVar1 != piVar9) {
      return iVar6 == *piVar9;
    }
  }
  return false;
}





// ------------------------------------------------------------------
// IDX 140  00106ba0  pinot_open
// ------------------------------------------------------------------
void * rea_pinot_open__dup2(string file)
{
  undefined *puVar1;
  char *pcVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 *puVar5;
  void *pvVar6;
  long *plVar7;
  long lVar8;
  
  pcVar2 = *(char **)file._M_dataplus._M_p;
  puVar5 = rea_operator_new(8);
  if (pinot_reader_handle == (void *)0x0) {
                    /* Unresolved local var: void * l@[???] */
    pvVar6 = (void *)rea_dlopen("/opt/bbcluster/alpha/pinot/bin/libpinot_reader.so",2);
    if (pvVar6 != (void *)0x0) {
      pinot_reader_handle = pvVar6;
      pinot_reader_open = (code *)rea_dlsym(pvVar6,"pinot_reader_open");
      pinot_reader_close = (code *)rea_dlsym(pvVar6,"pinot_reader_close");
      pinot_reader_is_open = (code *)rea_dlsym(pvVar6,"pinot_reader_is_open");
      pinot_reader_getline = (code *)rea_dlsym(pvVar6,"pinot_reader_getline");
      pinot_reader_read = (code *)rea_dlsym(pvVar6,"pinot_reader_read");
    }
    if (pinot_reader_handle == (void *)0x0) {
      plVar7 = rea_operator_new(0x208);
      rea_std__ios_base__ios_base((ios_base *)(plVar7 + 0x20));
      puVar1 = PTR_vtable_00311f68;
      *(undefined1 *)(plVar7 + 0x3c) = 0;
      plVar7[0x3b] = 0;
      *(undefined1 *)((long)plVar7 + 0x1e1) = 0;
      plVar7[0x3d] = 0;
      plVar7[0x3e] = 0;
      plVar7[0x3f] = 0;
      plVar7[0x40] = 0;
      plVar7[0x20] = (long)(puVar1 + 0x10);
      lVar8 = *(long *)(PTR_VTT_00311fe0 + 8);
      uVar3 = *(undefined8 *)(PTR_VTT_00311fe0 + 0x10);
      lVar4 = *(long *)(lVar8 + -0x18);
      *plVar7 = lVar8;
      *(undefined8 *)((long)plVar7 + lVar4) = uVar3;
      plVar7[1] = 0;
      rea_std__ios__init((streambuf *)((long)plVar7 + *(long *)(lVar8 + -0x18)));
      puVar1 = PTR_vtable_00311fb0 + 0x18;
      plVar7[0x20] = (long)(PTR_vtable_00311fb0 + 0x40);
      *plVar7 = (long)puVar1;
      rea_std__filebuf__filebuf((filebuf *)(plVar7 + 2));
      rea_std__ios__init((streambuf *)(plVar7 + 0x20));
      lVar8 = rea_std__filebuf__open((char *)(plVar7 + 2),(_Ios_Openmode)pcVar2);
      if (lVar8 == 0) {
        rea_std__ios__clear((int)plVar7 + (int)*(undefined8 *)(*plVar7 + -0x18));
      }
      else {
        rea_std__ios__clear((int)plVar7 + (int)*(undefined8 *)(*plVar7 + -0x18));
      }
      *puVar5 = plVar7;
      return puVar5;
    }
  }
  pvVar6 = (*pinot_reader_open)(pcVar2);
  *puVar5 = pvVar6;
  return puVar5;
}





// ------------------------------------------------------------------
// IDX 141  00106e30  pinot_close
// ------------------------------------------------------------------
void rea_pinot_close__dup2(void * fp)
{
  long *plVar1;
  
  if (fp == (void *)0x0) {
    return;
  }
  plVar1 = *(long **)fp;
  if (pinot_reader_handle == (void *)0x0) {
    if (plVar1 != (long *)0x0) {
      (**(code **)(*plVar1 + 8))();
      rea_operator_delete(fp);
      return;
    }
  }
  else {
    (*pinot_reader_close)(plVar1);
  }
  rea_operator_delete(fp);
  return;
}





// ------------------------------------------------------------------
// IDX 142  00106e80  pinot_getline
// ------------------------------------------------------------------
pair_int__std__basic_string_char__std__char_traits_char__std__allocator_char__ rea_pinot_getline__dup2(void * fp)
{
  long *plVar1;
  undefined *puVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  istream *piVar6;
  undefined8 uVar7;
  _Alloc_hider extraout_RDX;
  _Alloc_hider extraout_RDX_00;
  basic_string_char__std__char_traits_char__std__allocator_char_ bVar8;
  undefined8 *in_RSI;
  pair_int__std__basic_string_char__std__char_traits_char__std__allocator_char__ pVar9;
  string line;
  
  puVar2 = PTR__S_empty_rep_storage_00311ff0;
                    /* Unresolved local var: int b@[???] */
  line._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
  if (pinot_reader_handle == (void *)0x0) {
    piVar6 = (istream *)*in_RSI;
    plVar1 = *(long **)(piVar6 + *(long *)(*(long *)piVar6 + -0x18) + 0xf0);
    if (plVar1 == (long *)0x0) {
      uVar7 = rea_std____throw_bad_cast();
      rea_std__string___Rep___M_dispose((allocator *)((long)line._M_dataplus._M_p + -0x18));
                    /* WARNING: Subroutine does not return */
      rea__Unwind_Resume(uVar7);
    }
    if ((char)plVar1[7] == '\0') {
      rea_std__ctype_char___M_widen_init();
      cVar4 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
    }
    else {
      cVar4 = *(char *)((long)plVar1 + 0x43);
    }
    piVar6 = rea_std__getline_char_std__char_traits_char_std__allocator_char(piVar6,&line,cVar4);
    bVar3 = ((byte)piVar6[*(long *)(*(long *)piVar6 + -0x18) + 0x20] & 5) == 0;
  }
  else {
    bVar3 = (*pinot_reader_getline)((void *)*in_RSI,&line);
  }
  *(uint *)fp = (uint)bVar3;
  rea_std__string__string((void *)((long)fp + 8),&line);
  bVar8._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)extraout_RDX._M_p;
  if ((allocator *)((long)line._M_dataplus._M_p + -0x18) != (allocator *)puVar2) {
    bVar8._M_dataplus._M_p = (_Alloc_hider)((long)line._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
      uVar5 = *(uint *)((long)line._M_dataplus._M_p + -8);
      bVar8._M_dataplus._M_p = (_Alloc_hider)(ulong)uVar5;
      *(uint *)((long)line._M_dataplus._M_p + -8) = uVar5 - 1;
    }
    else {
      LOCK();
      uVar5 = *(uint *)bVar8._M_dataplus._M_p;
      *(uint *)bVar8._M_dataplus._M_p = *(uint *)bVar8._M_dataplus._M_p - 1;
      UNLOCK();
    }
    if ((int)uVar5 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long)line._M_dataplus._M_p + -0x18));
      bVar8._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)extraout_RDX_00._M_p;
    }
  }
  pVar9.second._M_dataplus._M_p = bVar8._M_dataplus._M_p;
  (*(undefined8 *)((uint8_t *)&pVar9 + 0x0)) = fp;
  return pVar9;
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
// IDX 144  00106fe0  SecInfo__SecInfo
// ------------------------------------------------------------------
void rea_SecInfo__SecInfo__dup2(SecInfo * this_ptr, Mode m)
{
  undefined4 *puVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  FILE *__stream;
  size_t sVar5;
  void *pvVar6;
  ulong uVar7;
  allocator local_3a [2];
  string local_38 [3];
  
  puVar2 = PTR_data_00311fc8;
  if (*(long *)PTR_data_00311fc8 != 0) goto LAB_00106ffa;
  rea_std__string__string(local_38,"SecInfo.dump",local_3a);
  piVar4 = rea_operator_new(0x18);
  *piVar4 = 0;
  piVar4[1] = 0;
                    /* Unresolved local var: _IO_FILE * fp@[???] */
  piVar4[2] = 0;
  piVar4[3] = 0;
  piVar4[4] = 0;
  piVar4[5] = 0;
  __stream = rea_open_file(local_38);
  if (__stream != (FILE *)0x0) {
                    /* Unresolved local var: bool fail@[???] */
    sVar5 = rea_fread(piVar4,4,1,(FILE *)__stream);
    if ((sVar5 == 1) && (sVar5 = rea_fread(piVar4 + 1,4,1,(FILE *)__stream), sVar5 == 1)) {
      uVar7 = 0xffffffffffffffff;
      if ((ulong)(long)*piVar4 < 0x550000000000001) {
        uVar7 = (long)*piVar4 * 0x18;
      }
      pvVar6 = rea_operator_new(uVar7);
      *(void **)(piVar4 + 2) = pvVar6;
      uVar7 = 0xffffffffffffffff;
      if ((ulong)(long)piVar4[1] < 0x550000000000001) {
        uVar7 = (long)piVar4[1] * 0x18;
      }
      pvVar6 = rea_operator_new(uVar7);
      *(void **)(piVar4 + 4) = pvVar6;
      sVar5 = rea_fread(*(void **)(piVar4 + 2),0x18,(long)*piVar4,(FILE *)__stream);
      if ((sVar5 != (long)*piVar4) ||
         (sVar5 = rea_fread(*(void **)(piVar4 + 4),0x18,(long)piVar4[1],(FILE *)__stream),
         sVar5 != (long)piVar4[1])) goto LAB_00107082;
    }
    else {
LAB_00107082:
      *piVar4 = 0;
      piVar4[1] = 0;
      if (*(void **)(piVar4 + 2) != (void *)0x0) {
        rea_operator_delete(*(void **)(piVar4 + 2));
        piVar4[2] = 0;
        piVar4[3] = 0;
      }
      if (*(void **)(piVar4 + 4) != (void *)0x0) {
        rea_operator_delete(*(void **)(piVar4 + 4));
        piVar4[4] = 0;
        piVar4[5] = 0;
      }
    }
    rea_fclose((FILE *)__stream);
  }
                    /* Unresolved local var: Data * __tmp@[???] */
  puVar1 = *(undefined4 **)puVar2;
  *(int **)puVar2 = piVar4;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    if (*(void **)(puVar1 + 2) != (void *)0x0) {
      rea_operator_delete(*(void **)(puVar1 + 2));
      *(undefined8 *)(puVar1 + 2) = 0;
    }
    if (*(void **)(puVar1 + 4) != (void *)0x0) {
      rea_operator_delete(*(void **)(puVar1 + 4));
      *(undefined8 *)(puVar1 + 4) = 0;
    }
    rea_operator_delete(puVar1);
  }
  if ((allocator *)((long)local_38[0]._M_dataplus._M_p + -0x18) !=
      (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar4 = (int *)((long)local_38[0]._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
      iVar3 = *(int *)((long)local_38[0]._M_dataplus._M_p + -8);
      *(int *)((long)local_38[0]._M_dataplus._M_p + -8) = iVar3 + -1;
    }
    else {
      LOCK();
      iVar3 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
    }
    if (iVar3 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long)local_38[0]._M_dataplus._M_p + -0x18));
    }
  }
LAB_00106ffa:
  this_ptr->no_check = true;
  return;
}





// ------------------------------------------------------------------
// IDX 145  00107270  SecInfo__SecInfo
// ------------------------------------------------------------------
void rea_SecInfo__SecInfo__dup3(SecInfo * this_ptr)
{
  undefined4 *puVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  FILE *__stream;
  size_t sVar5;
  void *pvVar6;
  ulong uVar7;
  allocator local_3a [2];
  string local_38 [3];
  
  puVar2 = PTR_data_00311fc8;
  if (*(long *)PTR_data_00311fc8 != 0) goto LAB_0010728a;
  rea_std__string__string(local_38,"SecInfo.dump",local_3a);
  piVar4 = rea_operator_new(0x18);
  *piVar4 = 0;
  piVar4[1] = 0;
                    /* Unresolved local var: _IO_FILE * fp@[???] */
  piVar4[2] = 0;
  piVar4[3] = 0;
  piVar4[4] = 0;
  piVar4[5] = 0;
  __stream = rea_open_file(local_38);
  if (__stream != (FILE *)0x0) {
                    /* Unresolved local var: bool fail@[???] */
    sVar5 = rea_fread(piVar4,4,1,(FILE *)__stream);
    if ((sVar5 == 1) && (sVar5 = rea_fread(piVar4 + 1,4,1,(FILE *)__stream), sVar5 == 1)) {
      uVar7 = 0xffffffffffffffff;
      if ((ulong)(long)*piVar4 < 0x550000000000001) {
        uVar7 = (long)*piVar4 * 0x18;
      }
      pvVar6 = rea_operator_new(uVar7);
      *(void **)(piVar4 + 2) = pvVar6;
      uVar7 = 0xffffffffffffffff;
      if ((ulong)(long)piVar4[1] < 0x550000000000001) {
        uVar7 = (long)piVar4[1] * 0x18;
      }
      pvVar6 = rea_operator_new(uVar7);
      *(void **)(piVar4 + 4) = pvVar6;
      sVar5 = rea_fread(*(void **)(piVar4 + 2),0x18,(long)*piVar4,(FILE *)__stream);
      if ((sVar5 != (long)*piVar4) ||
         (sVar5 = rea_fread(*(void **)(piVar4 + 4),0x18,(long)piVar4[1],(FILE *)__stream),
         sVar5 != (long)piVar4[1])) goto LAB_00107312;
    }
    else {
LAB_00107312:
      *piVar4 = 0;
      piVar4[1] = 0;
      if (*(void **)(piVar4 + 2) != (void *)0x0) {
        rea_operator_delete(*(void **)(piVar4 + 2));
        piVar4[2] = 0;
        piVar4[3] = 0;
      }
      if (*(void **)(piVar4 + 4) != (void *)0x0) {
        rea_operator_delete(*(void **)(piVar4 + 4));
        piVar4[4] = 0;
        piVar4[5] = 0;
      }
    }
    rea_fclose((FILE *)__stream);
  }
                    /* Unresolved local var: Data * __tmp@[???] */
  puVar1 = *(undefined4 **)puVar2;
  *(int **)puVar2 = piVar4;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    if (*(void **)(puVar1 + 2) != (void *)0x0) {
      rea_operator_delete(*(void **)(puVar1 + 2));
      *(undefined8 *)(puVar1 + 2) = 0;
    }
    if (*(void **)(puVar1 + 4) != (void *)0x0) {
      rea_operator_delete(*(void **)(puVar1 + 4));
      *(undefined8 *)(puVar1 + 4) = 0;
    }
    rea_operator_delete(puVar1);
  }
  if ((allocator *)((long)local_38[0]._M_dataplus._M_p + -0x18) !=
      (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar4 = (int *)((long)local_38[0]._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
      iVar3 = *(int *)((long)local_38[0]._M_dataplus._M_p + -8);
      *(int *)((long)local_38[0]._M_dataplus._M_p + -8) = iVar3 + -1;
    }
    else {
      LOCK();
      iVar3 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
    }
    if (iVar3 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long)local_38[0]._M_dataplus._M_p + -0x18));
    }
  }
LAB_0010728a:
  this_ptr->no_check = false;
  return;
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





// ------------------------------------------------------------------
// IDX 150  00107600  SecInfo__find_data2
// ------------------------------------------------------------------
Data2 * rea_SecInfo__find_data2__dup2(SecInfo * this_ptr, int date)
{
  _Base_ptr *pp_Var1;
  int *piVar2;
  _Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_ this_00;
  undefined *this_01;
  undefined *puVar3;
  int iVar4;
  _Link_type p_Var5;
  iterator __position;
  long *plVar6;
  _Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_ _Var7;
  FILE *__stream;
  size_t sVar8;
  void *pvVar9;
  _Base_ptr p_Var10;
  _Base_ptr p_Var11;
  _Base_ptr p_Var12;
  _Base_ptr p_Var13;
  ulong uVar14;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar15;
  long local_68 [2];
  long local_58 [2];
  string local_48 [3];
  
  this_01 = PTR_data_store2_00311f70;
  p_Var12 = *(_Base_ptr *)(PTR_data_store2_00311f70 + 0x10);
                    /* Unresolved local var: iterator __j@[???] */
  if (p_Var12 == (_Base_ptr)0x0) {
LAB_00107720:
    rea___gnu_cxx____to_xstring_std__basic_string_char__char
              ((code *)
               local_68,(size_t)PTR_vsnprintf_00311fd0,(char *)0x10,(void *)&DAT_0010fc03,date);
    plVar6 = (long *)rea_std__string__insert((ulong)local_68,(char *)0x0,0x10fc06);
    puVar3 = PTR__S_empty_rep_storage_00311ff0;
    local_58[0] = *plVar6;
    *plVar6 = (long)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    plVar6 = (long *)rea_std__string__append((char *)local_58,0x10fbfd);
    local_48[0]._M_dataplus._M_p = (_Alloc_hider)*plVar6;
    *plVar6 = (long)(puVar3 + 0x18);
    _Var7 = (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)
            rea_operator_new(0x18);
                    /* Unresolved local var: _IO_FILE * fp@[???] */
    *(int *)_Var7 = 0;
    *(int *)((long)_Var7 + 4) = 0;
    ((int *)((long)_Var7 + 8))[0] = 0;
    ((int *)((long)_Var7 + 8))[1] = 0;
    ((int *)((long)_Var7 + 0x10))[0] = 0;
    ((int *)((long)_Var7 + 0x10))[1] = 0;
    __stream = rea_open_file(local_48);
    if (__stream != (FILE *)0x0) {
                    /* Unresolved local var: bool fail@[???] */
      sVar8 = rea_fread((void *)_Var7,4,1,(FILE *)__stream);
      if ((sVar8 == 1) && (sVar8 = rea_fread((int *)((long)_Var7 + 4),4,1,(FILE *)__stream), sVar8 == 1)
         ) {
        uVar14 = 0xffffffffffffffff;
        if ((ulong)(long)*(int *)_Var7 < 0x550000000000001) {
          uVar14 = (long)*(int *)_Var7 * 0x18;
        }
        pvVar9 = rea_operator_new(uVar14);
        *(void **)((long)_Var7 + 8) = pvVar9;
        uVar14 = 0xffffffffffffffff;
        if ((ulong)(long)*(int *)((long)_Var7 + 4) < 0x1c4000000000001) {
          uVar14 = (long)*(int *)((long)_Var7 + 4) * 0x48;
        }
        pvVar9 = rea_operator_new(uVar14);
        *(void **)((long)_Var7 + 0x10) = pvVar9;
        sVar8 = rea_fread(*(void **)((long)_Var7 + 8),0x18,(long)*(int *)_Var7,(FILE *)__stream);
        if ((sVar8 != (long)*(int *)_Var7) ||
           (sVar8 = rea_fread(*(void **)((long)_Var7 + 0x10),0x48,(long)*(int *)((long)_Var7 + 4),
                          (FILE *)__stream), sVar8 != (long)*(int *)((long)_Var7 + 4)))
        goto LAB_001077f4;
      }
      else {
LAB_001077f4:
        *(int *)_Var7 = 0;
        *(int *)((long)_Var7 + 4) = 0;
        if (*(void **)((long)_Var7 + 8) != (void *)0x0) {
          rea_operator_delete(*(void **)((long)_Var7 + 8));
          ((int *)((long)_Var7 + 8))[0] = 0;
          ((int *)((long)_Var7 + 8))[1] = 0;
        }
        if (*(void **)((long)_Var7 + 0x10) != (void *)0x0) {
          rea_operator_delete(*(void **)((long)_Var7 + 0x10));
          ((int *)((long)_Var7 + 0x10))[0] = 0;
          ((int *)((long)_Var7 + 0x10))[1] = 0;
        }
      }
      rea_fclose((FILE *)__stream);
    }
                    /* Unresolved local var: _Link_type __z@[???]
                       Unresolved local var: _Link_type __tmp@[???] */
    p_Var5 = rea_operator_new(0x30);
    if (p_Var5 != (_Link_type)0x0) {
      (p_Var5->_M_value_field).second._M_t.
      super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_> = _Var7;
      (p_Var5->super__Rb_tree_node_base)._M_color = _S_red;
                    /* Unresolved local var: pointer __p@[???] */
      _Var7 = (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
      (p_Var5->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
      (p_Var5->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
      (p_Var5->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
      (p_Var5->_M_value_field).first = date;
    }
                    /* Unresolved local var:
                       pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ __res@[???] */
    pVar15 = std_________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____________________M_get_insert_unique_pos________________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____
                         *)this_01,&(p_Var5->_M_value_field).first);
    if (pVar15.second == (_Base_ptr)0x0) {
                    /* Unresolved local var: Data2 * * __ptr@[???] */
      this_00 = (p_Var5->_M_value_field).second._M_t.
                super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_>;
      if (this_00 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
        rea_IndexedData_GIDKey__Item2__free((IndexedData_GIDKey__Item2 *)this_00);
        rea_operator_delete((void *)this_00);
      }
      (p_Var5->_M_value_field).second._M_t.
      super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_> =
           (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
      rea_operator_delete(p_Var5);
    }
    else {
      std__________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2______________M_insert_node((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____
                        *)this_01,pVar15.first,pVar15.second,p_Var5);
    }
                    /* Unresolved local var: Data2 * * __ptr@[???] */
    if (_Var7 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
      *(int *)_Var7 = 0;
      *(int *)((long)_Var7 + 4) = 0;
      if (*(void **)((long)_Var7 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var7 + 8));
        ((int *)((long)_Var7 + 8))[0] = 0;
        ((int *)((long)_Var7 + 8))[1] = 0;
      }
      if (*(void **)((long)_Var7 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var7 + 0x10));
        ((int *)((long)_Var7 + 0x10))[0] = 0;
        ((int *)((long)_Var7 + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)_Var7);
    }
    if ((allocator *)((long)local_48[0]._M_dataplus._M_p + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)((long)local_48[0]._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar4 = *(int *)((long)local_48[0]._M_dataplus._M_p + -8);
        *(int *)((long)local_48[0]._M_dataplus._M_p + -8) = iVar4 + -1;
      }
      else {
        LOCK();
        iVar4 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar4 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long)local_48[0]._M_dataplus._M_p + -0x18));
      }
    }
    if ((allocator *)(local_58[0] + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)(local_58[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar4 = *(int *)(local_58[0] + -8);
        *(int *)(local_58[0] + -8) = iVar4 + -1;
      }
      else {
        LOCK();
        iVar4 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar4 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_58[0] + -0x18));
      }
    }
    if ((allocator *)(local_68[0] + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)(local_68[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar4 = *(int *)(local_68[0] + -8);
        *(int *)(local_68[0] + -8) = iVar4 + -1;
      }
      else {
        LOCK();
        iVar4 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar4 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_68[0] + -0x18));
      }
    }
    p_Var12 = *(_Base_ptr *)(this_01 + 0x10);
    if (p_Var12 != (_Base_ptr)0x0) goto LAB_00107661;
    __position._M_node = (_Base_ptr)(this_01 + 8);
  }
  else {
    p_Var13 = p_Var12;
    p_Var10 = (_Base_ptr)(PTR_data_store2_00311f70 + 8);
    do {
      while (p_Var11 = p_Var13, date <= (int)p_Var11[1]._M_color) {
        p_Var13 = p_Var11->_M_left;
        p_Var10 = p_Var11;
        if (p_Var11->_M_left == (_Base_ptr)0x0) goto LAB_0010764a;
      }
      pp_Var1 = &p_Var11->_M_right;
      p_Var13 = *pp_Var1;
      p_Var11 = p_Var10;
    } while (*pp_Var1 != (_Base_ptr)0x0);
LAB_0010764a:
    if ((p_Var11 == (_Base_ptr)(PTR_data_store2_00311f70 + 8)) || (date < (int)p_Var11[1]._M_color))
    goto LAB_00107720;
LAB_00107661:
    p_Var13 = (_Base_ptr)(this_01 + 8);
    do {
      while (__position._M_node = p_Var12, date <= (int)__position._M_node[1]._M_color) {
                    /* Unresolved local var: iterator __i@[???] */
        p_Var12 = (__position._M_node)->_M_left;
        p_Var13 = __position._M_node;
        if ((__position._M_node)->_M_left == (_Base_ptr)0x0) goto LAB_0010768a;
      }
      pp_Var1 = &(__position._M_node)->_M_right;
      p_Var12 = *pp_Var1;
      __position._M_node = p_Var13;
    } while (*pp_Var1 != (_Base_ptr)0x0);
LAB_0010768a:
    if ((__position._M_node != (_Base_ptr)(this_01 + 8)) &&
       ((int)__position._M_node[1]._M_color <= date)) goto LAB_00107703;
  }
                    /* Unresolved local var: _Link_type __z@[???]
                       Unresolved local var: _Link_type __tmp@[???] */
  p_Var5 = rea_operator_new(0x30);
  if (p_Var5 != (_Link_type)0x0) {
    (p_Var5->super__Rb_tree_node_base)._M_color = _S_red;
    (p_Var5->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (p_Var5->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (p_Var5->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (p_Var5->_M_value_field).first = date;
    (p_Var5->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_> =
         (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
  }
                    /* Unresolved local var:
                       pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ __res@[???] */
  pVar15 = std_______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2___________________M_get_insert_hint_unique_pos______________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____
                       *)this_01,(const_iterator)__position._M_node,&(p_Var5->_M_value_field).first)
  ;
  __position._M_node = pVar15.first;
  if (pVar15.second == (_Base_ptr)0x0) {
                    /* Unresolved local var: Data2 * * __ptr@[???] */
    _Var7 = (p_Var5->_M_value_field).second._M_t.
            super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_>;
    if (_Var7 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
      rea_IndexedData_GIDKey__Item2__free((IndexedData_GIDKey__Item2 *)_Var7);
      rea_operator_delete((void *)_Var7);
    }
    (p_Var5->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_> =
         (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
    rea_operator_delete(p_Var5);
  }
  else {
    __position = std_____________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_________________________M_insert_node((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____
                                   *)this_01,__position._M_node,pVar15.second,p_Var5);
  }
LAB_00107703:
  return (Data2 *)__position._M_node[1]._M_parent;
}





// ------------------------------------------------------------------
// IDX 151  00107bc0  SecInfo__getMarketValue
// ------------------------------------------------------------------
double rea_SecInfo__getMarketValue(SecInfo * this_ptr, string * gid, int date)
{
  Index *pIVar1;
  Item2 *pIVar2;
  char *__src;
  Index *__s1;
  int iVar3;
  Data2 *pDVar4;
  size_t __n;
  long lVar5;
  long lVar6;
  GIDKey key;
  Index idx;
  
                    /* Unresolved local var: Data2 * data2@[???] */
  pDVar4 = find_data2(this_ptr,date);
                    /* Unresolved local var: Item2 * item@[???]
                       Unresolved local var: Index * idx@[???]
                       Unresolved local var: ulong pos@[???] */
  if ((pDVar4 != (Data2 *)0x0) && (*(ulong *)((gid->_M_dataplus)._M_p + -0x18) < 0x10)) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    __src = (gid->_M_dataplus)._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(__src + -0x18);
    }
    rea_memcpy(&key,__src,__n);
    lVar5 = (long)(pDVar4->super_IndexedData<GIDKey,_Item2>).num_idxs;
    __s1 = (pDVar4->super_IndexedData<GIDKey,_Item2>).idxs;
                    /* Unresolved local var: Index * it@[???]
                       Unresolved local var: _DistanceType __len@[???] */
    key.gid[__n] = '\0';
    idx.start = 0;
    idx.size = 0;
    pIVar1 = __s1 + lVar5;
    for (; 0 < lVar5; lVar5 = (lVar5 - lVar6) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Index * __middle@[???] */
        lVar6 = lVar5 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */
        iVar3 = rea_strcmp((char *)(__s1 + lVar6),(char *)&idx);
        if (iVar3 < 0) break;
        lVar5 = lVar6;
        if (lVar6 == 0) goto LAB_00107cc3;
      }
      __s1 = __s1 + lVar6 + 1;
    }
LAB_00107cc3:
                    /* Unresolved local var: int i@[???] */
    if ((((pIVar1 != __s1) && (iVar3 = rea_strcmp((char *)__s1,(char *)&idx), iVar3 == 0)) &&
        (__s1 != (Index *)0x0)) &&
       (pIVar2 = (pDVar4->super_IndexedData<GIDKey,_Item2>).items + __s1->start,
       pIVar2 != (Item2 *)0x0)) {
      return pIVar2->marketvalue;
    }
  }
  return DAT_0010fd10;
}





// ------------------------------------------------------------------
// IDX 152  00107d40  SecInfo__get30DayIntradayAmplitude
// ------------------------------------------------------------------
double rea_SecInfo__get30DayIntradayAmplitude(SecInfo * this_ptr, string * gid, int date)
{
  Index *pIVar1;
  Item2 *pIVar2;
  char *__src;
  Index *__s1;
  int iVar3;
  Data2 *pDVar4;
  size_t __n;
  long lVar5;
  long lVar6;
  GIDKey key;
  Index idx;
  
                    /* Unresolved local var: Data2 * data2@[???] */
  pDVar4 = find_data2(this_ptr,date);
                    /* Unresolved local var: Item2 * item@[???]
                       Unresolved local var: Index * idx@[???]
                       Unresolved local var: ulong pos@[???] */
  if ((pDVar4 != (Data2 *)0x0) && (*(ulong *)((gid->_M_dataplus)._M_p + -0x18) < 0x10)) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    __src = (gid->_M_dataplus)._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(__src + -0x18);
    }
    rea_memcpy(&key,__src,__n);
    lVar5 = (long)(pDVar4->super_IndexedData<GIDKey,_Item2>).num_idxs;
    __s1 = (pDVar4->super_IndexedData<GIDKey,_Item2>).idxs;
                    /* Unresolved local var: Index * it@[???]
                       Unresolved local var: _DistanceType __len@[???] */
    key.gid[__n] = '\0';
    idx.start = 0;
    idx.size = 0;
    pIVar1 = __s1 + lVar5;
    for (; 0 < lVar5; lVar5 = (lVar5 - lVar6) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Index * __middle@[???] */
        lVar6 = lVar5 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */
        iVar3 = rea_strcmp((char *)(__s1 + lVar6),(char *)&idx);
        if (iVar3 < 0) break;
        lVar5 = lVar6;
        if (lVar6 == 0) goto LAB_00107e43;
      }
      __s1 = __s1 + lVar6 + 1;
    }
LAB_00107e43:
                    /* Unresolved local var: int i@[???] */
    if ((((pIVar1 != __s1) && (iVar3 = rea_strcmp((char *)__s1,(char *)&idx), iVar3 == 0)) &&
        (__s1 != (Index *)0x0)) &&
       (pIVar2 = (pDVar4->super_IndexedData<GIDKey,_Item2>).items + __s1->start,
       pIVar2 != (Item2 *)0x0)) {
      return pIVar2->intradayamplitude_30day;
    }
  }
  return DAT_0010fd10;
}





// ------------------------------------------------------------------
// IDX 153  00107ec0  SecInfo__get30DayTurnoverRate
// ------------------------------------------------------------------
double rea_SecInfo__get30DayTurnoverRate(SecInfo * this_ptr, string * gid, int date)
{
  Index *pIVar1;
  Item2 *pIVar2;
  char *__src;
  Index *__s1;
  int iVar3;
  Data2 *pDVar4;
  size_t __n;
  long lVar5;
  long lVar6;
  GIDKey key;
  Index idx;
  
                    /* Unresolved local var: Data2 * data2@[???] */
  pDVar4 = find_data2(this_ptr,date);
                    /* Unresolved local var: Item2 * item@[???]
                       Unresolved local var: Index * idx@[???]
                       Unresolved local var: ulong pos@[???] */
  if ((pDVar4 != (Data2 *)0x0) && (*(ulong *)((gid->_M_dataplus)._M_p + -0x18) < 0x10)) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    __src = (gid->_M_dataplus)._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(__src + -0x18);
    }
    rea_memcpy(&key,__src,__n);
    lVar5 = (long)(pDVar4->super_IndexedData<GIDKey,_Item2>).num_idxs;
    __s1 = (pDVar4->super_IndexedData<GIDKey,_Item2>).idxs;
                    /* Unresolved local var: Index * it@[???]
                       Unresolved local var: _DistanceType __len@[???] */
    key.gid[__n] = '\0';
    idx.start = 0;
    idx.size = 0;
    pIVar1 = __s1 + lVar5;
    for (; 0 < lVar5; lVar5 = (lVar5 - lVar6) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Index * __middle@[???] */
        lVar6 = lVar5 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */
        iVar3 = rea_strcmp((char *)(__s1 + lVar6),(char *)&idx);
        if (iVar3 < 0) break;
        lVar5 = lVar6;
        if (lVar6 == 0) goto LAB_00107fc3;
      }
      __s1 = __s1 + lVar6 + 1;
    }
LAB_00107fc3:
                    /* Unresolved local var: int i@[???] */
    if ((((pIVar1 != __s1) && (iVar3 = rea_strcmp((char *)__s1,(char *)&idx), iVar3 == 0)) &&
        (__s1 != (Index *)0x0)) &&
       (pIVar2 = (pDVar4->super_IndexedData<GIDKey,_Item2>).items + __s1->start,
       pIVar2 != (Item2 *)0x0)) {
      return pIVar2->turnoverrate_30day;
    }
  }
  return DAT_0010fd10;
}





// ------------------------------------------------------------------
// IDX 154  00108040  SecInfo__get30DayRmbVolume
// ------------------------------------------------------------------
double rea_SecInfo__get30DayRmbVolume(SecInfo * this_ptr, string * gid, int date)
{
  Index *pIVar1;
  Item2 *pIVar2;
  char *__src;
  Index *__s1;
  int iVar3;
  Data2 *pDVar4;
  size_t __n;
  long lVar5;
  long lVar6;
  GIDKey key;
  Index idx;
  
                    /* Unresolved local var: Data2 * data2@[???] */
  pDVar4 = find_data2(this_ptr,date);
                    /* Unresolved local var: Item2 * item@[???]
                       Unresolved local var: Index * idx@[???]
                       Unresolved local var: ulong pos@[???] */
  if ((pDVar4 != (Data2 *)0x0) && (*(ulong *)((gid->_M_dataplus)._M_p + -0x18) < 0x10)) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    __src = (gid->_M_dataplus)._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(__src + -0x18);
    }
    rea_memcpy(&key,__src,__n);
    lVar5 = (long)(pDVar4->super_IndexedData<GIDKey,_Item2>).num_idxs;
    __s1 = (pDVar4->super_IndexedData<GIDKey,_Item2>).idxs;
                    /* Unresolved local var: Index * it@[???]
                       Unresolved local var: _DistanceType __len@[???] */
    key.gid[__n] = '\0';
    idx.start = 0;
    idx.size = 0;
    pIVar1 = __s1 + lVar5;
    for (; 0 < lVar5; lVar5 = (lVar5 - lVar6) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Index * __middle@[???] */
        lVar6 = lVar5 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */
        iVar3 = rea_strcmp((char *)(__s1 + lVar6),(char *)&idx);
        if (iVar3 < 0) break;
        lVar5 = lVar6;
        if (lVar6 == 0) goto LAB_00108143;
      }
      __s1 = __s1 + lVar6 + 1;
    }
LAB_00108143:
                    /* Unresolved local var: int i@[???] */
    if ((((pIVar1 != __s1) && (iVar3 = rea_strcmp((char *)__s1,(char *)&idx), iVar3 == 0)) &&
        (__s1 != (Index *)0x0)) &&
       (pIVar2 = (pDVar4->super_IndexedData<GIDKey,_Item2>).items + __s1->start,
       pIVar2 != (Item2 *)0x0)) {
      return pIVar2->rmbvolume_30day;
    }
  }
  return DAT_0010fd10;
}





// ------------------------------------------------------------------
// IDX 155  001081c0  SecInfo__find_group_data1
// ------------------------------------------------------------------
GroupData1 * rea_SecInfo__find_group_data1__dup2(SecInfo * this_ptr, int date)
{
  _Base_ptr *pp_Var1;
  int *piVar2;
  _Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_ this_00;
  undefined *this_01;
  undefined *puVar3;
  string sVar4;
  _Base_ptr p_Var5;
  int iVar6;
  iterator iVar7;
  _Link_type __z;
  long *plVar8;
  FILE *__stream;
  size_t sVar9;
  _Alloc_hider _Var10;
  void *pvVar11;
  _Base_ptr p_Var12;
  ulong uVar13;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar14;
  uint local_7c [5];
  long local_68 [2];
  int version;
  string local_48 [3];
  
  this_01 = PTR_group_data_store1_00311fc0;
  local_7c[0] = date;
  iVar7 = std______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________find((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____
                  *)PTR_group_data_store1_00311fc0,(int *)local_7c);
  if (iVar7._M_node == (_Base_ptr)(this_01 + 8)) {
                    /* Unresolved local var: FILE * fp@[???] */
    rea___gnu_cxx____to_xstring_std__basic_string_char__char
              ((code *)
               local_68,(size_t)PTR_vsnprintf_00311fd0,(char *)0x10,(void *)&DAT_0010fc03,(ulong)local_7c[0]
              );
    plVar8 = (long *)rea_std__string__insert((ulong)local_68,(char *)0x0,0x10fc13);
    puVar3 = PTR__S_empty_rep_storage_00311ff0;
    _version = *plVar8;
    *plVar8 = (long)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    plVar8 = (long *)rea_std__string__append((char *)&version,0x10fbfd);
    local_48[0]._M_dataplus._M_p = (_Alloc_hider)*plVar8;
    *plVar8 = (long)(puVar3 + 0x18);
    __stream = rea_open_file(local_48);
    if ((allocator *)((long)local_48[0]._M_dataplus._M_p + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)((long)local_48[0]._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar6 = *(int *)((long)local_48[0]._M_dataplus._M_p + -8);
        *(int *)((long)local_48[0]._M_dataplus._M_p + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long)local_48[0]._M_dataplus._M_p + -0x18));
      }
    }
    if ((allocator *)(_version + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)(_version + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar6 = *(int *)(_version + -8);
        *(int *)(_version + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(_version + -0x18));
      }
    }
    if ((allocator *)(local_68[0] + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)(local_68[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar6 = *(int *)(local_68[0] + -8);
        *(int *)(local_68[0] + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_68[0] + -0x18));
      }
    }
    if (((__stream == (FILE *)0x0) || (sVar9 = rea_fread(&version,4,1,(FILE *)__stream), sVar9 != 1)) ||
       (version != 0)) {
      return (GroupData1 *)0x0;
    }
    _Var10._M_p = rea_operator_new(0x18);
                    /* Unresolved local var: bool fail@[???] */
    _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)(_Var10._M_p + 4) < 0xaa0000000000001) {
        uVar13 = (long)*(int *)(_Var10._M_p + 4) * 0xc;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long)*(int *)_Var10._M_p) ||
         (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),0xc,(long)*(int *)(_Var10._M_p + 4),
                        (FILE *)__stream), sVar9 != (long)*(int *)(_Var10._M_p + 4)))
      goto LAB_00108410;
    }
    else {
LAB_00108410:
      _Var10._M_p[0] = '\0';
      _Var10._M_p[1] = '\0';
      _Var10._M_p[2] = '\0';
      _Var10._M_p[3] = '\0';
      *(int *)(_Var10._M_p + 4) = 0;
      if (*(void **)(_Var10._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 8));
        *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    local_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____
                *)this_01);
    sVar4._M_dataplus._M_p = local_48[0]._M_dataplus._M_p;
                    /* Unresolved local var: GroupData1 * * __ptr@[???] */
    if (local_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)local_48[0]._M_dataplus._M_p = 0;
      *(int *)((long)local_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long)local_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)local_48[0]._M_dataplus._M_p + 8));
        ((int *)((long)sVar4._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long)sVar4._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long)sVar4._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)sVar4._M_dataplus._M_p + 0x10));
        ((int *)((long)sVar4._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long)sVar4._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar4._M_dataplus._M_p);
    }
    _Var10._M_p = rea_operator_new(0x18);
                    /* Unresolved local var: bool fail@[???] */
    _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)(_Var10._M_p + 4) < 0x3f80000000000001) {
        uVar13 = (long)*(int *)(_Var10._M_p + 4) * 2;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long)*(int *)_Var10._M_p) ||
         (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),2,(long)*(int *)(_Var10._M_p + 4),
                        (FILE *)__stream), sVar9 != (long)*(int *)(_Var10._M_p + 4)))
      goto LAB_00108500;
    }
    else {
LAB_00108500:
      _Var10._M_p[0] = '\0';
      _Var10._M_p[1] = '\0';
      _Var10._M_p[2] = '\0';
      _Var10._M_p[3] = '\0';
      *(int *)(_Var10._M_p + 4) = 0;
      if (*(void **)(_Var10._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 8));
        *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    local_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____
                *)PTR_group_data_store2_00311ff8);
    sVar4._M_dataplus._M_p = local_48[0]._M_dataplus._M_p;
                    /* Unresolved local var: GroupData2 * * __ptr@[???] */
    if (local_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)local_48[0]._M_dataplus._M_p = 0;
      *(int *)((long)local_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long)local_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)local_48[0]._M_dataplus._M_p + 8));
        ((int *)((long)sVar4._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long)sVar4._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long)sVar4._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)sVar4._M_dataplus._M_p + 0x10));
        ((int *)((long)sVar4._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long)sVar4._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar4._M_dataplus._M_p);
    }
    rea_fclose((FILE *)__stream);
  }
                    /* Unresolved local var: iterator __i@[???] */
  if (*(_Base_ptr *)(this_01 + 0x10) == (_Base_ptr)0x0) {
    iVar7._M_node = (_Base_ptr)(this_01 + 8);
  }
  else {
    p_Var5 = *(_Base_ptr *)(this_01 + 0x10);
    p_Var12 = (_Base_ptr)(this_01 + 8);
    do {
      while (iVar7._M_node = p_Var5, (int)iVar7._M_node[1]._M_color < (int)local_7c[0]) {
        pp_Var1 = &(iVar7._M_node)->_M_right;
        p_Var5 = *pp_Var1;
        iVar7._M_node = p_Var12;
        if (*pp_Var1 == (_Base_ptr)0x0) goto LAB_0010822a;
      }
      p_Var5 = (iVar7._M_node)->_M_left;
      p_Var12 = iVar7._M_node;
    } while ((iVar7._M_node)->_M_left != (_Base_ptr)0x0);
LAB_0010822a:
    if ((iVar7._M_node != (_Base_ptr)(this_01 + 8)) &&
       ((int)iVar7._M_node[1]._M_color <= (int)local_7c[0])) goto LAB_00108238;
  }
                    /* Unresolved local var: _Link_type __z@[???]
                       Unresolved local var: _Link_type __tmp@[???] */
  __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_> =
         (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
    (__z->_M_value_field).first = local_7c[0];
  }
                    /* Unresolved local var:
                       pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ __res@[???] */
  pVar14 = std_______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1___________________M_get_insert_hint_unique_pos______________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____
                       *)this_01,(const_iterator)iVar7._M_node,&(__z->_M_value_field).first);
  iVar7._M_node = pVar14.first;
  if (pVar14.second == (_Base_ptr)0x0) {
                    /* Unresolved local var: GroupData1 * * __ptr@[???] */
    this_00 = (__z->_M_value_field).second._M_t.
              super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_>
    ;
    if (this_00 !=
        (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0) {
      IndexedData_GroupKey__GroupForwardItem__free_________________((IndexedData_GroupKey__GroupForwardItem *)this_00);
      rea_operator_delete((void *)this_00);
    }
    (__z->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_> =
         (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
    rea_operator_delete(__z);
  }
  else {
    iVar7 = std________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____________________M_insert_node((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____
                              *)this_01,iVar7._M_node,pVar14.second,__z);
  }
LAB_00108238:
  return (GroupData1 *)iVar7._M_node[1]._M_parent;
}





// ------------------------------------------------------------------
// IDX 156  001088e0  SecInfo__find_group_data2
// ------------------------------------------------------------------
GroupData2 * rea_SecInfo__find_group_data2__dup2(SecInfo * this_ptr, int date)
{
  _Base_ptr *pp_Var1;
  int *piVar2;
  _Base_ptr p_Var3;
  _Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_ this_00;
  undefined *this_01;
  undefined *puVar4;
  string sVar5;
  int iVar6;
  iterator iVar7;
  _Link_type __z;
  iterator __position;
  long *plVar8;
  FILE *__stream;
  size_t sVar9;
  _Alloc_hider _Var10;
  void *pvVar11;
  _Base_ptr p_Var12;
  _Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____
  *this_02;
  ulong uVar13;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar14;
  uint local_7c [5];
  long local_68 [2];
  int version;
  string local_48 [3];
  
  this_01 = PTR_group_data_store1_00311fc0;
  local_7c[0] = date;
  iVar7 = std______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________find((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____
                  *)PTR_group_data_store1_00311fc0,(int *)local_7c);
  this_02 = (_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____
             *)PTR_group_data_store2_00311ff8;
  if (iVar7._M_node == (_Base_ptr)(this_01 + 8)) {
                    /* Unresolved local var: FILE * fp@[???] */
    rea___gnu_cxx____to_xstring_std__basic_string_char__char
              ((code *)
               local_68,(size_t)PTR_vsnprintf_00311fd0,(char *)0x10,(void *)&DAT_0010fc03,(ulong)local_7c[0]
              );
    plVar8 = (long *)rea_std__string__insert((ulong)local_68,(char *)0x0,0x10fc13);
    puVar4 = PTR__S_empty_rep_storage_00311ff0;
    _version = *plVar8;
    *plVar8 = (long)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    plVar8 = (long *)rea_std__string__append((char *)&version,0x10fbfd);
    local_48[0]._M_dataplus._M_p = (_Alloc_hider)*plVar8;
    *plVar8 = (long)(puVar4 + 0x18);
    __stream = rea_open_file(local_48);
    if ((allocator *)((long)local_48[0]._M_dataplus._M_p + -0x18) != (allocator *)puVar4) {
      piVar2 = (int *)((long)local_48[0]._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar6 = *(int *)((long)local_48[0]._M_dataplus._M_p + -8);
        *(int *)((long)local_48[0]._M_dataplus._M_p + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long)local_48[0]._M_dataplus._M_p + -0x18));
      }
    }
    if ((allocator *)(_version + -0x18) != (allocator *)puVar4) {
      piVar2 = (int *)(_version + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar6 = *(int *)(_version + -8);
        *(int *)(_version + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(_version + -0x18));
      }
    }
    if ((allocator *)(local_68[0] + -0x18) != (allocator *)puVar4) {
      piVar2 = (int *)(local_68[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar6 = *(int *)(local_68[0] + -8);
        *(int *)(local_68[0] + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(local_68[0] + -0x18));
      }
    }
    if (((__stream == (FILE *)0x0) || (sVar9 = rea_fread(&version,4,1,(FILE *)__stream), sVar9 != 1)) ||
       (version != 0)) {
      return (GroupData2 *)0x0;
    }
    _Var10._M_p = rea_operator_new(0x18);
                    /* Unresolved local var: bool fail@[???] */
    _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)(_Var10._M_p + 4) < 0xaa0000000000001) {
        uVar13 = (long)*(int *)(_Var10._M_p + 4) * 0xc;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long)*(int *)_Var10._M_p) ||
         (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),0xc,(long)*(int *)(_Var10._M_p + 4),
                        (FILE *)__stream), sVar9 != (long)*(int *)(_Var10._M_p + 4)))
      goto LAB_00108b30;
    }
    else {
LAB_00108b30:
      _Var10._M_p[0] = '\0';
      _Var10._M_p[1] = '\0';
      _Var10._M_p[2] = '\0';
      _Var10._M_p[3] = '\0';
      *(int *)(_Var10._M_p + 4) = 0;
      if (*(void **)(_Var10._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 8));
        *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    local_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____
                *)this_01);
    sVar5._M_dataplus._M_p = local_48[0]._M_dataplus._M_p;
                    /* Unresolved local var: GroupData1 * * __ptr@[???] */
    if (local_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)local_48[0]._M_dataplus._M_p = 0;
      *(int *)((long)local_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long)local_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)local_48[0]._M_dataplus._M_p + 8));
        ((int *)((long)sVar5._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long)sVar5._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long)sVar5._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)sVar5._M_dataplus._M_p + 0x10));
        ((int *)((long)sVar5._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long)sVar5._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar5._M_dataplus._M_p);
    }
    _Var10._M_p = rea_operator_new(0x18);
                    /* Unresolved local var: bool fail@[???] */
    _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long)*(int *)(_Var10._M_p + 4) < 0x3f80000000000001) {
        uVar13 = (long)*(int *)(_Var10._M_p + 4) * 2;
      }
      pvVar11 = rea_operator_new(uVar13);
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long)*(int *)_Var10._M_p) ||
         (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),2,(long)*(int *)(_Var10._M_p + 4),
                        (FILE *)__stream), sVar9 != (long)*(int *)(_Var10._M_p + 4)))
      goto LAB_00108c18;
    }
    else {
LAB_00108c18:
      _Var10._M_p[0] = '\0';
      _Var10._M_p[1] = '\0';
      _Var10._M_p[2] = '\0';
      _Var10._M_p[3] = '\0';
      *(int *)(_Var10._M_p + 4) = 0;
      if (*(void **)(_Var10._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 8));
        *(int *)((long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    this_02 = (_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____
               *)PTR_group_data_store2_00311ff8;
    local_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____
                *)PTR_group_data_store2_00311ff8);
    sVar5._M_dataplus._M_p = local_48[0]._M_dataplus._M_p;
                    /* Unresolved local var: GroupData2 * * __ptr@[???] */
    if (local_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)local_48[0]._M_dataplus._M_p = 0;
      *(int *)((long)local_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long)local_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)local_48[0]._M_dataplus._M_p + 8));
        ((int *)((long)sVar5._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long)sVar5._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long)sVar5._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)sVar5._M_dataplus._M_p + 0x10));
        ((int *)((long)sVar5._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long)sVar5._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar5._M_dataplus._M_p);
    }
    rea_fclose((FILE *)__stream);
  }
  p_Var3 = (this_02->_M_impl)._M_header._M_parent;
                    /* Unresolved local var: iterator __i@[???] */
  if (p_Var3 == (_Base_ptr)0x0) {
    __position._M_node = &(this_02->_M_impl)._M_header;
  }
  else {
    p_Var12 = &(this_02->_M_impl)._M_header;
    do {
      while (__position._M_node = p_Var3, (int)__position._M_node[1]._M_color < (int)local_7c[0]) {
        pp_Var1 = &(__position._M_node)->_M_right;
        p_Var3 = *pp_Var1;
        __position._M_node = p_Var12;
        if (*pp_Var1 == (_Base_ptr)0x0) goto LAB_0010894a;
      }
      p_Var3 = (__position._M_node)->_M_left;
      p_Var12 = __position._M_node;
    } while ((__position._M_node)->_M_left != (_Base_ptr)0x0);
LAB_0010894a:
    if ((__position._M_node != &(this_02->_M_impl)._M_header) &&
       ((int)__position._M_node[1]._M_color <= (int)local_7c[0])) goto LAB_00108958;
  }
                    /* Unresolved local var: _Link_type __z@[???]
                       Unresolved local var: _Link_type __tmp@[???] */
  __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_> =
         (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
    (__z->_M_value_field).first = local_7c[0];
  }
                    /* Unresolved local var:
                       pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ __res@[???] */
  pVar14 = std_______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2___________________M_get_insert_hint_unique_pos______________________(this_02,(const_iterator)__position._M_node,&(__z->_M_value_field).first);
  __position._M_node = pVar14.first;
  if (pVar14.second == (_Base_ptr)0x0) {
                    /* Unresolved local var: GroupData2 * * __ptr@[???] */
    this_00 = (__z->_M_value_field).second._M_t.
              super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_>
    ;
    if (this_00 !=
        (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0) {
      IndexedData_GIDKey__GroupBackwardItem__free_________________((IndexedData_GIDKey__GroupBackwardItem *)this_00);
      rea_operator_delete((void *)this_00);
    }
    (__z->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_> =
         (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
    rea_operator_delete(__z);
  }
  else {
    __position = std_____________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________________M_insert_node(this_02,__position._M_node,pVar14.second,__z);
  }
LAB_00108958:
  return (GroupData2 *)__position._M_node[1]._M_parent;
}





// ------------------------------------------------------------------
// IDX 157  00108ff0  SecInfo__getGroups
// ------------------------------------------------------------------
Set_SecInfo__GroupsIterator * rea_SecInfo__getGroups(Set_SecInfo__GroupsIterator * __return_storage_ptr__, SecInfo * this_ptr, string * gid, int date)
{
  Index *pIVar1;
  int iVar2;
  char *__src;
  GroupBackwardItem *pGVar3;
  Index *pIVar4;
  int iVar5;
  GroupData1 *pGVar6;
  GroupData2 *pGVar7;
  size_t __n;
  long lVar8;
  Index *__s1;
  long lVar9;
  GIDKey key;
  vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___
  res;
  Index idx;
  
                    /* Unresolved local var: GroupData1 * data1@[???]
                       Unresolved local var: GroupData2 * data2@[???] */
  pGVar6 = find_group_data1(this_ptr,date);
  pGVar7 = find_group_data2(this_ptr,date);
                    /* Unresolved local var: Index * idx@[???]
                       Unresolved local var: ulong pos@[???] */
  if (((pGVar7 != (GroupData2 *)0x0) && (pGVar6 != (GroupData1 *)0x0)) &&
     (*(ulong *)((gid->_M_dataplus)._M_p + -0x18) < 0x10)) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    __src = (gid->_M_dataplus)._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(__src + -0x18);
    }
    rea_memcpy(&key,__src,__n);
    lVar8 = (long)(pGVar7->super_IndexedData<GIDKey,_GroupBackwardItem>).num_idxs;
    key.gid[__n] = '\0';
                    /* Unresolved local var: Index * it@[???] */
    __s1 = (pGVar7->super_IndexedData<GIDKey,_GroupBackwardItem>).idxs;
    idx.start = 0;
    idx.size = 0;
    idx.key.gid[0] = key.gid[0];
    idx.key.gid[1] = key.gid[1];
    idx.key.gid[2] = key.gid[2];
    idx.key.gid[3] = key.gid[3];
    idx.key.gid[4] = key.gid[4];
    idx.key.gid[5] = key.gid[5];
    idx.key.gid[6] = key.gid[6];
    idx.key.gid[7] = key.gid[7];
                    /* Unresolved local var: _DistanceType __len@[???] */
    idx.key.gid[8] = key.gid[8];
    idx.key.gid[9] = key.gid[9];
    idx.key.gid[10] = key.gid[10];
    idx.key.gid[0xb] = key.gid[0xb];
    idx.key.gid[0xc] = key.gid[0xc];
    idx.key.gid[0xd] = key.gid[0xd];
    idx.key.gid[0xe] = key.gid[0xe];
    idx.key.gid[0xf] = key.gid[0xf];
    pIVar1 = __s1 + lVar8;
    for (; 0 < lVar8; lVar8 = (lVar8 - lVar9) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Index * __middle@[???] */
        lVar9 = lVar8 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */
        iVar5 = rea_strcmp((char *)(__s1 + lVar9),(char *)&idx);
        if (iVar5 < 0) break;
        lVar8 = lVar9;
        if (lVar9 == 0) goto LAB_001091c0;
      }
      __s1 = __s1 + lVar9 + 1;
    }
LAB_001091c0:
    if (((pIVar1 != __s1) && (iVar5 = rea_strcmp((char *)__s1,(char *)&idx), iVar5 == 0)) &&
       (__s1 != (Index *)0x0)) {
      iVar5 = __s1->start;
      pGVar3 = (pGVar7->super_IndexedData<GIDKey,_GroupBackwardItem>).items;
      iVar2 = __s1->size;
      __return_storage_ptr__->data2 = pGVar7;
      __return_storage_ptr__->mask_eod_values = false;
      __return_storage_ptr__->data1 = pGVar6;
      pIVar4 = (pGVar6->super_IndexedData<GroupKey,_GroupForwardItem>).idxs;
      __return_storage_ptr__->size_ = iVar2;
      __return_storage_ptr__->base = pGVar3 + iVar5;
      __return_storage_ptr__->idxbase = pIVar4;
      return __return_storage_ptr__;
    }
  }
  __return_storage_ptr__->data1 = (GroupData1 *)0x0;
  __return_storage_ptr__->data2 = (GroupData2 *)0x0;
  __return_storage_ptr__->idxbase = (void *)0x0;
  __return_storage_ptr__->base = (void *)0x0;
  __return_storage_ptr__->size_ = 0;
  __return_storage_ptr__->mask_eod_values = false;
  return __return_storage_ptr__;
}





// ------------------------------------------------------------------
// IDX 158  00109280  SecInfo__getMembers
// ------------------------------------------------------------------
Set_SecInfo__MembersIterator * rea_SecInfo__getMembers(Set_SecInfo__MembersIterator * __return_storage_ptr__, SecInfo * this_ptr, string * group, int date)
{
  Index *pIVar1;
  int iVar2;
  char *__src;
  GroupForwardItem *pGVar3;
  Index *pIVar4;
  int iVar5;
  GroupData1 *pGVar6;
  GroupData2 *pGVar7;
  long lVar8;
  Index *__s1;
  long lVar9;
  GroupKey key;
  vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___
  res;
  Index idx;
  
                    /* Unresolved local var: GroupData1 * data1@[???]
                       Unresolved local var: GroupData2 * data2@[???] */
  pGVar6 = find_group_data1(this_ptr,date);
  pGVar7 = find_group_data2(this_ptr,date);
                    /* Unresolved local var: Index * idx@[???] */
  if (((pGVar7 != (GroupData2 *)0x0) && (pGVar6 != (GroupData1 *)0x0)) &&
     (__src = (group->_M_dataplus)._M_p, *(ulong *)(__src + -0x18) < 0x10)) {
    rea_strcpy(key.group_name,__src);
                    /* Unresolved local var: Index * it@[???] */
    lVar8 = (long)(pGVar6->super_IndexedData<GroupKey,_GroupForwardItem>).num_idxs;
    __s1 = (pGVar6->super_IndexedData<GroupKey,_GroupForwardItem>).idxs;
    idx.key.group_name[8] = key.group_name[8];
    idx.key.group_name[9] = key.group_name[9];
    idx.key.group_name[10] = key.group_name[10];
    idx.key.group_name[0xb] = key.group_name[0xb];
    idx.key.group_name[0xc] = key.group_name[0xc];
    idx.key.group_name[0xd] = key.group_name[0xd];
    idx.key.group_name[0xe] = key.group_name[0xe];
    idx.key.group_name[0xf] = key.group_name[0xf];
    idx.start = 0;
    idx.size = 0;
    idx.key.group_name[0] = key.group_name[0];
    idx.key.group_name[1] = key.group_name[1];
    idx.key.group_name[2] = key.group_name[2];
    idx.key.group_name[3] = key.group_name[3];
    idx.key.group_name[4] = key.group_name[4];
    idx.key.group_name[5] = key.group_name[5];
    idx.key.group_name[6] = key.group_name[6];
    idx.key.group_name[7] = key.group_name[7];
                    /* Unresolved local var: _DistanceType __len@[???] */
    pIVar1 = __s1 + lVar8;
    for (; 0 < lVar8; lVar8 = (lVar8 - lVar9) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???]
                       Unresolved local var: Index * __middle@[???] */
        lVar9 = lVar8 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */
        iVar5 = rea_strcmp((char *)(__s1 + lVar9),(char *)&idx);
        if (iVar5 < 0) break;
        lVar8 = lVar9;
        if (lVar9 == 0) goto LAB_00109420;
      }
      __s1 = __s1 + lVar9 + 1;
    }
LAB_00109420:
    if (((pIVar1 != __s1) && (iVar5 = rea_strcmp((char *)__s1,(char *)&idx), iVar5 == 0)) &&
       (__s1 != (Index *)0x0)) {
      iVar5 = __s1->start;
      iVar2 = __s1->size;
      __return_storage_ptr__->data2 = pGVar7;
      __return_storage_ptr__->mask_eod_values = false;
      __return_storage_ptr__->data1 = pGVar6;
      pGVar3 = (pGVar6->super_IndexedData<GroupKey,_GroupForwardItem>).items;
      __return_storage_ptr__->size_ = iVar2;
      pIVar4 = (pGVar7->super_IndexedData<GIDKey,_GroupBackwardItem>).idxs;
      __return_storage_ptr__->base = pGVar3 + iVar5;
      __return_storage_ptr__->idxbase = pIVar4;
      return __return_storage_ptr__;
    }
  }
  __return_storage_ptr__->data1 = (GroupData1 *)0x0;
  __return_storage_ptr__->data2 = (GroupData2 *)0x0;
  __return_storage_ptr__->idxbase = (void *)0x0;
  __return_storage_ptr__->base = (void *)0x0;
  __return_storage_ptr__->size_ = 0;
  __return_storage_ptr__->mask_eod_values = false;
  return __return_storage_ptr__;
}





// ------------------------------------------------------------------
// IDX 159  001094e0  PyWrapper<std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char____
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char(undefined8 * pyargs)
{
  _Rb_tree_node_base *__k;
  _Base_ptr *pp_Var1;
  pointer *ppbVar2;
  int *piVar3;
  uchar *puVar4;
  uchar uVar5;
  void *pvVar6;
  _Base_ptr p_Var7;
  string *psVar8;
  string *psVar9;
  string *psVar10;
  pointer pbVar11;
  pointer pbVar12;
  double dVar13;
  pointer pbVar14;
  int iVar15;
  char *pcVar16;
  pointer puVar17;
  _Alloc_hider p;
  iterator iVar18;
  _Rb_tree_node_base *p_Var19;
  _typeobject *p_Var20;
  undefined8 uVar21;
  undefined8 uVar22;
  string sVar23;
  pointer __src;
  pointer pbVar24;
  string *psVar25;
  char *pcVar26;
  basic_string_char__std__char_traits_char__std__allocator_char_ bVar27;
  ulong uVar28;
  uchar *puVar29;
  _Base_ptr p_Var30;
  _Base_ptr p_Var31;
  ulong uVar32;
  string *psVar33;
  PyObject *pPVar34;
  ulong uVar35;
  pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___
  *ppVar36;
  long lVar37;
  bool bVar38;
  undefined1 local_280 [2];
  allocator local_27e [3];
  undefined1 local_27b [2];
  allocator local_279;
  parse_ctx t;
  uchar *local_268 [2];
  string ts;
  string buf;
  string fmt;
  double hv;
  double uv;
  undefined1 local_1f0;
  undefined1 local_1ef;
  undefined1 local_1ee;
  undefined1 local_1ed;
  undefined1 local_1ec;
  undefined1 local_1eb;
  undefined1 local_1ea;
  undefined1 local_1e9;
  undefined1 local_1e8;
  undefined1 local_1e7;
  undefined1 local_1e6;
  undefined1 local_1e5;
  undefined1 local_1e4;
  undefined1 local_1e3;
  undefined1 local_1e2;
  vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___
  index;
  vector_unsigned_char__std__allocator_unsigned_char_ rv;
  double prc;
  string *local_190;
  undefined8 local_188;
  string local_180;
  double volume;
  string *local_170;
  long local_168;
  string local_160;
  pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___
  r;
  map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__
  se_prc;
  map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__
  se_volume;
  map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
  se_alphas;
  map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__
  hold;
  map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__
  usable;
  _object *pa;
  
  usable._M_t._M_impl._M_key_compare.
  super_binary_function<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__basic_string_char__std__char_traits_char__std__allocator_char_,_bool>
       = (binary_function<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__basic_string_char__std__char_traits_char__std__allocator_char_,_bool>
          )0x4f;
  usable._M_t.(*(undefined1 *)((uint8_t *)&_M_impl + 0x1)) = 0;
  iVar15 = rea_PyArg_ParseTuple(pyargs,(allocator *)&usable,&t);
  if (iVar15 == 0) {
    return (PyObject *)0x0;
  }
  if (((t.v)->ob_type->tp_flags & 0x8000000) == 0) {
    pcVar16 = (char *)rea_PyUnicode_AsUTF8();
    rea_std__string__string(local_268,pcVar16,(allocator *)&usable);
  }
  else {
    uVar35 = rea_PyBytes_Size();
    pcVar16 = (char *)rea_PyBytes_AsString(t.v);
    rea_std__string__string(local_268,pcVar16,uVar35,(allocator *)&usable);
  }
  puVar29 = local_268[0];
  se_prc._M_t._M_impl._M_header._M_left = &se_prc._M_t._M_impl._M_header;
  se_prc._M_t._M_impl._M_header._M_color = _S_red;
  se_prc._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  se_volume._M_t._M_impl._M_header._M_left = &se_volume._M_t._M_impl._M_header;
  ts._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
  se_alphas._M_t._M_impl._M_header._M_left = &se_alphas._M_t._M_impl._M_header;
  se_prc._M_t._M_impl._M_node_count = 0;
  hold._M_t._M_impl._M_header._M_left = &hold._M_t._M_impl._M_header;
  se_volume._M_t._M_impl._M_header._M_color = _S_red;
  se_volume._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  usable._M_t._M_impl._M_header._M_left = &usable._M_t._M_impl._M_header;
  se_volume._M_t._M_impl._M_node_count = 0;
  se_alphas._M_t._M_impl._M_header._M_color = _S_red;
  se_alphas._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  se_alphas._M_t._M_impl._M_node_count = 0;
  hold._M_t._M_impl._M_header._M_color = _S_red;
  hold._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  hold._M_t._M_impl._M_node_count = 0;
  usable._M_t._M_impl._M_header._M_color = _S_red;
  usable._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  usable._M_t._M_impl._M_node_count = 0;
  index.
  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
  ._M_impl._M_start = (pointer)0x0;
  index.
  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
  ._M_impl._M_finish = (pointer)0x0;
                    /* Unresolved local var: size_type __n@[???] */
  __src = (pointer)0x0;
  index.
  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
  ._M_impl._M_end_of_storage = (pointer)0x0;
  uVar35 = *(ulong *)(local_268[0] + -0x18);
  rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_start =
       (pointer)0x0;
  rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_finish =
       (pointer)0x0;
  rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_end_of_storage =
       (pointer)0x0;
  buf._M_dataplus._M_p = ts._M_dataplus._M_p;
  se_prc._M_t._M_impl._M_header._M_right = se_prc._M_t._M_impl._M_header._M_left;
  se_volume._M_t._M_impl._M_header._M_right = se_volume._M_t._M_impl._M_header._M_left;
  se_alphas._M_t._M_impl._M_header._M_right = se_alphas._M_t._M_impl._M_header._M_left;
  hold._M_t._M_impl._M_header._M_right = hold._M_t._M_impl._M_header._M_left;
  usable._M_t._M_impl._M_header._M_right = usable._M_t._M_impl._M_header._M_left;
  if (uVar35 != 0) {
    __src = rea_operator_new(uVar35);
  }
  rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_end_of_storage =
       __src + uVar35;
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: _Distance __n@[???] */
  puVar4 = puVar29 + uVar35;
  puVar17 = __src;
  rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_start = __src;
  if ((long)uVar35 < 1) {
    fmt._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_finish = __src;
LAB_0010a170:
    bVar38 = false;
    sVar23._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
  }
  else {
    do {
      uVar5 = *puVar29;
      puVar29 = puVar29 + 1;
      *puVar17 = uVar5;
      puVar17 = puVar17 + 1;
    } while (puVar29 != puVar4);
                    /* Unresolved local var: size_t l@[???]
                       Unresolved local var: size_t np@[???]
                       Unresolved local var: size_t p@[???] */
    fmt._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
                    /* Unresolved local var: uint8_t * s@[???] */
    rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_finish =
         rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl.
         _M_end_of_storage;
    if ((ulong)((long)rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl.
                      _M_end_of_storage - (long)__src) < 8) goto LAB_0010a170;
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
    rea_memcpy(&r,__src,8);
    bVar27 = r.first;
    p._M_p = (char *)detail________________________P_std__basic_string_char__std__char_traits_char__std__allocator_char__________________________parse(&rv,8,&fmt);
    if (p._M_p == (char *)0x8) {
LAB_001098d9:
      bVar38 = false;
      sVar23._M_dataplus._M_p = fmt._M_dataplus._M_p;
    }
    else {
      local_1e2 = 0;
      uv = 2.849611842993279e+247;
      local_1f0 = 100;
      local_1ef = 0x4d;
      local_1ee = 0x50;
      local_1ed = 0x73;
      local_1ec = 0x56;
      local_1eb = 100;
      local_1ea = 0x4d;
      local_1e9 = 0x50;
      local_1e8 = 0x73;
      local_1e7 = 100;
      local_1e6 = 0x4d;
      local_1e5 = 0x50;
      local_1e4 = 0x73;
      local_1e3 = 100;
      rea_std__string__string(&hv,(char *)&uv,local_27e);
      dVar13 = hv;
      if (*(size_t *)((long)fmt._M_dataplus._M_p + -0x18) != *(size_t *)((long)hv + -0x18)) {
        rea_std__string___Rep___M_dispose((allocator *)((long)hv + -0x18));
        goto LAB_001098d9;
      }
      iVar15 = rea_memcmp((void *)fmt._M_dataplus._M_p,(void *)hv,
                      *(size_t *)((long)fmt._M_dataplus._M_p + -0x18));
      rea_std__string___Rep___M_dispose((allocator *)((long)dVar13 + -0x18));
      if (iVar15 != 0) goto LAB_001098d9;
                    /* Unresolved local var: size_t np@[???] */
      pcVar16 = (char *)detail___________________________P_std__basic_string_char__std__char_traits_char__std__allocator_char_____________________________parse(&rv,(size_t)p._M_p,&ts);
                    /* Unresolved local var: size_t np@[???] */
                    /* Unresolved local var: size_t np@[???] */
                    /* Unresolved local var: size_t np@[???] */
                    /* Unresolved local var: size_t np@[???] */
      if ((((p._M_p != pcVar16) &&
           (pcVar26 = (char *)detail::
                              rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse(&rv,(size_t)pcVar16,
                                      (map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__
                                       *)&se_prc._M_t), p._M_p = pcVar16, pcVar16 != pcVar26)) &&
          (pcVar16 = (char *)detail::
                             rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse(&rv,(size_t)pcVar26,
                                     (map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__
                                      *)&se_volume._M_t), p._M_p = pcVar26, pcVar26 != pcVar16)) &&
         ((pcVar26 = (char *)detail::
                             rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____M___parse(&rv,(size_t)pcVar16,
                                     (map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
                                      *)&se_alphas._M_t), p._M_p = pcVar16, pcVar16 != pcVar26 &&
          (pcVar16 = (char *)detail::
                             rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse(&rv,(size_t)pcVar26,
                                     (map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__
                                      *)&hold._M_t), p._M_p = pcVar26, pcVar26 != pcVar16)))) {
                    /* Unresolved local var: size_t np@[???] */
        p._M_p = (char *)detail::
                         rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse(&rv,(size_t)pcVar16,&usable);
      }
      bVar38 = bVar27._M_dataplus._M_p == (_Alloc_hider)p._M_p;
      sVar23._M_dataplus._M_p = fmt._M_dataplus._M_p;
    }
  }
  if ((allocator *)((long)sVar23._M_dataplus._M_p + -0x18) !=
      (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar3 = (int *)((long)sVar23._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
      iVar15 = *(int *)((long)sVar23._M_dataplus._M_p + -8);
      *(int *)((long)sVar23._M_dataplus._M_p + -8) = iVar15 + -1;
    }
    else {
      LOCK();
      iVar15 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar15 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long)sVar23._M_dataplus._M_p + -0x18));
    }
  }
  if (bVar38) {
                    /* Unresolved local var:
                       pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__
                       * p@[???]
                       Unresolved local var:
                       map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
                       * __for_range@[???]
                       Unresolved local var: iterator __for_begin@[???]
                       Unresolved local var: iterator __for_end@[???] */
    p_Var19 = se_alphas._M_t._M_impl._M_header._M_left;
    if (se_alphas._M_t._M_impl._M_header._M_left != &se_alphas._M_t._M_impl._M_header) {
      do {
        __k = p_Var19 + 1;
        if (index.
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            ._M_impl._M_finish ==
            index.
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            ._M_impl._M_end_of_storage) {
          std_____________vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char____________________________M_emplace_back_aux_const_std__basic_string_char__std__char_traits_char__std__allocator_char_______________________(&index);
        }
        else {
          if (index.
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              ._M_impl._M_finish == (pointer)0x0) {
            index.
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            ._M_impl._M_finish = (pointer)0x0;
          }
          else {
            rea_std__string__string(index.
                                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                                ._M_impl._M_finish,(string *)__k);
          }
          index.
          super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
          ._M_impl._M_finish =
               index.
               super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
               ._M_impl._M_finish + 1;
        }
        hv = 0.0;
        iVar18 = std_____________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______________________find(&hold._M_t,
                        (basic_string_char__std__char_traits_char__std__allocator_char_ *)__k);
        if (iVar18._M_node != &hold._M_t._M_impl._M_header) {
          hv = (double)iVar18._M_node[1]._M_parent;
        }
        uv = 0.0;
        iVar18 = std_____________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______________________find((_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__
                         *)&usable,
                        (basic_string_char__std__char_traits_char__std__allocator_char_ *)__k);
        if (iVar18._M_node != &usable._M_t._M_impl._M_header) {
          uv = (double)iVar18._M_node[1]._M_parent;
        }
        if (se_prc._M_t._M_impl._M_header._M_parent == (_Base_ptr)0x0) {
          iVar18._M_node = &se_prc._M_t._M_impl._M_header;
LAB_0010a0be:
          iVar18 = std_______________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_____________________________________________M_emplace_hint_unique_const_std__piecewise_construct_t___std__tuple_const_std__basic_string_char__std__char_traits_char__std__allocator_char____std__tuple________________________________(&se_prc._M_t,iVar18._M_node);
        }
        else {
          pvVar6 = *(void **)(p_Var19 + 1);
          uVar35 = *(ulong *)((long)pvVar6 + -0x18);
          p_Var30 = &se_prc._M_t._M_impl._M_header;
          p_Var7 = se_prc._M_t._M_impl._M_header._M_parent;
          do {
            while( true ) {
              iVar18._M_node = p_Var7;
              uVar32 = *(ulong *)((long)*(void **)(iVar18._M_node + 1) + -0x18);
              uVar28 = uVar32;
              if (uVar35 <= uVar32) {
                uVar28 = uVar35;
              }
              iVar15 = rea_memcmp(*(void **)(iVar18._M_node + 1),pvVar6,uVar28);
              if (iVar15 != 0) break;
              lVar37 = uVar32 - uVar35;
              if (0x7fffffff < lVar37) goto LAB_00109a27;
              if (-0x80000001 < lVar37) {
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???]
                       Unresolved local var: difference_type __d@[???] */
                iVar15 = (int)lVar37;
                break;
              }
LAB_00109a66:
              pp_Var1 = &(iVar18._M_node)->_M_right;
              iVar18._M_node = p_Var30;
              p_Var7 = *pp_Var1;
              if (*pp_Var1 == (_Base_ptr)0x0) goto LAB_00109a6f;
            }
            if (iVar15 < 0) goto LAB_00109a66;
LAB_00109a27:
            p_Var30 = iVar18._M_node;
            p_Var7 = (iVar18._M_node)->_M_left;
          } while ((iVar18._M_node)->_M_left != (_Base_ptr)0x0);
LAB_00109a6f:
          if (iVar18._M_node == &se_prc._M_t._M_impl._M_header) goto LAB_0010a0be;
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
          uVar32 = *(ulong *)((long)*(void **)(iVar18._M_node + 1) + -0x18);
          uVar28 = uVar32;
          if (uVar35 <= uVar32) {
            uVar28 = uVar35;
          }
          iVar15 = rea_memcmp(pvVar6,*(void **)(iVar18._M_node + 1),uVar28);
          if (iVar15 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */
            lVar37 = uVar35 - uVar32;
            if (lVar37 < 0x80000000) {
              if (lVar37 < -0x80000000) goto LAB_0010a0be;
              iVar15 = (int)lVar37;
              goto LAB_00109abd;
            }
          }
          else {
LAB_00109abd:
            if (iVar15 < 0) goto LAB_0010a0be;
          }
        }
        prc = (double)iVar18._M_node[1]._M_parent;
        if (se_volume._M_t._M_impl._M_header._M_parent == (_Base_ptr)0x0) {
          iVar18._M_node = &se_volume._M_t._M_impl._M_header;
LAB_0010a0fe:
          iVar18 = std_______________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_____________________________________________M_emplace_hint_unique_const_std__piecewise_construct_t___std__tuple_const_std__basic_string_char__std__char_traits_char__std__allocator_char____std__tuple________________________________(&se_volume._M_t,iVar18._M_node);
        }
        else {
          pvVar6 = *(void **)(p_Var19 + 1);
          uVar35 = *(ulong *)((long)pvVar6 + -0x18);
          p_Var30 = &se_volume._M_t._M_impl._M_header;
          p_Var7 = se_volume._M_t._M_impl._M_header._M_parent;
          do {
            while( true ) {
              iVar18._M_node = p_Var7;
              uVar32 = *(ulong *)((long)*(void **)(iVar18._M_node + 1) + -0x18);
              uVar28 = uVar32;
              if (uVar35 <= uVar32) {
                uVar28 = uVar35;
              }
              iVar15 = rea_memcmp(*(void **)(iVar18._M_node + 1),pvVar6,uVar28);
              if (iVar15 != 0) break;
              lVar37 = uVar32 - uVar35;
              if (0x7fffffff < lVar37) goto LAB_00109b07;
              if (-0x80000001 < lVar37) {
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???]
                       Unresolved local var: difference_type __d@[???] */
                iVar15 = (int)lVar37;
                break;
              }
LAB_00109b46:
              pp_Var1 = &(iVar18._M_node)->_M_right;
              iVar18._M_node = p_Var30;
              p_Var7 = *pp_Var1;
              if (*pp_Var1 == (_Base_ptr)0x0) goto LAB_00109b4f;
            }
            if (iVar15 < 0) goto LAB_00109b46;
LAB_00109b07:
            p_Var30 = iVar18._M_node;
            p_Var7 = (iVar18._M_node)->_M_left;
          } while ((iVar18._M_node)->_M_left != (_Base_ptr)0x0);
LAB_00109b4f:
          if (iVar18._M_node == &se_volume._M_t._M_impl._M_header) goto LAB_0010a0fe;
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
          uVar32 = *(ulong *)((long)*(void **)(iVar18._M_node + 1) + -0x18);
          uVar28 = uVar32;
          if (uVar35 <= uVar32) {
            uVar28 = uVar35;
          }
          iVar15 = rea_memcmp(pvVar6,*(void **)(iVar18._M_node + 1),uVar28);
          if (iVar15 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */
            lVar37 = uVar35 - uVar32;
            if (lVar37 < 0x80000000) {
              if (lVar37 < -0x80000000) goto LAB_0010a0fe;
              iVar15 = (int)lVar37;
              goto LAB_00109b9d;
            }
          }
          else {
LAB_00109b9d:
            if (iVar15 < 0) goto LAB_0010a0fe;
          }
        }
        volume = (double)iVar18._M_node[1]._M_parent;
        rea_std__string__append((char *)&buf,(ulong)&hv);
        rea_std__string__append((char *)&buf,(ulong)&uv);
        rea_std__string__append((char *)&buf,(ulong)&prc);
        rea_std__string__append((char *)&buf,(ulong)&volume);
                    /* Unresolved local var: vector_double__std__allocator_double_ *
                       __for_range@[???]
                       Unresolved local var: iterator __for_begin@[???]
                       Unresolved local var: iterator __for_end@[???] */
        p_Var7 = p_Var19[1]._M_left;
        for (p_Var31 = p_Var19[1]._M_parent; p_Var31 != p_Var7;
            p_Var31 = (_Base_ptr)&p_Var31->_M_parent) {
          r.first._M_dataplus._M_p = *(_Alloc_hider *)p_Var31;
          rea_std__string__append((char *)&buf,(ulong)&r);
        }
        p_Var19 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var19);
      } while (p_Var19 != &se_alphas._M_t._M_impl._M_header);
    }
    pbVar24 = index.
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              ._M_impl._M_finish;
    psVar25 = (string *)0x0;
    volume = 0.0;
    local_170 = (string *)0x0;
    local_168 = 0;
    uVar32 = (long)index.
                   super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                   ._M_impl._M_finish -
             (long)index.
                   super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                   ._M_impl._M_start >> 3;
    uVar35 = 0;
    if (uVar32 != 0) {
      if (0x1fffffffffffffff < uVar32) {
        uVar21 = rea_std____throw_bad_alloc();
        iVar15 = (int)local_27b;
        rea_std__string___Rep___M_dispose((allocator *)((long)r.first._M_dataplus._M_p + -0x18));
        std___________pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char______________pair((pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char__
                 *)pbVar24,iVar15);
        if (rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_start !=
            (pointer)0x0) {
          rea_operator_delete(rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>.
                          _M_impl._M_start);
        }
        iVar15 = (int)local_280;
        rea_std__string___Rep___M_dispose((allocator *)((long)buf._M_dataplus._M_p + -0x18));
        std___________vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______________vector(&index,iVar15);
        std____________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______________M_erase((_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__
                    *)&usable,(_Link_type)usable._M_t._M_impl._M_header._M_parent);
        std____________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______________M_erase(&hold._M_t,(_Link_type)hold._M_t._M_impl._M_header._M_parent);
        std____________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________________M_erase(&se_alphas._M_t,(_Link_type)se_alphas._M_t._M_impl._M_header._M_parent);
        std____________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______________M_erase(&se_volume._M_t,(_Link_type)se_volume._M_t._M_impl._M_header._M_parent);
        std____________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______________M_erase(&se_prc._M_t,(_Link_type)se_prc._M_t._M_impl._M_header._M_parent);
        rea_std__string___Rep___M_dispose((allocator *)((long)ts._M_dataplus._M_p + -0x18));
        rea_std__string___Rep___M_dispose((allocator *)(local_268[0] + -0x18));
                    /* WARNING: Subroutine does not return */
        rea__Unwind_Resume(uVar21);
      }
      uVar35 = uVar32 << 3;
      psVar25 = rea_operator_new(uVar35);
    }
    pbVar24 = index.
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              ._M_impl._M_finish;
    local_168 = (long)&(psVar25->_M_dataplus)._M_p + uVar35;
    volume = (double)psVar25;
    local_170 = psVar25;
                    /* Unresolved local var:
                       basic_string_char__std__char_traits_char__std__allocator_char_ *
                       __cur@[???] */
    for (psVar33 = index.
                   super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                   ._M_impl._M_start; pbVar24 != psVar33; psVar33 = psVar33 + 1) {
      if (psVar25 != (string *)0x0) {
        rea_std__string__string(psVar25,psVar33);
      }
      psVar25 = psVar25 + 1;
    }
    local_170 = psVar25;
    rea_std__string__string(&local_160,&buf);
    ppVar36 = &r;
    rea_std__string__string(ppVar36,&ts);
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_start = (pointer)0x0;
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = (pointer)0x0;
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_end_of_storage = (pointer)0x0;
    pPVar34 = (PyObject *)((long)local_170 - (long)volume >> 3);
    if (pPVar34 == (PyObject *)0x0) {
      uVar35 = 0;
      pbVar24 = (pointer)0x0;
LAB_00109db2:
      psVar33 = local_170;
      r.second.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_end_of_storage = (pointer)((long)&(pbVar24->_M_dataplus)._M_p + uVar35);
      r.second.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_start = pbVar24;
      r.second.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_finish = pbVar24;
                    /* Unresolved local var:
                       basic_string_char__std__char_traits_char__std__allocator_char_ *
                       __cur@[???] */
      for (psVar25 = (string *)volume; psVar25 != psVar33; psVar25 = psVar25 + 1) {
        if (pbVar24 != (pointer)0x0) {
          rea_std__string__string(pbVar24,psVar25);
        }
        pbVar24 = pbVar24 + 1;
      }
      r.second.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_finish = pbVar24;
      rea_std__string__string(&r.second.second,&local_160);
      psVar25 = (string *)volume;
      psVar33 = local_170;
      psVar8 = local_170;
      if ((allocator *)((long)local_160._M_dataplus._M_p + -0x18) !=
          (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar3 = (int *)((long)local_160._M_dataplus._M_p + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
          iVar15 = *(int *)((long)local_160._M_dataplus._M_p + -8);
          *(int *)((long)local_160._M_dataplus._M_p + -8) = iVar15 + -1;
        }
        else {
          LOCK();
          iVar15 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        if (iVar15 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)((long)local_160._M_dataplus._M_p + -0x18));
          psVar25 = (string *)volume;
          psVar33 = local_170;
          psVar8 = local_170;
        }
      }
      for (; psVar9 = local_170, local_170 != psVar25; psVar25 = psVar25 + 1) {
        pcVar16 = (psVar25->_M_dataplus)._M_p;
        local_170 = psVar8;
        if ((allocator *)(pcVar16 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
          piVar3 = (int *)(pcVar16 + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
            iVar15 = *(int *)(pcVar16 + -8);
            *(int *)(pcVar16 + -8) = iVar15 + -1;
          }
          else {
            LOCK();
            iVar15 = *piVar3;
            *piVar3 = *piVar3 + -1;
            UNLOCK();
          }
          if (iVar15 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)(pcVar16 + -0x18));
          }
        }
        psVar33 = (string *)volume;
        psVar8 = local_170;
        local_170 = psVar9;
      }
      local_170 = psVar8;
      if (psVar33 != (string *)0x0) {
        rea_operator_delete(psVar33);
      }
LAB_00109e74:
      if (rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_start !=
          (pointer)0x0) {
        rea_operator_delete(rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl
                        ._M_start);
      }
      pbVar24 = index.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_start;
      pbVar11 = index.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_finish;
      pbVar12 = index.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_finish;
      if ((allocator *)((long)buf._M_dataplus._M_p + -0x18) !=
          (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar3 = (int *)((long)buf._M_dataplus._M_p + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
          iVar15 = *(int *)((long)buf._M_dataplus._M_p + -8);
          *(int *)((long)buf._M_dataplus._M_p + -8) = iVar15 + -1;
        }
        else {
          LOCK();
          iVar15 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        if (iVar15 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)((long)buf._M_dataplus._M_p + -0x18));
          pbVar24 = index.
                    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                    ._M_impl._M_start;
          pbVar11 = index.
                    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                    ._M_impl._M_finish;
          pbVar12 = index.
                    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                    ._M_impl._M_finish;
        }
      }
      for (; pbVar14 = index.
                       super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                       ._M_impl._M_finish,
          index.
          super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
          ._M_impl._M_finish != pbVar24; pbVar24 = pbVar24 + 1) {
        pcVar16 = (pbVar24->_M_dataplus)._M_p;
        index.
        super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
        ._M_impl._M_finish = pbVar12;
        if ((allocator *)(pcVar16 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
          piVar3 = (int *)(pcVar16 + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
            iVar15 = *(int *)(pcVar16 + -8);
            *(int *)(pcVar16 + -8) = iVar15 + -1;
          }
          else {
            LOCK();
            iVar15 = *piVar3;
            *piVar3 = *piVar3 + -1;
            UNLOCK();
          }
          if (iVar15 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)(pcVar16 + -0x18));
          }
        }
        pbVar11 = index.
                  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                  ._M_impl._M_start;
        pbVar12 = index.
                  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                  ._M_impl._M_finish;
        index.
        super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
        ._M_impl._M_finish = pbVar14;
      }
      index.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_finish = pbVar12;
      if (pbVar11 != (pointer)0x0) {
        rea_operator_delete(pbVar11);
      }
      std__________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____________M_erase((_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__
                  *)&usable,(_Link_type)usable._M_t._M_impl._M_header._M_parent);
      std__________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____________M_erase(&hold._M_t,(_Link_type)hold._M_t._M_impl._M_header._M_parent);
      std__________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______________M_erase(&se_alphas._M_t,(_Link_type)se_alphas._M_t._M_impl._M_header._M_parent);
      std__________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____________M_erase(&se_volume._M_t,(_Link_type)se_volume._M_t._M_impl._M_header._M_parent);
      std__________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____________M_erase(&se_prc._M_t,(_Link_type)se_prc._M_t._M_impl._M_header._M_parent);
      if ((allocator *)((long)ts._M_dataplus._M_p + -0x18) !=
          (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar3 = (int *)((long)ts._M_dataplus._M_p + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
          iVar15 = *(int *)((long)ts._M_dataplus._M_p + -8);
          *(int *)((long)ts._M_dataplus._M_p + -8) = iVar15 + -1;
        }
        else {
          LOCK();
          iVar15 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        if (iVar15 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)((long)ts._M_dataplus._M_p + -0x18));
        }
      }
      if ((allocator *)(local_268[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar3 = (int *)(local_268[0] + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
          iVar15 = *(int *)(local_268[0] + -8);
          *(int *)(local_268[0] + -8) = iVar15 + -1;
        }
        else {
          LOCK();
          iVar15 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        if (iVar15 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(local_268[0] + -0x18));
        }
      }
                    /* Unresolved local var: _object * pa@[???]
                       Unresolved local var: _object * pb@[DW_OP_reg3(RBX)]
                       Unresolved local var: PyObject * tup@[???] */
      p_Var20 = (_typeobject *)
                rea_PyBytes_FromStringAndSize
                          (r.first._M_dataplus._M_p,
                           *(undefined8 *)((long)r.first._M_dataplus._M_p + -0x18));
                    /* Unresolved local var: _object * pb@[???]
                       Unresolved local var: PyObject * tup@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: PyObject * o@[???] */
      iVar15 = (int)((long)r.second.first.
                           super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                           ._M_impl._M_finish -
                     (long)r.second.first.
                           super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                           ._M_impl._M_start >> 3);
      uVar21 = rea_PyList_New((long)iVar15);
                    /* Unresolved local var: int i@[???] */
      lVar37 = 0;
      if (0 < iVar15) {
        do {
          pcVar16 = r.second.first.
                    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                    ._M_impl._M_start[lVar37]._M_dataplus._M_p;
          uVar22 = rea_PyBytes_FromStringAndSize(pcVar16,*(undefined8 *)(pcVar16 + -0x18));
          rea_PyList_SetItem(uVar21,lVar37,uVar22);
          lVar37 = lVar37 + 1;
        } while ((int)lVar37 < iVar15);
      }
      uVar22 = rea_PyBytes_FromStringAndSize
                         (r.second.second._M_dataplus._M_p,
                          *(undefined8 *)((long)r.second.second._M_dataplus._M_p + -0x18));
      lVar37 = rea_PyTuple_New(2);
      *(undefined8 *)(lVar37 + 0x18) = uVar21;
      *(undefined8 *)(lVar37 + 0x20) = uVar22;
      pPVar34 = (PyObject *)rea_PyTuple_New(2);
      pPVar34[1].ob_type = p_Var20;
      pPVar34[2].ob_refcnt = lVar37;
      ppVar36 = (pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___
                 *)((long)r.second.second._M_dataplus._M_p + -0x18);
      pbVar24 = r.second.first.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_start;
      pbVar11 = r.second.first.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_finish;
      pbVar12 = r.second.first.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_finish;
      if (ppVar36 !=
          (pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___
           *)PTR__S_empty_rep_storage_00311ff0) goto LAB_0010aa4d;
    }
    else {
      if (pPVar34 < (PyObject *)0x2000000000000000) {
        uVar35 = (long)pPVar34 << 3;
        pbVar24 = rea_operator_new(uVar35);
        goto LAB_00109db2;
      }
      r.second.second._M_dataplus._M_p = (_Alloc_hider)rea_std____throw_bad_alloc();
LAB_0010aa4d:
      ppbVar2 = &(ppVar36->second).first.
                 super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                 ._M_impl._M_finish;
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar15 = *(int *)((long)r.second.second._M_dataplus._M_p + -8);
        *(int *)((long)r.second.second._M_dataplus._M_p + -8) = iVar15 + -1;
      }
      else {
        LOCK();
        iVar15 = *(int *)ppbVar2;
        *(int *)ppbVar2 = *(int *)ppbVar2 + -1;
        UNLOCK();
      }
      pbVar24 = r.second.first.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_start;
      pbVar11 = r.second.first.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_finish;
      pbVar12 = r.second.first.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_finish;
      if (iVar15 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)ppVar36);
        pbVar24 = r.second.first.
                  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                  ._M_impl._M_start;
        pbVar11 = r.second.first.
                  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                  ._M_impl._M_finish;
        pbVar12 = r.second.first.
                  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                  ._M_impl._M_finish;
      }
    }
    for (; pbVar14 = r.second.first.
                     super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                     ._M_impl._M_finish,
        r.second.first.
        super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
        ._M_impl._M_finish != pbVar24; pbVar24 = pbVar24 + 1) {
      pcVar16 = (pbVar24->_M_dataplus)._M_p;
      r.second.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_finish = pbVar12;
      if ((allocator *)(pcVar16 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar3 = (int *)(pcVar16 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
          iVar15 = *(int *)(pcVar16 + -8);
          *(int *)(pcVar16 + -8) = iVar15 + -1;
        }
        else {
          LOCK();
          iVar15 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        if (iVar15 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(pcVar16 + -0x18));
        }
      }
      pbVar11 = r.second.first.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_start;
      pbVar12 = r.second.first.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_finish;
      r.second.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_finish = pbVar14;
    }
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = pbVar12;
    if (pbVar11 != (pointer)0x0) {
      rea_operator_delete(pbVar11);
    }
    ppVar36 = (pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___
               *)((long)r.first._M_dataplus._M_p + -0x18);
    if (ppVar36 ==
        (pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___
         *)PTR__S_empty_rep_storage_00311ff0) {
      return pPVar34;
    }
    piVar3 = (int *)((long)r.first._M_dataplus._M_p + -8);
    bVar27._M_dataplus._M_p = r.first._M_dataplus._M_p;
    if (PTR___pthread_key_create_00311fd8 != (undefined *)0x0) {
      LOCK();
      iVar15 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
      goto LAB_0010ab48;
    }
  }
  else {
    volume = 0.0;
    local_170 = (string *)0x0;
    local_168 = 0;
    prc = 0.0;
    uv = (double)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    local_188 = 0;
    local_190 = (string *)0x0;
    rea_std__string__string(&local_180,(string *)&uv);
    ppVar36 = &r;
    rea_std__string__string(ppVar36,"",&local_279);
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_start = (pointer)0x0;
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = (pointer)0x0;
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_end_of_storage = (pointer)0x0;
    pPVar34 = (PyObject *)((long)local_190 - (long)prc >> 3);
    if (pPVar34 == (PyObject *)0x0) {
      uVar35 = 0;
      pbVar24 = (pointer)0x0;
LAB_0010a30d:
      psVar33 = local_190;
      r.second.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_end_of_storage = (pointer)((long)&(pbVar24->_M_dataplus)._M_p + uVar35);
      r.second.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_start = pbVar24;
      r.second.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_finish = pbVar24;
                    /* Unresolved local var:
                       basic_string_char__std__char_traits_char__std__allocator_char_ *
                       __cur@[???] */
      for (psVar25 = (string *)prc; psVar25 != psVar33; psVar25 = psVar25 + 1) {
        if (pbVar24 != (pointer)0x0) {
          rea_std__string__string(pbVar24,psVar25);
        }
        pbVar24 = pbVar24 + 1;
      }
      r.second.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_finish = pbVar24;
      rea_std__string__string(&r.second.second,&local_180);
      psVar25 = (string *)prc;
      psVar33 = local_190;
      psVar8 = local_190;
      if ((allocator *)((long)local_180._M_dataplus._M_p + -0x18) !=
          (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar3 = (int *)((long)local_180._M_dataplus._M_p + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
          iVar15 = *(int *)((long)local_180._M_dataplus._M_p + -8);
          *(int *)((long)local_180._M_dataplus._M_p + -8) = iVar15 + -1;
        }
        else {
          LOCK();
          iVar15 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        if (iVar15 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)((long)local_180._M_dataplus._M_p + -0x18));
          psVar25 = (string *)prc;
          psVar33 = local_190;
          psVar8 = local_190;
        }
      }
      for (; psVar9 = local_190, local_190 != psVar25; psVar25 = psVar25 + 1) {
        pcVar16 = (psVar25->_M_dataplus)._M_p;
        local_190 = psVar8;
        if ((allocator *)(pcVar16 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
          piVar3 = (int *)(pcVar16 + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
            iVar15 = *(int *)(pcVar16 + -8);
            *(int *)(pcVar16 + -8) = iVar15 + -1;
          }
          else {
            LOCK();
            iVar15 = *piVar3;
            *piVar3 = *piVar3 + -1;
            UNLOCK();
          }
          if (iVar15 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)(pcVar16 + -0x18));
          }
        }
        psVar33 = (string *)prc;
        psVar8 = local_190;
        local_190 = psVar9;
      }
      local_190 = psVar8;
      psVar25 = (string *)volume;
      psVar9 = local_170;
      psVar10 = local_170;
      if (psVar33 != (string *)0x0) {
        rea_operator_delete(psVar33);
        psVar25 = (string *)volume;
        psVar9 = local_170;
        psVar10 = local_170;
      }
      for (; psVar33 = local_170, local_170 != psVar25; psVar25 = psVar25 + 1) {
        pcVar16 = (psVar25->_M_dataplus)._M_p;
        local_170 = psVar10;
        if ((allocator *)(pcVar16 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
          piVar3 = (int *)(pcVar16 + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
            iVar15 = *(int *)(pcVar16 + -8);
            *(int *)(pcVar16 + -8) = iVar15 + -1;
          }
          else {
            LOCK();
            iVar15 = *piVar3;
            *piVar3 = *piVar3 + -1;
            UNLOCK();
          }
          if (iVar15 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)(pcVar16 + -0x18));
          }
        }
        psVar9 = (string *)volume;
        psVar10 = local_170;
        local_170 = psVar33;
      }
      local_170 = psVar10;
      if (psVar9 != (string *)0x0) {
        rea_operator_delete(psVar9);
      }
      rea_std__string___Rep___M_dispose((allocator *)((long)uv + -0x18));
      goto LAB_00109e74;
    }
    if (pPVar34 < (PyObject *)0x2000000000000000) {
      uVar35 = (long)pPVar34 << 3;
      pbVar24 = rea_operator_new(uVar35);
      goto LAB_0010a30d;
    }
    bVar27._M_dataplus._M_p = (_Alloc_hider)rea_std____throw_bad_alloc();
  }
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
  iVar15 = *(int *)((long)bVar27._M_dataplus._M_p + -8);
  *(int *)((long)bVar27._M_dataplus._M_p + -8) = iVar15 + -1;
LAB_0010ab48:
  if (iVar15 < 1) {
    rea_std__string___Rep___M_destroy((allocator *)ppVar36);
  }
  return pPVar34;
}





// ------------------------------------------------------------------
// IDX 160  0010ab80  PyWrapper<std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char____
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char__dup2(undefined8 * pyargs)
{
  pointer puVar1;
  int *piVar2;
  uchar *puVar3;
  uchar uVar4;
  _Base_ptr p_Var5;
  pointer pdVar6;
  string *psVar7;
  pointer pvVar8;
  pointer pvVar9;
  pointer pvVar10;
  pointer pbVar11;
  pointer pbVar12;
  pointer pbVar13;
  pointer pvVar14;
  basic_string_char__std__char_traits_char__std__allocator_char_ bVar15;
  int iVar16;
  int iVar17;
  char *pcVar18;
  ulong *puVar19;
  _Alloc_hider p;
  string sVar20;
  _Rb_tree_node_base *p_Var21;
  _Base_ptr p_Var22;
  _typeobject *p_Var23;
  undefined8 uVar24;
  undefined8 uVar25;
  PyObject *pPVar26;
  string *psVar27;
  pointer puVar28;
  pointer pbVar29;
  uchar *puVar30;
  _Base_ptr p_Var31;
  long lVar32;
  string *psVar33;
  void *pvVar34;
  _Rb_tree_node_base *p_Var35;
  pointer __src;
  pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___
  *ppVar36;
  pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___
  *ppVar37;
  pointer puVar38;
  ulong uVar39;
  pointer puVar40;
  bool bVar41;
  undefined1 local_1e0 [2];
  allocator local_1de [2];
  allocator local_1dc;
  undefined1 local_1db [2];
  allocator local_1d9;
  undefined1 local_1d8;
  undefined1 local_1d7;
  undefined1 local_1d6;
  undefined1 local_1d5;
  undefined1 local_1d4;
  undefined1 local_1d3;
  undefined1 local_1d2;
  undefined4 local_1c8;
  undefined2 local_1c4;
  undefined1 local_1c2;
  undefined4 local_1b8;
  undefined2 local_1b4;
  undefined1 local_1b2;
  parse_ctx t;
  uchar *local_198 [2];
  string ts;
  string buf;
  string fmt;
  void *local_158 [2];
  string s_1;
  vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___
  index;
  vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double___
  values;
  vector_unsigned_char__std__allocator_unsigned_char_ rv;
  string local_c0;
  pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char__
  local_b8;
  pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___
  r;
  SliceData s;
  _object *pa;
  
  s._M_t._M_impl._M_key_compare.
  super_binary_function<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__basic_string_char__std__char_traits_char__std__allocator_char_,_bool>
       = (binary_function<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__basic_string_char__std__char_traits_char__std__allocator_char_,_bool>
          )0x4f;
  s._M_t.(*(undefined1 *)((uint8_t *)&_M_impl + 0x1)) = 0;
  iVar16 = rea_PyArg_ParseTuple(pyargs,(allocator *)&s,&t);
  if (iVar16 == 0) {
    return (PyObject *)0x0;
  }
  if (((t.v)->ob_type->tp_flags & 0x8000000) == 0) {
    pcVar18 = (char *)rea_PyUnicode_AsUTF8();
    rea_std__string__string(local_198,pcVar18,(allocator *)&s);
  }
  else {
    uVar39 = rea_PyBytes_Size();
    pcVar18 = (char *)rea_PyBytes_AsString(t.v);
    rea_std__string__string(local_198,pcVar18,uVar39,(allocator *)&s);
  }
  puVar30 = local_198[0];
  s._M_t._M_impl._M_node_count = 0;
  s._M_t._M_impl._M_header._M_color = _S_red;
  s._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  uVar39 = *(ulong *)(local_198[0] + -0x18);
  ts._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
  s._M_t._M_impl._M_header._M_left = &s._M_t._M_impl._M_header;
                    /* Unresolved local var: size_type __n@[???] */
  puVar28 = (pointer)0x0;
  index.
  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
  ._M_impl._M_start = (pointer)0x0;
  index.
  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
  ._M_impl._M_finish = (pointer)0x0;
  index.
  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
  ._M_impl._M_end_of_storage = (pointer)0x0;
  values.
  super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
  ._M_impl._M_start = (pointer)0x0;
  values.
  super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
  ._M_impl._M_finish = (pointer)0x0;
  values.
  super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
  ._M_impl._M_end_of_storage = (pointer)0x0;
  rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_start =
       (pointer)0x0;
  rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_finish =
       (pointer)0x0;
  rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_end_of_storage =
       (pointer)0x0;
  buf._M_dataplus._M_p = ts._M_dataplus._M_p;
  s._M_t._M_impl._M_header._M_right = s._M_t._M_impl._M_header._M_left;
  if (uVar39 != 0) {
    puVar28 = rea_operator_new(uVar39);
  }
  puVar40 = puVar28 + uVar39;
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: _Distance __n@[???] */
  puVar3 = puVar30 + uVar39;
  puVar38 = puVar28;
  rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_start = puVar28;
  rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_end_of_storage =
       puVar40;
  if ((long)uVar39 < 1) {
    fmt._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_finish = puVar28
    ;
LAB_0010af6e:
    iVar16 = (int)puVar40;
    sVar20._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18)
    ;
LAB_0010af79:
    bVar41 = false;
  }
  else {
    do {
      uVar4 = *puVar30;
      puVar30 = puVar30 + 1;
      *puVar38 = uVar4;
      puVar38 = puVar38 + 1;
    } while (puVar30 != puVar3);
                    /* Unresolved local var: size_t l@[???]
                       Unresolved local var: size_t np@[???]
                       Unresolved local var: size_t p@[???] */
    puVar38 = puVar40 + -(long)puVar28;
    fmt._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
                    /* Unresolved local var: uint8_t * s@[???] */
    rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_finish = puVar40
    ;
    if (puVar38 < (pointer)0x8) goto LAB_0010af6e;
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
    ppVar36 = &r;
    __src = puVar28 + 8;
    puVar40 = puVar28;
    rea_memcpy(ppVar36,puVar28,8);
    bVar15 = r.first;
                    /* Unresolved local var: size_t l@[???]
                       Unresolved local var: size_t np@[???]
                       Unresolved local var: uint8_t * s@[???] */
    if (puVar38 < (pointer)0x10) goto LAB_0010af6e;
    puVar1 = puVar28 + 0x10;
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
    if ((long)puVar1 - (long)__src != 0) {
      rea_memcpy(ppVar36,__src,(long)puVar1 - (long)__src);
      puVar40 = __src;
    }
    p = r.first._M_dataplus._M_p + 0x10;
    if (puVar38 < p._M_p) goto LAB_0010af6e;
    puVar40 = puVar1 + (long)r.first._M_dataplus._M_p;
                    /* Unresolved local var: size_type __dnew@[???]
                       Unresolved local var: _Rep * __r@[???] */
    if (puVar1 == puVar40) {
      s_1._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    }
    else {
      uVar39 = (long)puVar40 - (long)puVar1;
      puVar19 = (ulong *)rea_std__string___Rep___S_create(uVar39,0,local_1de);
      s_1._M_dataplus._M_p = (_Alloc_hider)(puVar19 + 3);
      puVar38 = (pointer)0x0;
      do {
        *(uchar *)((long)s_1._M_dataplus._M_p + (long)puVar38) = puVar28[(long)(puVar38 + 0x10)];
        puVar38 = puVar38 + 1;
      } while (puVar38 != puVar40 + (-0x10 - (long)puVar28));
      if (puVar19 != (ulong *)PTR__S_empty_rep_storage_00311ff0) {
        *(undefined4 *)(puVar19 + 2) = 0;
        *puVar19 = uVar39;
        *(undefined1 *)((long)puVar19 + uVar39 + 0x18) = 0;
      }
    }
    iVar16 = (int)&s_1;
    rea_std__string__assign(&fmt);
    if ((allocator *)((long)s_1._M_dataplus._M_p + -0x18) !=
        (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar2 = (int *)((long)s_1._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar17 = *(int *)((long)s_1._M_dataplus._M_p + -8);
        *(int *)((long)s_1._M_dataplus._M_p + -8) = iVar17 + -1;
      }
      else {
        LOCK();
        iVar17 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar17 < 1) {
        ppVar37 = ppVar36;
        rea_std__string___Rep___M_destroy((allocator *)((long)s_1._M_dataplus._M_p + -0x18));
        iVar16 = (int)ppVar37;
      }
    }
    sVar20._M_dataplus._M_p = fmt._M_dataplus._M_p;
    if ((pointer)p._M_p == (pointer)0x8) goto LAB_0010af79;
    local_1c8 = 0x73504d73;
    pcVar18 = (char *)&local_1b8;
    local_1c4 = 0x6456;
    local_1b8 = 0x73504d73;
    r.first._M_dataplus._M_p =
         (_Alloc_hider)
         (CONCAT26(r.first._M_dataplus.(*(undefined2 *)((uint8_t *)&_M_p + 0x6)),0x645673504d73) & 0xff00ffffffffffff);
    local_1d2 = 0;
    local_1d8 = 0x73;
    local_1d7 = 0x4d;
    local_1d6 = 0x50;
    local_1d5 = 0x73;
    local_1d4 = 0x56;
    local_1d3 = 100;
    local_1c2 = 0;
    local_1b4 = 0x6456;
    local_1b2 = 0;
    rea_std__string__string(local_158,pcVar18,&local_1dc);
    iVar16 = (int)pcVar18;
    bVar41 = true;
    if (*(size_t *)((long)fmt._M_dataplus._M_p + -0x18) == *(size_t *)((long)local_158[0] + -0x18))
    {
      pvVar34 = local_158[0];
      iVar17 = rea_memcmp((void *)fmt._M_dataplus._M_p,local_158[0],
                      *(size_t *)((long)fmt._M_dataplus._M_p + -0x18));
      iVar16 = (int)pvVar34;
      bVar41 = iVar17 != 0;
    }
    if ((allocator *)((long)local_158[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0)
    {
      piVar2 = (int *)((long)local_158[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar17 = *(int *)((long)local_158[0] + -8);
        *(int *)((long)local_158[0] + -8) = iVar17 + -1;
      }
      else {
        LOCK();
        iVar17 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar17 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long)local_158[0] + -0x18));
        iVar16 = (int)ppVar36;
      }
    }
    if (bVar41) {
      bVar41 = false;
      sVar20._M_dataplus._M_p = fmt._M_dataplus._M_p;
    }
    else {
                    /* Unresolved local var: size_t np@[???] */
      puVar28 = (pointer)p._M_p;
      puVar40 = (pointer)detail____________________________P_std__basic_string_char__std__char_traits_char__std__allocator_char______________________________parse(&rv,(size_t)p._M_p,&ts);
      iVar16 = (int)puVar28;
      if ((pointer)p._M_p != puVar40) {
                    /* Unresolved local var: size_t np@[???] */
        p._M_p = (char *)detail::
                         rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____M___parse(&rv,(size_t)puVar40,
                                 (map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
                                  *)&s);
        iVar16 = (int)puVar40;
      }
      bVar41 = bVar15._M_dataplus._M_p == (_Alloc_hider)p._M_p;
      sVar20._M_dataplus._M_p = fmt._M_dataplus._M_p;
    }
  }
  if ((allocator *)((long)sVar20._M_dataplus._M_p + -0x18) !=
      (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar2 = (int *)((long)sVar20._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
      iVar17 = *(int *)((long)sVar20._M_dataplus._M_p + -8);
      *(int *)((long)sVar20._M_dataplus._M_p + -8) = iVar17 + -1;
    }
    else {
      LOCK();
      iVar17 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar17 < 1) {
      iVar16 = (int)&r;
      rea_std__string___Rep___M_destroy((allocator *)((long)sVar20._M_dataplus._M_p + -0x18));
    }
  }
  if (bVar41) {
                    /* Unresolved local var:
                       pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__
                       * p@[???]
                       Unresolved local var:
                       map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
                       * __for_range@[???]
                       Unresolved local var: iterator __for_begin@[???]
                       Unresolved local var: iterator __for_end@[???] */
    p_Var21 = &s._M_t._M_impl._M_header;
    if (s._M_t._M_impl._M_header._M_left != p_Var21) {
      p_Var22 = s._M_t._M_impl._M_header._M_left;
      do {
        p_Var35 = p_Var22 + 1;
        if (index.
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            ._M_impl._M_finish ==
            index.
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            ._M_impl._M_end_of_storage) {
          std_____________vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char____________________________M_emplace_back_aux_const_std__basic_string_char__std__char_traits_char__std__allocator_char_______________________(&index);
          iVar16 = (int)p_Var35;
        }
        else {
          if (index.
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              ._M_impl._M_finish == (pointer)0x0) {
            index.
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            ._M_impl._M_finish = (pointer)0x0;
          }
          else {
            rea_std__string__string(index.
                                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                                ._M_impl._M_finish,(string *)p_Var35);
          }
          iVar16 = (int)p_Var35;
          index.
          super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
          ._M_impl._M_finish =
               index.
               super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
               ._M_impl._M_finish + 1;
        }
                    /* Unresolved local var: vector_double__std__allocator_double_ *
                       __for_range@[???]
                       Unresolved local var: iterator __for_begin@[???]
                       Unresolved local var: iterator __for_end@[???] */
        p_Var5 = p_Var22[1]._M_left;
        for (p_Var31 = p_Var22[1]._M_parent; p_Var31 != p_Var5;
            p_Var31 = (_Base_ptr)&p_Var31->_M_parent) {
          r.first._M_dataplus._M_p = *(_Alloc_hider *)p_Var31;
          ppVar36 = &r;
          rea_std__string__append((char *)&buf,(ulong)&r);
          iVar16 = (int)ppVar36;
        }
        p_Var22 = (_Base_ptr)rea_std___Rb_tree_increment(p_Var22);
      } while (p_Var22 != p_Var21);
    }
    local_b8.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_start = (string *)0x0;
    local_b8.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = (string *)0x0;
    local_b8.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_end_of_storage = (pointer)0x0;
    uVar39 = (long)index.
                   super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                   ._M_impl._M_finish -
             (long)index.
                   super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                   ._M_impl._M_start >> 3;
    if (uVar39 == 0) {
      uVar39 = 0;
      psVar27 = (string *)0x0;
    }
    else {
      if (0x1fffffffffffffff < uVar39) {
        uVar24 = rea_std____throw_bad_alloc();
        if (rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_start !=
            (pointer)0x0) {
          rea_operator_delete(rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>.
                          _M_impl._M_start);
        }
        goto LAB_0010b98f;
      }
      uVar39 = uVar39 * 8;
      psVar27 = rea_operator_new(uVar39);
    }
    pbVar29 = index.
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              ._M_impl._M_finish;
    local_b8.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_end_of_storage = (pointer)((long)&(psVar27->_M_dataplus)._M_p + uVar39);
    local_b8.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_start = psVar27;
    local_b8.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = psVar27;
                    /* Unresolved local var:
                       basic_string_char__std__char_traits_char__std__allocator_char_ *
                       __cur@[???] */
    for (psVar33 = index.
                   super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                   ._M_impl._M_start; psVar33 != pbVar29; psVar33 = psVar33 + 1) {
      if (psVar27 != (string *)0x0) {
        rea_std__string__string(psVar27,psVar33);
      }
      psVar27 = psVar27 + 1;
    }
    local_b8.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = psVar27;
    rea_std__string__string(&local_b8.second,&buf);
    rea_std__string__string(&r,&ts);
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_start = (pointer)0x0;
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = (pointer)0x0;
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_end_of_storage = (pointer)0x0;
    uVar39 = (long)local_b8.first.
                   super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                   ._M_impl._M_finish -
             (long)local_b8.first.
                   super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                   ._M_impl._M_start >> 3;
    if (uVar39 == 0) {
      uVar39 = 0;
      pbVar29 = (pointer)0x0;
    }
    else {
      if (0x1fffffffffffffff < uVar39) {
        uVar24 = rea_std____throw_bad_alloc();
        iVar16 = (int)local_1db;
        rea_std__string___Rep___M_dispose((allocator *)((long)r.first._M_dataplus._M_p + -0x18));
        std___________pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char______________pair(&local_b8,iVar16);
        if (rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_start !=
            (pointer)0x0) {
          rea_operator_delete(rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>.
                          _M_impl._M_start);
        }
LAB_0010b98f:
        iVar17 = (int)local_1e0;
        std___________vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double_______________vector(&values,iVar16);
        rea_std__string___Rep___M_dispose((allocator *)((long)buf._M_dataplus._M_p + -0x18));
        std___________vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______________vector(&index,iVar17);
        std____________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________________M_erase((_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
                    *)&s,(_Link_type)s._M_t._M_impl._M_header._M_parent);
        rea_std__string___Rep___M_dispose((allocator *)((long)ts._M_dataplus._M_p + -0x18));
        rea_std__string___Rep___M_dispose((allocator *)(local_198[0] + -0x18));
                    /* WARNING: Subroutine does not return */
        rea__Unwind_Resume(uVar24);
      }
      uVar39 = uVar39 << 3;
      pbVar29 = rea_operator_new(uVar39);
    }
    pbVar11 = local_b8.first.
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              ._M_impl._M_finish;
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_end_of_storage = (pointer)((long)&(pbVar29->_M_dataplus)._M_p + uVar39);
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_start = pbVar29;
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = pbVar29;
                    /* Unresolved local var:
                       basic_string_char__std__char_traits_char__std__allocator_char_ *
                       __cur@[???] */
    for (psVar27 = local_b8.first.
                   super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                   ._M_impl._M_start; psVar27 != pbVar11; psVar27 = psVar27 + 1) {
      if (pbVar29 != (pointer)0x0) {
        rea_std__string__string(pbVar29,psVar27);
      }
      pbVar29 = pbVar29 + 1;
    }
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = pbVar29;
    rea_std__string__string(&r.second.second,&local_b8.second);
    psVar27 = local_b8.first.
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              ._M_impl._M_start;
    psVar33 = local_b8.first.
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              ._M_impl._M_finish;
    psVar7 = local_b8.first.
             super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
             ._M_impl._M_finish;
    if ((allocator *)((long)local_b8.second._M_dataplus._M_p + -0x18) !=
        (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar2 = (int *)((long)local_b8.second._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar16 = *(int *)((long)local_b8.second._M_dataplus._M_p + -8);
        *(int *)((long)local_b8.second._M_dataplus._M_p + -8) = iVar16 + -1;
      }
      else {
        LOCK();
        iVar16 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar16 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long)local_b8.second._M_dataplus._M_p + -0x18))
        ;
        psVar27 = local_b8.first.
                  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                  ._M_impl._M_start;
        psVar33 = local_b8.first.
                  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                  ._M_impl._M_finish;
        psVar7 = local_b8.first.
                 super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                 ._M_impl._M_finish;
      }
    }
    for (; pbVar29 = local_b8.first.
                     super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                     ._M_impl._M_finish,
        local_b8.first.
        super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
        ._M_impl._M_finish != psVar27; psVar27 = psVar27 + 1) {
      pcVar18 = (psVar27->_M_dataplus)._M_p;
      local_b8.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_finish = psVar7;
      if ((allocator *)(pcVar18 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar2 = (int *)(pcVar18 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
          iVar16 = *(int *)(pcVar18 + -8);
          *(int *)(pcVar18 + -8) = iVar16 + -1;
        }
        else {
          LOCK();
          iVar16 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
        }
        if (iVar16 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(pcVar18 + -0x18));
        }
      }
      psVar33 = local_b8.first.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_start;
      psVar7 = local_b8.first.
               super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
               ._M_impl._M_finish;
      local_b8.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_finish = pbVar29;
    }
    local_b8.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = psVar7;
    if (psVar33 != (string *)0x0) {
      rea_operator_delete(psVar33);
    }
  }
  else {
    local_b8.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_start = (string *)0x0;
    local_b8.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = (string *)0x0;
    local_b8.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_end_of_storage = (pointer)0x0;
    s_1._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    rea_std__string__string(&local_c0,&s_1);
    rea_std__string__string(&r,"",&local_1d9);
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_end_of_storage = (pointer)0x0;
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_start = (pointer)0x0;
                    /* Unresolved local var:
                       basic_string_char__std__char_traits_char__std__allocator_char_ *
                       __cur@[???] */
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = (pointer)0x0;
    rea_std__string__string(&r.second.second,&local_c0);
    psVar27 = local_b8.first.
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              ._M_impl._M_start;
    psVar33 = local_b8.first.
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              ._M_impl._M_finish;
    psVar7 = local_b8.first.
             super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
             ._M_impl._M_finish;
    if ((allocator *)((long)local_c0._M_dataplus._M_p + -0x18) !=
        (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar2 = (int *)((long)local_c0._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar16 = *(int *)((long)local_c0._M_dataplus._M_p + -8);
        *(int *)((long)local_c0._M_dataplus._M_p + -8) = iVar16 + -1;
      }
      else {
        LOCK();
        iVar16 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar16 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long)local_c0._M_dataplus._M_p + -0x18));
        psVar27 = local_b8.first.
                  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                  ._M_impl._M_start;
        psVar33 = local_b8.first.
                  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                  ._M_impl._M_finish;
        psVar7 = local_b8.first.
                 super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                 ._M_impl._M_finish;
      }
    }
    for (; pbVar29 = local_b8.first.
                     super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                     ._M_impl._M_finish,
        local_b8.first.
        super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
        ._M_impl._M_finish != psVar27; psVar27 = psVar27 + 1) {
      pcVar18 = (psVar27->_M_dataplus)._M_p;
      local_b8.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_finish = psVar7;
      if ((allocator *)(pcVar18 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar2 = (int *)(pcVar18 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
          iVar16 = *(int *)(pcVar18 + -8);
          *(int *)(pcVar18 + -8) = iVar16 + -1;
        }
        else {
          LOCK();
          iVar16 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
        }
        if (iVar16 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(pcVar18 + -0x18));
        }
      }
      psVar33 = local_b8.first.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_start;
      psVar7 = local_b8.first.
               super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
               ._M_impl._M_finish;
      local_b8.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_finish = pbVar29;
    }
    local_b8.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = psVar7;
    if (psVar33 != (string *)0x0) {
      rea_operator_delete(psVar33);
    }
    if ((allocator *)((long)s_1._M_dataplus._M_p + -0x18) !=
        (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar2 = (int *)((long)s_1._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar16 = *(int *)((long)s_1._M_dataplus._M_p + -8);
        *(int *)((long)s_1._M_dataplus._M_p + -8) = iVar16 + -1;
      }
      else {
        LOCK();
        iVar16 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar16 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long)s_1._M_dataplus._M_p + -0x18));
      }
    }
  }
  pvVar8 = values.
           super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
           ._M_impl._M_start;
  pvVar9 = values.
           super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
           ._M_impl._M_finish;
  pvVar10 = values.
            super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
            ._M_impl._M_finish;
  if (rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl._M_start !=
      (pointer)0x0) {
    rea_operator_delete(rv.super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>._M_impl.
                    _M_start);
    pvVar8 = values.
             super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
             ._M_impl._M_start;
    pvVar9 = values.
             super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
             ._M_impl._M_finish;
    pvVar10 = values.
              super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
              ._M_impl._M_finish;
  }
  for (; pvVar14 = values.
                   super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
                   ._M_impl._M_finish,
      values.
      super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
      ._M_impl._M_finish != pvVar8; pvVar8 = pvVar8 + 1) {
    pdVar6 = (pvVar8->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
    values.
    super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
    ._M_impl._M_finish = pvVar10;
    if (pdVar6 != (pointer)0x0) {
      rea_operator_delete(pdVar6);
    }
    pvVar9 = values.
             super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
             ._M_impl._M_start;
    pvVar10 = values.
              super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
              ._M_impl._M_finish;
    values.
    super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
    ._M_impl._M_finish = pvVar14;
  }
  values.
  super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
  ._M_impl._M_finish = pvVar10;
  if (pvVar9 != (pointer)0x0) {
    rea_operator_delete(pvVar9);
  }
  pbVar29 = index.
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            ._M_impl._M_start;
  pbVar11 = index.
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            ._M_impl._M_finish;
  pbVar12 = index.
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            ._M_impl._M_finish;
  if ((allocator *)((long)buf._M_dataplus._M_p + -0x18) !=
      (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar2 = (int *)((long)buf._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
      iVar16 = *(int *)((long)buf._M_dataplus._M_p + -8);
      *(int *)((long)buf._M_dataplus._M_p + -8) = iVar16 + -1;
    }
    else {
      LOCK();
      iVar16 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar16 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long)buf._M_dataplus._M_p + -0x18));
      pbVar29 = index.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_start;
      pbVar11 = index.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_finish;
      pbVar12 = index.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_finish;
    }
  }
  for (; pbVar13 = index.
                   super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                   ._M_impl._M_finish,
      index.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_finish != pbVar29; pbVar29 = pbVar29 + 1) {
    pcVar18 = (pbVar29->_M_dataplus)._M_p;
    index.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = pbVar12;
    if ((allocator *)(pcVar18 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar2 = (int *)(pcVar18 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar16 = *(int *)(pcVar18 + -8);
        *(int *)(pcVar18 + -8) = iVar16 + -1;
      }
      else {
        LOCK();
        iVar16 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar16 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(pcVar18 + -0x18));
      }
    }
    pbVar11 = index.
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              ._M_impl._M_start;
    pbVar12 = index.
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              ._M_impl._M_finish;
    index.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = pbVar13;
  }
  index.
  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
  ._M_impl._M_finish = pbVar12;
  if (pbVar11 != (pointer)0x0) {
    rea_operator_delete(pbVar11);
  }
  std______Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__________M_erase((_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
              *)&s,(_Link_type)s._M_t._M_impl._M_header._M_parent);
  if ((allocator *)((long)ts._M_dataplus._M_p + -0x18) !=
      (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar2 = (int *)((long)ts._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
      iVar16 = *(int *)((long)ts._M_dataplus._M_p + -8);
      *(int *)((long)ts._M_dataplus._M_p + -8) = iVar16 + -1;
    }
    else {
      LOCK();
      iVar16 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar16 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long)ts._M_dataplus._M_p + -0x18));
    }
  }
  if ((allocator *)(local_198[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar2 = (int *)(local_198[0] + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
      iVar16 = *(int *)(local_198[0] + -8);
      *(int *)(local_198[0] + -8) = iVar16 + -1;
    }
    else {
      LOCK();
      iVar16 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar16 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(local_198[0] + -0x18));
    }
  }
                    /* Unresolved local var: _object * pa@[???]
                       Unresolved local var: _object * pb@[DW_OP_reg3(RBX)]
                       Unresolved local var: PyObject * tup@[???] */
  p_Var23 = (_typeobject *)
            rea_PyBytes_FromStringAndSize
                      (r.first._M_dataplus._M_p,
                       *(undefined8 *)((long)r.first._M_dataplus._M_p + -0x18));
                    /* Unresolved local var: _object * pb@[???]
                       Unresolved local var: PyObject * tup@[???]
                       Unresolved local var: int size@[???]
                       Unresolved local var: PyObject * o@[???] */
  iVar16 = (int)((long)r.second.first.
                       super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                       ._M_impl._M_finish -
                 (long)r.second.first.
                       super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                       ._M_impl._M_start >> 3);
  uVar24 = rea_PyList_New((long)iVar16);
                    /* Unresolved local var: int i@[???] */
  lVar32 = 0;
  if (0 < iVar16) {
    do {
      pcVar18 = r.second.first.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_start[lVar32]._M_dataplus._M_p;
      uVar25 = rea_PyBytes_FromStringAndSize(pcVar18,*(undefined8 *)(pcVar18 + -0x18));
      rea_PyList_SetItem(uVar24,lVar32,uVar25);
      lVar32 = lVar32 + 1;
    } while ((int)lVar32 < iVar16);
  }
  uVar25 = rea_PyBytes_FromStringAndSize
                     (r.second.second._M_dataplus._M_p,
                      *(undefined8 *)((long)r.second.second._M_dataplus._M_p + -0x18));
  lVar32 = rea_PyTuple_New(2);
  *(undefined8 *)(lVar32 + 0x18) = uVar24;
  *(undefined8 *)(lVar32 + 0x20) = uVar25;
  pPVar26 = (PyObject *)rea_PyTuple_New(2);
  pPVar26[1].ob_type = p_Var23;
  pPVar26[2].ob_refcnt = lVar32;
  pbVar29 = r.second.first.
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            ._M_impl._M_start;
  pbVar11 = r.second.first.
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            ._M_impl._M_finish;
  pbVar12 = r.second.first.
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            ._M_impl._M_finish;
  if ((allocator *)((long)r.second.second._M_dataplus._M_p + -0x18) !=
      (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar2 = (int *)((long)r.second.second._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
      iVar16 = *(int *)((long)r.second.second._M_dataplus._M_p + -8);
      *(int *)((long)r.second.second._M_dataplus._M_p + -8) = iVar16 + -1;
    }
    else {
      LOCK();
      iVar16 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar16 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long)r.second.second._M_dataplus._M_p + -0x18));
      pbVar29 = r.second.first.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_start;
      pbVar11 = r.second.first.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_finish;
      pbVar12 = r.second.first.
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                ._M_impl._M_finish;
    }
  }
  for (; pbVar13 = r.second.first.
                   super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                   ._M_impl._M_finish,
      r.second.first.
      super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
      ._M_impl._M_finish != pbVar29; pbVar29 = pbVar29 + 1) {
    pcVar18 = (pbVar29->_M_dataplus)._M_p;
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = pbVar12;
    if ((allocator *)(pcVar18 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar2 = (int *)(pcVar18 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar16 = *(int *)(pcVar18 + -8);
        *(int *)(pcVar18 + -8) = iVar16 + -1;
      }
      else {
        LOCK();
        iVar16 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar16 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(pcVar18 + -0x18));
      }
    }
    pbVar11 = r.second.first.
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              ._M_impl._M_start;
    pbVar12 = r.second.first.
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              ._M_impl._M_finish;
    r.second.first.
    super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
    ._M_impl._M_finish = pbVar13;
  }
  r.second.first.
  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
  ._M_impl._M_finish = pbVar12;
  if (pbVar11 != (pointer)0x0) {
    rea_operator_delete(pbVar11);
  }
  if ((allocator *)((long)r.first._M_dataplus._M_p + -0x18) !=
      (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar2 = (int *)((long)r.first._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
      iVar16 = *(int *)((long)r.first._M_dataplus._M_p + -8);
      *(int *)((long)r.first._M_dataplus._M_p + -8) = iVar16 + -1;
    }
    else {
      LOCK();
      iVar16 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar16 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long)r.first._M_dataplus._M_p + -0x18));
    }
  }
  return pPVar26;
}





// ------------------------------------------------------------------
// IDX 161  0010bef0  std__unique_ptr_SecInfo__Data__std__default_delete_SecInfo__Data____unique_ptr___________
// ------------------------------------------------------------------
void rea_std__unique_ptr_SecInfo__Data__std__default_delete_SecInfo__Data____unique_ptr(unique_ptr_SecInfo__Data__std__default_delete_SecInfo__Data_ * this_ptr, int __in_chrg)
{
  _Tuple_impl_0ul__SecInfo__Data___std__default_delete_SecInfo__Data_ _Var1;
  
                    /* Unresolved local var: Data * * __ptr@[???] */
  _Var1 = (this_ptr->_M_t).super__Tuple_impl<0ul,_SecInfo__Data*,_std__default_delete_SecInfo__Data_>;
  if (_Var1 != (_Tuple_impl_0ul__SecInfo__Data___std__default_delete_SecInfo__Data_)0x0) {
    *(undefined4 *)_Var1 = 0;
    *(undefined4 *)((long)_Var1 + 4) = 0;
    if (*(void **)((long)_Var1 + 8) != (void *)0x0) {
      rea_operator_delete(*(void **)((long)_Var1 + 8));
      *(undefined8 *)((long)_Var1 + 8) = 0;
    }
    if (*(void **)((long)_Var1 + 0x10) != (void *)0x0) {
      rea_operator_delete(*(void **)((long)_Var1 + 0x10));
      *(undefined8 *)((long)_Var1 + 0x10) = 0;
    }
    rea_operator_delete((void *)_Var1);
  }
  (this_ptr->_M_t).super__Tuple_impl<0ul,_SecInfo__Data*,_std__default_delete_SecInfo__Data_> =
       (_Tuple_impl_0ul__SecInfo__Data___std__default_delete_SecInfo__Data_)0x0;
  return;
}





// ------------------------------------------------------------------
// IDX 162  0010bf60  PyWrapper<void*_
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_void(undefined8 * pyargs)
{
  int *piVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  void *pvVar5;
  PyObject *pPVar6;
  ulong uVar7;
  allocator local_39;
  parse_ctx t;
  undefined2 local_28;
  undefined6 uStack_26;
  
                    /* Unresolved local var: void * r@[???] */
  local_28 = 0x4f;
  iVar3 = rea_PyArg_ParseTuple(pyargs,&local_28,&t);
  if (iVar3 != 0) {
    if (((t.v)->ob_type->tp_flags & 0x8000000) == 0) {
      pcVar4 = (char *)rea_PyUnicode_AsUTF8();
      rea_std__string__string(&local_28,pcVar4,&local_39);
    }
    else {
      uVar7 = rea_PyBytes_Size();
      pcVar4 = (char *)rea_PyBytes_AsString(t.v);
      rea_std__string__string(&local_28,pcVar4,uVar7,&local_39);
    }
    pvVar5 = rea_pinot_open((string)&local_28);
    lVar2 = CONCAT62(uStack_26,local_28);
    if ((allocator *)(lVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar1 = (int *)(lVar2 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
        iVar3 = *(int *)(lVar2 + -8);
        *(int *)(lVar2 + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
      }
    }
    pPVar6 = (PyObject *)rea_PyLong_FromVoidPtr(pvVar5);
    return pPVar6;
  }
  return (PyObject *)0x0;
}





// ------------------------------------------------------------------
// IDX 163  0010c090  pydetail__PyWrapper<void_
// ------------------------------------------------------------------
PyObject * rea_pydetail__PyWrapper_void(undefined8 * pyargs)
{
  int iVar1;
  void *fp;
  PyObject *pPVar2;
  undefined2 local_28 [8];
  parse_ctx t;
  
  local_28[0] = 0x4f;
  iVar1 = rea_PyArg_ParseTuple(pyargs,local_28,&t);
  pPVar2 = (PyObject *)0x0;
  if (iVar1 != 0) {
    fp = (void *)rea_PyLong_AsVoidPtr(t.v);
    rea_pinot_close(fp);
    pPVar2 = (PyObject *)rea_Py_BuildValue((void *)&DAT_0010fbf2,0);
  }
  return pPVar2;
}





// ------------------------------------------------------------------
// IDX 164  0010c0e0  PyWrapper<std__pair_int__std__basic_string_char__std__char_traits_char__std__allocator_char___
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_std__pair_int__std__basic_string_char__std__char_traits_char__std__allocator_char(undefined8 * pyargs)
{
  int *piVar1;
  int iVar2;
  _typeobject *p_Var3;
  Py_ssize_t PVar4;
  PyObject *pPVar5;
  pair_int__std__basic_string_char__std__char_traits_char__std__allocator_char__ pVar6;
  parse_ctx t;
  pair_int__std__basic_string_char__std__char_traits_char__std__allocator_char__ r;
  
  r.first = CONCAT22(r.(*(undefined2 *)((uint8_t *)&first + 0x2)),0x4f);
  iVar2 = rea_PyArg_ParseTuple(pyargs,&r,&t);
  if (iVar2 != 0) {
    rea_PyLong_AsVoidPtr(t.v);
    pVar6 = rea_pinot_getline(&r);
                    /* Unresolved local var: _object * pa@[???]
                       Unresolved local var: _object * pb@[???]
                       Unresolved local var: PyObject * tup@[???] */
    p_Var3 = (_typeobject *)
             rea_Py_BuildValue((void *)&DAT_0010fbf4,(long)r.first,pVar6.second._M_dataplus._M_p._M_dataplus);
    PVar4 = rea_PyBytes_FromStringAndSize
                      (r.second._M_dataplus._M_p,
                       *(undefined8 *)((long)r.second._M_dataplus._M_p + -0x18));
    pPVar5 = (PyObject *)rea_PyTuple_New(2);
    pPVar5[1].ob_type = p_Var3;
    pPVar5[2].ob_refcnt = PVar4;
    if ((allocator *)((long)r.second._M_dataplus._M_p + -0x18) !=
        (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar1 = (int *)((long)r.second._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
        iVar2 = *(int *)((long)r.second._M_dataplus._M_p + -8);
        *(int *)((long)r.second._M_dataplus._M_p + -8) = iVar2 + -1;
      }
      else {
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar2 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long)r.second._M_dataplus._M_p + -0x18));
      }
    }
    return pPVar5;
  }
  return (PyObject *)0x0;
}





// ------------------------------------------------------------------
// IDX 165  0010c1e0  detail__P_std__basic_string_char__std__char_traits_char__std__allocator_char____parse__________________
// ------------------------------------------------------------------
size_t rea_detail__P_std__basic_string_char__std__char_traits_char__std__allocator_char____parse__dup2(vector_unsigned_char__std__allocator_unsigned_char_ * b, size_t p, string * ps)
{
  int *piVar1;
  ulong uVar2;
  int iVar3;
  ulong *puVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  allocator *paVar8;
  pointer puVar9;
  allocator local_49;
  ulong o;
  
                    /* Unresolved local var: size_t l@[???]
                       Unresolved local var: size_t np@[???]
                       Unresolved local var: uint8_t * s@[???] */
  uVar6 = p + 8;
  puVar9 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl._M_start;
  uVar7 = (long)(b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                _M_finish - (long)puVar9;
  if (uVar6 <= uVar7) {
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
    rea_memcpy(&o,puVar9 + p,8);
    uVar2 = uVar6 + o;
    if (uVar2 <= uVar7) {
      if (ps != (string *)0x0) {
        puVar9 = puVar9 + uVar6;
                    /* Unresolved local var: size_type __dnew@[???]
                       Unresolved local var: _Rep * __r@[???] */
        if (puVar9 == puVar9 + o) {
          o = (ulong)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
          paVar8 = (allocator *)PTR__S_empty_rep_storage_00311ff0;
        }
        else {
          uVar7 = (long)(puVar9 + o) - (long)puVar9;
          puVar4 = (ulong *)rea_std__string___Rep___S_create(uVar7,0,&local_49);
          o = (ulong)(puVar4 + 3);
          uVar6 = 0;
          do {
            uVar5 = uVar6;
            *(uchar *)(o + uVar5) = puVar9[uVar5];
            paVar8 = (allocator *)PTR__S_empty_rep_storage_00311ff0;
            uVar6 = uVar5 + 1;
          } while (uVar6 != uVar7);
          if (puVar4 != (ulong *)PTR__S_empty_rep_storage_00311ff0) {
            *(undefined4 *)(puVar4 + 2) = 0;
            *puVar4 = uVar6;
            *(undefined1 *)((long)puVar4 + uVar5 + 0x19) = 0;
          }
        }
        rea_std__string__assign(ps);
        if ((allocator *)(o - 0x18) != paVar8) {
          piVar1 = (int *)(o - 8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
            iVar3 = *(int *)(o - 8);
            *(int *)(o - 8) = iVar3 + -1;
          }
          else {
            LOCK();
            iVar3 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
          }
          if (iVar3 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)(o - 0x18));
          }
        }
      }
      return uVar2;
    }
  }
  return p;
}





// ------------------------------------------------------------------
// IDX 166  0010c360  std___pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char______pair
// ------------------------------------------------------------------
void rea_std___pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char______pair__dup2(pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char__ * this_ptr, int __in_chrg)
{
  int *piVar1;
  char *pcVar2;
  undefined *puVar3;
  int iVar4;
  pointer pbVar5;
  pointer pbVar6;
  
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
  pcVar2 = (this_ptr->second)._M_dataplus._M_p;
  if ((allocator *)(pcVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar1 = (int *)(pcVar2 + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
      iVar4 = *(int *)(pcVar2 + -8);
      *(int *)(pcVar2 + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
    }
  }
  pbVar6 = (this_ptr->first).
           super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
           ._M_impl._M_finish;
  pbVar5 = (this_ptr->first).
           super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
           ._M_impl._M_start;
  if (pbVar6 != pbVar5) {
    do {
      pcVar2 = (pbVar5->_M_dataplus)._M_p;
      if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar3) {
        piVar1 = (int *)(pcVar2 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
          iVar4 = *(int *)(pcVar2 + -8);
          *(int *)(pcVar2 + -8) = iVar4 + -1;
        }
        else {
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar4 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
        }
      }
      pbVar5 = pbVar5 + 1;
    } while (pbVar6 != pbVar5);
    pbVar6 = (this_ptr->first).
             super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
             ._M_impl._M_start;
  }
  if (pbVar6 != (pointer)0x0) {
    rea_operator_delete(pbVar6);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 167  0010c440  std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char_______pair
// ------------------------------------------------------------------
void rea_std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char_______pair__dup2(pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___ * this_ptr, int __in_chrg)
{
  int *piVar1;
  char *pcVar2;
  undefined *puVar3;
  int iVar4;
  pointer pbVar5;
  pointer pbVar6;
  
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
  pcVar2 = (this_ptr->second).second._M_dataplus._M_p;
  if ((allocator *)(pcVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar1 = (int *)(pcVar2 + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
      iVar4 = *(int *)(pcVar2 + -8);
      *(int *)(pcVar2 + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
    }
  }
  pbVar6 = (this_ptr->second).first.
           super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
           ._M_impl._M_finish;
  pbVar5 = (this_ptr->second).first.
           super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
           ._M_impl._M_start;
  if (pbVar6 != pbVar5) {
    do {
      pcVar2 = (pbVar5->_M_dataplus)._M_p;
      if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar3) {
        piVar1 = (int *)(pcVar2 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
          iVar4 = *(int *)(pcVar2 + -8);
          *(int *)(pcVar2 + -8) = iVar4 + -1;
        }
        else {
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar4 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
        }
      }
      pbVar5 = pbVar5 + 1;
    } while (pbVar6 != pbVar5);
    pbVar6 = (this_ptr->second).first.
             super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
             ._M_impl._M_start;
  }
  if (pbVar6 != (pointer)0x0) {
    rea_operator_delete(pbVar6);
  }
  pcVar2 = (this_ptr->first)._M_dataplus._M_p;
  if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar3) {
    piVar1 = (int *)(pcVar2 + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
      iVar4 = *(int *)(pcVar2 + -8);
      *(int *)(pcVar2 + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 168  0010c560  __gnu_cxx____to_xstring_std__basic_string_char__char
// ------------------------------------------------------------------
basic_string_char__std__char_traits_char__std__allocator_char_ rea___gnu_cxx____to_xstring_std__basic_string_char__char__dup2(code * __convf, size_t __n, char * __fmt, undefined8 param_x3)
{
  undefined8 stack0x00000008;
  undefined1 *__src;
  long lVar1;
  char in_AL;
  int iVar2;
  ulong *puVar3;
  ulong *__dest;
  undefined8 in_RCX;
  undefined8 in_R8;
  undefined8 in_R9;
  ulong __n_00;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM1_Qa;
  undefined8 in_XMM2_Qa;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM4_Qa;
  undefined8 in_XMM5_Qa;
  undefined8 in_XMM6_Qa;
  undefined8 in_XMM7_Qa;
  undefined8 uStack_100;
  allocator local_f1;
  typedef___va_list_tag___va_list_tag __args [1];
  undefined1 local_d8 [32];
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_98;
  undefined8 local_88;
  undefined8 local_78;
  undefined8 local_68;
  undefined8 local_58;
  undefined8 local_48;
  undefined8 local_38;
  
  if (in_AL != '\0') {
    local_a8 = in_XMM0_Qa;
    local_98 = in_XMM1_Qa;
    local_88 = in_XMM2_Qa;
    local_78 = in_XMM3_Qa;
    local_68 = in_XMM4_Qa;
    local_58 = in_XMM5_Qa;
    local_48 = in_XMM6_Qa;
    local_38 = in_XMM7_Qa;
  }
                    /* Unresolved local var: char * __s@[???]
                       Unresolved local var: int __len@[???] */
  __args[0].overflow_arg_area = (void *)&stack0x00000008;
  lVar1 = -((ulong)(__fmt + 0x1e) & 0xfffffffffffffff0);
  __args[0].reg_save_area = local_d8;
  __src = (undefined1 *)((long)__args + lVar1);
  __args[0].gp_offset = 0x20;
  __args[0].fp_offset = 0x30;
  local_b8 = in_R8;
  local_b0 = in_R9;
  *(undefined8 *)((long)&uStack_100 + lVar1) = 0x10c604;
  iVar2 = (*(code *)__n)(__src,__fmt,in_RCX,__args);
                    /* Unresolved local var: size_type __dnew@[???]
                       Unresolved local var: _Rep * __r@[???] */
  if (__src == __src + iVar2) {
    __dest = (ulong *)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
  }
  else {
    __n_00 = (long)(__src + iVar2) - (long)__src;
    *(undefined8 *)((long)&uStack_100 + lVar1) = 0x10c623;
    puVar3 = (ulong *)rea_std__string___Rep___S_create(__n_00,0,&local_f1);
    __dest = puVar3 + 3;
    if (__n_00 == 1) {
      *(undefined1 *)(puVar3 + 3) = *__src;
    }
    else {
      *(undefined8 *)((long)&uStack_100 + lVar1) = 0x10c63e;
      __dest = rea_memcpy(__dest,__src,__n_00);
    }
    if (puVar3 != (ulong *)PTR__S_empty_rep_storage_00311ff0) {
      *(undefined4 *)(puVar3 + 2) = 0;
      *puVar3 = __n_00;
      *(undefined1 *)((long)puVar3 + __n_00 + 0x18) = 0;
    }
  }
  *(ulong **)__convf = __dest;
  return (basic_string_char__std__char_traits_char__std__allocator_char_)(_Alloc_hider)__convf;
}





// ------------------------------------------------------------------
// IDX 169  0010c690  std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______vector
// ------------------------------------------------------------------
void rea_std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______vector__dup2(vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___ * this_ptr, int __in_chrg)
{
  int *piVar1;
  char *pcVar2;
  undefined *puVar3;
  int iVar4;
  pointer pbVar5;
  pointer pbVar6;
  
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
  pbVar6 = (this_ptr->
           super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
           )._M_impl._M_finish;
  pbVar5 = (this_ptr->
           super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
           )._M_impl._M_start;
  if (pbVar6 != pbVar5) {
    do {
      pcVar2 = (pbVar5->_M_dataplus)._M_p;
      if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar3) {
        piVar1 = (int *)(pcVar2 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg2(RCX)] */
          iVar4 = *(int *)(pcVar2 + -8);
          *(int *)(pcVar2 + -8) = iVar4 + -1;
        }
        else {
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = *piVar1 + -1;
          UNLOCK();
        }
        if (iVar4 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
        }
      }
      pbVar5 = pbVar5 + 1;
    } while (pbVar6 != pbVar5);
    pbVar6 = (this_ptr->
             super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
             )._M_impl._M_start;
  }
  if (pbVar6 != (pointer)0x0) {
    rea_operator_delete(pbVar6);
  }
  return;
}





// ------------------------------------------------------------------
// IDX 170  0010c730  std___vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double_______vector
// ------------------------------------------------------------------
void rea_std___vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double_______vector__dup2(vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double___ * this_ptr, int __in_chrg)
{
  pointer pdVar1;
  pointer pvVar2;
  pointer pvVar3;
  
  pvVar3 = (this_ptr->
           super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
           )._M_impl._M_finish;
  pvVar2 = (this_ptr->
           super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
           )._M_impl._M_start;
  if (pvVar3 != pvVar2) {
    do {
      pdVar1 = (pvVar2->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
      if (pdVar1 != (pointer)0x0) {
        rea_operator_delete(pdVar1);
      }
      pvVar2 = pvVar2 + 1;
    } while (pvVar3 != pvVar2);
    pvVar3 = (this_ptr->
             super__Vector_base<std__vector_double__std__allocator_double_,_std__allocator_std__vector_double__std__allocator_double___>
             )._M_impl._M_start;
  }
  if (pvVar3 == (pointer)0x0) {
    return;
  }
  rea_operator_delete(pvVar3);
  return;
}





// ------------------------------------------------------------------
// IDX 171  0010c780  IndexedData_GIDKey__Item__free
// ------------------------------------------------------------------
void rea_IndexedData_GIDKey__Item__free__dup2(IndexedData_GIDKey__Item * this_ptr)
{
  this_ptr->num_idxs = 0;
  this_ptr->num_items = 0;
  if (this_ptr->idxs != (Index *)0x0) {
    rea_operator_delete(this_ptr->idxs);
    this_ptr->idxs = (Index *)0x0;
  }
  if (this_ptr->items != (Item *)0x0) {
    rea_operator_delete(this_ptr->items);
    this_ptr->items = (Item *)0x0;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 172  0010c7c0  PyWrapper<double_
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_double(undefined8 param_x0, undefined8 * pyargs)
{
  int *piVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  PyObject *pPVar5;
  ulong uVar6;
  double dVar7;
  allocator local_79;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined2 local_68;
  undefined1 local_66;
  parse_ctx t;
  parse_ctx t_1;
  string local_38 [3];
  
                    /* Unresolved local var: double r@[???] */
  local_68 = 0x4f4f;
  local_76 = 0;
  local_78 = 0x4f;
  local_77 = 0x4f;
  local_66 = 0;
  local_38[0]._M_dataplus.(*(undefined1 *)((uint8_t *)&_M_p + 0x2)) = 0;
  local_38[0]._M_dataplus.(*(undefined2 *)((uint8_t *)&_M_p + 0x0)) = 0x4f4f;
  iVar3 = rea_PyArg_ParseTuple(pyargs,local_38,&t,&t_1);
  if (iVar3 != 0) {
    iVar3 = rea_PyLong_AsLong(t_1.v);
    if (((t.v)->ob_type->tp_flags & 0x8000000) == 0) {
      pcVar4 = (char *)rea_PyUnicode_AsUTF8();
      rea_std__string__string(local_38,pcVar4,&local_79);
    }
    else {
      uVar6 = rea_PyBytes_Size();
      pcVar4 = (char *)rea_PyBytes_AsString(t.v);
      rea_std__string__string(local_38,pcVar4,uVar6,&local_79);
    }
    dVar7 = rea_getPreClosePrice(local_38,iVar3);
    lVar2 = CONCAT53(local_38[0]._M_dataplus.(*(arr_undefined1_5 *)((uint8_t *)&_M_p + 0x3)),
                     CONCAT12(local_38[0]._M_dataplus.(*(undefined1 *)((uint8_t *)&_M_p + 0x2)),local_38[0]._M_dataplus.(*(undefined2 *)((uint8_t *)&_M_p + 0x0)))
                    );
    if ((allocator *)(lVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar1 = (int *)(lVar2 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
        iVar3 = *(int *)(lVar2 + -8);
        *(int *)(lVar2 + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
      }
    }
    pPVar5 = (PyObject *)rea_Py_BuildValue(dVar7,(void *)&DAT_0010fc04);
    return pPVar5;
  }
  return (PyObject *)0x0;
}





// ------------------------------------------------------------------
// IDX 173  0010c930  PyWrapper<double_
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_double__dup2(undefined8 param_x0, undefined8 * pyargs)
{
  int *piVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  PyObject *pPVar5;
  ulong uVar6;
  double dVar7;
  allocator local_79;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined2 local_68;
  undefined1 local_66;
  parse_ctx t;
  parse_ctx t_1;
  string local_38 [3];
  
                    /* Unresolved local var: double r@[???] */
  local_68 = 0x4f4f;
  local_76 = 0;
  local_78 = 0x4f;
  local_77 = 0x4f;
  local_66 = 0;
  local_38[0]._M_dataplus.(*(undefined1 *)((uint8_t *)&_M_p + 0x2)) = 0;
  local_38[0]._M_dataplus.(*(undefined2 *)((uint8_t *)&_M_p + 0x0)) = 0x4f4f;
  iVar3 = rea_PyArg_ParseTuple(pyargs,local_38,&t,&t_1);
  if (iVar3 != 0) {
    iVar3 = rea_PyLong_AsLong(t_1.v);
    if (((t.v)->ob_type->tp_flags & 0x8000000) == 0) {
      pcVar4 = (char *)rea_PyUnicode_AsUTF8();
      rea_std__string__string(local_38,pcVar4,&local_79);
    }
    else {
      uVar6 = rea_PyBytes_Size();
      pcVar4 = (char *)rea_PyBytes_AsString(t.v);
      rea_std__string__string(local_38,pcVar4,uVar6,&local_79);
    }
    dVar7 = rea_getLastClosePrice(local_38,iVar3);
    lVar2 = CONCAT53(local_38[0]._M_dataplus.(*(arr_undefined1_5 *)((uint8_t *)&_M_p + 0x3)),
                     CONCAT12(local_38[0]._M_dataplus.(*(undefined1 *)((uint8_t *)&_M_p + 0x2)),local_38[0]._M_dataplus.(*(undefined2 *)((uint8_t *)&_M_p + 0x0)))
                    );
    if ((allocator *)(lVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar1 = (int *)(lVar2 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
        iVar3 = *(int *)(lVar2 + -8);
        *(int *)(lVar2 + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
      }
    }
    pPVar5 = (PyObject *)rea_Py_BuildValue(dVar7,(void *)&DAT_0010fc04);
    return pPVar5;
  }
  return (PyObject *)0x0;
}





// ------------------------------------------------------------------
// IDX 174  0010caa0  PyWrapper<double_
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_double__dup3(undefined8 param_x0, undefined8 * pyargs)
{
  int *piVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  PyObject *pPVar5;
  ulong uVar6;
  double dVar7;
  allocator local_79;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined2 local_68;
  undefined1 local_66;
  parse_ctx t;
  parse_ctx t_1;
  string local_38 [3];
  
                    /* Unresolved local var: double r@[???] */
  local_68 = 0x4f4f;
  local_76 = 0;
  local_78 = 0x4f;
  local_77 = 0x4f;
  local_66 = 0;
  local_38[0]._M_dataplus.(*(undefined1 *)((uint8_t *)&_M_p + 0x2)) = 0;
  local_38[0]._M_dataplus.(*(undefined2 *)((uint8_t *)&_M_p + 0x0)) = 0x4f4f;
  iVar3 = rea_PyArg_ParseTuple(pyargs,local_38,&t,&t_1);
  if (iVar3 != 0) {
    iVar3 = rea_PyLong_AsLong(t_1.v);
    if (((t.v)->ob_type->tp_flags & 0x8000000) == 0) {
      pcVar4 = (char *)rea_PyUnicode_AsUTF8();
      rea_std__string__string(local_38,pcVar4,&local_79);
    }
    else {
      uVar6 = rea_PyBytes_Size();
      pcVar4 = (char *)rea_PyBytes_AsString(t.v);
      rea_std__string__string(local_38,pcVar4,uVar6,&local_79);
    }
    dVar7 = rea_getClosePrice(local_38,iVar3);
    lVar2 = CONCAT53(local_38[0]._M_dataplus.(*(arr_undefined1_5 *)((uint8_t *)&_M_p + 0x3)),
                     CONCAT12(local_38[0]._M_dataplus.(*(undefined1 *)((uint8_t *)&_M_p + 0x2)),local_38[0]._M_dataplus.(*(undefined2 *)((uint8_t *)&_M_p + 0x0)))
                    );
    if ((allocator *)(lVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar1 = (int *)(lVar2 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
        iVar3 = *(int *)(lVar2 + -8);
        *(int *)(lVar2 + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
      }
    }
    pPVar5 = (PyObject *)rea_Py_BuildValue(dVar7,(void *)&DAT_0010fc04);
    return pPVar5;
  }
  return (PyObject *)0x0;
}





// ------------------------------------------------------------------
// IDX 175  0010cc10  PyWrapper<double_
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_double__dup4(undefined8 param_x0, undefined8 * pyargs)
{
  int *piVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  PyObject *pPVar5;
  ulong uVar6;
  double dVar7;
  allocator local_79;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined2 local_68;
  undefined1 local_66;
  parse_ctx t;
  parse_ctx t_1;
  string local_38 [3];
  
                    /* Unresolved local var: double r@[???] */
  local_68 = 0x4f4f;
  local_76 = 0;
  local_78 = 0x4f;
  local_77 = 0x4f;
  local_66 = 0;
  local_38[0]._M_dataplus.(*(undefined1 *)((uint8_t *)&_M_p + 0x2)) = 0;
  local_38[0]._M_dataplus.(*(undefined2 *)((uint8_t *)&_M_p + 0x0)) = 0x4f4f;
  iVar3 = rea_PyArg_ParseTuple(pyargs,local_38,&t,&t_1);
  if (iVar3 != 0) {
    iVar3 = rea_PyLong_AsLong(t_1.v);
    if (((t.v)->ob_type->tp_flags & 0x8000000) == 0) {
      pcVar4 = (char *)rea_PyUnicode_AsUTF8();
      rea_std__string__string(local_38,pcVar4,&local_79);
    }
    else {
      uVar6 = rea_PyBytes_Size();
      pcVar4 = (char *)rea_PyBytes_AsString(t.v);
      rea_std__string__string(local_38,pcVar4,uVar6,&local_79);
    }
    dVar7 = rea_getRescale(local_38,iVar3);
    lVar2 = CONCAT53(local_38[0]._M_dataplus.(*(arr_undefined1_5 *)((uint8_t *)&_M_p + 0x3)),
                     CONCAT12(local_38[0]._M_dataplus.(*(undefined1 *)((uint8_t *)&_M_p + 0x2)),local_38[0]._M_dataplus.(*(undefined2 *)((uint8_t *)&_M_p + 0x0)))
                    );
    if ((allocator *)(lVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar1 = (int *)(lVar2 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
        iVar3 = *(int *)(lVar2 + -8);
        *(int *)(lVar2 + -8) = iVar3 + -1;
      }
      else {
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar3 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(lVar2 + -0x18));
      }
    }
    pPVar5 = (PyObject *)rea_Py_BuildValue(dVar7,(void *)&DAT_0010fc04);
    return pPVar5;
  }
  return (PyObject *)0x0;
}





// ------------------------------------------------------------------
// IDX 176  0010cd80  IndexedData_GIDKey__Item2__free
// ------------------------------------------------------------------
void rea_IndexedData_GIDKey__Item2__free__dup2(IndexedData_GIDKey__Item2 * this_ptr)
{
  this_ptr->num_idxs = 0;
  this_ptr->num_items = 0;
  if (this_ptr->idxs != (Index *)0x0) {
    rea_operator_delete(this_ptr->idxs);
    this_ptr->idxs = (Index *)0x0;
  }
  if (this_ptr->items != (Item2 *)0x0) {
    rea_operator_delete(this_ptr->items);
    this_ptr->items = (Item2 *)0x0;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 177  0010cdc0  IndexedData_GroupKey__GroupForwardItem__free
// ------------------------------------------------------------------
void rea_IndexedData_GroupKey__GroupForwardItem__free__dup2(IndexedData_GroupKey__GroupForwardItem * this_ptr)
{
  this_ptr->num_idxs = 0;
  this_ptr->num_items = 0;
  if (this_ptr->idxs != (Index *)0x0) {
    rea_operator_delete(this_ptr->idxs);
    this_ptr->idxs = (Index *)0x0;
  }
  if (this_ptr->items != (GroupForwardItem *)0x0) {
    rea_operator_delete(this_ptr->items);
    this_ptr->items = (GroupForwardItem *)0x0;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 178  0010ce00  IndexedData_GIDKey__GroupBackwardItem__free
// ------------------------------------------------------------------
void rea_IndexedData_GIDKey__GroupBackwardItem__free__dup2(IndexedData_GIDKey__GroupBackwardItem * this_ptr)
{
  this_ptr->num_idxs = 0;
  this_ptr->num_items = 0;
  if (this_ptr->idxs != (Index *)0x0) {
    rea_operator_delete(this_ptr->idxs);
    this_ptr->idxs = (Index *)0x0;
  }
  if (this_ptr->items != (GroupBackwardItem *)0x0) {
    rea_operator_delete(this_ptr->items);
    this_ptr->items = (GroupBackwardItem *)0x0;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 179  0010ce40  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_______find
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_______find__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, int * __k)
{
  _Rb_tree_node_base *p_Var1;
  _Base_ptr *pp_Var2;
  _Base_ptr p_Var3;
  _Base_ptr p_Var4;
  iterator iVar5;
  
  p_Var3 = (this_ptr->_M_impl)._M_header._M_parent;
                    /* Unresolved local var: iterator __j@[???] */
  p_Var1 = &(this_ptr->_M_impl)._M_header;
  if (p_Var3 != (_Base_ptr)0x0) {
    p_Var4 = p_Var1;
    do {
      while (iVar5._M_node = p_Var3, (int)iVar5._M_node[1]._M_color < *__k) {
        pp_Var2 = &(iVar5._M_node)->_M_right;
        iVar5._M_node = p_Var4;
        p_Var3 = *pp_Var2;
        if (*pp_Var2 == (_Base_ptr)0x0) goto LAB_0010ce72;
      }
      p_Var4 = iVar5._M_node;
      p_Var3 = (iVar5._M_node)->_M_left;
    } while ((iVar5._M_node)->_M_left != (_Base_ptr)0x0);
LAB_0010ce72:
    if ((p_Var1 != iVar5._M_node) && ((int)iVar5._M_node[1]._M_color <= *__k)) {
      return (iterator)iVar5._M_node;
    }
  }
  return (iterator)p_Var1;
}





// ------------------------------------------------------------------
// IDX 180  0010ce90  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_erase__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * this_ptr, _Link_type __x)
{
  int *piVar1;
  pointer pdVar2;
  _Link_type p_Var3;
  char *pcVar4;
  undefined *puVar5;
  int iVar6;
  
  puVar5 = PTR__S_empty_rep_storage_00311ff0;
  while (__x != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(__x->super__Rb_tree_node_base)._M_right);
    pdVar2 = (__x->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
             _M_impl._M_start;
    p_Var3 = (_Link_type)(__x->super__Rb_tree_node_base)._M_left;
    if (pdVar2 != (pointer)0x0) {
      rea_operator_delete(pdVar2);
    }
    pcVar4 = (__x->_M_value_field).first._M_dataplus._M_p;
    if ((allocator *)(pcVar4 + -0x18) != (allocator *)puVar5) {
      piVar1 = (int *)(pcVar4 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
        iVar6 = *(int *)(pcVar4 + -8);
        *(int *)(pcVar4 + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(pcVar4 + -0x18));
      }
    }
    rea_operator_delete(__x);
    __x = p_Var3;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 181  0010cf40  std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______M_emplace_back_aux_const_std__basic_string_char__std__char_traits_char__std__allocator_char_____________
// ------------------------------------------------------------------
void rea_std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______M_emplace_back_aux_const_std__basic_string_char__std__char_traits_char__std__allocator_char__dup2(vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___ * this_ptr)
{
  char *pcVar1;
  int *piVar2;
  undefined *puVar3;
  ulong uVar4;
  int iVar5;
  ulong uVar6;
  pointer pbVar7;
  void *this_00;
  pointer pbVar8;
  pointer pbVar9;
  pointer pbVar10;
  string *in_RSI;
  pointer pbVar11;
  ulong uVar12;
  pointer pbVar13;
  
                    /* Unresolved local var: size_type __len@[???]
                       Unresolved local var: pointer __new_start@[???]
                       Unresolved local var: pointer __new_finish@[???] */
  uVar6 = (long)(this_ptr->
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                )._M_impl._M_finish -
          (long)(this_ptr->
                super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
                )._M_impl._M_start >> 3;
  if (uVar6 == 0) {
    uVar4 = 1;
  }
  else {
    uVar4 = uVar6 * 2;
    if (uVar4 < uVar6) {
      uVar6 = 0xfffffffffffffff8;
      uVar12 = 0x1fffffffffffffff;
      goto LAB_0010cf83;
    }
    uVar12 = 0x1fffffffffffffff;
    if (0x1fffffffffffffff < uVar4) {
      uVar6 = 0xfffffffffffffff8;
      goto LAB_0010cf83;
    }
  }
  uVar12 = uVar4;
  uVar6 = uVar12 * 8;
LAB_0010cf83:
  pbVar7 = rea_operator_new(uVar6);
  pbVar13 = (this_ptr->
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            )._M_impl._M_finish;
  pbVar11 = (this_ptr->
            super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
            )._M_impl._M_start;
  this_00 = (void *)((long)&(pbVar7->_M_dataplus)._M_p +
                    ((long)pbVar13 - (long)pbVar11 & 0xfffffffffffffff8U));
  if (this_00 != (void *)0x0) {
    rea_std__string__string(this_00,in_RSI);
    pbVar13 = (this_ptr->
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              )._M_impl._M_finish;
    pbVar11 = (this_ptr->
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              )._M_impl._M_start;
  }
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
                    /* Unresolved local var:
                       basic_string_char__std__char_traits_char__std__allocator_char_ *
                       __cur@[???] */
  if (pbVar11 == pbVar13) {
    pbVar8 = pbVar7 + 1;
  }
  else {
    pcVar1 = PTR__S_empty_rep_storage_00311ff0 + 0x18;
    pbVar8 = pbVar7;
    pbVar9 = pbVar11;
    do {
      if (pbVar8 != (pointer)0x0) {
        (pbVar8->_M_dataplus)._M_p = (pbVar9->_M_dataplus)._M_p;
        (pbVar9->_M_dataplus)._M_p = pcVar1;
      }
      pbVar9 = pbVar9 + 1;
      pbVar8 = pbVar8 + 1;
    } while (pbVar9 != pbVar13);
    pbVar8 = (pointer)((long)&pbVar7[2]._M_dataplus._M_p +
                      ((long)pbVar13 - (long)(pbVar11 + 1) & 0xfffffffffffffff8U));
    pbVar9 = pbVar11 + 1;
    while( true ) {
      pbVar10 = pbVar9;
      pcVar1 = (pbVar11->_M_dataplus)._M_p;
      if ((allocator *)(pcVar1 + -0x18) != (allocator *)puVar3) {
        piVar2 = (int *)(pcVar1 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
          iVar5 = *(int *)(pcVar1 + -8);
          *(int *)(pcVar1 + -8) = iVar5 + -1;
        }
        else {
          LOCK();
          iVar5 = *piVar2;
          *piVar2 = *piVar2 + -1;
          UNLOCK();
        }
        if (iVar5 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)(pcVar1 + -0x18));
        }
      }
      if (pbVar10 == pbVar13) break;
      pbVar9 = pbVar10 + 1;
      pbVar11 = pbVar10;
    }
    pbVar11 = (this_ptr->
              super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
              )._M_impl._M_start;
  }
  if (pbVar11 != (pointer)0x0) {
    rea_operator_delete(pbVar11);
  }
  (this_ptr->
  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
  )._M_impl._M_start = pbVar7;
  (this_ptr->
  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
  )._M_impl._M_finish = pbVar8;
  (this_ptr->
  super__Vector_base<std__basic_string_char__std__char_traits_char__std__allocator_char_,_std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___>
  )._M_impl._M_end_of_storage = pbVar7 + uVar12;
  return;
}





// ------------------------------------------------------------------
// IDX 182  0010d140  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_erase__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, _Link_type __x)
{
  int *piVar1;
  char *pcVar2;
  _Link_type p_Var3;
  undefined *puVar4;
  int iVar5;
  
  puVar4 = PTR__S_empty_rep_storage_00311ff0;
  while (__x != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(__x->super__Rb_tree_node_base)._M_right);
    pcVar2 = (__x->_M_value_field).first._M_dataplus._M_p;
    p_Var3 = (_Link_type)(__x->super__Rb_tree_node_base)._M_left;
    if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar4) {
      piVar1 = (int *)(pcVar2 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg2(RCX)] */
        iVar5 = *(int *)(pcVar2 + -8);
        *(int *)(pcVar2 + -8) = iVar5 + -1;
      }
      else {
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar5 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(pcVar2 + -0x18));
      }
    }
    rea_operator_delete(__x);
    __x = p_Var3;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 183  0010d1e0  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_____find
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_____find__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, basic_string_char__std__char_traits_char__std__allocator_char_ * __k)
{
  _Rb_tree_node_base *p_Var1;
  _Base_ptr *pp_Var2;
  _Base_ptr p_Var3;
  char *__s2;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  _Base_ptr p_Var9;
  _Base_ptr p_Var10;
  
                    /* Unresolved local var: iterator __j@[???] */
  p_Var1 = &(this_ptr->_M_impl)._M_header;
  p_Var3 = (this_ptr->_M_impl)._M_header._M_parent;
  if (p_Var3 != (_Base_ptr)0x0) {
    __s2 = (__k->_M_dataplus)._M_p;
    uVar4 = *(ulong *)(__s2 + -0x18);
    p_Var9 = p_Var1;
    do {
      while( true ) {
        p_Var10 = p_Var3;
        uVar5 = *(ulong *)((long)*(void **)(p_Var10 + 1) + -0x18);
        uVar7 = uVar5;
        if (uVar4 <= uVar5) {
          uVar7 = uVar4;
        }
        iVar6 = rea_memcmp(*(void **)(p_Var10 + 1),__s2,uVar7);
        if (iVar6 != 0) break;
        lVar8 = uVar5 - uVar4;
        if (0x7fffffff < lVar8) goto LAB_0010d216;
        if (-0x80000001 < lVar8) {
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???]
                       Unresolved local var: difference_type __d@[???] */
          iVar6 = (int)lVar8;
          break;
        }
LAB_0010d255:
        pp_Var2 = &p_Var10->_M_right;
        p_Var3 = *pp_Var2;
        p_Var10 = p_Var9;
        if (*pp_Var2 == (_Base_ptr)0x0) goto LAB_0010d25e;
      }
      if (iVar6 < 0) goto LAB_0010d255;
LAB_0010d216:
      p_Var3 = p_Var10->_M_left;
      p_Var9 = p_Var10;
    } while (p_Var10->_M_left != (_Base_ptr)0x0);
LAB_0010d25e:
    if (p_Var1 == p_Var10) {
      return (iterator)p_Var1;
    }
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
    uVar5 = *(ulong *)((long)*(void **)(p_Var10 + 1) + -0x18);
    uVar7 = uVar5;
    if (uVar4 <= uVar5) {
      uVar7 = uVar4;
    }
    iVar6 = rea_memcmp(__s2,*(void **)(p_Var10 + 1),uVar7);
    if (iVar6 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */
      lVar8 = uVar4 - uVar5;
      if (0x7fffffff < lVar8) {
        return (iterator)p_Var10;
      }
      if (lVar8 < -0x80000000) {
        return (iterator)p_Var1;
      }
      iVar6 = (int)lVar8;
    }
    if (-1 < iVar6) {
      return (iterator)p_Var10;
    }
  }
  return (iterator)p_Var1;
}





// ------------------------------------------------------------------
// IDX 184  0010d2d0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_erase__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, _Link_type __x)
{
  _Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_ _Var1;
  _Link_type p_Var2;
  
  while (__x != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(__x->super__Rb_tree_node_base)._M_right);
                    /* Unresolved local var: Data2 * * __ptr@[???] */
    _Var1 = (__x->_M_value_field).second._M_t.
            super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_>;
    p_Var2 = (_Link_type)(__x->super__Rb_tree_node_base)._M_left;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long)_Var1 + 4) = 0;
      if (*(void **)((long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 8));
        *(undefined8 *)((long)_Var1 + 8) = 0;
      }
      if (*(void **)((long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 0x10));
        *(undefined8 *)((long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (__x->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__Data2*,_std__default_delete_SecInfo__Data2_> =
         (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
    rea_operator_delete(__x);
    __x = p_Var2;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 185  0010d370  std___map_int__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________map
// ------------------------------------------------------------------
void rea_std___map_int__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________map(map_int__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, int __in_chrg)
{
  _Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2__________M_erase(&this_ptr->_M_t,(_Link_type)(this_ptr->_M_t)._M_impl._M_header._M_parent);
  return;
}





// ------------------------------------------------------------------
// IDX 186  0010d380  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_unique_pos__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, key_type * __k)
{
  _Rb_tree_node_base *p_Var1;
  int iVar2;
  _Rb_tree_color _Var3;
  _Rb_tree_node_base *p_Var4;
  _Rb_tree_node_base *p_Var5;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar6;
  
  p_Var1 = (this_ptr->_M_impl)._M_header._M_parent;
                    /* Unresolved local var: _Link_type __x@[???]
                       Unresolved local var: _Link_type __y@[???]
                       Unresolved local var: bool __comp@[???]
                       Unresolved local var: iterator __j@[???] */
  if (p_Var1 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = &(this_ptr->_M_impl)._M_header;
LAB_0010d3f0:
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
    if ((this_ptr->_M_impl)._M_header._M_left == p_Var5) goto LAB_0010d3df;
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var5);
    iVar2 = *__k;
    _Var3 = p_Var1[1]._M_color;
  }
  else {
    iVar2 = *__k;
    do {
      p_Var5 = p_Var1;
      _Var3 = p_Var5[1]._M_color;
      if (iVar2 < (int)_Var3) {
        p_Var1 = p_Var5->_M_left;
      }
      else {
        p_Var1 = p_Var5->_M_right;
      }
    } while (p_Var1 != (_Base_ptr)0x0);
    p_Var1 = p_Var5;
    if (iVar2 < (int)_Var3) goto LAB_0010d3f0;
  }
  p_Var4 = (_Rb_tree_node_base *)0x0;
  if ((int)_Var3 < iVar2) {
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
  }
LAB_0010d3df:
  pVar6.second = p_Var4;
  pVar6.first = p_Var1;
  return pVar6;
}





// ------------------------------------------------------------------
// IDX 187  0010d420  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_insert_node
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_insert_node__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, _Base_ptr __x, _Base_ptr __p, _Link_type __z)
{
  _Rb_tree_node_base *p_Var1;
  size_type *psVar2;
  bool bVar3;
  
  p_Var1 = &(this_ptr->_M_impl)._M_header;
                    /* Unresolved local var: bool __insert_left@[???] */
  if ((__x == (_Base_ptr)0x0) && (p_Var1 != __p)) {
    bVar3 = (__z->_M_value_field).first < (int)__p[1]._M_color;
  }
  else {
    bVar3 = true;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar3,&__z->super__Rb_tree_node_base,__p,p_Var1);
  psVar2 = &(this_ptr->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)&__z->super__Rb_tree_node_base;
}





// ------------------------------------------------------------------
// IDX 188  0010d470  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_hint_unique_pos__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, const_iterator __position, key_type * __k)
{
  int iVar1;
  _Base_ptr p_Var2;
  const_iterator cVar3;
  const_iterator cVar4;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar5;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar6;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar7;
  
                    /* Unresolved local var: iterator __pos@[DW_OP_reg4(RSI); DW_OP_piece: 8] */
  if (__position._M_node == &(this_ptr->_M_impl)._M_header) {
    if (((this_ptr->_M_impl)._M_node_count == 0) ||
       (cVar3._M_node = (this_ptr->_M_impl)._M_header._M_right, *__k <= (int)cVar3._M_node[1]._M_color))
    {
LAB_0010d528:
      pVar7 = _M_get_insert_unique_pos(this_ptr,__k);
      return pVar7;
    }
  }
  else {
    iVar1 = *__k;
    if (iVar1 < (int)__position._M_node[1]._M_color) {
                    /* Unresolved local var: iterator __before@[???] */
      cVar4._M_node = (this_ptr->_M_impl)._M_header._M_left;
      cVar3._M_node = cVar4._M_node;
      if (cVar4._M_node != __position._M_node) {
        cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_decrement(__position._M_node);
        if (iVar1 <= (int)cVar3._M_node[1]._M_color) goto LAB_0010d528;
        cVar4._M_node = (_Base_ptr)0x0;
        if ((cVar3._M_node)->_M_right != (_Base_ptr)0x0) {
          cVar4._M_node = __position._M_node;
          cVar3._M_node = __position._M_node;
        }
      }
      goto LAB_0010d4c5;
    }
    if (iVar1 <= (int)__position._M_node[1]._M_color) {
      pVar7.second = (_Rb_tree_node_base *)0x0;
      pVar7.first = __position._M_node;
      return pVar7;
    }
                    /* Unresolved local var: iterator __after@[???] */
    cVar3._M_node = (this_ptr->_M_impl)._M_header._M_right;
    if (cVar3._M_node != __position._M_node) {
      cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_increment(__position._M_node);
      if (iVar1 < (int)cVar3._M_node[1]._M_color) {
        p_Var2 = cVar3._M_node;
        if ((__position._M_node)->_M_right == (_Base_ptr)0x0) {
          cVar3._M_node = __position._M_node;
          p_Var2 = (_Base_ptr)0x0;
        }
        pVar6.second = cVar3._M_node;
        pVar6.first = p_Var2;
        return pVar6;
      }
      goto LAB_0010d528;
    }
  }
  cVar4._M_node = (_Base_ptr)0x0;
LAB_0010d4c5:
  pVar5.second = cVar3._M_node;
  pVar5.first = cVar4._M_node;
  return pVar5;
}





// ------------------------------------------------------------------
// IDX 189  0010d560  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_unique_pos__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, key_type * __k)
{
  _Rb_tree_node_base *p_Var1;
  int iVar2;
  _Rb_tree_color _Var3;
  _Rb_tree_node_base *p_Var4;
  _Rb_tree_node_base *p_Var5;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar6;
  
  p_Var1 = (this_ptr->_M_impl)._M_header._M_parent;
                    /* Unresolved local var: _Link_type __x@[???]
                       Unresolved local var: _Link_type __y@[???]
                       Unresolved local var: bool __comp@[???]
                       Unresolved local var: iterator __j@[???] */
  if (p_Var1 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = &(this_ptr->_M_impl)._M_header;
LAB_0010d5d0:
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
    if ((this_ptr->_M_impl)._M_header._M_left == p_Var5) goto LAB_0010d5bf;
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var5);
    iVar2 = *__k;
    _Var3 = p_Var1[1]._M_color;
  }
  else {
    iVar2 = *__k;
    do {
      p_Var5 = p_Var1;
      _Var3 = p_Var5[1]._M_color;
      if (iVar2 < (int)_Var3) {
        p_Var1 = p_Var5->_M_left;
      }
      else {
        p_Var1 = p_Var5->_M_right;
      }
    } while (p_Var1 != (_Base_ptr)0x0);
    p_Var1 = p_Var5;
    if (iVar2 < (int)_Var3) goto LAB_0010d5d0;
  }
  p_Var4 = (_Rb_tree_node_base *)0x0;
  if ((int)_Var3 < iVar2) {
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
  }
LAB_0010d5bf:
  pVar6.second = p_Var4;
  pVar6.first = p_Var1;
  return pVar6;
}





// ------------------------------------------------------------------
// IDX 190  0010d600  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_insert_node
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_insert_node__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, _Base_ptr __x, _Base_ptr __p, _Link_type __z)
{
  _Rb_tree_node_base *p_Var1;
  size_type *psVar2;
  bool bVar3;
  
  p_Var1 = &(this_ptr->_M_impl)._M_header;
                    /* Unresolved local var: bool __insert_left@[???] */
  if ((__x == (_Base_ptr)0x0) && (p_Var1 != __p)) {
    bVar3 = (__z->_M_value_field).first < (int)__p[1]._M_color;
  }
  else {
    bVar3 = true;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar3,&__z->super__Rb_tree_node_base,__p,p_Var1);
  psVar2 = &(this_ptr->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)&__z->super__Rb_tree_node_base;
}





// ------------------------------------------------------------------
// IDX 191  0010d650  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____________
// ------------------------------------------------------------------
pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____bool rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr)
{
  _Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_ _Var1;
  _Link_type __z;
  _Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_ *in_RDX;
  int *in_RSI;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar2;
  pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____bool
  pVar3;
  pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____bool
  pVar4;
  
                    /* Unresolved local var: _Link_type __z@[???]
                       Unresolved local var: _Link_type __tmp@[???] */
  __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->_M_value_field).first = *in_RSI;
                    /* Unresolved local var: pointer __p@[???] */
    _Var1 = *in_RDX;
    *in_RDX = (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0
    ;
    (__z->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_> = _Var1;
  }
                    /* Unresolved local var:
                       pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ __res@[???] */
  pVar2 = _M_get_insert_unique_pos(this_ptr,&(__z->_M_value_field).first);
  pVar4.first._M_node = pVar2.first;
  if (pVar2.second != (_Base_ptr)0x0) {
    pVar3.first._M_node = _M_insert_node(this_ptr,pVar4.first._M_node,pVar2.second,__z);
    (*(undefined8 *)((uint8_t *)&pVar3 + 0x8)) = 1;
    return pVar3;
  }
                    /* Unresolved local var: GroupData1 * * __ptr@[???] */
  _Var1 = (__z->_M_value_field).second._M_t.
          super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_>;
  if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)
               0x0) {
    *(undefined4 *)_Var1 = 0;
    *(undefined4 *)((long)_Var1 + 4) = 0;
    if (*(void **)((long)_Var1 + 8) != (void *)0x0) {
      rea_operator_delete(*(void **)((long)_Var1 + 8));
      *(undefined8 *)((long)_Var1 + 8) = 0;
    }
    if (*(void **)((long)_Var1 + 0x10) != (void *)0x0) {
      rea_operator_delete(*(void **)((long)_Var1 + 0x10));
      *(undefined8 *)((long)_Var1 + 0x10) = 0;
    }
    rea_operator_delete((void *)_Var1);
  }
  (__z->_M_value_field).second._M_t.
  super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_> =
       (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
  rea_operator_delete(__z);
  (*(undefined8 *)((uint8_t *)&pVar4 + 0x8)) = 0;
  return pVar4;
}





// ------------------------------------------------------------------
// IDX 192  0010d760  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_unique_pos__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, key_type * __k)
{
  _Rb_tree_node_base *p_Var1;
  int iVar2;
  _Rb_tree_color _Var3;
  _Rb_tree_node_base *p_Var4;
  _Rb_tree_node_base *p_Var5;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar6;
  
  p_Var1 = (this_ptr->_M_impl)._M_header._M_parent;
                    /* Unresolved local var: _Link_type __x@[???]
                       Unresolved local var: _Link_type __y@[???]
                       Unresolved local var: bool __comp@[???]
                       Unresolved local var: iterator __j@[???] */
  if (p_Var1 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = &(this_ptr->_M_impl)._M_header;
LAB_0010d7d0:
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
    if ((this_ptr->_M_impl)._M_header._M_left == p_Var5) goto LAB_0010d7bf;
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var5);
    iVar2 = *__k;
    _Var3 = p_Var1[1]._M_color;
  }
  else {
    iVar2 = *__k;
    do {
      p_Var5 = p_Var1;
      _Var3 = p_Var5[1]._M_color;
      if (iVar2 < (int)_Var3) {
        p_Var1 = p_Var5->_M_left;
      }
      else {
        p_Var1 = p_Var5->_M_right;
      }
    } while (p_Var1 != (_Base_ptr)0x0);
    p_Var1 = p_Var5;
    if (iVar2 < (int)_Var3) goto LAB_0010d7d0;
  }
  p_Var4 = (_Rb_tree_node_base *)0x0;
  if ((int)_Var3 < iVar2) {
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
  }
LAB_0010d7bf:
  pVar6.second = p_Var4;
  pVar6.first = p_Var1;
  return pVar6;
}





// ------------------------------------------------------------------
// IDX 193  0010d800  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_insert_node
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_insert_node__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, _Base_ptr __x, _Base_ptr __p, _Link_type __z)
{
  _Rb_tree_node_base *p_Var1;
  size_type *psVar2;
  bool bVar3;
  
  p_Var1 = &(this_ptr->_M_impl)._M_header;
                    /* Unresolved local var: bool __insert_left@[???] */
  if ((__x == (_Base_ptr)0x0) && (p_Var1 != __p)) {
    bVar3 = (__z->_M_value_field).first < (int)__p[1]._M_color;
  }
  else {
    bVar3 = true;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar3,&__z->super__Rb_tree_node_base,__p,p_Var1);
  psVar2 = &(this_ptr->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)&__z->super__Rb_tree_node_base;
}





// ------------------------------------------------------------------
// IDX 194  0010d850  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____________
// ------------------------------------------------------------------
pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____bool rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr)
{
  _Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_ _Var1;
  _Link_type __z;
  _Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_ *in_RDX;
  int *in_RSI;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar2;
  pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____bool
  pVar3;
  pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____bool
  pVar4;
  
                    /* Unresolved local var: _Link_type __z@[???]
                       Unresolved local var: _Link_type __tmp@[???] */
  __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->_M_value_field).first = *in_RSI;
                    /* Unresolved local var: pointer __p@[???] */
    _Var1 = *in_RDX;
    *in_RDX = (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0
    ;
    (__z->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_> = _Var1;
  }
                    /* Unresolved local var:
                       pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ __res@[???] */
  pVar2 = _M_get_insert_unique_pos(this_ptr,&(__z->_M_value_field).first);
  pVar4.first._M_node = pVar2.first;
  if (pVar2.second != (_Base_ptr)0x0) {
    pVar3.first._M_node = _M_insert_node(this_ptr,pVar4.first._M_node,pVar2.second,__z);
    (*(undefined8 *)((uint8_t *)&pVar3 + 0x8)) = 1;
    return pVar3;
  }
                    /* Unresolved local var: GroupData2 * * __ptr@[???] */
  _Var1 = (__z->_M_value_field).second._M_t.
          super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_>;
  if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)
               0x0) {
    *(undefined4 *)_Var1 = 0;
    *(undefined4 *)((long)_Var1 + 4) = 0;
    if (*(void **)((long)_Var1 + 8) != (void *)0x0) {
      rea_operator_delete(*(void **)((long)_Var1 + 8));
      *(undefined8 *)((long)_Var1 + 8) = 0;
    }
    if (*(void **)((long)_Var1 + 0x10) != (void *)0x0) {
      rea_operator_delete(*(void **)((long)_Var1 + 0x10));
      *(undefined8 *)((long)_Var1 + 0x10) = 0;
    }
    rea_operator_delete((void *)_Var1);
  }
  (__z->_M_value_field).second._M_t.
  super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_> =
       (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
  rea_operator_delete(__z);
  (*(undefined8 *)((uint8_t *)&pVar4 + 0x8)) = 0;
  return pVar4;
}





// ------------------------------------------------------------------
// IDX 195  0010d960  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_hint_unique_pos__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, const_iterator __position, key_type * __k)
{
  int iVar1;
  _Base_ptr p_Var2;
  const_iterator cVar3;
  const_iterator cVar4;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar5;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar6;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar7;
  
                    /* Unresolved local var: iterator __pos@[DW_OP_reg4(RSI); DW_OP_piece: 8] */
  if (__position._M_node == &(this_ptr->_M_impl)._M_header) {
    if (((this_ptr->_M_impl)._M_node_count == 0) ||
       (cVar3._M_node = (this_ptr->_M_impl)._M_header._M_right, *__k <= (int)cVar3._M_node[1]._M_color))
    {
LAB_0010da18:
      pVar7 = _M_get_insert_unique_pos(this_ptr,__k);
      return pVar7;
    }
  }
  else {
    iVar1 = *__k;
    if (iVar1 < (int)__position._M_node[1]._M_color) {
                    /* Unresolved local var: iterator __before@[???] */
      cVar4._M_node = (this_ptr->_M_impl)._M_header._M_left;
      cVar3._M_node = cVar4._M_node;
      if (cVar4._M_node != __position._M_node) {
        cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_decrement(__position._M_node);
        if (iVar1 <= (int)cVar3._M_node[1]._M_color) goto LAB_0010da18;
        cVar4._M_node = (_Base_ptr)0x0;
        if ((cVar3._M_node)->_M_right != (_Base_ptr)0x0) {
          cVar4._M_node = __position._M_node;
          cVar3._M_node = __position._M_node;
        }
      }
      goto LAB_0010d9b5;
    }
    if (iVar1 <= (int)__position._M_node[1]._M_color) {
      pVar7.second = (_Rb_tree_node_base *)0x0;
      pVar7.first = __position._M_node;
      return pVar7;
    }
                    /* Unresolved local var: iterator __after@[???] */
    cVar3._M_node = (this_ptr->_M_impl)._M_header._M_right;
    if (cVar3._M_node != __position._M_node) {
      cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_increment(__position._M_node);
      if (iVar1 < (int)cVar3._M_node[1]._M_color) {
        p_Var2 = cVar3._M_node;
        if ((__position._M_node)->_M_right == (_Base_ptr)0x0) {
          cVar3._M_node = __position._M_node;
          p_Var2 = (_Base_ptr)0x0;
        }
        pVar6.second = cVar3._M_node;
        pVar6.first = p_Var2;
        return pVar6;
      }
      goto LAB_0010da18;
    }
  }
  cVar4._M_node = (_Base_ptr)0x0;
LAB_0010d9b5:
  pVar5.second = cVar3._M_node;
  pVar5.first = cVar4._M_node;
  return pVar5;
}





// ------------------------------------------------------------------
// IDX 196  0010da50  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_hint_unique_pos__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, const_iterator __position, key_type * __k)
{
  int iVar1;
  _Base_ptr p_Var2;
  const_iterator cVar3;
  const_iterator cVar4;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar5;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar6;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar7;
  
                    /* Unresolved local var: iterator __pos@[DW_OP_reg4(RSI); DW_OP_piece: 8] */
  if (__position._M_node == &(this_ptr->_M_impl)._M_header) {
    if (((this_ptr->_M_impl)._M_node_count == 0) ||
       (cVar3._M_node = (this_ptr->_M_impl)._M_header._M_right, *__k <= (int)cVar3._M_node[1]._M_color))
    {
LAB_0010db08:
      pVar7 = _M_get_insert_unique_pos(this_ptr,__k);
      return pVar7;
    }
  }
  else {
    iVar1 = *__k;
    if (iVar1 < (int)__position._M_node[1]._M_color) {
                    /* Unresolved local var: iterator __before@[???] */
      cVar4._M_node = (this_ptr->_M_impl)._M_header._M_left;
      cVar3._M_node = cVar4._M_node;
      if (cVar4._M_node != __position._M_node) {
        cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_decrement(__position._M_node);
        if (iVar1 <= (int)cVar3._M_node[1]._M_color) goto LAB_0010db08;
        cVar4._M_node = (_Base_ptr)0x0;
        if ((cVar3._M_node)->_M_right != (_Base_ptr)0x0) {
          cVar4._M_node = __position._M_node;
          cVar3._M_node = __position._M_node;
        }
      }
      goto LAB_0010daa5;
    }
    if (iVar1 <= (int)__position._M_node[1]._M_color) {
      pVar7.second = (_Rb_tree_node_base *)0x0;
      pVar7.first = __position._M_node;
      return pVar7;
    }
                    /* Unresolved local var: iterator __after@[???] */
    cVar3._M_node = (this_ptr->_M_impl)._M_header._M_right;
    if (cVar3._M_node != __position._M_node) {
      cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_increment(__position._M_node);
      if (iVar1 < (int)cVar3._M_node[1]._M_color) {
        p_Var2 = cVar3._M_node;
        if ((__position._M_node)->_M_right == (_Base_ptr)0x0) {
          cVar3._M_node = __position._M_node;
          p_Var2 = (_Base_ptr)0x0;
        }
        pVar6.second = cVar3._M_node;
        pVar6.first = p_Var2;
        return pVar6;
      }
      goto LAB_0010db08;
    }
  }
  cVar4._M_node = (_Base_ptr)0x0;
LAB_0010daa5:
  pVar5.second = cVar3._M_node;
  pVar5.first = cVar4._M_node;
  return pVar5;
}





// ------------------------------------------------------------------
// IDX 197  0010db40  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_erase__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, _Link_type __x)
{
  _Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_ _Var1;
  _Link_type p_Var2;
  
  while (__x != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(__x->super__Rb_tree_node_base)._M_right);
                    /* Unresolved local var: GroupData1 * * __ptr@[???] */
    _Var1 = (__x->_M_value_field).second._M_t.
            super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_>;
    p_Var2 = (_Link_type)(__x->super__Rb_tree_node_base)._M_left;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)
                 0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long)_Var1 + 4) = 0;
      if (*(void **)((long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 8));
        *(undefined8 *)((long)_Var1 + 8) = 0;
      }
      if (*(void **)((long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 0x10));
        *(undefined8 *)((long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (__x->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData1*,_std__default_delete_SecInfo__GroupData1_> =
         (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
    rea_operator_delete(__x);
    __x = p_Var2;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 198  0010dbe0  std___map_int__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________map
// ------------------------------------------------------------------
void rea_std___map_int__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________map(map_int__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, int __in_chrg)
{
  _Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1__________M_erase(&this_ptr->_M_t,(_Link_type)(this_ptr->_M_t)._M_impl._M_header._M_parent);
  return;
}





// ------------------------------------------------------------------
// IDX 199  0010dbf0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_erase__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, _Link_type __x)
{
  _Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_ _Var1;
  _Link_type p_Var2;
  
  while (__x != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(__x->super__Rb_tree_node_base)._M_right);
                    /* Unresolved local var: GroupData2 * * __ptr@[???] */
    _Var1 = (__x->_M_value_field).second._M_t.
            super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_>;
    p_Var2 = (_Link_type)(__x->super__Rb_tree_node_base)._M_left;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)
                 0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long)_Var1 + 4) = 0;
      if (*(void **)((long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 8));
        *(undefined8 *)((long)_Var1 + 8) = 0;
      }
      if (*(void **)((long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long)_Var1 + 0x10));
        *(undefined8 *)((long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (__x->_M_value_field).second._M_t.
    super__Tuple_impl<0ul,_SecInfo__GroupData2*,_std__default_delete_SecInfo__GroupData2_> =
         (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
    rea_operator_delete(__x);
    __x = p_Var2;
  }
  return;
}





// ------------------------------------------------------------------
// IDX 200  0010dc90  std___map_int__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________map
// ------------------------------------------------------------------
void rea_std___map_int__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________map(map_int__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, int __in_chrg)
{
  _Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2__________M_erase(&this_ptr->_M_t,(_Link_type)(this_ptr->_M_t)._M_impl._M_header._M_parent);
  return;
}





// ------------------------------------------------------------------
// IDX 201  0010dca0  std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______pair
// ------------------------------------------------------------------
void rea_std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______pair__dup2(pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__ * this_ptr, int __in_chrg)
{
  int *piVar1;
  pointer pdVar2;
  char *pcVar3;
  int iVar4;
  
  pdVar2 = (this_ptr->second).super__Vector_base_double__std__allocator_double_._M_impl._M_start;
  if (pdVar2 != (pointer)0x0) {
    rea_operator_delete(pdVar2);
  }
  pcVar3 = (this_ptr->first)._M_dataplus._M_p;
  if ((allocator *)(pcVar3 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar1 = (int *)(pcVar3 + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
      iVar4 = *(int *)(pcVar3 + -8);
      *(int *)(pcVar3 + -8) = iVar4 + -1;
    }
    else {
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = *piVar1 + -1;
      UNLOCK();
    }
    if (iVar4 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)(pcVar3 + -0x18));
    }
  }
  return;
}





// ------------------------------------------------------------------
// IDX 202  0010dd00  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_unique_pos__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, key_type * __k)
{
  undefined1 auVar1 [16];
  bool bVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  _Rb_tree_node_base *p_Var6;
  size_t __n;
  _Rb_tree_node_base *p_Var7;
  ulong uVar8;
  long lVar9;
  char *__s1;
  void *__s2;
  ulong uVar10;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar11;
  
  p_Var6 = (this_ptr->_M_impl)._M_header._M_parent;
                    /* Unresolved local var: _Link_type __x@[???]
                       Unresolved local var: _Link_type __y@[???]
                       Unresolved local var: bool __comp@[???]
                       Unresolved local var: iterator __j@[???] */
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
    p_Var7 = &(this_ptr->_M_impl)._M_header;
LAB_0010de00:
    if ((this_ptr->_M_impl)._M_header._M_left == p_Var7) {
      p_Var6 = (_Rb_tree_node_base *)0x0;
      goto LAB_0010ddbd;
    }
    p_Var6 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var7);
    __s2 = *(void **)(p_Var6 + 1);
    __s1 = (__k->_M_dataplus)._M_p;
    uVar8 = *(ulong *)((long)__s2 + -0x18);
    uVar10 = *(ulong *)(__s1 + -0x18);
    __n = uVar10;
    if (uVar8 <= uVar10) {
      __n = uVar8;
    }
  }
  else {
    __s1 = (__k->_M_dataplus)._M_p;
    uVar10 = *(ulong *)(__s1 + -0x18);
    do {
      p_Var7 = p_Var6;
      __s2 = *(void **)(p_Var7 + 1);
      uVar8 = *(ulong *)((long)__s2 + -0x18);
      __n = uVar8;
      if (uVar10 <= uVar8) {
        __n = uVar10;
      }
      uVar3 = rea_memcmp(__s1,__s2,__n);
      uVar5 = (ulong)uVar3;
      if (uVar3 == 0) {
        uVar5 = uVar10 - uVar8;
        if ((long)uVar5 < 0x80000000) {
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???]
                       Unresolved local var: difference_type __d@[???] */
          if (-0x80000001 < (long)uVar5) goto LAB_0010dd40;
          goto LAB_0010dd44;
        }
LAB_0010dd87:
        p_Var6 = p_Var7->_M_right;
        bVar2 = false;
      }
      else {
LAB_0010dd40:
        if (-1 < (int)uVar5) goto LAB_0010dd87;
LAB_0010dd44:
        p_Var6 = p_Var7->_M_left;
        bVar2 = true;
      }
    } while (p_Var6 != (_Base_ptr)0x0);
    p_Var6 = p_Var7;
    if (bVar2) goto LAB_0010de00;
  }
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
  iVar4 = rea_memcmp(__s2,__s1,__n);
  if (iVar4 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */
    lVar9 = uVar8 - uVar10;
    if (lVar9 < 0x80000000) {
      if (lVar9 < -0x80000000) goto LAB_0010dde0;
      iVar4 = (int)lVar9;
      goto LAB_0010dddb;
    }
  }
  else {
LAB_0010dddb:
    if (iVar4 < 0) {
LAB_0010dde0:
      (*(undefined8 *)((uint8_t *)&auVar1 + 0x8)) = 0;
      (*(undefined8 *)((uint8_t *)&auVar1 + 0x0)) = p_Var7;
      return (pair_std___Rb_tree_node_base___std___Rb_tree_node_base_)(auVar1 << 0x40);
    }
  }
  p_Var7 = (_Rb_tree_node_base *)0x0;
LAB_0010ddbd:
  pVar11.second = p_Var7;
  pVar11.first = p_Var6;
  return pVar11;
}





// ------------------------------------------------------------------
// IDX 203  0010de50  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_hint_unique_pos__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, const_iterator __position, key_type * __k)
{
  void *__s2;
  char *pcVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  const_iterator cVar7;
  _Base_ptr p_Var8;
  ulong uVar9;
  long lVar10;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar11;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar12;
  
                    /* Unresolved local var: iterator __pos@[DW_OP_reg4(RSI); DW_OP_piece: 8] */
  if (__position._M_node == &(this_ptr->_M_impl)._M_header) {
    if ((this_ptr->_M_impl)._M_node_count == 0) goto LAB_0010e000;
    __position._M_node = (this_ptr->_M_impl)._M_header._M_right;
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
    pcVar1 = (__k->_M_dataplus)._M_p;
    uVar2 = *(ulong *)(pcVar1 + -0x18);
    uVar3 = *(ulong *)((long)*(void **)(__position._M_node + 1) + -0x18);
    uVar9 = uVar3;
    if (uVar2 <= uVar3) {
      uVar9 = uVar2;
    }
    iVar5 = rea_memcmp(*(void **)(__position._M_node + 1),pcVar1,uVar9);
    if (iVar5 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */
      lVar10 = uVar3 - uVar2;
      if (0x7fffffff < lVar10) goto LAB_0010e000;
      if (-0x80000001 < lVar10) {
        iVar5 = (int)lVar10;
        goto LAB_0010e065;
      }
    }
    else {
LAB_0010e065:
      if (-1 < iVar5) goto LAB_0010e000;
    }
LAB_0010e069:
    cVar7._M_node = (_Base_ptr)0x0;
    goto LAB_0010deff;
  }
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
  __s2 = *(void **)(__position._M_node + 1);
  pcVar1 = (__k->_M_dataplus)._M_p;
  uVar2 = *(ulong *)((long)__s2 + -0x18);
  uVar3 = *(ulong *)(pcVar1 + -0x18);
  uVar9 = uVar3;
  if (uVar2 <= uVar3) {
    uVar9 = uVar2;
  }
  uVar4 = rea_memcmp(pcVar1,__s2,uVar9);
  uVar6 = (ulong)uVar4;
  cVar7._M_node = __position._M_node;
  if (uVar4 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */
    uVar6 = uVar3 - uVar2;
    if ((long)uVar6 < 0x80000000) {
      if (-0x80000001 < (long)uVar6) goto LAB_0010dfa0;
      goto LAB_0010df1c;
    }
  }
  else {
LAB_0010dfa0:
    if ((int)uVar6 < 0) {
LAB_0010df1c:
                    /* Unresolved local var: iterator __before@[???] */
      if ((this_ptr->_M_impl)._M_header._M_left != __position._M_node) {
        p_Var8 = (_Base_ptr)rea_std___Rb_tree_decrement(__position._M_node);
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
        uVar2 = *(ulong *)((long)*(void **)(p_Var8 + 1) + -0x18);
        uVar9 = uVar3;
        if (uVar2 <= uVar3) {
          uVar9 = uVar2;
        }
        iVar5 = rea_memcmp(*(void **)(p_Var8 + 1),pcVar1,uVar9);
        if (iVar5 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */
          lVar10 = uVar2 - uVar3;
          if (0x7fffffff < lVar10) goto LAB_0010e000;
          if (lVar10 < -0x80000000) goto LAB_0010df7c;
          iVar5 = (int)lVar10;
        }
        if (iVar5 < 0) {
LAB_0010df7c:
          if (p_Var8->_M_right == (_Base_ptr)0x0) {
            __position._M_node = p_Var8;
            cVar7._M_node = (_Base_ptr)0x0;
          }
          pVar12.second = __position._M_node;
          pVar12.first = cVar7._M_node;
          return pVar12;
        }
        goto LAB_0010e000;
      }
      goto LAB_0010deff;
    }
  }
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
  iVar5 = rea_memcmp(__s2,pcVar1,uVar9);
  if (iVar5 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */
    lVar10 = uVar2 - uVar3;
    if (lVar10 < 0x80000000) {
      if (-0x80000001 < lVar10) {
        iVar5 = (int)lVar10;
        goto LAB_0010def2;
      }
      goto LAB_0010dfb0;
    }
  }
  else {
LAB_0010def2:
    if (iVar5 < 0) {
LAB_0010dfb0:
                    /* Unresolved local var: iterator __after@[???] */
      if ((this_ptr->_M_impl)._M_header._M_right == __position._M_node) goto LAB_0010e069;
      p_Var8 = (_Base_ptr)rea_std___Rb_tree_increment(__position._M_node);
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
      uVar2 = *(ulong *)((long)*(void **)(p_Var8 + 1) + -0x18);
      uVar9 = uVar3;
      if (uVar2 <= uVar3) {
        uVar9 = uVar2;
      }
      iVar5 = rea_memcmp(pcVar1,*(void **)(p_Var8 + 1),uVar9);
      if (iVar5 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */
        lVar10 = uVar3 - uVar2;
        if (0x7fffffff < lVar10) goto LAB_0010e000;
        if (-0x80000001 < lVar10) {
          iVar5 = (int)lVar10;
          goto LAB_0010e083;
        }
      }
      else {
LAB_0010e083:
        if (-1 < iVar5) {
LAB_0010e000:
          pVar12 = _M_get_insert_unique_pos(this_ptr,__k);
          return pVar12;
        }
      }
      cVar7._M_node = (_Base_ptr)0x0;
      if ((__position._M_node)->_M_right != (_Base_ptr)0x0) {
        cVar7._M_node = p_Var8;
        __position._M_node = p_Var8;
      }
      goto LAB_0010deff;
    }
  }
  __position._M_node = (_Base_ptr)0x0;
LAB_0010deff:
  pVar11.second = __position._M_node;
  pVar11.first = cVar7._M_node;
  return pVar11;
}





// ------------------------------------------------------------------
// IDX 204  0010e0b0  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_______M_emplace_hint_unique_const_std__piecewise_construct_t___std__tuple_const_std__basic_string_char__std__char_traits_char__std__allocator_char____std__tuple_____________
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_______M_emplace_hint_unique_const_std__piecewise_construct_t___std__tuple_const_std__basic_string_char__std__char_traits_char__std__allocator_char____std__tuple__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, const_iterator __pos)
{
  _Rb_tree_node_base *p_Var1;
  size_type *psVar2;
  int *piVar3;
  string *psVar4;
  ulong uVar5;
  ulong uVar6;
  int iVar7;
  _Rb_tree_node_base *p_Var8;
  undefined8 *in_RCX;
  ulong __n;
  bool bVar9;
  _Rb_tree_node_base *p_Var10;
  long lVar11;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar12;
  
  p_Var10 = (_Rb_tree_node_base *)0x20;
                    /* Unresolved local var: _Link_type __z@[???]
                       Unresolved local var: _Link_type __tmp@[???] */
  p_Var8 = rea_operator_new(0x30);
  if (p_Var8 != (_Rb_tree_node_base *)0x0) {
    p_Var10 = p_Var8 + 1;
    psVar4 = (string *)*in_RCX;
    p_Var8->_M_color = _S_red;
    p_Var8->_M_parent = (_Base_ptr)0x0;
    p_Var8->_M_left = (_Base_ptr)0x0;
    p_Var8->_M_right = (_Base_ptr)0x0;
    rea_std__string__string(p_Var10,psVar4);
    p_Var8[1]._M_parent = (_Base_ptr)0x0;
  }
                    /* Unresolved local var:
                       pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ __res@[???] */
  pVar12 = _M_get_insert_hint_unique_pos(this_ptr,__pos,(key_type *)p_Var10);
  p_Var10 = pVar12.second;
  if (p_Var10 == (_Rb_tree_node_base *)0x0) {
    lVar11 = *(long *)(p_Var8 + 1);
    if ((allocator *)(lVar11 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar3 = (int *)(lVar11 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
        iVar7 = *(int *)(lVar11 + -8);
        *(int *)(lVar11 + -8) = iVar7 + -1;
      }
      else {
        LOCK();
        iVar7 = *piVar3;
        *piVar3 = *piVar3 + -1;
        UNLOCK();
      }
      if (iVar7 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)(lVar11 + -0x18));
      }
    }
    rea_operator_delete(p_Var8);
    return (iterator)pVar12.first;
  }
                    /* Unresolved local var: bool __insert_left@[???] */
  p_Var1 = &(this_ptr->_M_impl)._M_header;
  if ((pVar12.first == (_Base_ptr)0x0) && (p_Var10 != p_Var1)) {
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
    uVar5 = *(ulong *)((long)*(void **)(p_Var8 + 1) + -0x18);
    uVar6 = *(ulong *)((long)*(void **)(p_Var10 + 1) + -0x18);
    __n = uVar5;
    if (uVar6 <= uVar5) {
      __n = uVar6;
    }
    iVar7 = rea_memcmp(*(void **)(p_Var8 + 1),*(void **)(p_Var10 + 1),__n);
    if (iVar7 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */
      lVar11 = uVar5 - uVar6;
      bVar9 = false;
      if (0x7fffffff < lVar11) goto LAB_0010e136;
      if (lVar11 < -0x80000000) goto LAB_0010e131;
      iVar7 = (int)lVar11;
    }
    if (-1 < iVar7) {
      bVar9 = false;
      goto LAB_0010e136;
    }
  }
LAB_0010e131:
  bVar9 = true;
LAB_0010e136:
  rea_std___Rb_tree_insert_and_rebalance(bVar9,p_Var8,p_Var10,p_Var1);
  psVar2 = &(this_ptr->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)p_Var8;
}





// ------------------------------------------------------------------
// IDX 205  0010e270  std__vector_double__std__allocator_double___operator_assign___________
// ------------------------------------------------------------------
vector_double__std__allocator_double_ * rea_std__vector_double__std__allocator_double___operator__assign__dup2(vector_double__std__allocator_double_ * this_ptr, vector_double__std__allocator_double_ * __x)
{
  _Rb_tree_color _Var1;
  _Const_Link_type p_Var2;
  double dVar3;
  double dVar4;
  ulong uVar5;
  pointer pdVar6;
  _Link_type __p;
  _Link_type p_Var7;
  _Link_type p_Var8;
  pointer pdVar9;
  pointer pdVar10;
  undefined8 uVar11;
  long lVar12;
  _Base_ptr extraout_RDX;
  ulong uVar13;
  pointer __src;
  _Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
  *this_00;
  size_t sVar14;
  
  if (__x == this_ptr) {
    return this_ptr;
  }
                    /* Unresolved local var: size_type __xlen@[???] */
  pdVar6 = (__x->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish;
  pdVar9 = (__x->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
  this_00 = (_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
             *)(this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
  uVar13 = (long)pdVar6 - (long)pdVar9 >> 3;
  if (uVar13 <= (ulong)((long)(this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl.
                              _M_end_of_storage - (long)this_00 >> 3)) {
    pdVar10 = (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish;
    uVar5 = (long)pdVar10 - (long)this_00 >> 3;
    if (uVar5 < uVar13) {
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
      __src = pdVar9 + uVar5;
      if (uVar5 == 0) {
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
        lVar12 = (long)pdVar6 - (long)__src;
        this_00 = (_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
                   *)((long)&this_00->_M_impl + uVar13 * 8);
      }
      else {
        rea_memmove(this_00,pdVar9,uVar5 * 8);
        pdVar10 = (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish;
        pdVar6 = (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
        this_00 = (_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
                   *)(pdVar6 + uVar13);
        __src = (pointer)(((long)pdVar10 - (long)pdVar6 & 0xfffffffffffffff8U) +
                         (long)(__x->super__Vector_base_double__std__allocator_double_)._M_impl.
                               _M_start);
        lVar12 = (long)(__x->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish
                 - (long)__src;
      }
      if (lVar12 >> 3 != 0) {
        rea_memmove(pdVar10,__src,(lVar12 >> 3) * 8);
        (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish =
             (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start + uVar13;
        return this_ptr;
      }
    }
    else {
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
      if (uVar13 != 0) {
        rea_memmove(this_00,pdVar9,uVar13 * 8);
        (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish =
             (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start + uVar13;
        return this_ptr;
      }
    }
    (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish = (pointer)this_00
    ;
    return this_ptr;
  }
                    /* Unresolved local var: pointer __tmp@[???]
                       Unresolved local var: pointer __result@[???] */
  if (uVar13 == 0) {
    uVar5 = 0;
    pdVar6 = (pointer)0x0;
  }
  else {
    if (0x1fffffffffffffff < uVar13) {
      rea_std____throw_bad_alloc();
      __p = rea_operator_new(0x40);
      if (__p != (_Link_type)0x0) {
        (__p->super__Rb_tree_node_base)._M_color = _S_red;
        (__p->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
        (__p->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
        (__p->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
        rea_std__string__string(&__p->_M_value_field,
                            (string *)
                            &__x[1].super__Vector_base_double__std__allocator_double_._M_impl.
                             _M_finish);
        pdVar6 = __x[2].super__Vector_base_double__std__allocator_double_._M_impl._M_start;
        pdVar9 = __x[1].super__Vector_base_double__std__allocator_double_._M_impl.
                 _M_end_of_storage;
        uVar13 = 0;
        pdVar10 = (pointer)0x0;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_start = (pointer)0x0;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_finish = (pointer)0x0;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_end_of_storage = (pointer)0x0;
        uVar5 = (long)pdVar6 - (long)pdVar9 >> 3;
        if (uVar5 != 0) {
          if (0x1fffffffffffffff < uVar5) {
            p_Var8 = (_Link_type)rea_std____throw_bad_alloc();
            std__string___Rep___M_dispose_______________________((allocator *)((__p->_M_value_field).first._M_dataplus._M_p + -0x18));
            p_Var7 = p_Var8;
            goto LAB_0010e6ea;
          }
          uVar13 = uVar5 * 8;
          pdVar10 = rea_operator_new(uVar13);
        }
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_start = pdVar10;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_finish = pdVar10;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_end_of_storage = (pointer)(uVar13 + (long)pdVar10);
        pdVar6 = __x[1].super__Vector_base_double__std__allocator_double_._M_impl.
                 _M_end_of_storage;
        sVar14 = 0;
        lVar12 = (long)__x[2].super__Vector_base_double__std__allocator_double_._M_impl._M_start -
                 (long)pdVar6 >> 3;
        if (lVar12 != 0) {
          sVar14 = lVar12 * 8;
          pdVar10 = rea_memmove(pdVar10,pdVar6,sVar14);
        }
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
        _M_finish = (pointer)((long)pdVar10 + sVar14);
      }
      _Var1 = *(_Rb_tree_color *)
               &(__x->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
      (__p->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
      p_Var2 = (_Const_Link_type)
               __x[1].super__Vector_base_double__std__allocator_double_._M_impl._M_start;
      (__p->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
      (__p->super__Rb_tree_node_base)._M_parent = extraout_RDX;
      (__p->super__Rb_tree_node_base)._M_color = _Var1;
      if (p_Var2 != (_Const_Link_type)0x0) {
        p_Var7 = _Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_________________________M_copy(this_00,p_Var2,__p);
        (__p->super__Rb_tree_node_base)._M_right = &p_Var7->super__Rb_tree_node_base;
      }
      pdVar6 = (__x->super__Vector_base_double__std__allocator_double_)._M_impl._M_end_of_storage;
      p_Var8 = __p;
      do {
        if (pdVar6 == (pointer)0x0) {
          return (vector_double__std__allocator_double_ *)__p;
        }
        p_Var7 = rea_operator_new(0x40);
        if (p_Var7 != (_Link_type)0x0) {
          (p_Var7->super__Rb_tree_node_base)._M_color = _S_red;
          (p_Var7->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
          (p_Var7->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
          (p_Var7->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
          rea_std__string__string(&p_Var7->_M_value_field,(string *)(pdVar6 + 4));
          dVar3 = pdVar6[6];
          dVar4 = pdVar6[5];
          uVar13 = 0;
          pdVar9 = (pointer)0x0;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
          _M_impl._M_start = (pointer)0x0;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
          _M_impl._M_finish = (pointer)0x0;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
          _M_impl._M_end_of_storage = (pointer)0x0;
          uVar5 = (long)dVar3 - (long)dVar4 >> 3;
          if (uVar5 != 0) {
            if (0x1fffffffffffffff < uVar5) {
              uVar11 = rea_std____throw_bad_alloc();
              do {
                std__string___Rep___M_dispose___________________________((allocator *)((p_Var7->_M_value_field).first._M_dataplus._M_p + -0x18));
                rea___cxa_begin_catch(uVar11);
                rea_operator_delete(p_Var7);
                p_Var8 = (_Link_type)rea___cxa_rethrow();
LAB_0010e6ea:
                rea___cxa_begin_catch(p_Var8);
                rea_operator_delete(__p);
                uVar11 = rea___cxa_rethrow();
              } while( true );
            }
            uVar13 = uVar5 * 8;
            pdVar9 = rea_operator_new(uVar13);
          }
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
          _M_impl._M_start = pdVar9;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
          _M_impl._M_finish = pdVar9;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
          _M_impl._M_end_of_storage = (pointer)(uVar13 + (long)pdVar9);
          sVar14 = 0;
          lVar12 = (long)pdVar6[6] - (long)pdVar6[5] >> 3;
          if (lVar12 != 0) {
            sVar14 = lVar12 * 8;
            pdVar9 = rea_memmove(pdVar9,(void *)pdVar6[5],sVar14);
          }
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
          _M_impl._M_finish = (pointer)((long)pdVar9 + sVar14);
        }
        _Var1 = *(_Rb_tree_color *)pdVar6;
        (p_Var7->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
        p_Var2 = (_Const_Link_type)pdVar6[3];
        (p_Var7->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
        (p_Var7->super__Rb_tree_node_base)._M_color = _Var1;
        (p_Var8->super__Rb_tree_node_base)._M_left = &p_Var7->super__Rb_tree_node_base;
        (p_Var7->super__Rb_tree_node_base)._M_parent = &p_Var8->super__Rb_tree_node_base;
        if (p_Var2 != (_Const_Link_type)0x0) {
          p_Var8 = _Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___________________________M_copy(this_00,p_Var2,p_Var7);
          (p_Var7->super__Rb_tree_node_base)._M_right = &p_Var8->super__Rb_tree_node_base;
        }
        pdVar6 = (pointer)pdVar6[2];
        p_Var8 = p_Var7;
      } while( true );
    }
    uVar5 = uVar13 * 8;
    pdVar6 = rea_operator_new(uVar5);
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
    if (uVar13 != 0) {
      rea_memmove(pdVar6,pdVar9,uVar5);
      pdVar9 = (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
      goto joined_r0x0010e356;
    }
  }
  pdVar9 = (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
joined_r0x0010e356:
  if (pdVar9 != (pointer)0x0) {
    rea_operator_delete(pdVar9);
  }
  (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start = pdVar6;
  (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_end_of_storage =
       (pointer)((long)pdVar6 + uVar5);
  (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish =
       (pointer)((long)pdVar6 + uVar5);
  return this_ptr;
}





// ------------------------------------------------------------------
// IDX 206  0010e430  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_copy
// ------------------------------------------------------------------
_Link_type rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_copy__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * this_ptr, _Const_Link_type __x, _Link_type __p)
{
  _Rb_tree_color _Var1;
  pointer pdVar2;
  _Const_Link_type p_Var3;
  _Base_ptr p_Var4;
  _Base_ptr p_Var5;
  _Base_ptr p_Var6;
  _Link_type __p_00;
  _Link_type p_Var7;
  _Link_type p_Var8;
  pointer pdVar9;
  pointer __dest;
  undefined8 uVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  size_t sVar14;
  
                    /* Unresolved local var: _Link_type __top@[???]
                       Unresolved local var: _Link_type __tmp@[???] */
  __p_00 = rea_operator_new(0x40);
  if (__p_00 != (_Link_type)0x0) {
    (__p_00->super__Rb_tree_node_base)._M_color = _S_red;
    (__p_00->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    rea_std__string__string(&__p_00->_M_value_field,&(__x->_M_value_field).first);
    pdVar9 = (__x->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
             _M_impl._M_finish;
    pdVar2 = (__x->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
             _M_impl._M_start;
    uVar13 = 0;
    __dest = (pointer)0x0;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
    _M_start = (pointer)0x0;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
    _M_finish = (pointer)0x0;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
    _M_end_of_storage = (pointer)0x0;
    uVar11 = (long)pdVar9 - (long)pdVar2 >> 3;
    if (uVar11 != 0) {
      if (0x1fffffffffffffff < uVar11) {
        p_Var8 = (_Link_type)rea_std____throw_bad_alloc();
        std__string___Rep___M_dispose___________________((allocator *)((__p_00->_M_value_field).first._M_dataplus._M_p + -0x18));
        p_Var7 = p_Var8;
        goto LAB_0010e6ea;
      }
      uVar13 = uVar11 * 8;
      __dest = rea_operator_new(uVar13);
    }
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
    _M_start = __dest;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
    _M_finish = __dest;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
    _M_end_of_storage = (pointer)(uVar13 + (long)__dest);
    pdVar9 = (__x->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
             _M_impl._M_start;
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
    sVar14 = 0;
    lVar12 = (long)(__x->_M_value_field).second.super__Vector_base_double__std__allocator_double_.
                   _M_impl._M_finish - (long)pdVar9 >> 3;
    if (lVar12 != 0) {
      sVar14 = lVar12 * 8;
      __dest = rea_memmove(__dest,pdVar9,sVar14);
    }
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
    _M_finish = (pointer)((long)__dest + sVar14);
  }
  _Var1 = (__x->super__Rb_tree_node_base)._M_color;
  (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
  p_Var3 = (_Const_Link_type)(__x->super__Rb_tree_node_base)._M_right;
  (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
  (__p_00->super__Rb_tree_node_base)._M_parent = &__p->super__Rb_tree_node_base;
  (__p_00->super__Rb_tree_node_base)._M_color = _Var1;
  if (p_Var3 != (_Const_Link_type)0x0) {
    p_Var7 = _M_copy(this_ptr,p_Var3,__p_00);
    (__p_00->super__Rb_tree_node_base)._M_right = &p_Var7->super__Rb_tree_node_base;
  }
  p_Var4 = (__x->super__Rb_tree_node_base)._M_left;
  p_Var8 = __p_00;
  do {
    if (p_Var4 == (_Base_ptr)0x0) {
      return __p_00;
    }
    p_Var7 = rea_operator_new(0x40);
    if (p_Var7 != (_Link_type)0x0) {
      (p_Var7->super__Rb_tree_node_base)._M_color = _S_red;
      (p_Var7->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
      (p_Var7->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
      (p_Var7->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
      rea_std__string__string(&p_Var7->_M_value_field,(string *)(p_Var4 + 1));
      p_Var5 = p_Var4[1]._M_left;
      p_Var6 = p_Var4[1]._M_parent;
      uVar13 = 0;
      pdVar9 = (pointer)0x0;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
      _M_start = (pointer)0x0;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
      _M_finish = (pointer)0x0;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
      _M_end_of_storage = (pointer)0x0;
      uVar11 = (long)p_Var5 - (long)p_Var6 >> 3;
      if (uVar11 != 0) {
        if (0x1fffffffffffffff < uVar11) {
          uVar10 = rea_std____throw_bad_alloc();
          do {
            std__string___Rep___M_dispose_______________________((allocator *)((p_Var7->_M_value_field).first._M_dataplus._M_p + -0x18));
            rea___cxa_begin_catch(uVar10);
            rea_operator_delete(p_Var7);
            p_Var8 = (_Link_type)rea___cxa_rethrow();
LAB_0010e6ea:
            rea___cxa_begin_catch(p_Var8);
            rea_operator_delete(__p_00);
            uVar10 = rea___cxa_rethrow();
          } while( true );
        }
        uVar13 = uVar11 * 8;
        pdVar9 = rea_operator_new(uVar13);
      }
                    /* Unresolved local var: _Link_type __y@[???]
                       Unresolved local var: _Link_type __tmp@[???] */
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
      _M_start = pdVar9;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
      _M_finish = pdVar9;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
      _M_end_of_storage = (pointer)(uVar13 + (long)pdVar9);
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
      sVar14 = 0;
      lVar12 = (long)p_Var4[1]._M_left - (long)p_Var4[1]._M_parent >> 3;
      if (lVar12 != 0) {
        sVar14 = lVar12 * 8;
        pdVar9 = rea_memmove(pdVar9,p_Var4[1]._M_parent,sVar14);
      }
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl.
      _M_finish = (pointer)((long)pdVar9 + sVar14);
    }
    _Var1 = p_Var4->_M_color;
    (p_Var7->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    p_Var3 = (_Const_Link_type)p_Var4->_M_right;
    (p_Var7->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (p_Var7->super__Rb_tree_node_base)._M_color = _Var1;
    (p_Var8->super__Rb_tree_node_base)._M_left = &p_Var7->super__Rb_tree_node_base;
    (p_Var7->super__Rb_tree_node_base)._M_parent = &p_Var8->super__Rb_tree_node_base;
    if (p_Var3 != (_Const_Link_type)0x0) {
      p_Var8 = _M_copy(this_ptr,p_Var3,p_Var7);
      (p_Var7->super__Rb_tree_node_base)._M_right = &p_Var8->super__Rb_tree_node_base;
    }
    p_Var4 = p_Var4->_M_left;
    p_Var8 = p_Var7;
  } while( true );
}





// ------------------------------------------------------------------
// IDX 207  0010e780  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_copy
// ------------------------------------------------------------------
_Link_type rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_copy__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, _Const_Link_type __x, _Link_type __p)
{
  _Rb_tree_color _Var1;
  _Const_Link_type p_Var2;
  _Base_ptr p_Var3;
  _Link_type __p_00;
  _Link_type p_Var4;
  _Link_type __p_01;
  
                    /* Unresolved local var: _Link_type __top@[???]
                       Unresolved local var: _Link_type __tmp@[???] */
  __p_00 = rea_operator_new(0x30);
  if (__p_00 != (_Link_type)0x0) {
    (__p_00->super__Rb_tree_node_base)._M_color = _S_red;
    (__p_00->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    rea_std__string__string(&__p_00->_M_value_field,&(__x->_M_value_field).first);
    (__p_00->_M_value_field).second = (__x->_M_value_field).second;
  }
  _Var1 = (__x->super__Rb_tree_node_base)._M_color;
  (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
  p_Var2 = (_Const_Link_type)(__x->super__Rb_tree_node_base)._M_right;
  (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
  (__p_00->super__Rb_tree_node_base)._M_parent = &__p->super__Rb_tree_node_base;
  (__p_00->super__Rb_tree_node_base)._M_color = _Var1;
  if (p_Var2 != (_Const_Link_type)0x0) {
    p_Var4 = _M_copy(this_ptr,p_Var2,__p_00);
    (__p_00->super__Rb_tree_node_base)._M_right = &p_Var4->super__Rb_tree_node_base;
  }
  p_Var4 = __p_00;
  for (p_Var3 = (__x->super__Rb_tree_node_base)._M_left; p_Var3 != (_Base_ptr)0x0;
      p_Var3 = p_Var3->_M_left) {
                    /* Unresolved local var: _Link_type __y@[???]
                       Unresolved local var: _Link_type __tmp@[???] */
    __p_01 = rea_operator_new(0x30);
    if (__p_01 != (_Link_type)0x0) {
      (__p_01->super__Rb_tree_node_base)._M_color = _S_red;
      (__p_01->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
      (__p_01->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
      (__p_01->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
      rea_std__string__string(&__p_01->_M_value_field,(string *)(p_Var3 + 1));
      (__p_01->_M_value_field).second = (double)p_Var3[1]._M_parent;
    }
    _Var1 = p_Var3->_M_color;
    (__p_01->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    p_Var2 = (_Const_Link_type)p_Var3->_M_right;
    (__p_01->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__p_01->super__Rb_tree_node_base)._M_color = _Var1;
    (p_Var4->super__Rb_tree_node_base)._M_left = &__p_01->super__Rb_tree_node_base;
    (__p_01->super__Rb_tree_node_base)._M_parent = &p_Var4->super__Rb_tree_node_base;
    if (p_Var2 != (_Const_Link_type)0x0) {
      p_Var4 = _M_copy(this_ptr,p_Var2,__p_01);
      (__p_01->super__Rb_tree_node_base)._M_right = &p_Var4->super__Rb_tree_node_base;
    }
    p_Var4 = __p_01;
  }
  return __p_00;
}





// ------------------------------------------------------------------
// IDX 208  0010e930  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_insert__const_std__pair_std__basic_string_char__std__vector_double_____________
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_insert__const_std__pair_std__basic_string_char__std__vector_double__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * this_ptr, _Base_ptr __x, _Base_ptr __p, pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__ * __v)
{
  size_type *psVar1;
  pointer pdVar2;
  pointer pdVar3;
  char *__s1;
  int iVar4;
  _Rb_tree_node_base *p_Var5;
  _Base_ptr __dest;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  ulong __n;
  size_t __n_00;
  bool bVar9;
  ulong uVar10;
  
                    /* Unresolved local var: bool __insert_left@[???]
                       Unresolved local var: _Link_type __z@[???] */
  bVar9 = true;
  if ((__x == (_Base_ptr)0x0) && (__p != &(this_ptr->_M_impl)._M_header)) {
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
    __s1 = (__v->first)._M_dataplus._M_p;
    uVar10 = *(ulong *)((long)*(void **)(__p + 1) + -0x18);
    uVar7 = *(ulong *)(__s1 + -0x18);
    __n = uVar7;
    if (uVar10 <= uVar7) {
      __n = uVar10;
    }
    iVar4 = rea_memcmp(__s1,*(void **)(__p + 1),__n);
    if (iVar4 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */
      lVar8 = uVar7 - uVar10;
      bVar9 = false;
      if ((0x7fffffff < lVar8) || (bVar9 = true, lVar8 < -0x80000000)) goto LAB_0010e956;
      iVar4 = (int)lVar8;
    }
    bVar9 = SUB41((uint)iVar4 >> 0x1f,0);
  }
LAB_0010e956:
                    /* Unresolved local var: _Link_type __tmp@[???] */
  p_Var5 = rea_operator_new(0x40);
  if (p_Var5 != (_Rb_tree_node_base *)0x0) {
    p_Var5->_M_color = _S_red;
    p_Var5->_M_parent = (_Base_ptr)0x0;
    p_Var5->_M_left = (_Base_ptr)0x0;
    p_Var5->_M_right = (_Base_ptr)0x0;
    rea_std__string__string(p_Var5 + 1,&__v->first);
    pdVar2 = (__v->second).super__Vector_base_double__std__allocator_double_._M_impl._M_finish;
    pdVar3 = (__v->second).super__Vector_base_double__std__allocator_double_._M_impl._M_start;
    uVar10 = 0;
    __dest = (_Base_ptr)0x0;
    p_Var5[1]._M_parent = (_Base_ptr)0x0;
    p_Var5[1]._M_left = (_Base_ptr)0x0;
    p_Var5[1]._M_right = (_Base_ptr)0x0;
    uVar7 = (long)pdVar2 - (long)pdVar3 >> 3;
    if (uVar7 != 0) {
      if (0x1fffffffffffffff < uVar7) {
        uVar6 = rea_std____throw_bad_alloc();
        rea_std__string___Rep___M_dispose((allocator *)(*(long *)(p_Var5 + 1) + -0x18));
        do {
          rea___cxa_begin_catch(uVar6);
          rea_operator_delete(p_Var5);
          uVar6 = rea___cxa_rethrow();
        } while( true );
      }
      uVar10 = uVar7 * 8;
      __dest = rea_operator_new(uVar10);
    }
    p_Var5[1]._M_parent = __dest;
    p_Var5[1]._M_left = __dest;
    p_Var5[1]._M_right = (_Base_ptr)((long)&__dest->_M_color + uVar10);
    pdVar2 = (__v->second).super__Vector_base_double__std__allocator_double_._M_impl._M_start;
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
    __n_00 = 0;
    lVar8 = (long)(__v->second).super__Vector_base_double__std__allocator_double_._M_impl.
                  _M_finish - (long)pdVar2 >> 3;
    if (lVar8 != 0) {
      __n_00 = lVar8 * 8;
      __dest = rea_memmove(__dest,pdVar2,__n_00);
    }
    p_Var5[1]._M_left = (_Base_ptr)((long)&__dest->_M_color + __n_00);
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar9,p_Var5,__p,&(this_ptr->_M_impl)._M_header);
  psVar1 = &(this_ptr->_M_impl)._M_node_count;
  *psVar1 = *psVar1 + 1;
  return (iterator)p_Var5;
}





// ------------------------------------------------------------------
// IDX 209  0010eb20  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_insert__const_std__pair_std__basic_string_char__double____________
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_insert__const_std__pair_std__basic_string_char__double__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, _Base_ptr __x, _Base_ptr __p, pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double * __v)
{
  size_type *psVar1;
  char *__s1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  _Rb_tree_node_base *p_Var5;
  ulong __n;
  bool bVar6;
  long lVar7;
  
                    /* Unresolved local var: bool __insert_left@[???]
                       Unresolved local var: _Link_type __z@[???] */
  bVar6 = true;
  if ((__x == (_Base_ptr)0x0) && (__p != &(this_ptr->_M_impl)._M_header)) {
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
    __s1 = (__v->first)._M_dataplus._M_p;
    uVar2 = *(ulong *)((long)*(void **)(__p + 1) + -0x18);
    uVar3 = *(ulong *)(__s1 + -0x18);
    __n = uVar3;
    if (uVar2 <= uVar3) {
      __n = uVar2;
    }
    iVar4 = rea_memcmp(__s1,*(void **)(__p + 1),__n);
    if (iVar4 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */
      lVar7 = uVar3 - uVar2;
      bVar6 = false;
      if ((0x7fffffff < lVar7) || (bVar6 = true, lVar7 < -0x80000000)) goto LAB_0010eb42;
      iVar4 = (int)lVar7;
    }
    bVar6 = SUB41((uint)iVar4 >> 0x1f,0);
  }
LAB_0010eb42:
                    /* Unresolved local var: _Link_type __tmp@[???] */
  p_Var5 = rea_operator_new(0x30);
  if (p_Var5 != (_Rb_tree_node_base *)0x0) {
    p_Var5->_M_color = _S_red;
    p_Var5->_M_parent = (_Base_ptr)0x0;
    p_Var5->_M_left = (_Base_ptr)0x0;
    p_Var5->_M_right = (_Base_ptr)0x0;
    rea_std__string__string(p_Var5 + 1,&__v->first);
    p_Var5[1]._M_parent = (_Base_ptr)__v->second;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar6,p_Var5,__p,&(this_ptr->_M_impl)._M_header);
  psVar1 = &(this_ptr->_M_impl)._M_node_count;
  *psVar1 = *psVar1 + 1;
  return (iterator)p_Var5;
}





// ------------------------------------------------------------------
// IDX 210  0010ec40  _Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse
// ------------------------------------------------------------------
undefined8 rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse__dup2(vector_unsigned_char__std__allocator_unsigned_char_ * b, size_t p, map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * v)
{
  _Rb_tree_node_base *__p;
  int *piVar1;
  ulong uVar2;
  undefined *puVar3;
  ulong uVar4;
  int iVar5;
  pointer puVar6;
  ulong uVar7;
  ulong *puVar8;
  undefined *puVar9;
  _Link_type p_Var10;
  _Link_type p_Var11;
  long lVar12;
  ulong uVar13;
  pointer puVar14;
  _Link_type p_Var15;
  _Alloc_hider _Var16;
  ulong uVar17;
  pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ pVar18;
  ulong local_108;
  allocator local_9a [2];
  ulong o_1;
  pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double t;
  ulong o;
  double local_70;
  map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__
  vv;
  
                    /* Unresolved local var: size_t l@[???]
                       Unresolved local var: size_t np@[???]
                       Unresolved local var: uint8_t * s@[???] */
  uVar13 = p + 8;
  puVar6 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl._M_finish;
  puVar14 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl._M_start;
  vv._M_t._M_impl._M_header._M_color = _S_red;
  vv._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  vv._M_t._M_impl._M_header._M_left = &vv._M_t._M_impl._M_header;
  vv._M_t._M_impl._M_node_count = 0;
  vv._M_t._M_impl._M_header._M_right = vv._M_t._M_impl._M_header._M_left;
  if (uVar13 <= (ulong)((long)puVar6 - (long)puVar14)) {
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
    rea_memcpy((string *)&o,puVar14 + p,8);
    uVar4 = o;
    puVar3 = PTR__S_empty_rep_storage_00311ff0;
                    /* Unresolved local var: size_t i@[???] */
    if (o != 0) {
                    /* Unresolved local var: size_t nnp@[???]
                       Unresolved local var: size_t p1@[???]
                       Unresolved local var: size_t p2@[???]
                       Unresolved local var: size_t l@[???]
                       Unresolved local var: size_t np@[???]
                       Unresolved local var: uint8_t * s@[???]
                       Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
      local_108 = 0;
                    /* Unresolved local var: size_type __dnew@[???]
                       Unresolved local var: _Rep * __r@[???] */
      do {
        uVar7 = uVar13 + 8;
        _Var16._M_p = puVar3 + 0x18;
        t.second = 0.0;
        local_70 = 0.0;
        t.first._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var16._M_p;
        o = (ulong)_Var16._M_p;
        uVar17 = uVar13;
        if ((ulong)((long)puVar6 - (long)puVar14) < uVar7) {
LAB_0010ef10:
          puVar9 = puVar3 + 0x18;
        }
        else {
          rea_memcpy(&o_1,puVar14 + uVar13,8);
          uVar2 = uVar7 + o_1;
          if ((ulong)((long)puVar6 - (long)puVar14) < uVar2) goto LAB_0010ef10;
          puVar14 = puVar14 + uVar7;
          puVar6 = puVar14 + o_1;
          if (puVar14 != puVar6) {
            uVar7 = (long)puVar6 - (long)puVar14;
            puVar8 = (ulong *)rea_std__string___Rep___S_create(uVar7,0,local_9a);
            _Var16._M_p = (char *)(puVar8 + 3);
            lVar12 = 0;
            do {
              *(uchar *)((long)_Var16._M_p + lVar12) = puVar14[lVar12];
              lVar12 = lVar12 + 1;
            } while (lVar12 != (long)puVar6 - (long)puVar14);
            if (puVar8 != (ulong *)puVar3) {
              *(undefined4 *)(puVar8 + 2) = 0;
              *puVar8 = uVar7;
              *(undefined1 *)((long)puVar8 + uVar7 + 0x18) = 0;
            }
          }
          o_1 = (ulong)_Var16._M_p;
          rea_std__string__assign((string *)&o);
          if ((allocator *)(o_1 - 0x18) != (allocator *)puVar3) {
            piVar1 = (int *)(o_1 - 8);
            if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
              iVar5 = *(int *)(o_1 - 8);
              *(int *)(o_1 - 8) = iVar5 + -1;
            }
            else {
              LOCK();
              iVar5 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
            }
            if (iVar5 < 1) {
              rea_std__string___Rep___M_destroy((allocator *)(o_1 - 0x18));
            }
          }
          puVar9 = (undefined *)o;
          if (uVar13 != uVar2) {
            puVar6 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                     _M_start;
                    /* Unresolved local var: uint8_t * s@[???] */
            if (uVar2 + 8 <=
                (ulong)((long)(b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)
                              ._M_impl._M_finish - (long)puVar6)) {
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
              rea_memcpy(&o_1,puVar6 + uVar2,8);
              local_70 = (double)o_1;
              rea_std__string__assign(&t.first);
              t.second = local_70;
              puVar9 = (undefined *)o;
              uVar17 = uVar2 + 8;
            }
          }
        }
        if ((allocator *)(puVar9 + -0x18) != (allocator *)puVar3) {
          piVar1 = (int *)(puVar9 + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
            iVar5 = *(int *)(puVar9 + -8);
            *(int *)(puVar9 + -8) = iVar5 + -1;
          }
          else {
            LOCK();
            iVar5 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
          }
          if (iVar5 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)(puVar9 + -0x18));
          }
        }
        if (uVar13 == uVar17) {
          p_Var15 = (_Link_type)vv._M_t._M_impl._M_header._M_parent;
          if ((allocator *)((long)t.first._M_dataplus._M_p + -0x18) != (allocator *)puVar3) {
            piVar1 = (int *)((long)t.first._M_dataplus._M_p + -8);
            if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
              iVar5 = *(int *)((long)t.first._M_dataplus._M_p + -8);
              *(int *)((long)t.first._M_dataplus._M_p + -8) = iVar5 + -1;
            }
            else {
              LOCK();
              iVar5 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
            }
            if (iVar5 < 1) {
              rea_std__string___Rep___M_destroy((allocator *)((long)t.first._M_dataplus._M_p + -0x18));
              p_Var15 = (_Link_type)vv._M_t._M_impl._M_header._M_parent;
            }
          }
          goto LAB_0010efd9;
        }
                    /* Unresolved local var:
                       pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ __res@[???] */
        pVar18 = std_____________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_______________________M_get_insert_unique_pos(&vv._M_t,&t.first);
        if (pVar18.second != (_Base_ptr)0x0) {
          std______________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double________________M_insert__const_std__pair_std__basic_string_char__double______________________(&vv._M_t,pVar18.first,pVar18.second,&t);
        }
        if ((allocator *)((long)t.first._M_dataplus._M_p + -0x18) != (allocator *)puVar3) {
          piVar1 = (int *)((long)t.first._M_dataplus._M_p + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
            iVar5 = *(int *)((long)t.first._M_dataplus._M_p + -8);
            *(int *)((long)t.first._M_dataplus._M_p + -8) = iVar5 + -1;
          }
          else {
            LOCK();
            iVar5 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
          }
          if (iVar5 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)((long)t.first._M_dataplus._M_p + -0x18));
          }
        }
        local_108 = local_108 + 1;
        uVar13 = uVar17;
        if (local_108 == uVar4) break;
        puVar14 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                  _M_start;
        puVar6 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                 _M_finish;
      } while( true );
    }
    p = uVar13;
    p_Var15 = (_Link_type)vv._M_t._M_impl._M_header._M_parent;
    if (v == (map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__
              *)0x0) goto LAB_0010efd9;
    std________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__________M_erase(&v->_M_t,(_Link_type)(v->_M_t)._M_impl._M_header._M_parent);
    __p = &(v->_M_t)._M_impl._M_header;
    (v->_M_t)._M_impl._M_header._M_parent = (_Base_ptr)0x0;
    (v->_M_t)._M_impl._M_node_count = 0;
    (v->_M_t)._M_impl._M_header._M_left = __p;
    (v->_M_t)._M_impl._M_header._M_right = __p;
    if (vv._M_t._M_impl._M_header._M_parent != (_Base_ptr)0x0) {
      p_Var10 = std____________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______________________M_copy(&v->_M_t,(_Const_Link_type)vv._M_t._M_impl._M_header._M_parent,
                          (_Link_type)__p);
      (v->_M_t)._M_impl._M_header._M_parent = &p_Var10->super__Rb_tree_node_base;
      p_Var15 = p_Var10;
      do {
        p_Var11 = p_Var15;
        p_Var15 = (_Link_type)(p_Var11->super__Rb_tree_node_base)._M_left;
      } while (p_Var15 != (_Link_type)0x0);
      (v->_M_t)._M_impl._M_header._M_left = &p_Var11->super__Rb_tree_node_base;
      do {
        p_Var15 = p_Var10;
        p_Var10 = (_Link_type)(p_Var15->super__Rb_tree_node_base)._M_right;
      } while (p_Var10 != (_Link_type)0x0);
      (v->_M_t)._M_impl._M_header._M_right = &p_Var15->super__Rb_tree_node_base;
      (v->_M_t)._M_impl._M_node_count = vv._M_t._M_impl._M_node_count;
      p_Var15 = (_Link_type)vv._M_t._M_impl._M_header._M_parent;
      goto LAB_0010efd9;
    }
  }
  p_Var15 = (_Link_type)0x0;
LAB_0010efd9:
  std______Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double________M_erase(&vv._M_t,p_Var15);
  return p;
}





// ------------------------------------------------------------------
// IDX 211  0010f1d0  std__vector_double__std__allocator_double____M_emplace_back_aux_double_const____________
// ------------------------------------------------------------------
void rea_std__vector_double__std__allocator_double____M_emplace_back_aux_double_const__dup2(vector_double__std__allocator_double_ * this_ptr)
{
  pointer __dest;
  long lVar1;
  ulong uVar2;
  double *in_RSI;
  pointer __src;
  ulong uVar3;
  pointer pdVar4;
  
                    /* Unresolved local var: size_type __len@[???]
                       Unresolved local var: pointer __new_start@[???]
                       Unresolved local var: pointer __new_finish@[???]
                       Unresolved local var: size_type __len@[DW_OP_reg0(RAX)] */
  uVar2 = (long)(this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish -
          (long)(this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start >> 3;
  uVar3 = 8;
  if (uVar2 != 0) {
    if (uVar2 * 2 < uVar2) {
      uVar3 = 0xfffffffffffffff8;
    }
    else {
      uVar3 = 0xfffffffffffffff8;
      if (uVar2 * 2 < 0x2000000000000000) {
        uVar3 = uVar2 << 4;
      }
    }
  }
  __dest = rea_operator_new(uVar3);
  __src = (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
  lVar1 = (long)(this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish -
          (long)__src >> 3;
  pdVar4 = __dest + lVar1;
  if (pdVar4 != (pointer)0x0) {
    *pdVar4 = *in_RSI;
  }
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
  if (lVar1 != 0) {
    rea_memmove(__dest,__src,lVar1 * 8);
    __src = (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
  }
  if (__src != (pointer)0x0) {
    rea_operator_delete(__src);
  }
  (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_start = __dest;
  (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_finish = pdVar4 + 1;
  (this_ptr->super__Vector_base_double__std__allocator_double_)._M_impl._M_end_of_storage =
       (pointer)((long)__dest + uVar3);
  return;
}





// ------------------------------------------------------------------
// IDX 212  0010f2b0  _Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____M___parse
// ------------------------------------------------------------------
undefined8 rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____M___parse__dup2(vector_unsigned_char__std__allocator_unsigned_char_ * b, size_t p, map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * v)
{
  ulong uVar1;
  _Rb_tree_node_base *__p;
  int *piVar2;
  _Base_ptr p_Var3;
  bool bVar4;
  string sVar5;
  basic_string_char__std__char_traits_char__std__allocator_char_ __s1;
  ulong uVar6;
  uint uVar7;
  int iVar8;
  pointer puVar9;
  ulong *puVar10;
  _Link_type p_Var11;
  _Link_type p_Var12;
  ulong uVar13;
  size_t __n;
  _Alloc_hider _Var14;
  _Link_type p_Var15;
  void *pvVar16;
  pointer puVar17;
  ulong uVar18;
  long lVar19;
  ulong uVar20;
  _Base_ptr __p_00;
  _Alloc_hider local_148;
  ulong local_140;
  ulong local_130;
  allocator local_e1;
  double t_1;
  string s;
  ulong o_1;
  _Alloc_hider *local_c0;
  _Alloc_hider *local_b8;
  pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__
  t;
  ulong o;
  vector_double__std__allocator_double_ local_80;
  map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
  vv;
  
  puVar9 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl._M_finish;
  puVar17 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl._M_start;
                    /* Unresolved local var: size_t l@[???]
                       Unresolved local var: size_t np@[???] */
  vv._M_t._M_impl._M_header._M_color = _S_red;
  vv._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  vv._M_t._M_impl._M_header._M_left = &vv._M_t._M_impl._M_header;
  vv._M_t._M_impl._M_node_count = 0;
                    /* Unresolved local var: uint8_t * s@[???] */
  local_148._M_p = (char *)(p + 8);
  vv._M_t._M_impl._M_header._M_right = vv._M_t._M_impl._M_header._M_left;
  if ((ulong)((long)puVar9 - (long)puVar17) < local_148._M_p) {
    p_Var15 = (_Link_type)0x0;
    local_140 = p;
  }
  else {
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
    rea_memcpy((string *)&o,puVar17 + p,8);
    uVar6 = o;
                    /* Unresolved local var: size_t i@[???] */
    local_140 = (ulong)local_148._M_p;
    if (o != 0) {
                    /* Unresolved local var: size_t nnp@[???]
                       Unresolved local var: size_t p1@[???]
                       Unresolved local var: size_t p2@[???]
                       Unresolved local var: size_t l@[???]
                       Unresolved local var: size_t np@[???]
                       Unresolved local var: uint8_t * s@[???]
                       Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
      local_130 = 0;
                    /* Unresolved local var: size_type __dnew@[???]
                       Unresolved local var: _Rep * __r@[???] */
                    /* Unresolved local var: size_t l@[???]
                       Unresolved local var: size_t np@[???]
                       Unresolved local var: size_t i@[???]
                       Unresolved local var: size_t nnp@[???] */
      do {
        t.second.super__Vector_base_double__std__allocator_double_._M_impl._M_start = (pointer)0x0
        ;
        t.second.super__Vector_base_double__std__allocator_double_._M_impl._M_finish =
             (pointer)0x0;
        t.second.super__Vector_base_double__std__allocator_double_._M_impl._M_end_of_storage =
             (pointer)0x0;
        local_80.super__Vector_base_double__std__allocator_double_._M_impl._M_start = (pointer)0x0
        ;
        local_80.super__Vector_base_double__std__allocator_double_._M_impl._M_finish =
             (pointer)0x0;
        _Var14._M_p = PTR__S_empty_rep_storage_00311ff0 + 0x18;
        local_80.super__Vector_base_double__std__allocator_double_._M_impl._M_end_of_storage =
             (pointer)0x0;
        uVar13 = (long)local_148._M_p + 8;
        t.first._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var14._M_p;
        o = (ulong)_Var14._M_p;
        if ((ulong)((long)puVar9 - (long)puVar17) < uVar13) {
LAB_0010f7e8:
          local_140 = (ulong)local_148._M_p;
        }
        else {
          rea_memcpy((vector_double__std__allocator_double_ *)&o_1,puVar17 + (long)local_148._M_p,8);
          uVar18 = uVar13 + o_1;
          if ((ulong)((long)puVar9 - (long)puVar17) < uVar18) goto LAB_0010f7e8;
          puVar17 = puVar17 + uVar13;
          if (puVar17 != puVar17 + o_1) {
            uVar20 = (long)(puVar17 + o_1) - (long)puVar17;
            puVar10 = (ulong *)rea_std__string___Rep___S_create(uVar20,0,&local_e1);
            _Var14._M_p = (char *)(puVar10 + 3);
            uVar13 = 0;
            do {
              *(uchar *)((long)_Var14._M_p + uVar13) = puVar17[uVar13];
              uVar13 = uVar13 + 1;
            } while (uVar13 != uVar20);
            if (puVar10 != (ulong *)PTR__S_empty_rep_storage_00311ff0) {
              *(undefined4 *)(puVar10 + 2) = 0;
              *puVar10 = uVar20;
              *(undefined1 *)((long)puVar10 + uVar20 + 0x18) = 0;
            }
          }
          s._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var14._M_p;
          rea_std__string__assign((string *)&o);
          if ((allocator *)((long)s._M_dataplus._M_p + -0x18) !=
              (allocator *)PTR__S_empty_rep_storage_00311ff0) {
            piVar2 = (int *)((long)s._M_dataplus._M_p + -8);
            if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */
              iVar8 = *(int *)((long)s._M_dataplus._M_p + -8);
              *(int *)((long)s._M_dataplus._M_p + -8) = iVar8 + -1;
            }
            else {
              LOCK();
              iVar8 = *piVar2;
              *piVar2 = *piVar2 + -1;
              UNLOCK();
            }
            if (iVar8 < 1) {
              rea_std__string___Rep___M_destroy((allocator *)((long)s._M_dataplus._M_p + -0x18));
            }
          }
          if (local_148._M_p == (char *)uVar18) {
LAB_0010f880:
            local_140 = (ulong)local_148._M_p;
          }
          else {
                    /* Unresolved local var: uint8_t * s@[???] */
            puVar9 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                     _M_start;
            o_1 = 0;
            local_c0 = (_Alloc_hider *)0x0;
            local_b8 = (_Alloc_hider *)0x0;
            uVar13 = uVar18 + 8;
            uVar20 = (long)(b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>).
                           _M_impl._M_finish - (long)puVar9;
            if (uVar20 < uVar13) goto LAB_0010f880;
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
            rea_memcpy(&s,puVar9 + uVar18,8);
            sVar5 = s;
            if (s._M_dataplus._M_p == (char *)0x0) {
LAB_0010f7c0:
              std__vector_double__std__allocator_double___operator_assign_________________________(&local_80,(vector_double__std__allocator_double_ *)&o_1);
              pvVar16 = (void *)o_1;
              local_140 = uVar13;
            }
            else {
                    /* Unresolved local var: uint8_t * s@[???] */
              local_140 = uVar18;
              if (uVar20 < uVar18 + 0x10) {
                pvVar16 = (void *)0x0;
              }
              else {
                lVar19 = 0;
                uVar20 = uVar13;
                uVar13 = uVar18 + 0x10;
                do {
                    /* Unresolved local var: bool __simple@[???]
                       Unresolved local var: ptrdiff_t _Num@[???] */
                  rea_memcpy(&s,puVar9 + uVar20,8);
                  t_1 = (double)s._M_dataplus._M_p;
                  pvVar16 = (void *)o_1;
                  if (uVar20 == uVar13) break;
                  if (local_c0 == local_b8) {
                    std__vector_double__std__allocator_double____M_emplace_back_aux_double_const________________________________((vector_double__std__allocator_double_ *)&o_1);
                    pvVar16 = (void *)o_1;
                  }
                  else {
                    if (local_c0 != (_Alloc_hider *)0x0) {
                      local_c0->_M_p = (char *)s._M_dataplus._M_p;
                    }
                    local_c0 = local_c0 + 1;
                  }
                  o_1 = (ulong)pvVar16;
                  if ((char *)(lVar19 + 1) == sVar5._M_dataplus._M_p) goto LAB_0010f7c0;
                  lVar19 = lVar19 + 1;
                  puVar9 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>).
                           _M_impl._M_start;
                  uVar1 = uVar13 + 8;
                  uVar20 = uVar13;
                  uVar13 = uVar1;
                } while (uVar1 <= (ulong)((long)(b->
                                                super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>
                                                )._M_impl._M_finish - (long)puVar9));
              }
            }
            if (pvVar16 != (void *)0x0) {
              rea_operator_delete(pvVar16);
            }
            if (uVar18 == local_140) goto LAB_0010f880;
            rea_std__string__assign(&t.first);
            std__vector_double__std__allocator_double___operator_assign(&t.second,&local_80);
          }
          if (local_80.super__Vector_base_double__std__allocator_double_._M_impl._M_start !=
              (pointer)0x0) {
            rea_operator_delete(local_80.super__Vector_base_double__std__allocator_double_._M_impl.
                            _M_start);
          }
        }
        if ((allocator *)(o - 0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
          piVar2 = (int *)(o - 8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
            iVar8 = *(int *)(o - 8);
            *(int *)(o - 8) = iVar8 + -1;
          }
          else {
            LOCK();
            iVar8 = *piVar2;
            *piVar2 = *piVar2 + -1;
            UNLOCK();
          }
          if (iVar8 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)(o - 0x18));
          }
        }
        __s1._M_dataplus._M_p = t.first._M_dataplus._M_p;
        if (local_148._M_p == (char *)local_140) {
          if (t.second.super__Vector_base_double__std__allocator_double_._M_impl._M_start !=
              (pointer)0x0) {
            rea_operator_delete(t.second.super__Vector_base_double__std__allocator_double_._M_impl.
                            _M_start);
          }
          p_Var15 = (_Link_type)vv._M_t._M_impl._M_header._M_parent;
          local_140 = p;
          if ((allocator *)((long)t.first._M_dataplus._M_p + -0x18) !=
              (allocator *)PTR__S_empty_rep_storage_00311ff0) {
            piVar2 = (int *)((long)t.first._M_dataplus._M_p + -8);
            if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
              iVar8 = *(int *)((long)t.first._M_dataplus._M_p + -8);
              *(int *)((long)t.first._M_dataplus._M_p + -8) = iVar8 + -1;
            }
            else {
              LOCK();
              iVar8 = *piVar2;
              *piVar2 = *piVar2 + -1;
              UNLOCK();
            }
            if (iVar8 < 1) {
              rea_std__string___Rep___M_destroy((allocator *)((long)t.first._M_dataplus._M_p + -0x18));
              p_Var15 = (_Link_type)vv._M_t._M_impl._M_header._M_parent;
            }
          }
          goto LAB_0010f8d7;
        }
                    /* Unresolved local var:
                       pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ __res@[???]
                       Unresolved local var: _Link_type __x@[???]
                       Unresolved local var: _Link_type __y@[???]
                       Unresolved local var: bool __comp@[???]
                       Unresolved local var: iterator __j@[???] */
        if (vv._M_t._M_impl._M_header._M_parent == (_Base_ptr)0x0) {
          __p_00 = &vv._M_t._M_impl._M_header;
LAB_0010f800:
          if (vv._M_t._M_impl._M_header._M_left != __p_00) {
            lVar19 = rea_std___Rb_tree_decrement(__p_00);
            pvVar16 = *(void **)(lVar19 + 0x20);
            local_148 = t.first._M_dataplus._M_p;
            uVar18 = *(ulong *)((long)pvVar16 + -0x18);
            uVar13 = *(ulong *)((long)t.first._M_dataplus._M_p + -0x18);
            __n = uVar13;
            if (uVar18 <= uVar13) {
              __n = uVar18;
            }
            goto LAB_0010f70c;
          }
LAB_0010f849:
          std______________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__________________M_insert__const_std__pair_std__basic_string_char__std__vector_double_______________________(&vv._M_t,(_Base_ptr)0x0,__p_00,&t);
        }
        else {
          local_148 = t.first._M_dataplus._M_p;
          uVar13 = *(ulong *)((long)t.first._M_dataplus._M_p + -0x18);
          p_Var3 = vv._M_t._M_impl._M_header._M_parent;
          do {
            __p_00 = p_Var3;
            pvVar16 = *(void **)(__p_00 + 1);
            uVar18 = *(ulong *)((long)pvVar16 + -0x18);
            __n = uVar18;
            if (uVar13 <= uVar18) {
              __n = uVar13;
            }
            uVar7 = rea_memcmp((void *)__s1._M_dataplus._M_p,pvVar16,__n);
            uVar20 = (ulong)uVar7;
            if (uVar7 == 0) {
              uVar20 = uVar13 - uVar18;
              if ((long)uVar20 < 0x80000000) {
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???]
                       Unresolved local var: difference_type __d@[???] */
                if (-0x80000001 < (long)uVar20) goto LAB_0010f6a8;
                goto LAB_0010f6ac;
              }
LAB_0010f6f0:
              p_Var3 = __p_00->_M_right;
              bVar4 = false;
            }
            else {
LAB_0010f6a8:
              if (-1 < (int)uVar20) goto LAB_0010f6f0;
LAB_0010f6ac:
              p_Var3 = __p_00->_M_left;
              bVar4 = true;
            }
          } while (p_Var3 != (_Base_ptr)0x0);
          if (bVar4) goto LAB_0010f800;
LAB_0010f70c:
                    /* Unresolved local var: size_type __size@[???]
                       Unresolved local var: size_type __osize@[???]
                       Unresolved local var: size_type __len@[???]
                       Unresolved local var: int __r@[???] */
          iVar8 = rea_memcmp(pvVar16,local_148._M_p,__n);
          if (iVar8 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */
            lVar19 = uVar18 - uVar13;
            if (lVar19 < 0x80000000) {
              if (-0x80000001 < lVar19) {
                iVar8 = (int)lVar19;
                goto LAB_0010f739;
              }
              goto LAB_0010f840;
            }
          }
          else {
LAB_0010f739:
            if (iVar8 < 0) {
LAB_0010f840:
              if (__p_00 != (_Rb_tree_node_base *)0x0) goto LAB_0010f849;
            }
          }
        }
        if (t.second.super__Vector_base_double__std__allocator_double_._M_impl._M_start !=
            (pointer)0x0) {
          rea_operator_delete(t.second.super__Vector_base_double__std__allocator_double_._M_impl.
                          _M_start);
        }
        if ((allocator *)((long)t.first._M_dataplus._M_p + -0x18) !=
            (allocator *)PTR__S_empty_rep_storage_00311ff0) {
          piVar2 = (int *)((long)t.first._M_dataplus._M_p + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */
            iVar8 = *(int *)((long)t.first._M_dataplus._M_p + -8);
            *(int *)((long)t.first._M_dataplus._M_p + -8) = iVar8 + -1;
          }
          else {
            LOCK();
            iVar8 = *piVar2;
            *piVar2 = *piVar2 + -1;
            UNLOCK();
          }
          if (iVar8 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)((long)t.first._M_dataplus._M_p + -0x18));
          }
        }
        local_130 = local_130 + 1;
        if (local_130 == uVar6) break;
        puVar17 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                  _M_start;
        puVar9 = (b->super__Vector_base<unsigned_char,_std__allocator_unsigned_char_>)._M_impl.
                 _M_finish;
        local_148._M_p = (char *)local_140;
      } while( true );
    }
    p_Var15 = (_Link_type)vv._M_t._M_impl._M_header._M_parent;
    if (v != (map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____
              *)0x0) {
      std__________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______________M_erase(&v->_M_t,(_Link_type)(v->_M_t)._M_impl._M_header._M_parent);
      __p = &(v->_M_t)._M_impl._M_header;
      (v->_M_t)._M_impl._M_header._M_parent = (_Base_ptr)0x0;
      (v->_M_t)._M_impl._M_node_count = 0;
      (v->_M_t)._M_impl._M_header._M_left = __p;
      (v->_M_t)._M_impl._M_header._M_right = __p;
      if (vv._M_t._M_impl._M_header._M_parent == (_Base_ptr)0x0) {
        p_Var15 = (_Link_type)0x0;
      }
      else {
        p_Var11 = std______________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__________________________M_copy(&v->_M_t,(_Const_Link_type)vv._M_t._M_impl._M_header._M_parent,
                            (_Link_type)__p);
        (v->_M_t)._M_impl._M_header._M_parent = &p_Var11->super__Rb_tree_node_base;
        p_Var15 = p_Var11;
        do {
          p_Var12 = p_Var15;
          p_Var15 = (_Link_type)(p_Var12->super__Rb_tree_node_base)._M_left;
        } while (p_Var15 != (_Link_type)0x0);
        (v->_M_t)._M_impl._M_header._M_left = &p_Var12->super__Rb_tree_node_base;
        do {
          p_Var15 = p_Var11;
          p_Var11 = (_Link_type)(p_Var15->super__Rb_tree_node_base)._M_right;
        } while (p_Var11 != (_Link_type)0x0);
        (v->_M_t)._M_impl._M_header._M_right = &p_Var15->super__Rb_tree_node_base;
        (v->_M_t)._M_impl._M_node_count = vv._M_t._M_impl._M_node_count;
        p_Var15 = (_Link_type)vv._M_t._M_impl._M_header._M_parent;
      }
    }
  }
LAB_0010f8d7:
  std______Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__________M_erase(&vv._M_t,p_Var15);
  return local_140;
}





// ------------------------------------------------------------------
// IDX 213  0010fb58  _fini
// ------------------------------------------------------------------
void rea__fini(void)
{
  return;
}





// ------------------------------------------------------------------
// IDX 214  00313000  std__string__append
// ------------------------------------------------------------------
void rea_std__string__append__dup3(char * param_1, ulong param_2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_string_char_std_char_traits_char_std_allocator_char_append@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 215  00313008  std__getline_char_std__char_traits_char_std__allocator_char
// ------------------------------------------------------------------
istream * rea_std__getline_char_std__char_traits_char_std__allocator_char__dup2(istream * param_1, string * param_2, char param_3)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_istream_char_std_char_traits_char_std_getline_char_std_char_traits_char_std_allocator_char@@GLIBCXX_3.4
                        */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 216  00313010  std____throw_bad_cast
// ------------------------------------------------------------------
void rea_std____throw_bad_cast__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_throw_bad_cast@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 217  00313020  PyLong_FromVoidPtr
// ------------------------------------------------------------------
void rea_PyLong_FromVoidPtr__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 218  00313028  std__ios_base__ios_base
// ------------------------------------------------------------------
void rea_std__ios_base__ios_base__dup2(ios_base * this_ptr)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_ios_base_ios_base@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 219  00313030  PyLong_AsVoidPtr
// ------------------------------------------------------------------
void rea_PyLong_AsVoidPtr__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 220  00313038  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup4(void * this_ptr, char * param_1, ulong param_2, allocator * param_3)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_string_char_std_char_traits_char_std_allocator_char_basic_string_2@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 221  00313040  __gmon_start__
// ------------------------------------------------------------------
void rea___gmon_start__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 222  00313048  _Jv_RegisterClasses
// ------------------------------------------------------------------
void rea__Jv_RegisterClasses(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 223  00313050  operator_new__
// ------------------------------------------------------------------
void * rea_operator__new__dup3(ulong param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* operator_new@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 224  00313058  operator_delete
// ------------------------------------------------------------------
void rea_operator__delete__dup3(void * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* operator_delete_2@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 225  00313060  std__string__reserve
// ------------------------------------------------------------------
void rea_std__string__reserve__dup2(ulong param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_string_char_std_char_traits_char_std_allocator_char_reserve@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 226  00313068  std__string___Rep___M_dispose
// ------------------------------------------------------------------
void rea_std__string___Rep___M_dispose__dup2(allocator * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_string_char_std_char_traits_char_std_allocator_char_Rep_M_dispose@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 227  00313070  PyBytes_Size
// ------------------------------------------------------------------
void rea_PyBytes_Size__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 228  00313078  std__ctype_char___M_widen_init
// ------------------------------------------------------------------
void rea_std__ctype_char___M_widen_init__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_ctype_char_M_widen_init@@GLIBCXX_3.4.11 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 229  00313080  __cxa_rethrow
// ------------------------------------------------------------------
void rea___cxa_rethrow__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __cxa_rethrow@@CXXABI_1.3 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 230  00313088  fopen
// ------------------------------------------------------------------
FILE * rea_fopen__dup2(char * __filename, char * __modes)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* fopen@@GLIBC_2.2.5 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 231  00313090  std___Rb_tree_decrement
// ------------------------------------------------------------------
void rea_std___Rb_tree_decrement__dup2(_Rb_tree_node_base * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_Rb_tree_decrement@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 232  00313098  std__string___Rep___S_create
// ------------------------------------------------------------------
void rea_std__string___Rep___S_create__dup2(ulong param_1, ulong param_2, allocator * param_3)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_string_char_std_char_traits_char_std_allocator_char_Rep_S_create@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 233  003130a0  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup5(void * this_ptr, string * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_string_char_std_char_traits_char_std_allocator_char_basic_string_3@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 234  003130a8  __cxa_atexit
// ------------------------------------------------------------------
void rea___cxa_atexit__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __cxa_atexit@@GLIBC_2.2.5 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 235  003130b0  dlsym
// ------------------------------------------------------------------
void rea_dlsym__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 236  003130b8  std__filebuf__open
// ------------------------------------------------------------------
void rea_std__filebuf__open__dup2(char * param_1, _Ios_Openmode param_2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_filebuf_char_std_char_traits_char_open@@GLIBCXX_3.4
                        */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 237  003130c0  PyLong_AsLong
// ------------------------------------------------------------------
void rea_PyLong_AsLong__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 238  003130c8  _ITM_deregisterTMCloneTable
// ------------------------------------------------------------------
void rea__ITM_deregisterTMCloneTable(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 239  003130d0  PyArg_ParseTuple
// ------------------------------------------------------------------
void rea_PyArg_ParseTuple__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 240  003130d8  _ITM_registerTMCloneTable
// ------------------------------------------------------------------
void rea__ITM_registerTMCloneTable(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 241  003130e8  std__string___Rep___M_destroy
// ------------------------------------------------------------------
void rea_std__string___Rep___M_destroy__dup2(allocator * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_string_char_std_char_traits_char_std_allocator_char_Rep_M_destroy@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 242  003130f0  __cxa_finalize
// ------------------------------------------------------------------
void rea___cxa_finalize__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __cxa_finalize@@GLIBC_2.2.5 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 243  003130f8  PyBytes_AsString
// ------------------------------------------------------------------
void rea_PyBytes_AsString__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 244  00313100  std__string__insert
// ------------------------------------------------------------------
void rea_std__string__insert__dup2(ulong param_1, char * param_2, ulong param_3)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_string_char_std_char_traits_char_std_allocator_char_insert@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 245  00313108  std__string__string
// ------------------------------------------------------------------
void rea_std__string__string__dup6(void * this_ptr, char * param_1, allocator * param_2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_string_char_std_char_traits_char_std_allocator_char_basic_string@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 246  00313110  std__string__find
// ------------------------------------------------------------------
void rea_std__string__find__dup2(char * param_1, ulong param_2, ulong param_3)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_string_char_std_char_traits_char_std_allocator_char_find@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 247  00313118  memmove
// ------------------------------------------------------------------
void * rea_memmove__dup2(void * __dest, void * __src, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* memmove@@GLIBC_2.2.5 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 248  00313120  vsnprintf
// ------------------------------------------------------------------
int rea_vsnprintf(char * __s, size_t __maxlen, char * __format, __gnuc_va_list __arg)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* vsnprintf@@GLIBC_2.2.5 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 249  00313128  fread
// ------------------------------------------------------------------
size_t rea_fread__dup2(void * __ptr, size_t __size, size_t __n, FILE * __stream)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* fread@@GLIBC_2.2.5 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 250  00313130  getenv
// ------------------------------------------------------------------
char * rea_getenv__dup2(char * __name)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* getenv@@GLIBC_2.2.5 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 251  00313138  std__ios__init
// ------------------------------------------------------------------
void rea_std__ios__init__dup2(streambuf * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_ios_char_std_char_traits_char_init@@GLIBCXX_3.4
                        */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 252  00313140  Py_BuildValue
// ------------------------------------------------------------------
void rea_Py_BuildValue__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 253  00313148  std___Rb_tree_insert_and_rebalance________________
// ------------------------------------------------------------------
void rea_std___Rb_tree_insert_and_rebalance__dup2(bool param_1, _Rb_tree_node_base * param_2, _Rb_tree_node_base * param_3, _Rb_tree_node_base * param_4)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_Rb_tree_insert_and_rebalance@@GLIBCXX_3.4
                        */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 254  00313150  std__ios_base__dtor_ios_base
// ------------------------------------------------------------------
void rea_std__ios_base__dtor_ios_base__dup2(ios_base * this_ptr)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_ios_base_ios_base_2@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 255  00313158  strcmp
// ------------------------------------------------------------------
int rea_strcmp__dup2(char * __s1, char * __s2)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* strcmp@@GLIBC_2.2.5 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 256  00313160  PyBytes_FromStringAndSize
// ------------------------------------------------------------------
void rea_PyBytes_FromStringAndSize__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 257  00313168  strcpy
// ------------------------------------------------------------------
char * rea_strcpy__dup2(char * __dest, char * __src)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* strcpy@@GLIBC_2.2.5 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 258  00313180  std__string__assign
// ------------------------------------------------------------------
void rea_std__string__assign__dup2(string * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_string_char_std_char_traits_char_std_allocator_char_assign@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 259  00313188  operator_delete__
// ------------------------------------------------------------------
void rea_operator__delete__dup4(void * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* operator_delete@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 260  00313190  memcmp
// ------------------------------------------------------------------
int rea_memcmp__dup2(void * __s1, void * __s2, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* memcmp@@GLIBC_2.2.5 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 261  00313198  std__ios__clear
// ------------------------------------------------------------------
void rea_std__ios__clear__dup2(_Ios_Iostate param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_ios_char_std_char_traits_char_clear@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 262  003131a0  fclose
// ------------------------------------------------------------------
int rea_fclose__dup2(FILE * __stream)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* fclose@@GLIBC_2.2.5 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 263  003131a8  PyModule_Create2
// ------------------------------------------------------------------
void rea_PyModule_Create2__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 264  003131b0  PyTuple_New
// ------------------------------------------------------------------
void rea_PyTuple_New__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 265  003131b8  std__filebuf__filebuf
// ------------------------------------------------------------------
void rea_std__filebuf__filebuf__dup2(filebuf * this_ptr)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_filebuf_char_std_char_traits_char_basic_filebuf@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 266  003131c0  std___Rb_tree_increment
// ------------------------------------------------------------------
void rea_std___Rb_tree_increment__dup2(_Rb_tree_node_base * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_Rb_tree_increment@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 267  003131c8  __cxa_end_catch
// ------------------------------------------------------------------
void rea___cxa_end_catch__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __cxa_end_catch@@CXXABI_1.3 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 268  003131d0  std____throw_bad_alloc
// ------------------------------------------------------------------
void rea_std____throw_bad_alloc__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_throw_bad_alloc@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 269  003131e0  std__filebuf__dtor_filebuf
// ------------------------------------------------------------------
void rea_std__filebuf__dtor_filebuf__dup2(filebuf * this_ptr)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_filebuf_char_std_char_traits_char_basic_filebuf_2@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 270  003131e8  PyList_SetItem
// ------------------------------------------------------------------
void rea_PyList_SetItem__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 271  003131f0  __cxa_begin_catch
// ------------------------------------------------------------------
void rea___cxa_begin_catch__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __cxa_begin_catch@@CXXABI_1.3 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 272  003131f8  __gxx_personality_v0
// ------------------------------------------------------------------
void rea___gxx_personality_v0(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* __gxx_personality_v0@@CXXABI_1.3 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 273  00313200  operator_new
// ------------------------------------------------------------------
void * rea_operator__new__dup4(ulong param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* operator_new_2@@GLIBCXX_3.4 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 274  00313208  _Unwind_Resume
// ------------------------------------------------------------------
void rea__Unwind_Resume__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* _Unwind_Resume@@GCC_3.0 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 275  00313210  dlopen
// ------------------------------------------------------------------
void rea_dlopen__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 276  00313218  PyList_New
// ------------------------------------------------------------------
void rea_PyList_New__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 277  00313220  PyUnicode_AsUTF8
// ------------------------------------------------------------------
void rea_PyUnicode_AsUTF8__dup2(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 278  00313228  memcpy
// ------------------------------------------------------------------
void * rea_memcpy__dup2(void * __dest, void * __src, size_t __n)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* memcpy@@GLIBC_2.14 */
  halt_baddata();
}





// ------------------------------------------------------------------
// IDX 279  00313230  std__string__append
// ------------------------------------------------------------------
void rea_std__string__append__dup4(string * param_1)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
                    /* std_basic_string_char_std_char_traits_char_std_allocator_char_append_2@@GLIBCXX_3.4 */
  halt_baddata();
}





