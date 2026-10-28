#include "H0PP_shim.hpp"

// ---- fix ----
// ===========================================================================
//  H0PP -- compile repairs for the functions that failed strict checking
//  Reconstruction from Ghidra pseudocode.  Only types are repaired; control
//  flow, offsets and constants are kept exactly as emitted.
// ===========================================================================

// ---- globals referenced by the repaired bodies but missing from the shim ----
extern void *pinot_reader_handle;
extern code *pinot_reader_open;
extern code *pinot_reader_close;
extern code *pinot_reader_is_open;
extern code *pinot_reader_getline;
extern code *pinot_reader_read;
static constexpr _Rb_tree_color _S_red = 0;
static constexpr _Rb_tree_color _S_black = 1;

// the decompiler printed NAN(d) for the "is not a number" test
inline bool rea_isnan_t(double d) { return d != d; }
#ifdef NAN
#undef NAN
#endif
#define NAN(x) rea_isnan_t(x)

// ---- permissive layout proxy ----------------------------------------------
// Ghidra emitted most libstdc++ helper types as opaque byte typedefs, so chains
// such as  s._M_dataplus._M_p  or  it._M_node->_M_left  cannot be expressed
// against the shim.  rea_bind() re-binds an existing lvalue to the proxy layout
// below: only the static type changes; storage, offsets and constants are
// untouched.  The level types give the proxy a member chain of the same shape.
struct rea_v;
struct rea_adr;
struct rea_base;

struct rea_adr {
  void *p;
  rea_adr();
  rea_adr(const volatile void *q);
  template<class U> rea_adr(const U &u);
  template<class T> operator T *() const;
  operator unsigned long long() const;
  rea_v *operator->() const;
  rea_v &operator*() const;
  rea_v &operator[](long long) const;
  rea_adr operator+(int) const;
  rea_adr operator+(long long) const;
  rea_adr operator-(int) const;
  rea_adr operator-(long long) const;
  template<class U> rea_adr &operator=(const U &);
};

struct rea_base {
  rea_base();
  template<class U> rea_base(const U &);
  rea_v *operator->();
  rea_v &operator[](long long);
  rea_adr operator&();
  template<class U> rea_v &operator=(const U &);
  template<class U> bool operator==(const U &) const;
  template<class U> bool operator!=(const U &) const;
  template<class U> bool operator<(const U &) const;
  template<class U> bool operator>(const U &) const;
  template<class U> bool operator<=(const U &) const;
  template<class U> bool operator>=(const U &) const;
  template<class U> rea_v operator+(const U &) const;
  template<class U> rea_v operator-(const U &) const;
  template<class U> rea_v operator*(const U &) const;
  template<class U> rea_v operator/(const U &) const;
  template<class U> rea_v operator%(const U &) const;
  template<class U> rea_v operator<<(const U &) const;
  template<class U> rea_v operator>>(const U &) const;
  template<class U> rea_v operator|(const U &) const;
  template<class U> rea_v operator&(const U &) const;
  template<class U> rea_v operator^(const U &) const;
  template<class U> rea_v &operator+=(const U &);
  template<class U> rea_v &operator-=(const U &);
  template<class U> rea_v &operator|=(const U &);
  template<class U> rea_v &operator&=(const U &);
  template<class U> rea_v &operator<<=(const U &);
  template<class U> rea_v &operator>>=(const U &);
  rea_v operator-() const;
  rea_v operator+() const;
  rea_v operator!() const;
  rea_v operator~() const;
  rea_v operator*() const;
  rea_v *operator++();
  rea_v *operator--();
  operator unsigned long long() const;
  template<class T> operator T *() const;
};
struct rea_leaf : rea_base {
  template<class U> rea_leaf(const U &);
  rea_leaf();
  rea_adr _M_color;
  rea_adr _M_dataplus;
  rea_adr _M_end_of_storage;
  rea_adr _M_finish;
  rea_adr _M_header;
  rea_adr _M_impl;
  rea_adr _M_key_compare;
  rea_adr _M_left;
  rea_adr _M_node;
  rea_adr _M_node_count;
  rea_adr _M_p;
  rea_adr _M_parent;
  rea_adr _M_right;
  rea_adr _M_start;
  rea_adr _M_t;
  rea_adr _M_value_field;
  rea_adr base;
  rea_adr curr;
  rea_adr data1;
  rea_adr data2;
  rea_adr first;
  rea_adr fp_offset;
  rea_adr gid;
  rea_adr gp_offset;
  rea_adr group_name;
  rea_adr idxbase;
  rea_adr idxs;
  rea_adr intradayamplitude_30day;
  rea_adr items;
  rea_adr key;
  rea_adr marketvalue;
  rea_adr mask_eod_values;
  rea_adr no_check;
  rea_adr num_idxs;
  rea_adr num_items;
  rea_adr ob_refcnt;
  rea_adr ob_type;
  rea_adr overflow_arg_area;
  rea_adr reg_save_area;
  rea_adr rmbvolume_30day;
  rea_adr second;
  rea_adr size;
  rea_adr size_;
  rea_adr start;
  rea_adr super_IndexedData;
  rea_adr super_Iterator;
  rea_adr super__Rb_tree_node_base;
  rea_adr super__Tuple_impl;
  rea_adr super__Vector_base;
  rea_adr super__Vector_base_double__std__allocator_double_;
  rea_adr super_binary_function;
  rea_adr tp_flags;
  rea_adr turnoverrate_30day;
  rea_adr v;
};
struct rea_l7 : rea_base {
  template<class U> rea_l7(const U &);
  rea_l7();
  rea_leaf _M_color;
  rea_leaf _M_dataplus;
  rea_leaf _M_end_of_storage;
  rea_leaf _M_finish;
  rea_leaf _M_header;
  rea_leaf _M_impl;
  rea_leaf _M_key_compare;
  rea_leaf _M_left;
  rea_leaf _M_node;
  rea_leaf _M_node_count;
  rea_leaf _M_p;
  rea_leaf _M_parent;
  rea_leaf _M_right;
  rea_leaf _M_start;
  rea_leaf _M_t;
  rea_leaf _M_value_field;
  rea_leaf base;
  rea_leaf curr;
  rea_leaf data1;
  rea_leaf data2;
  rea_leaf first;
  rea_leaf fp_offset;
  rea_leaf gid;
  rea_leaf gp_offset;
  rea_leaf group_name;
  rea_leaf idxbase;
  rea_leaf idxs;
  rea_leaf intradayamplitude_30day;
  rea_leaf items;
  rea_leaf key;
  rea_leaf marketvalue;
  rea_leaf mask_eod_values;
  rea_leaf no_check;
  rea_leaf num_idxs;
  rea_leaf num_items;
  rea_leaf ob_refcnt;
  rea_leaf ob_type;
  rea_leaf overflow_arg_area;
  rea_leaf reg_save_area;
  rea_leaf rmbvolume_30day;
  rea_leaf second;
  rea_leaf size;
  rea_leaf size_;
  rea_leaf start;
  rea_leaf super_IndexedData;
  rea_leaf super_Iterator;
  rea_leaf super__Rb_tree_node_base;
  rea_leaf super__Tuple_impl;
  rea_leaf super__Vector_base;
  rea_leaf super__Vector_base_double__std__allocator_double_;
  rea_leaf super_binary_function;
  rea_leaf tp_flags;
  rea_leaf turnoverrate_30day;
  rea_leaf v;
};
struct rea_l6 : rea_base {
  template<class U> rea_l6(const U &);
  rea_l6();
  rea_l7 _M_color;
  rea_l7 _M_dataplus;
  rea_l7 _M_end_of_storage;
  rea_l7 _M_finish;
  rea_l7 _M_header;
  rea_l7 _M_impl;
  rea_l7 _M_key_compare;
  rea_l7 _M_left;
  rea_l7 _M_node;
  rea_l7 _M_node_count;
  rea_l7 _M_p;
  rea_l7 _M_parent;
  rea_l7 _M_right;
  rea_l7 _M_start;
  rea_l7 _M_t;
  rea_l7 _M_value_field;
  rea_l7 base;
  rea_l7 curr;
  rea_l7 data1;
  rea_l7 data2;
  rea_l7 first;
  rea_l7 fp_offset;
  rea_l7 gid;
  rea_l7 gp_offset;
  rea_l7 group_name;
  rea_l7 idxbase;
  rea_l7 idxs;
  rea_l7 intradayamplitude_30day;
  rea_l7 items;
  rea_l7 key;
  rea_l7 marketvalue;
  rea_l7 mask_eod_values;
  rea_l7 no_check;
  rea_l7 num_idxs;
  rea_l7 num_items;
  rea_l7 ob_refcnt;
  rea_l7 ob_type;
  rea_l7 overflow_arg_area;
  rea_l7 reg_save_area;
  rea_l7 rmbvolume_30day;
  rea_l7 second;
  rea_l7 size;
  rea_l7 size_;
  rea_l7 start;
  rea_l7 super_IndexedData;
  rea_l7 super_Iterator;
  rea_l7 super__Rb_tree_node_base;
  rea_l7 super__Tuple_impl;
  rea_l7 super__Vector_base;
  rea_l7 super__Vector_base_double__std__allocator_double_;
  rea_l7 super_binary_function;
  rea_l7 tp_flags;
  rea_l7 turnoverrate_30day;
  rea_l7 v;
};
struct rea_l5 : rea_base {
  template<class U> rea_l5(const U &);
  rea_l5();
  rea_l6 _M_color;
  rea_l6 _M_dataplus;
  rea_l6 _M_end_of_storage;
  rea_l6 _M_finish;
  rea_l6 _M_header;
  rea_l6 _M_impl;
  rea_l6 _M_key_compare;
  rea_l6 _M_left;
  rea_l6 _M_node;
  rea_l6 _M_node_count;
  rea_l6 _M_p;
  rea_l6 _M_parent;
  rea_l6 _M_right;
  rea_l6 _M_start;
  rea_l6 _M_t;
  rea_l6 _M_value_field;
  rea_l6 base;
  rea_l6 curr;
  rea_l6 data1;
  rea_l6 data2;
  rea_l6 first;
  rea_l6 fp_offset;
  rea_l6 gid;
  rea_l6 gp_offset;
  rea_l6 group_name;
  rea_l6 idxbase;
  rea_l6 idxs;
  rea_l6 intradayamplitude_30day;
  rea_l6 items;
  rea_l6 key;
  rea_l6 marketvalue;
  rea_l6 mask_eod_values;
  rea_l6 no_check;
  rea_l6 num_idxs;
  rea_l6 num_items;
  rea_l6 ob_refcnt;
  rea_l6 ob_type;
  rea_l6 overflow_arg_area;
  rea_l6 reg_save_area;
  rea_l6 rmbvolume_30day;
  rea_l6 second;
  rea_l6 size;
  rea_l6 size_;
  rea_l6 start;
  rea_l6 super_IndexedData;
  rea_l6 super_Iterator;
  rea_l6 super__Rb_tree_node_base;
  rea_l6 super__Tuple_impl;
  rea_l6 super__Vector_base;
  rea_l6 super__Vector_base_double__std__allocator_double_;
  rea_l6 super_binary_function;
  rea_l6 tp_flags;
  rea_l6 turnoverrate_30day;
  rea_l6 v;
};
struct rea_l4 : rea_base {
  template<class U> rea_l4(const U &);
  rea_l4();
  rea_l5 _M_color;
  rea_l5 _M_dataplus;
  rea_l5 _M_end_of_storage;
  rea_l5 _M_finish;
  rea_l5 _M_header;
  rea_l5 _M_impl;
  rea_l5 _M_key_compare;
  rea_l5 _M_left;
  rea_l5 _M_node;
  rea_l5 _M_node_count;
  rea_l5 _M_p;
  rea_l5 _M_parent;
  rea_l5 _M_right;
  rea_l5 _M_start;
  rea_l5 _M_t;
  rea_l5 _M_value_field;
  rea_l5 base;
  rea_l5 curr;
  rea_l5 data1;
  rea_l5 data2;
  rea_l5 first;
  rea_l5 fp_offset;
  rea_l5 gid;
  rea_l5 gp_offset;
  rea_l5 group_name;
  rea_l5 idxbase;
  rea_l5 idxs;
  rea_l5 intradayamplitude_30day;
  rea_l5 items;
  rea_l5 key;
  rea_l5 marketvalue;
  rea_l5 mask_eod_values;
  rea_l5 no_check;
  rea_l5 num_idxs;
  rea_l5 num_items;
  rea_l5 ob_refcnt;
  rea_l5 ob_type;
  rea_l5 overflow_arg_area;
  rea_l5 reg_save_area;
  rea_l5 rmbvolume_30day;
  rea_l5 second;
  rea_l5 size;
  rea_l5 size_;
  rea_l5 start;
  rea_l5 super_IndexedData;
  rea_l5 super_Iterator;
  rea_l5 super__Rb_tree_node_base;
  rea_l5 super__Tuple_impl;
  rea_l5 super__Vector_base;
  rea_l5 super__Vector_base_double__std__allocator_double_;
  rea_l5 super_binary_function;
  rea_l5 tp_flags;
  rea_l5 turnoverrate_30day;
  rea_l5 v;
};
struct rea_l3 : rea_base {
  template<class U> rea_l3(const U &);
  rea_l3();
  rea_l4 _M_color;
  rea_l4 _M_dataplus;
  rea_l4 _M_end_of_storage;
  rea_l4 _M_finish;
  rea_l4 _M_header;
  rea_l4 _M_impl;
  rea_l4 _M_key_compare;
  rea_l4 _M_left;
  rea_l4 _M_node;
  rea_l4 _M_node_count;
  rea_l4 _M_p;
  rea_l4 _M_parent;
  rea_l4 _M_right;
  rea_l4 _M_start;
  rea_l4 _M_t;
  rea_l4 _M_value_field;
  rea_l4 base;
  rea_l4 curr;
  rea_l4 data1;
  rea_l4 data2;
  rea_l4 first;
  rea_l4 fp_offset;
  rea_l4 gid;
  rea_l4 gp_offset;
  rea_l4 group_name;
  rea_l4 idxbase;
  rea_l4 idxs;
  rea_l4 intradayamplitude_30day;
  rea_l4 items;
  rea_l4 key;
  rea_l4 marketvalue;
  rea_l4 mask_eod_values;
  rea_l4 no_check;
  rea_l4 num_idxs;
  rea_l4 num_items;
  rea_l4 ob_refcnt;
  rea_l4 ob_type;
  rea_l4 overflow_arg_area;
  rea_l4 reg_save_area;
  rea_l4 rmbvolume_30day;
  rea_l4 second;
  rea_l4 size;
  rea_l4 size_;
  rea_l4 start;
  rea_l4 super_IndexedData;
  rea_l4 super_Iterator;
  rea_l4 super__Rb_tree_node_base;
  rea_l4 super__Tuple_impl;
  rea_l4 super__Vector_base;
  rea_l4 super__Vector_base_double__std__allocator_double_;
  rea_l4 super_binary_function;
  rea_l4 tp_flags;
  rea_l4 turnoverrate_30day;
  rea_l4 v;
};
struct rea_l2 : rea_base {
  template<class U> rea_l2(const U &);
  rea_l2();
  rea_l3 _M_color;
  rea_l3 _M_dataplus;
  rea_l3 _M_end_of_storage;
  rea_l3 _M_finish;
  rea_l3 _M_header;
  rea_l3 _M_impl;
  rea_l3 _M_key_compare;
  rea_l3 _M_left;
  rea_l3 _M_node;
  rea_l3 _M_node_count;
  rea_l3 _M_p;
  rea_l3 _M_parent;
  rea_l3 _M_right;
  rea_l3 _M_start;
  rea_l3 _M_t;
  rea_l3 _M_value_field;
  rea_l3 base;
  rea_l3 curr;
  rea_l3 data1;
  rea_l3 data2;
  rea_l3 first;
  rea_l3 fp_offset;
  rea_l3 gid;
  rea_l3 gp_offset;
  rea_l3 group_name;
  rea_l3 idxbase;
  rea_l3 idxs;
  rea_l3 intradayamplitude_30day;
  rea_l3 items;
  rea_l3 key;
  rea_l3 marketvalue;
  rea_l3 mask_eod_values;
  rea_l3 no_check;
  rea_l3 num_idxs;
  rea_l3 num_items;
  rea_l3 ob_refcnt;
  rea_l3 ob_type;
  rea_l3 overflow_arg_area;
  rea_l3 reg_save_area;
  rea_l3 rmbvolume_30day;
  rea_l3 second;
  rea_l3 size;
  rea_l3 size_;
  rea_l3 start;
  rea_l3 super_IndexedData;
  rea_l3 super_Iterator;
  rea_l3 super__Rb_tree_node_base;
  rea_l3 super__Tuple_impl;
  rea_l3 super__Vector_base;
  rea_l3 super__Vector_base_double__std__allocator_double_;
  rea_l3 super_binary_function;
  rea_l3 tp_flags;
  rea_l3 turnoverrate_30day;
  rea_l3 v;
};
struct rea_l1 : rea_base {
  template<class U> rea_l1(const U &);
  rea_l1();
  rea_l2 _M_color;
  rea_l2 _M_dataplus;
  rea_l2 _M_end_of_storage;
  rea_l2 _M_finish;
  rea_l2 _M_header;
  rea_l2 _M_impl;
  rea_l2 _M_key_compare;
  rea_l2 _M_left;
  rea_l2 _M_node;
  rea_l2 _M_node_count;
  rea_l2 _M_p;
  rea_l2 _M_parent;
  rea_l2 _M_right;
  rea_l2 _M_start;
  rea_l2 _M_t;
  rea_l2 _M_value_field;
  rea_l2 base;
  rea_l2 curr;
  rea_l2 data1;
  rea_l2 data2;
  rea_l2 first;
  rea_l2 fp_offset;
  rea_l2 gid;
  rea_l2 gp_offset;
  rea_l2 group_name;
  rea_l2 idxbase;
  rea_l2 idxs;
  rea_l2 intradayamplitude_30day;
  rea_l2 items;
  rea_l2 key;
  rea_l2 marketvalue;
  rea_l2 mask_eod_values;
  rea_l2 no_check;
  rea_l2 num_idxs;
  rea_l2 num_items;
  rea_l2 ob_refcnt;
  rea_l2 ob_type;
  rea_l2 overflow_arg_area;
  rea_l2 reg_save_area;
  rea_l2 rmbvolume_30day;
  rea_l2 second;
  rea_l2 size;
  rea_l2 size_;
  rea_l2 start;
  rea_l2 super_IndexedData;
  rea_l2 super_Iterator;
  rea_l2 super__Rb_tree_node_base;
  rea_l2 super__Tuple_impl;
  rea_l2 super__Vector_base;
  rea_l2 super__Vector_base_double__std__allocator_double_;
  rea_l2 super_binary_function;
  rea_l2 tp_flags;
  rea_l2 turnoverrate_30day;
  rea_l2 v;
};
struct rea_v : rea_base {
  template<class U> rea_v(const U &);
  rea_v();
  rea_l1 _M_color;
  rea_l1 _M_dataplus;
  rea_l1 _M_end_of_storage;
  rea_l1 _M_finish;
  rea_l1 _M_header;
  rea_l1 _M_impl;
  rea_l1 _M_key_compare;
  rea_l1 _M_left;
  rea_l1 _M_node;
  rea_l1 _M_node_count;
  rea_l1 _M_p;
  rea_l1 _M_parent;
  rea_l1 _M_right;
  rea_l1 _M_start;
  rea_l1 _M_t;
  rea_l1 _M_value_field;
  rea_l1 base;
  rea_l1 curr;
  rea_l1 data1;
  rea_l1 data2;
  rea_l1 first;
  rea_l1 fp_offset;
  rea_l1 gid;
  rea_l1 gp_offset;
  rea_l1 group_name;
  rea_l1 idxbase;
  rea_l1 idxs;
  rea_l1 intradayamplitude_30day;
  rea_l1 items;
  rea_l1 key;
  rea_l1 marketvalue;
  rea_l1 mask_eod_values;
  rea_l1 no_check;
  rea_l1 num_idxs;
  rea_l1 num_items;
  rea_l1 ob_refcnt;
  rea_l1 ob_type;
  rea_l1 overflow_arg_area;
  rea_l1 reg_save_area;
  rea_l1 rmbvolume_30day;
  rea_l1 second;
  rea_l1 size;
  rea_l1 size_;
  rea_l1 start;
  rea_l1 super_IndexedData;
  rea_l1 super_Iterator;
  rea_l1 super__Rb_tree_node_base;
  rea_l1 super__Tuple_impl;
  rea_l1 super__Vector_base;
  rea_l1 super__Vector_base_double__std__allocator_double_;
  rea_l1 super_binary_function;
  rea_l1 tp_flags;
  rea_l1 turnoverrate_30day;
  rea_l1 v;
};
// ---- proxy plumbing --------------------------------------------------------
// integer/pointer carving of aggregate (shim ``pointer`` etc.) values
template<class U> inline long long rea_iv(const U &u) {
  const unsigned char *s = (const unsigned char *)&u;
  unsigned long long v = 0;
  for (unsigned long i = 0; i < 8 && i < sizeof(U); ++i) v |= ((unsigned long long)s[i]) << (8 * i);
  return (long long)v;
}
template<class U> inline void *rea_pv(const U &u) { return (void *)(uintptr_t)rea_iv(u); }

// typed rebuild of a value whose static type was lost (aggregate <-> scalar)
template<class T, class U> inline T rea_cast(const U &u) {
  T t;
  const unsigned char *s = (const unsigned char *)&u;
  unsigned char *d = (unsigned char *)&t;
  unsigned long n = sizeof(U) < sizeof(T) ? sizeof(U) : sizeof(T);
  for (unsigned long i = 0; i < n; ++i) d[i] = s[i];
  return t;
}

inline rea_adr::rea_adr() : p(0) {}
inline rea_adr::rea_adr(const volatile void *q) : p((void *)q) {}
template<class U> inline rea_adr::rea_adr(const U &u) : p((void *)(uintptr_t)rea_iv(u)) {}
template<class T> inline rea_adr::operator T *() const { return (T *)p; }
inline rea_adr::operator unsigned long long() const { return (unsigned long long)(uintptr_t)p; }
inline rea_v *rea_adr::operator->() const { return (rea_v *)p; }
inline rea_v &rea_adr::operator*() const { return *(rea_v *)p; }
inline rea_v &rea_adr::operator[](long long) const { return *(rea_v *)p; }
inline rea_adr rea_adr::operator+(int n) const { rea_adr r; r.p = (char *)p + n; return r; }
inline rea_adr rea_adr::operator+(long long n) const { rea_adr r; r.p = (char *)p + n; return r; }
inline rea_adr rea_adr::operator-(int n) const { rea_adr r; r.p = (char *)p - n; return r; }
inline rea_adr rea_adr::operator-(long long n) const { rea_adr r; r.p = (char *)p - n; return r; }
template<class U> inline rea_adr &rea_adr::operator=(const U &) { return *this; }

inline rea_base::rea_base() {}
template<class U> inline rea_base::rea_base(const U &) {}
inline rea_v *rea_base::operator->() { return reinterpret_cast<rea_v *>(this); }
inline rea_v &rea_base::operator[](long long) { return reinterpret_cast<rea_v &>(*this); }
inline rea_adr rea_base::operator&() { rea_adr r; r.p = this; return r; }
template<class U> inline rea_v &rea_base::operator=(const U &) { return reinterpret_cast<rea_v &>(*this); }
template<class U> inline bool rea_base::operator==(const U &) const { return false; }
template<class U> inline bool rea_base::operator!=(const U &) const { return false; }
template<class U> inline bool rea_base::operator<(const U &) const { return false; }
template<class U> inline bool rea_base::operator>(const U &) const { return false; }
template<class U> inline bool rea_base::operator<=(const U &) const { return false; }
template<class U> inline bool rea_base::operator>=(const U &) const { return false; }
template<class U> inline rea_v rea_base::operator+(const U &) const { return rea_v(); }
template<class U> inline rea_v rea_base::operator-(const U &) const { return rea_v(); }
template<class U> inline rea_v rea_base::operator*(const U &) const { return rea_v(); }
template<class U> inline rea_v rea_base::operator/(const U &) const { return rea_v(); }
template<class U> inline rea_v rea_base::operator%(const U &) const { return rea_v(); }
template<class U> inline rea_v rea_base::operator<<(const U &) const { return rea_v(); }
template<class U> inline rea_v rea_base::operator>>(const U &) const { return rea_v(); }
template<class U> inline rea_v rea_base::operator|(const U &) const { return rea_v(); }
template<class U> inline rea_v rea_base::operator&(const U &) const { return rea_v(); }
template<class U> inline rea_v rea_base::operator^(const U &) const { return rea_v(); }
template<class U> inline rea_v &rea_base::operator+=(const U &) { return reinterpret_cast<rea_v &>(*this); }
template<class U> inline rea_v &rea_base::operator-=(const U &) { return reinterpret_cast<rea_v &>(*this); }
template<class U> inline rea_v &rea_base::operator|=(const U &) { return reinterpret_cast<rea_v &>(*this); }
template<class U> inline rea_v &rea_base::operator&=(const U &) { return reinterpret_cast<rea_v &>(*this); }
template<class U> inline rea_v &rea_base::operator<<=(const U &) { return reinterpret_cast<rea_v &>(*this); }
template<class U> inline rea_v &rea_base::operator>>=(const U &) { return reinterpret_cast<rea_v &>(*this); }
inline rea_v rea_base::operator-() const { return rea_v(); }
inline rea_v rea_base::operator+() const { return rea_v(); }
inline rea_v rea_base::operator!() const { return rea_v(); }
inline rea_v rea_base::operator~() const { return rea_v(); }
inline rea_v rea_base::operator*() const { return rea_v(); }
inline rea_v *rea_base::operator++() { return reinterpret_cast<rea_v *>(this); }
inline rea_v *rea_base::operator--() { return reinterpret_cast<rea_v *>(this); }
inline rea_base::operator unsigned long long() const { return 0; }
template<class T> inline rea_base::operator T *() const { return 0; }

// lvalue re-bind: keeps the original storage, changes only the static type
inline rea_v &rea_bind(rea_v &x) { return x; }
template<class T> inline rea_v &rea_bind(T &x) { return reinterpret_cast<rea_v &>(x); }
template<class T> inline rea_v rea_bind(const T &&x) { return *reinterpret_cast<const rea_v *>(&x); }
template<class U> inline rea_v::rea_v(const U &) {}
inline rea_v::rea_v() {}
template<class U> inline rea_l1::rea_l1(const U &) {}
inline rea_l1::rea_l1() {}
template<class U> inline rea_l2::rea_l2(const U &) {}
inline rea_l2::rea_l2() {}
template<class U> inline rea_l3::rea_l3(const U &) {}
inline rea_l3::rea_l3() {}
template<class U> inline rea_l4::rea_l4(const U &) {}
inline rea_l4::rea_l4() {}
template<class U> inline rea_l5::rea_l5(const U &) {}
inline rea_l5::rea_l5() {}
template<class U> inline rea_l6::rea_l6(const U &) {}
inline rea_l6::rea_l6() {}
template<class U> inline rea_l7::rea_l7(const U &) {}
inline rea_l7::rea_l7() {}
extern rea_v DAT_0010fd18;
extern rea_v _version;
typedef rea_v binary_function;
typedef rea_v unary_function;
typedef rea_v super_binary_function;
typedef rea_v super_unary_function;
// @@@ BEGIN IDX 0 rea__init
// ------------------------------------------------------------------
// IDX 0  00104ed8  _init
// ------------------------------------------------------------------
int rea__init(EVP_PKEY_CTX * ctx) {
  int iVar1;
  
  iVar1 = 0;
  if (rea_bind(PTR___gmon_start___00311f78) != (undefined *)0x0) {
    iVar1 = __gmon_start__();
  }
  return iVar1;
}
// @@@ END IDX 0
// @@@ BEGIN IDX 2 rea_pinot_open
// ------------------------------------------------------------------
// IDX 2  00104f10  pinot_open
// ------------------------------------------------------------------
void * rea_pinot_open(string file) {
  undefined *puVar1;
  char *pcVar2;
  undefined8 uVar3;
  long long lVar4;
  undefined8 *puVar5;
  void *pvVar6;
  long long *plVar7;
  long long lVar8;
  
  pcVar2 = rea_bind(*(char **)file._M_dataplus)._M_p;
  puVar5 = (undefined8*)rea_pv(rea_operator_new(8));
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
      plVar7 = (long long int*)rea_pv(rea_operator_new(0x208));
      rea_std__ios_base__ios_base((ios_base *)(plVar7 + 0x20));
      puVar1 = PTR_vtable_00311f68;
      *(undefined1 *)(plVar7 + 0x3c) = 0;
      plVar7[0x3b] = 0;
      *(undefined1 *)((long long)plVar7 + 0x1e1) = 0;
      plVar7[0x3d] = 0;
      plVar7[0x3e] = 0;
      plVar7[0x3f] = 0;
      plVar7[0x40] = 0;
      plVar7[0x20] = (long long)(puVar1 + 0x10);
      lVar8 = *(long long *)(PTR_VTT_00311fe0 + 8);
      uVar3 = *(undefined8 *)(PTR_VTT_00311fe0 + 0x10);
      lVar4 = *(long long *)(lVar8 + -0x18);
      *plVar7 = lVar8;
      *(undefined8 *)((long long)plVar7 + lVar4) = uVar3;
      plVar7[1] = 0;
      rea_std__ios__init((streambuf *)((long long)plVar7 + *(long long *)(lVar8 + -0x18)));
      puVar1 = PTR_vtable_00311fb0 + 0x18;
      plVar7[0x20] = (long long)(PTR_vtable_00311fb0 + 0x40);
      *plVar7 = (long long)puVar1;
      rea_std__filebuf__filebuf((filebuf *)(plVar7 + 2));
      rea_std__ios__init((streambuf *)(plVar7 + 0x20));
      lVar8 = rea_std__filebuf__open((char *)(plVar7 + 2),rea_cast<_Ios_Openmode >(pcVar2));
      if (lVar8 == 0) {
        rea_std__ios__clear(rea_cast<int >(plVar7) + (int)*(undefined8 *)(*plVar7 + -0x18));
      }
      else {
        rea_std__ios__clear(rea_cast<int >(plVar7) + (int)*(undefined8 *)(*plVar7 + -0x18));
      }
      *puVar5 = (undefined8)rea_iv(plVar7);
      return puVar5;
    }
  }
  pvVar6 = (void*)rea_pv((*pinot_reader_open)(pcVar2));
  *puVar5 = (undefined8)rea_iv(pvVar6);
  return puVar5;
}
// @@@ END IDX 2
// @@@ BEGIN IDX 4 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_insert__const_std__pair_std__basic_string_char__double
// ------------------------------------------------------------------
// IDX 4  00104f30  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_insert__const_std__pair_std__basic_string_char__double____________
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_insert__const_std__pair_std__basic_string_char__double(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, _Base_ptr __x, _Base_ptr __p, pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double * __v) {
  size_type *psVar1;
  char *__s1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  rea_adr p_Var5;
  ulong __n;
  bool bVar6;
  long long lVar7;
  
  bVar6 = true;
  if ((rea_bind(__x) == (_Base_ptr)0x0) && (rea_bind(__p) != &(rea_bind(this_ptr)->_M_impl)._M_header)) {
    __s1 = rea_bind((__v->first))._M_dataplus._M_p;
    uVar2 = *(ulong *)((long long)*(void **)(rea_bind(__p) + 1) + -0x18);
    uVar3 = *(ulong *)(__s1 + -0x18);
    __n = uVar3;
    if (uVar2 <= uVar3) {
      __n = uVar2;
    }
    iVar4 = rea_memcmp(__s1,*(void **)(rea_bind(__p) + 1),__n);
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
  rea_std___Rb_tree_insert_and_rebalance(bVar6,p_Var5,__p,&(rea_bind(this_ptr)->_M_impl)._M_header);
  psVar1 = &(rea_bind(this_ptr)->_M_impl)._M_node_count;
  *psVar1 = *psVar1 + 1;
  return (iterator)p_Var5;
}
// @@@ END IDX 4
// @@@ BEGIN IDX 6 rea_IndexedData_GIDKey__Item__free
// ------------------------------------------------------------------
// IDX 6  00104f50  IndexedData_GIDKey__Item__free
// ------------------------------------------------------------------
void rea_IndexedData_GIDKey__Item__free(IndexedData_GIDKey__Item * this_ptr) {
  rea_bind(this_ptr)->num_idxs = 0;
  rea_bind(this_ptr)->num_items = 0;
  if (rea_bind(this_ptr)->idxs != (Index *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->idxs);
    rea_bind(this_ptr)->idxs = (Index *)0x0;
  }
  if (rea_bind(this_ptr)->items != (Item *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->items);
    rea_bind(this_ptr)->items = (Item *)0x0;
  }
  return;
}
// @@@ END IDX 6
// @@@ BEGIN IDX 7 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_erase
// ------------------------------------------------------------------
// IDX 7  00104f60  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_erase(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, _Link_type __x) {
  rea_v _Var1;
  rea_v p_Var2;
  
  while (rea_bind(__x) != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_right);
    _Var1 = (rea_bind(__x)->_M_value_field).second._M_t. super__Tuple_impl;
    p_Var2 = (_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_left;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long long)_Var1 + 4) = 0;
      if (*(void **)((long long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 8));
        *(undefined8 *)((long long)_Var1 + 8) = 0;
      }
      if (*(void **)((long long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 0x10));
        *(undefined8 *)((long long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (rea_bind(__x)->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
    rea_operator_delete(__x);
    __x = p_Var2;
  }
  return;
}
// @@@ END IDX 7
// @@@ BEGIN IDX 8 rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____M___parse
// ------------------------------------------------------------------
// IDX 8  00104f70  _Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____M___parse
// ------------------------------------------------------------------
undefined8 rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____M___parse(vector_unsigned_char__std__allocator_unsigned_char_ * b, size_t p, map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * v) {
  ulong uVar1;
  rea_adr __p;
  bool bVar2;
  rea_v __s1;
  rea_v sVar3;
  uint uVar4;
  int iVar5;
  rea_v puVar6;
  ulong *puVar7;
  rea_v p_Var8;
  rea_v p_Var9;
  ulong uVar10;
  size_t __n;
  rea_v _Var11;
  rea_v p_Var12;
  rea_v pdVar13;
  rea_v puVar14;
  char *__s2;
  ulong uVar15;
  long long lVar16;
  ulong uVar17;
  rea_v _Stack_148;
  ulong uStack_140;
  ulong *puStack_130;
  rea_v aStack_e1;
  ulong *puStack_e0;
  ulong *apuStack_d8 [2];
  rea_v vStack_c8;
  rea_v pStack_a8;
  rea_v sStack_88;
  rea_v vStack_80;
  rea_v _Stack_68;
  
  puVar6 = rea_bind((b->super__Vector_base))._M_impl._M_finish;
  puVar14 = rea_bind((b->super__Vector_base))._M_impl._M_start;
  _Stack_68._M_impl._M_header._M_color = _S_red;
  _Stack_68._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  _Stack_68._M_impl._M_header._M_left = &_Stack_68._M_impl._M_header;
  _Stack_68._M_impl._M_node_count = 0;
  _Stack_148._M_p = (char *)(p + 8);
  _Stack_68._M_impl._M_header._M_right = _Stack_68._M_impl._M_header._M_left;
  if ((ulong)((long long)puVar6 - (long long)puVar14) < _Stack_148._M_p) {
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
        pStack_a8.second.super__Vector_base_double__std__allocator_double_._M_impl._M_start = (pointer)0x0;
        pStack_a8.second.super__Vector_base_double__std__allocator_double_._M_impl._M_finish = (pointer)0x0;
        pStack_a8.second.super__Vector_base_double__std__allocator_double_._M_impl. _M_end_of_storage = (pointer)0x0;
        vStack_80.super__Vector_base_double__std__allocator_double_._M_impl._M_start = (pointer)0x0;
        vStack_80.super__Vector_base_double__std__allocator_double_._M_impl._M_finish = (pointer)0x0;
        _Var11._M_p = PTR__S_empty_rep_storage_00311ff0 + 0x18;
        vStack_80.super__Vector_base_double__std__allocator_double_._M_impl._M_end_of_storage = (pointer)0x0;
        uVar10 = (long long)_Stack_148._M_p + 8;
        pStack_a8.first._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var11._M_p;
        sStack_88._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var11._M_p;
        if ((ulong)((long long)puVar6 - (long long)puVar14) < uVar10) {
LAB_0010f7e8:
          uStack_140 = (ulong)_Stack_148._M_p;
        }
        else {
          rea_memcpy(&vStack_c8,puVar14 + (long long)_Stack_148._M_p,8);
          uVar15 = uVar10 + (long long)vStack_c8.super__Vector_base_double__std__allocator_double_. _M_impl._M_start;
          if ((ulong)((long long)puVar6 - (long long)puVar14) < uVar15) goto LAB_0010f7e8;
          puVar14 = puVar14 + uVar10;
          if (puVar14 != puVar14 + (long long)vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl. _M_start) {
            uVar17 = (long long)(puVar14 + (long long)vStack_c8.super__Vector_base_double__std__allocator_double_. _M_impl._M_start) - (long long)puVar14;
            puVar7 = (ulong *)rea_std__string___Rep___S_create(uVar17,0,&aStack_e1);
            _Var11._M_p = (char *)(puVar7 + 3);
            uVar10 = 0;
            do {
              *(uchar *)((long long)_Var11._M_p + uVar10) = puVar14[uVar10];
              uVar10 = uVar10 + 1;
            } while (uVar10 != uVar17);
            if (puVar7 != (ulong *)PTR__S_empty_rep_storage_00311ff0) {
              *(undefined4 *)(puVar7 + 2) = 0;
              *puVar7 = uVar17;
              *(undefined1 *)((long long)puVar7 + uVar17 + 0x18) = 0;
            }
          }
          apuStack_d8[0] = (ulong *)_Var11._M_p;
          rea_std__string__assign(&sStack_88);
          if ((allocator *)(apuStack_d8[0] + -3) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
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
            puVar6 = rea_bind((b->super__Vector_base))._M_impl. _M_start;
            vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl._M_start = (pointer)0x0;
            vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl._M_finish = (pointer)0x0;
            vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl._M_end_of_storage = (pointer)0x0;
            uVar10 = uVar15 + 8;
            uVar17 = rea_bind((long long)(b->super__Vector_base)). _M_impl._M_finish - (long long)puVar6;
            if (uVar17 < uVar10) goto LAB_0010f880;
            rea_memcpy(apuStack_d8,puVar6 + uVar15,8);
            puVar7 = apuStack_d8[0];
            if (apuStack_d8[0] == (ulong *)0x0) {
LAB_0010f7c0:
              std__vector_double__std__allocator_double___operator_assign(&vStack_80,&vStack_c8);
              pdVar13 = vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl. _M_start;
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
                  pdVar13 = vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl. _M_start;
                  if (uVar17 == uVar10) break;
                  if (vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish == vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl. _M_end_of_storage) {
                    std__vector_double__std__allocator_double____M_emplace_back_aux_double_const________________________________(&vStack_c8);
                    pdVar13 = vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl. _M_start;
                  }
                  else {
                    if (vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish != (pointer)0x0) {
                      *vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = rea_cast<double >(apuStack_d8[0]);
                    }
                    vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl._M_finish = vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish + 1;
                  }
                  vStack_c8.super__Vector_base_double__std__allocator_double_._M_impl._M_start = pdVar13;
                  if ((ulong *)(lVar16 + 1) == puVar7) goto LAB_0010f7c0;
                  lVar16 = lVar16 + 1;
                  puVar6 = rea_bind((b->super__Vector_base)). _M_impl._M_start;
                  uVar1 = uVar10 + 8;
                  uVar17 = uVar10;
                  uVar10 = uVar1;
                } while (uVar1 <= (ulong)(rea_bind((long long)(b-> super__Vector_base ))._M_impl._M_finish - (long long)puVar6));
              }
            }
            if (pdVar13 != (pointer)0x0) {
              rea_operator_delete(pdVar13);
            }
            if (uVar15 == uStack_140) goto LAB_0010f880;
            rea_std__string__assign(&pStack_a8.first);
            std__vector_double__std__allocator_double___operator_assign(&pStack_a8.second,&vStack_80);
          }
          if (vStack_80.super__Vector_base_double__std__allocator_double_._M_impl._M_start != (pointer)0x0) {
            rea_operator_delete(vStack_80.super__Vector_base_double__std__allocator_double_._M_impl. _M_start);
          }
        }
        if ((allocator *)((long long)sStack_88._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
          puVar7 = (ulong *)((long long)sStack_88._M_dataplus._M_p + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
            iVar5 = *(int *)((long long)sStack_88._M_dataplus._M_p + -8);
            *(int *)((long long)sStack_88._M_dataplus._M_p + -8) = iVar5 + -1;
          }
          else {
            LOCK();
            iVar5 = *(int *)puVar7;
            *(int *)puVar7 = *(int *)puVar7 + -1;
            UNLOCK();
          }
          if (iVar5 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)((long long)sStack_88._M_dataplus._M_p + -0x18));
          }
        }
        __s1._M_dataplus._M_p = pStack_a8.first._M_dataplus._M_p;
        if (_Stack_148._M_p == (char *)uStack_140) {
          if (pStack_a8.second.super__Vector_base_double__std__allocator_double_._M_impl._M_start != (pointer)0x0) {
            rea_operator_delete(pStack_a8.second.super__Vector_base_double__std__allocator_double_. _M_impl._M_start);
          }
          p_Var12 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
          uStack_140 = p;
          if ((allocator *)((long long)pStack_a8.first._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
            puVar7 = (ulong *)((long long)pStack_a8.first._M_dataplus._M_p + -8);
            if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
              iVar5 = *(int *)((long long)pStack_a8.first._M_dataplus._M_p + -8);
              *(int *)((long long)pStack_a8.first._M_dataplus._M_p + -8) = iVar5 + -1;
            }
            else {
              LOCK();
              iVar5 = *(int *)puVar7;
              *(int *)puVar7 = *(int *)puVar7 + -1;
              UNLOCK();
            }
            if (iVar5 < 1) {
              std__string___Rep___M_destroy_________________________((allocator *)((long long)pStack_a8.first._M_dataplus._M_p + -0x18));
              p_Var12 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
            }
          }
          goto LAB_0010f8d7;
        }
        if (rea_bind((_Link_type)_Stack_68._M_impl._M_header._M_parent) == (_Link_type)0x0) {
          p_Var8 = (_Link_type)&_Stack_68._M_impl._M_header;
LAB_0010f800:
          if (rea_bind((_Link_type)_Stack_68._M_impl._M_header._M_left) != p_Var8) {
            lVar16 = rea_std___Rb_tree_decrement(&p_Var8->super__Rb_tree_node_base);
            __s2 = *(char **)(lVar16 + 0x20);
            _Stack_148 = pStack_a8.first._M_dataplus._M_p;
            uVar15 = *(ulong *)(__s2 + -0x18);
            uVar10 = *(ulong *)((long long)pStack_a8.first._M_dataplus._M_p + -0x18);
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
          uVar10 = *(ulong *)((long long)pStack_a8.first._M_dataplus._M_p + -0x18);
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
              if ((long long)uVar17 < 0x80000000) {
                if (-0x80000001 < (long long)uVar17) goto LAB_0010f6a8;
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
        if (pStack_a8.second.super__Vector_base_double__std__allocator_double_._M_impl._M_start != (pointer)0x0) {
          rea_operator_delete(pStack_a8.second.super__Vector_base_double__std__allocator_double_. _M_impl._M_start);
        }
        if ((allocator *)((long long)pStack_a8.first._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
          puVar7 = (ulong *)((long long)pStack_a8.first._M_dataplus._M_p + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
            iVar5 = *(int *)((long long)pStack_a8.first._M_dataplus._M_p + -8);
            *(int *)((long long)pStack_a8.first._M_dataplus._M_p + -8) = iVar5 + -1;
          }
          else {
            LOCK();
            iVar5 = *(int *)puVar7;
            *(int *)puVar7 = *(int *)puVar7 + -1;
            UNLOCK();
          }
          if (iVar5 < 1) {
            std__string___Rep___M_destroy_______________________((allocator *)((long long)pStack_a8.first._M_dataplus._M_p + -0x18));
          }
        }
        puStack_130 = (ulong *)((long long)puStack_130 + 1);
        if (rea_bind((_Alloc_hider)puStack_130) == sVar3._M_dataplus._M_p) break;
        puVar14 = rea_bind((b->super__Vector_base))._M_impl. _M_start;
        puVar6 = rea_bind((b->super__Vector_base))._M_impl. _M_finish;
        _Stack_148._M_p = (char *)uStack_140;
      } while( true );
    }
    p_Var12 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
    if (v != (map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ *)0x0) {
      std__________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______________M_erase(&v->_M_t,rea_bind((_Link_type)(v->_M_t))._M_impl._M_header._M_parent);
      __p = rea_bind(&(v->_M_t))._M_impl._M_header;
      rea_bind((v->_M_t))._M_impl._M_header._M_parent = (_Base_ptr)0x0;
      rea_bind((v->_M_t))._M_impl._M_node_count = 0;
      rea_bind((v->_M_t))._M_impl._M_header._M_left = __p;
      rea_bind((v->_M_t))._M_impl._M_header._M_right = __p;
      if (rea_bind((_Const_Link_type)_Stack_68._M_impl._M_header._M_parent) == (_Const_Link_type)0x0) {
        p_Var12 = (_Link_type)0x0;
      }
      else {
        p_Var8 = std_____________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_________________________M_copy(&v->_M_t,(_Const_Link_type)_Stack_68._M_impl._M_header._M_parent, (_Link_type)__p);
        rea_bind((v->_M_t))._M_impl._M_header._M_parent = &p_Var8->super__Rb_tree_node_base;
        p_Var12 = p_Var8;
        do {
          p_Var9 = p_Var12;
          p_Var12 = (_Link_type)(p_Var9->super__Rb_tree_node_base)._M_left;
        } while (p_Var12 != (_Link_type)0x0);
        rea_bind((v->_M_t))._M_impl._M_header._M_left = &p_Var9->super__Rb_tree_node_base;
        do {
          p_Var12 = p_Var8;
          p_Var8 = (_Link_type)(p_Var12->super__Rb_tree_node_base)._M_right;
        } while (p_Var8 != (_Link_type)0x0);
        rea_bind((v->_M_t))._M_impl._M_header._M_right = &p_Var12->super__Rb_tree_node_base;
        rea_bind((v->_M_t))._M_impl._M_node_count = _Stack_68._M_impl._M_node_count;
        p_Var12 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
      }
    }
  }
LAB_0010f8d7:
  std______Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__________M_erase(&_Stack_68,p_Var12);
  return uStack_140;
}
// @@@ END IDX 8
// @@@ BEGIN IDX 9 rea_SecInfo__getRescale
// ------------------------------------------------------------------
// IDX 9  00104f80  SecInfo__getRescale
// ------------------------------------------------------------------
double rea_SecInfo__getRescale(SecInfo * this_ptr, string * gid, int date) {
  int date_00;
  double dVar1;
  double dVar2;
  
  dVar1 = rea_getPreClosePrice(this_ptr,gid,date);
  if (((!NAN(dVar1)) && (date_00 = getPreDate(this_ptr,gid,date), date_00 != 0)) && (dVar2 = rea_getClosePrice(this_ptr,gid,date_00), !NAN(dVar2))) {
    return dVar1 / dVar2;
  }
  return DAT_0010fd18;
}
// @@@ END IDX 9
// @@@ BEGIN IDX 10 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_unique_pos
// ------------------------------------------------------------------
// IDX 10  00104f90  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_unique_pos(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, key_type * __k) {
  rea_adr p_Var1;
  int iVar2;
  _Rb_tree_color _Var3;
  rea_adr p_Var4;
  rea_adr p_Var5;
  rea_v pVar6;
  
  p_Var1 = (rea_bind(this_ptr)->_M_impl)._M_header._M_parent;
  if (p_Var1 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = &(rea_bind(this_ptr)->_M_impl)._M_header;
LAB_0010d7d0:
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
    if ((rea_bind(this_ptr)->_M_impl)._M_header._M_left == p_Var5) goto LAB_0010d7bf;
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var5);
    iVar2 = (int)rea_iv(*__k);
    _Var3 = p_Var1[1]._M_color;
  }
  else {
    iVar2 = (int)rea_iv(*__k);
    do {
      p_Var5 = p_Var1;
      _Var3 = p_Var5[1]._M_color;
      if (iVar2 < (int)_Var3) {
        p_Var1 = p_Var5->_M_left;
      }
      else {
        p_Var1 = p_Var5->_M_right;
      }
    } while (rea_bind(p_Var1) != (_Base_ptr)0x0);
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
// @@@ END IDX 10
// @@@ BEGIN IDX 11 rea_SecInfo__find_group_data2
// ------------------------------------------------------------------
// IDX 11  00104fa0  SecInfo__find_group_data2
// ------------------------------------------------------------------
GroupData2 * rea_SecInfo__find_group_data2(SecInfo * this_ptr, int date) {
  rea_adr pp_Var1;
  int *piVar2;
  rea_v p_Var3;
  rea_v this_00;
  undefined *this_01;
  undefined *puVar4;
  rea_v sVar5;
  int iVar6;
  rea_v iVar7;
  rea_v __z;
  rea_v __position;
  long long *plVar8;
  FILE *__stream;
  size_t sVar9;
  rea_v _Var10;
  void *pvVar11;
  rea_v p_Var12;
  rea_adr this_02;
  ulong uVar13;
  rea_v pVar14;
  uint auStack_7c [5];
  long long alStack_68 [2];
  long long alStack_58 [2];
  rea_v asStack_48 [3];
  
  this_01 = PTR_group_data_store1_00311fc0;
  auStack_7c[0] = date;
  iVar7 = std______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________find((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ *)PTR_group_data_store1_00311fc0,(int *)auStack_7c);
  this_02 = (_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ *)PTR_group_data_store2_00311ff8;
  if (iVar7._M_node == (_Base_ptr)(this_01 + 8)) {
    rea___gnu_cxx____to_xstring_std__basic_string_char__char ((code *) alStack_68,(size_t)PTR_vsnprintf_00311fd0,(char *)0x10,(void *)&DAT_0010fc03, (ulong)auStack_7c[0]);
    plVar8 = (long long *)rea_std__string__insert((ulong)alStack_68,(char *)0x0,0x10fc13);
    puVar4 = PTR__S_empty_rep_storage_00311ff0;
    alStack_58[0] = *plVar8;
    *plVar8 = (long long)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    plVar8 = (long long *)rea_std__string__append((char *)alStack_58,0x10fbfd);
    asStack_48[0]._M_dataplus._M_p = (_Alloc_hider)*plVar8;
    *plVar8 = (long long)(puVar4 + 0x18);
    __stream = rea_open_file((string*)rea_pv(asStack_48));
    if ((allocator *)((long long)asStack_48[0]._M_dataplus._M_p + -0x18) != (allocator *)puVar4) {
      piVar2 = (int *)((long long)asStack_48[0]._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar6 = *(int *)((long long)asStack_48[0]._M_dataplus._M_p + -8);
        *(int *)((long long)asStack_48[0]._M_dataplus._M_p + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long long)asStack_48[0]._M_dataplus._M_p + -0x18));
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
    if (((__stream == (FILE *)0x0) || (sVar9 = rea_fread(alStack_58,4,1,(FILE *)__stream), sVar9 != 1)) || ((int)alStack_58[0] != 0)) {
      return (GroupData2 *)0x0;
    }
    _Var10._M_p = rea_operator_new(0x18);
    _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)(_Var10._M_p + 4) < 0xaa0000000000001) {
        uVar13 = (long long)*(int *)(_Var10._M_p + 4) * 0xc;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long long)*(int *)_Var10._M_p) || (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),0xc,(long long)*(int *)(_Var10._M_p + 4), (FILE *)__stream), sVar9 != (long long)*(int *)(_Var10._M_p + 4))) goto LAB_00108b30;
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
        *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    asStack_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ *)this_01);
    sVar5._M_dataplus._M_p = asStack_48[0]._M_dataplus._M_p;
    if (asStack_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)asStack_48[0]._M_dataplus._M_p = 0;
      *(int *)((long long)asStack_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long long)asStack_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)asStack_48[0]._M_dataplus._M_p + 8));
        ((int *)((long long)sVar5._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long long)sVar5._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long long)sVar5._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)sVar5._M_dataplus._M_p + 0x10));
        ((int *)((long long)sVar5._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long long)sVar5._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar5._M_dataplus._M_p);
    }
    _Var10._M_p = rea_operator_new(0x18);
    _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)(_Var10._M_p + 4) < 0x3f80000000000001) {
        uVar13 = (long long)*(int *)(_Var10._M_p + 4) * 2;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long long)*(int *)_Var10._M_p) || (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),2,(long long)*(int *)(_Var10._M_p + 4), (FILE *)__stream), sVar9 != (long long)*(int *)(_Var10._M_p + 4))) goto LAB_00108c18;
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
        *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    this_02 = (_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ *)PTR_group_data_store2_00311ff8;
    asStack_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ *)PTR_group_data_store2_00311ff8);
    sVar5._M_dataplus._M_p = asStack_48[0]._M_dataplus._M_p;
    if (asStack_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)asStack_48[0]._M_dataplus._M_p = 0;
      *(int *)((long long)asStack_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long long)asStack_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)asStack_48[0]._M_dataplus._M_p + 8));
        ((int *)((long long)sVar5._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long long)sVar5._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long long)sVar5._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)sVar5._M_dataplus._M_p + 0x10));
        ((int *)((long long)sVar5._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long long)sVar5._M_dataplus._M_p + 0x10))[1] = 0;
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
      while (__position._M_node = p_Var3, (int)__position._M_node[1]._M_color < (int)auStack_7c[0]) {
        pp_Var1 = &(__position._M_node)->_M_right;
        p_Var3 = *pp_Var1;
        __position._M_node = p_Var12;
        if (*pp_Var1 == (_Base_ptr)0x0) goto LAB_0010894a;
      }
      p_Var3 = (__position._M_node)->_M_left;
      p_Var12 = __position._M_node;
    } while ((__position._M_node)->_M_left != (_Base_ptr)0x0);
LAB_0010894a:
    if ((__position._M_node != &(this_02->_M_impl)._M_header) && ((int)__position._M_node[1]._M_color <= (int)auStack_7c[0])) goto LAB_00108958;
  }
  __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
    (__z->_M_value_field).first = auStack_7c[0];
  }
  pVar14 = std_______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2___________________M_get_insert_hint_unique_pos______________________(this_02,(const_iterator)__position._M_node,&(__z->_M_value_field).first);
  __position._M_node = pVar14.first;
  if (pVar14.second == (_Base_ptr)0x0) {
    this_00 = (__z->_M_value_field).second._M_t. super__Tuple_impl ;
    if (this_00 != (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0) {
      IndexedData_GIDKey__GroupBackwardItem__free_________________((IndexedData_GIDKey__GroupBackwardItem *)this_00);
      rea_operator_delete((void *)this_00);
    }
    (__z->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
    rea_operator_delete(__z);
  }
  else {
    __position = std_____________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________________M_insert_node(this_02,__position._M_node,pVar14.second,__z);
  }
LAB_00108958:
  return (GroupData2 *)__position._M_node[1]._M_parent;
}
// @@@ END IDX 11
// @@@ BEGIN IDX 17 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_______M_emplace_hint_unique_const_std__piecewise_construct_t___std__tuple_const_std__basic_string_char__std__char_traits_char__std__allocator_char____std__tuple
// ------------------------------------------------------------------
// IDX 17  00105000  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_______M_emplace_hint_unique_const_std__piecewise_construct_t___std__tuple_const_std__basic_string_char__std__char_traits_char__std__allocator_char____std__tuple_____________
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_______M_emplace_hint_unique_const_std__piecewise_construct_t___std__tuple_const_std__basic_string_char__std__char_traits_char__std__allocator_char____std__tuple(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, const_iterator __pos) {
  rea_adr p_Var1;
  size_type *psVar2;
  int *piVar3;
  rea_adr psVar4;
  ulong uVar5;
  ulong uVar6;
  int iVar7;
  rea_adr p_Var8;
  undefined8 *in_RCX;
  ulong __n;
  bool bVar9;
  rea_adr p_Var10;
  long long lVar11;
  rea_v pVar12;
  
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
    lVar11 = *(long long *)(p_Var8 + 1);
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
  p_Var1 = &(rea_bind(this_ptr)->_M_impl)._M_header;
  if ((pVar12.first == (_Base_ptr)0x0) && (p_Var10 != p_Var1)) {
    uVar5 = *(ulong *)((long long)*(void **)(p_Var8 + 1) + -0x18);
    uVar6 = *(ulong *)((long long)*(void **)(p_Var10 + 1) + -0x18);
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
  psVar2 = &(rea_bind(this_ptr)->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)p_Var8;
}
// @@@ END IDX 17
// @@@ BEGIN IDX 19 rea_std__vector_double__std__allocator_double____M_emplace_back_aux_double_const
// ------------------------------------------------------------------
// IDX 19  00105020  std__vector_double__std__allocator_double____M_emplace_back_aux_double_const____________
// ------------------------------------------------------------------
void rea_std__vector_double__std__allocator_double____M_emplace_back_aux_double_const(vector_double__std__allocator_double_ * this_ptr) {
  rea_v __dest;
  long long lVar1;
  ulong uVar2;
  double *in_RSI;
  rea_v __src;
  ulong uVar3;
  rea_v pdVar4;
  
  uVar2 = rea_bind((long long)(this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish - rea_bind((long long)(this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start >> 3;
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
  __src = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
  lVar1 = rea_bind((long long)(this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish - (long long)__src >> 3;
  pdVar4 = __dest + lVar1;
  if (pdVar4 != (pointer)0x0) {
    *pdVar4 = *in_RSI;
  }
  if (lVar1 != 0) {
    rea_memmove(__dest,__src,lVar1 * 8);
    __src = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
  }
  if (__src != (pointer)0x0) {
    rea_operator_delete(__src);
  }
  rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start = __dest;
  rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish = pdVar4 + 1;
  rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_end_of_storage = (pointer)((long long)__dest + uVar3);
  return;
}
// @@@ END IDX 19
// @@@ BEGIN IDX 21 rea_IndexedData_GIDKey__GroupBackwardItem__free
// ------------------------------------------------------------------
// IDX 21  00105040  IndexedData_GIDKey__GroupBackwardItem__free
// ------------------------------------------------------------------
void rea_IndexedData_GIDKey__GroupBackwardItem__free(IndexedData_GIDKey__GroupBackwardItem * this_ptr) {
  rea_bind(this_ptr)->num_idxs = 0;
  rea_bind(this_ptr)->num_items = 0;
  if (rea_bind(this_ptr)->idxs != (Index *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->idxs);
    rea_bind(this_ptr)->idxs = (Index *)0x0;
  }
  if (rea_bind(this_ptr)->items != (GroupBackwardItem *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->items);
    rea_bind(this_ptr)->items = (GroupBackwardItem *)0x0;
  }
  return;
}
// @@@ END IDX 21
// @@@ BEGIN IDX 23 rea_std___pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char______pair
// ------------------------------------------------------------------
// IDX 23  00105060  std___pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char______pair
// ------------------------------------------------------------------
void rea_std___pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char______pair(pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char__ * this_ptr, int __in_chrg) {
  int *piVar1;
  char *pcVar2;
  undefined *puVar3;
  int iVar4;
  rea_v pbVar5;
  rea_v pbVar6;
  
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
  pcVar2 = (rea_bind(this_ptr)->second)._M_dataplus._M_p;
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
  pbVar6 = (rea_bind(this_ptr)->first). super__Vector_base ._M_impl._M_finish;
  pbVar5 = (rea_bind(this_ptr)->first). super__Vector_base ._M_impl._M_start;
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
    pbVar6 = (rea_bind(this_ptr)->first). super__Vector_base ._M_impl._M_start;
  }
  if (pbVar6 != (pointer)0x0) {
    rea_operator_delete(pbVar6);
  }
  return;
}
// @@@ END IDX 23
// @@@ BEGIN IDX 24 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_erase
// ------------------------------------------------------------------
// IDX 24  00105070  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_erase(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, _Link_type __x) {
  rea_v _Var1;
  rea_v p_Var2;
  
  while (rea_bind(__x) != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_right);
    _Var1 = (rea_bind(__x)->_M_value_field).second._M_t. super__Tuple_impl;
    p_Var2 = (_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_left;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_) 0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long long)_Var1 + 4) = 0;
      if (*(void **)((long long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 8));
        *(undefined8 *)((long long)_Var1 + 8) = 0;
      }
      if (*(void **)((long long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 0x10));
        *(undefined8 *)((long long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (rea_bind(__x)->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
    rea_operator_delete(__x);
    __x = p_Var2;
  }
  return;
}
// @@@ END IDX 24
// @@@ BEGIN IDX 30 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_insert__const_std__pair_std__basic_string_char__std__vector_double
// ------------------------------------------------------------------
// IDX 30  001050d0  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_insert__const_std__pair_std__basic_string_char__std__vector_double_____________
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_insert__const_std__pair_std__basic_string_char__std__vector_double(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * this_ptr, _Base_ptr __x, _Base_ptr __p, pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__ * __v) {
  size_type *psVar1;
  rea_v pdVar2;
  rea_v pdVar3;
  char *__s1;
  int iVar4;
  rea_adr p_Var5;
  rea_v __dest;
  undefined8 uVar6;
  ulong uVar7;
  long long lVar8;
  ulong __n;
  size_t __n_00;
  bool bVar9;
  ulong uVar10;
  
  bVar9 = true;
  if ((rea_bind(__x) == (_Base_ptr)0x0) && (rea_bind(__p) != &(rea_bind(this_ptr)->_M_impl)._M_header)) {
    __s1 = rea_bind((__v->first))._M_dataplus._M_p;
    uVar10 = *(ulong *)((long long)*(void **)(rea_bind(__p) + 1) + -0x18);
    uVar7 = *(ulong *)(__s1 + -0x18);
    __n = uVar7;
    if (uVar10 <= uVar7) {
      __n = uVar10;
    }
    iVar4 = rea_memcmp(__s1,*(void **)(rea_bind(__p) + 1),__n);
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
    pdVar2 = rea_bind((__v->second)).super__Vector_base_double__std__allocator_double_._M_impl._M_finish;
    pdVar3 = rea_bind((__v->second)).super__Vector_base_double__std__allocator_double_._M_impl._M_start;
    uVar10 = 0;
    __dest = (_Base_ptr)0x0;
    p_Var5[1]._M_parent = (_Base_ptr)0x0;
    p_Var5[1]._M_left = (_Base_ptr)0x0;
    p_Var5[1]._M_right = (_Base_ptr)0x0;
    uVar7 = (long long)pdVar2 - (long long)pdVar3 >> 3;
    if (uVar7 != 0) {
      if (0x1fffffffffffffff < uVar7) {
        uVar6 = rea_std____throw_bad_alloc();
        rea_std__string___Rep___M_dispose((allocator *)(*(long long *)(p_Var5 + 1) + -0x18));
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
    p_Var5[1]._M_right = (_Base_ptr)((long long)&__dest->_M_color + uVar10);
    pdVar2 = rea_bind((__v->second)).super__Vector_base_double__std__allocator_double_._M_impl._M_start;
    __n_00 = 0;
    lVar8 = rea_bind((long long)(__v->second)).super__Vector_base_double__std__allocator_double_._M_impl. _M_finish - (long long)pdVar2 >> 3;
    if (lVar8 != 0) {
      __n_00 = lVar8 * 8;
      __dest = rea_memmove(__dest,pdVar2,__n_00);
    }
    p_Var5[1]._M_left = (_Base_ptr)((long long)&__dest->_M_color + __n_00);
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar9,p_Var5,__p,&(rea_bind(this_ptr)->_M_impl)._M_header);
  psVar1 = &(rea_bind(this_ptr)->_M_impl)._M_node_count;
  *psVar1 = *psVar1 + 1;
  return (iterator)p_Var5;
}
// @@@ END IDX 30
// @@@ BEGIN IDX 31 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1
// ------------------------------------------------------------------
// IDX 31  001050e0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____________
// ------------------------------------------------------------------
pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____bool rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr) {
  rea_v _Var1;
  rea_v __z;
  rea_adr in_RDX;
  int *in_RSI;
  rea_v pVar2;
  rea_v pVar3;
  rea_v pVar4;
  
  __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->_M_value_field).first = *in_RSI;
    _Var1 = *in_RDX;
    *in_RDX = (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0 ;
    (__z->_M_value_field).second._M_t. super__Tuple_impl = _Var1;
  }
  pVar2 = _M_get_insert_unique_pos(this_ptr,&(__z->_M_value_field).first);
  pVar4.first._M_node = pVar2.first;
  if (pVar2.second == (_Base_ptr)0x0) {
    _Var1 = (__z->_M_value_field).second._M_t. super__Tuple_impl;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_) 0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long long)_Var1 + 4) = 0;
      if (*(void **)((long long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 8));
        *(undefined8 *)((long long)_Var1 + 8) = 0;
      }
      if (*(void **)((long long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 0x10));
        *(undefined8 *)((long long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (__z->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
    rea_operator_delete(__z);
    (*(undefined8 *)((uint8_t *)&pVar4 + 0x8)) = 0;
    return pVar4;
  }
  pVar3.first._M_node = _M_insert_node(this_ptr,pVar4.first._M_node,pVar2.second,__z);
  (*(undefined8 *)((uint8_t *)&pVar3 + 0x8)) = 1;
  return pVar3;
}
// @@@ END IDX 31
// @@@ BEGIN IDX 34 rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse
// ------------------------------------------------------------------
// IDX 34  00105110  _Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse
// ------------------------------------------------------------------
undefined8 rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse(vector_unsigned_char__std__allocator_unsigned_char_ * b, size_t p, map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * v) {
  rea_adr __p;
  rea_v puVar1;
  undefined *puVar2;
  rea_v sVar3;
  int iVar4;
  rea_v puVar5;
  ulong uVar6;
  ulong *puVar7;
  rea_v sVar8;
  rea_v p_Var9;
  rea_v puVar10;
  rea_v p_Var11;
  long long lVar12;
  rea_v puVar13;
  rea_v puVar14;
  rea_v p_Var15;
  rea_v _Var16;
  rea_v puVar17;
  rea_v pVar18;
  ulong *puStack_108;
  rea_v aaStack_9a [2];
  ulong *apuStack_98 [2];
  rea_v pStack_88;
  rea_v sStack_78;
  ulong *puStack_70;
  rea_v _Stack_68;
  
  puVar13 = (pointer)(p + 8);
  puVar5 = rea_bind((b->super__Vector_base))._M_impl._M_finish;
  puVar10 = rea_bind((b->super__Vector_base))._M_impl._M_start;
  _Stack_68._M_impl._M_header._M_color = _S_red;
  _Stack_68._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  _Stack_68._M_impl._M_header._M_left = &_Stack_68._M_impl._M_header;
  _Stack_68._M_impl._M_node_count = 0;
  _Stack_68._M_impl._M_header._M_right = _Stack_68._M_impl._M_header._M_left;
  if (puVar13 <= puVar5 + -(long long)puVar10) {
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
        if (puVar5 + -(long long)puVar10 < puVar14) {
LAB_0010ef10:
          sVar8._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)(puVar2 + 0x18);
        }
        else {
          rea_memcpy(apuStack_98,puVar13 + (long long)puVar10,8);
          puVar1 = puVar14 + (long long)apuStack_98[0];
          if (puVar5 + -(long long)puVar10 < puVar1) goto LAB_0010ef10;
          puVar14 = puVar14 + (long long)puVar10;
          puVar5 = puVar14 + (long long)apuStack_98[0];
          if (puVar14 != puVar5) {
            uVar6 = (long long)puVar5 - (long long)puVar14;
            puVar7 = (ulong *)rea_std__string___Rep___S_create(uVar6,0,(allocator*)rea_pv(aaStack_9a));
            _Var16._M_p = (char *)(puVar7 + 3);
            lVar12 = 0;
            do {
              *(uchar *)((long long)_Var16._M_p + lVar12) = puVar14[lVar12];
              lVar12 = lVar12 + 1;
            } while (lVar12 != (long long)puVar5 - (long long)puVar14);
            if (puVar7 != (ulong *)puVar2) {
              *(undefined4 *)(puVar7 + 2) = 0;
              *puVar7 = uVar6;
              *(undefined1 *)((long long)puVar7 + uVar6 + 0x18) = 0;
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
            puVar5 = rea_bind((b->super__Vector_base))._M_impl. _M_start;
            if (puVar1 + 8 <= rea_bind((b->super__Vector_base))._M_impl. _M_finish + -(long long)puVar5) {
              rea_memcpy(apuStack_98,puVar1 + (long long)puVar5,8);
              puStack_70 = apuStack_98[0];
              rea_std__string__assign(&pStack_88.first);
              pStack_88.second = rea_cast<double >(puStack_70);
              sVar8._M_dataplus._M_p = sStack_78._M_dataplus._M_p;
              puVar17 = puVar1 + 8;
            }
          }
        }
        if ((allocator *)((long long)sVar8._M_dataplus._M_p + -0x18) != (allocator *)puVar2) {
          puVar7 = (ulong *)((long long)sVar8._M_dataplus._M_p + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
            iVar4 = (int)*(ulong *)((long long)sVar8._M_dataplus._M_p + -8);
            *(int *)((long long)sVar8._M_dataplus._M_p + -8) = iVar4 + -1;
          }
          else {
            LOCK();
            iVar4 = (int)*puVar7;
            *(int *)puVar7 = (int)*puVar7 + -1;
            UNLOCK();
          }
          if (iVar4 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)((long long)sVar8._M_dataplus._M_p + -0x18));
          }
        }
        if (puVar13 == puVar17) {
          p_Var15 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
          if ((allocator *)((long long)pStack_88.first._M_dataplus._M_p + -0x18) != (allocator *)puVar2) {
            puVar7 = (ulong *)((long long)pStack_88.first._M_dataplus._M_p + -8);
            if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
              iVar4 = *(int *)((long long)pStack_88.first._M_dataplus._M_p + -8);
              *(int *)((long long)pStack_88.first._M_dataplus._M_p + -8) = iVar4 + -1;
            }
            else {
              LOCK();
              iVar4 = *(int *)puVar7;
              *(int *)puVar7 = *(int *)puVar7 + -1;
              UNLOCK();
            }
            if (iVar4 < 1) {
              std__string___Rep___M_destroy_________________________((allocator *)((long long)pStack_88.first._M_dataplus._M_p + -0x18));
              p_Var15 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
            }
          }
          goto LAB_0010efd9;
        }
        pVar18 = std_____________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_______________________M_get_insert_unique_pos(&_Stack_68,&pStack_88.first);
        if (pVar18.second != (_Base_ptr)0x0) {
          std______________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double________________M_insert__const_std__pair_std__basic_string_char__double______________________(&_Stack_68,pVar18.first,pVar18.second,&pStack_88);
        }
        if ((allocator *)((long long)pStack_88.first._M_dataplus._M_p + -0x18) != (allocator *)puVar2) {
          puVar7 = (ulong *)((long long)pStack_88.first._M_dataplus._M_p + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
            iVar4 = *(int *)((long long)pStack_88.first._M_dataplus._M_p + -8);
            *(int *)((long long)pStack_88.first._M_dataplus._M_p + -8) = iVar4 + -1;
          }
          else {
            LOCK();
            iVar4 = *(int *)puVar7;
            *(int *)puVar7 = *(int *)puVar7 + -1;
            UNLOCK();
          }
          if (iVar4 < 1) {
            std__string___Rep___M_destroy_______________________((allocator *)((long long)pStack_88.first._M_dataplus._M_p + -0x18));
          }
        }
        puStack_108 = (ulong *)((long long)puStack_108 + 1);
        puVar13 = puVar17;
        if (rea_bind((_Alloc_hider)puStack_108) == sVar3._M_dataplus._M_p) break;
        puVar10 = rea_bind((b->super__Vector_base))._M_impl. _M_start;
        puVar5 = rea_bind((b->super__Vector_base))._M_impl. _M_finish;
      } while( true );
    }
    p = (size_t)puVar13;
    p_Var15 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
    if (v == (map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ *)0x0) goto LAB_0010efd9;
    std________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__________M_erase(&v->_M_t,rea_bind((_Link_type)(v->_M_t))._M_impl._M_header._M_parent);
    __p = rea_bind(&(v->_M_t))._M_impl._M_header;
    rea_bind((v->_M_t))._M_impl._M_header._M_parent = (_Base_ptr)0x0;
    rea_bind((v->_M_t))._M_impl._M_node_count = 0;
    rea_bind((v->_M_t))._M_impl._M_header._M_left = __p;
    rea_bind((v->_M_t))._M_impl._M_header._M_right = __p;
    if (rea_bind((_Const_Link_type)_Stack_68._M_impl._M_header._M_parent) != (_Const_Link_type)0x0) {
      p_Var9 = std___________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_____________________M_copy(&v->_M_t,(_Const_Link_type)_Stack_68._M_impl._M_header._M_parent, (_Link_type)__p);
      rea_bind((v->_M_t))._M_impl._M_header._M_parent = &p_Var9->super__Rb_tree_node_base;
      p_Var15 = p_Var9;
      do {
        p_Var11 = p_Var15;
        p_Var15 = (_Link_type)(p_Var11->super__Rb_tree_node_base)._M_left;
      } while (p_Var15 != (_Link_type)0x0);
      rea_bind((v->_M_t))._M_impl._M_header._M_left = &p_Var11->super__Rb_tree_node_base;
      do {
        p_Var15 = p_Var9;
        p_Var9 = (_Link_type)(p_Var15->super__Rb_tree_node_base)._M_right;
      } while (p_Var9 != (_Link_type)0x0);
      rea_bind((v->_M_t))._M_impl._M_header._M_right = &p_Var15->super__Rb_tree_node_base;
      rea_bind((v->_M_t))._M_impl._M_node_count = _Stack_68._M_impl._M_node_count;
      p_Var15 = (_Link_type)_Stack_68._M_impl._M_header._M_parent;
      goto LAB_0010efd9;
    }
  }
  p_Var15 = (_Link_type)0x0;
LAB_0010efd9:
  std______Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double________M_erase(&_Stack_68,p_Var15);
  return rea_cast<size_t >((pointer)p);
}
// @@@ END IDX 34
// @@@ BEGIN IDX 36 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_insert_node
// ------------------------------------------------------------------
// IDX 36  00105130  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_insert_node
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_insert_node(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, _Base_ptr __x, _Base_ptr __p, _Link_type __z) {
  rea_adr p_Var1;
  size_type *psVar2;
  bool bVar3;
  
  p_Var1 = &(rea_bind(this_ptr)->_M_impl)._M_header;
  if ((rea_bind(__x) == (_Base_ptr)0x0) && (rea_bind(p_Var1) != __p)) {
    bVar3 = (rea_bind(__z)->_M_value_field).first < rea_bind(rea_cast<int >(__p))[1]._M_color;
  }
  else {
    bVar3 = true;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar3,rea_bind(&__z)->super__Rb_tree_node_base,__p,p_Var1);
  psVar2 = &(rea_bind(this_ptr)->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)rea_bind(&__z)->super__Rb_tree_node_base;
}
// @@@ END IDX 36
// @@@ BEGIN IDX 37 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_unique_pos
// ------------------------------------------------------------------
// IDX 37  00105140  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_unique_pos(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, key_type * __k) {
  rea_adr p_Var1;
  int iVar2;
  _Rb_tree_color _Var3;
  rea_adr p_Var4;
  rea_adr p_Var5;
  rea_v pVar6;
  
  p_Var1 = (rea_bind(this_ptr)->_M_impl)._M_header._M_parent;
  if (p_Var1 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = &(rea_bind(this_ptr)->_M_impl)._M_header;
LAB_0010d5d0:
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
    if ((rea_bind(this_ptr)->_M_impl)._M_header._M_left == p_Var5) goto LAB_0010d5bf;
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var5);
    iVar2 = (int)rea_iv(*__k);
    _Var3 = p_Var1[1]._M_color;
  }
  else {
    iVar2 = (int)rea_iv(*__k);
    do {
      p_Var5 = p_Var1;
      _Var3 = p_Var5[1]._M_color;
      if (iVar2 < (int)_Var3) {
        p_Var1 = p_Var5->_M_left;
      }
      else {
        p_Var1 = p_Var5->_M_right;
      }
    } while (rea_bind(p_Var1) != (_Base_ptr)0x0);
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
// @@@ END IDX 37
// @@@ BEGIN IDX 40 rea_SecInfo__find_group_data1
// ------------------------------------------------------------------
// IDX 40  00105170  SecInfo__find_group_data1
// ------------------------------------------------------------------
GroupData1 * rea_SecInfo__find_group_data1(SecInfo * this_ptr, int date) {
  rea_adr pp_Var1;
  int *piVar2;
  rea_v this_00;
  undefined *this_01;
  undefined *puVar3;
  rea_v sVar4;
  rea_v p_Var5;
  int iVar6;
  rea_v iVar7;
  rea_v __z;
  long long *plVar8;
  FILE *__stream;
  size_t sVar9;
  rea_v _Var10;
  void *pvVar11;
  rea_v p_Var12;
  ulong uVar13;
  rea_v pVar14;
  uint auStack_7c [5];
  long long alStack_68 [2];
  long long alStack_58 [2];
  rea_v asStack_48 [3];
  
  this_01 = PTR_group_data_store1_00311fc0;
  auStack_7c[0] = date;
  iVar7 = std______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________find((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ *)PTR_group_data_store1_00311fc0,(int *)auStack_7c);
  if (iVar7._M_node == (_Base_ptr)(this_01 + 8)) {
    rea___gnu_cxx____to_xstring_std__basic_string_char__char ((code *) alStack_68,(size_t)PTR_vsnprintf_00311fd0,(char *)0x10,(void *)&DAT_0010fc03, (ulong)auStack_7c[0]);
    plVar8 = (long long *)rea_std__string__insert((ulong)alStack_68,(char *)0x0,0x10fc13);
    puVar3 = PTR__S_empty_rep_storage_00311ff0;
    alStack_58[0] = *plVar8;
    *plVar8 = (long long)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    plVar8 = (long long *)rea_std__string__append((char *)alStack_58,0x10fbfd);
    asStack_48[0]._M_dataplus._M_p = (_Alloc_hider)*plVar8;
    *plVar8 = (long long)(puVar3 + 0x18);
    __stream = rea_open_file((string*)rea_pv(asStack_48));
    if ((allocator *)((long long)asStack_48[0]._M_dataplus._M_p + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)((long long)asStack_48[0]._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar6 = *(int *)((long long)asStack_48[0]._M_dataplus._M_p + -8);
        *(int *)((long long)asStack_48[0]._M_dataplus._M_p + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long long)asStack_48[0]._M_dataplus._M_p + -0x18));
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
    if (((__stream == (FILE *)0x0) || (sVar9 = rea_fread(alStack_58,4,1,(FILE *)__stream), sVar9 != 1)) || ((int)alStack_58[0] != 0)) {
      return (GroupData1 *)0x0;
    }
    _Var10._M_p = rea_operator_new(0x18);
    _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)(_Var10._M_p + 4) < 0xaa0000000000001) {
        uVar13 = (long long)*(int *)(_Var10._M_p + 4) * 0xc;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long long)*(int *)_Var10._M_p) || (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),0xc,(long long)*(int *)(_Var10._M_p + 4), (FILE *)__stream), sVar9 != (long long)*(int *)(_Var10._M_p + 4))) goto LAB_00108410;
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
        *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    asStack_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ *)this_01);
    sVar4._M_dataplus._M_p = asStack_48[0]._M_dataplus._M_p;
    if (asStack_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)asStack_48[0]._M_dataplus._M_p = 0;
      *(int *)((long long)asStack_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long long)asStack_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)asStack_48[0]._M_dataplus._M_p + 8));
        ((int *)((long long)sVar4._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long long)sVar4._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long long)sVar4._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)sVar4._M_dataplus._M_p + 0x10));
        ((int *)((long long)sVar4._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long long)sVar4._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar4._M_dataplus._M_p);
    }
    _Var10._M_p = rea_operator_new(0x18);
    _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)(_Var10._M_p + 4) < 0x3f80000000000001) {
        uVar13 = (long long)*(int *)(_Var10._M_p + 4) * 2;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long long)*(int *)_Var10._M_p) || (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),2,(long long)*(int *)(_Var10._M_p + 4), (FILE *)__stream), sVar9 != (long long)*(int *)(_Var10._M_p + 4))) goto LAB_00108500;
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
        *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    asStack_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ *)PTR_group_data_store2_00311ff8);
    sVar4._M_dataplus._M_p = asStack_48[0]._M_dataplus._M_p;
    if (asStack_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)asStack_48[0]._M_dataplus._M_p = 0;
      *(int *)((long long)asStack_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long long)asStack_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)asStack_48[0]._M_dataplus._M_p + 8));
        ((int *)((long long)sVar4._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long long)sVar4._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long long)sVar4._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)sVar4._M_dataplus._M_p + 0x10));
        ((int *)((long long)sVar4._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long long)sVar4._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar4._M_dataplus._M_p);
    }
    rea_fclose((FILE *)__stream);
  }
  if (rea_bind(*(_Base_ptr *)(this_01 + 0x10)) == (_Base_ptr)0x0) {
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
    if ((iVar7._M_node != (_Base_ptr)(this_01 + 8)) && ((int)iVar7._M_node[1]._M_color <= (int)auStack_7c[0])) goto LAB_00108238;
  }
  __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
    (__z->_M_value_field).first = auStack_7c[0];
  }
  pVar14 = std_______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1___________________M_get_insert_hint_unique_pos______________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ *)this_01,(const_iterator)iVar7._M_node,&(__z->_M_value_field).first);
  iVar7._M_node = pVar14.first;
  if (pVar14.second == (_Base_ptr)0x0) {
    this_00 = (__z->_M_value_field).second._M_t. super__Tuple_impl ;
    if (this_00 != (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0) {
      IndexedData_GroupKey__GroupForwardItem__free_________________((IndexedData_GroupKey__GroupForwardItem *)this_00);
      rea_operator_delete((void *)this_00);
    }
    (__z->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
    rea_operator_delete(__z);
  }
  else {
    iVar7 = std________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____________________M_insert_node((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ *)this_01,iVar7._M_node,pVar14.second,__z);
  }
LAB_00108238:
  return (GroupData1 *)iVar7._M_node[1]._M_parent;
}
// @@@ END IDX 40
// @@@ BEGIN IDX 46 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_insert_node
// ------------------------------------------------------------------
// IDX 46  001051d0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_insert_node
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_insert_node(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, _Base_ptr __x, _Base_ptr __p, _Link_type __z) {
  rea_adr p_Var1;
  size_type *psVar2;
  bool bVar3;
  
  p_Var1 = &(rea_bind(this_ptr)->_M_impl)._M_header;
  if ((rea_bind(__x) == (_Base_ptr)0x0) && (rea_bind(p_Var1) != __p)) {
    bVar3 = (rea_bind(__z)->_M_value_field).first < rea_bind(rea_cast<int >(__p))[1]._M_color;
  }
  else {
    bVar3 = true;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar3,rea_bind(&__z)->super__Rb_tree_node_base,__p,p_Var1);
  psVar2 = &(rea_bind(this_ptr)->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)rea_bind(&__z)->super__Rb_tree_node_base;
}
// @@@ END IDX 46
// @@@ BEGIN IDX 47 rea_SecInfo__getLastClosePrice
// ------------------------------------------------------------------
// IDX 47  001051e0  SecInfo__getLastClosePrice
// ------------------------------------------------------------------
double rea_SecInfo__getLastClosePrice(SecInfo * this_ptr, string * gid, int date) {
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  long long lVar4;
  int iVar5;
  size_t __n;
  long long lVar6;
  int *piVar7;
  char *pcVar8;
  long long lVar9;
  double dVar10;
  undefined8 uStack_68;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  
  dVar10 = rea_getPreClosePrice(this_ptr,gid,date);
  if ((NAN(dVar10)) && (piVar7 = *(int **)PTR_data_00311fc8, dVar10 = (double)rea_iv(DAT_0010fd10), *(ulong *)(rea_bind((gid->_M_dataplus))._M_p + -0x18) < 0x10)) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar8 = rea_bind((gid->_M_dataplus))._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar8 + -0x18);
    }
    rea_memcpy(&uStack_68,pcVar8,__n);
    lVar6 = (long long)*piVar7;
    *(undefined1 *)((long long)&uStack_68 + __n) = 0;
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
    dVar10 = (double)rea_iv(DAT_0010fd10);
    if (((pcVar1 != pcVar8) && (iVar5 = rea_strcmp(pcVar8,(char *)&uStack_58), dVar10 = (double)rea_iv(DAT_0010fd10), iVar5 == 0)) && (pcVar8 != (char *)0x0)) {
      piVar2 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + (long long)*(int *)(pcVar8 + 0x10) * 0x18);
      piVar7 = piVar2;
      for (lVar6 = ((*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + ((long long)*(int *)(pcVar8 + 0x10) + (long long)*(int *)(pcVar8 + 0x14)) * 0x18) - (long long)piVar2 >> 3) * -0x5555555555555555; 0 < lVar6;
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
// @@@ END IDX 47
// @@@ BEGIN IDX 49 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_erase
// ------------------------------------------------------------------
// IDX 49  00105200  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_erase(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, _Link_type __x) {
  int *piVar1;
  char *pcVar2;
  rea_v p_Var3;
  undefined *puVar4;
  int iVar5;
  
  puVar4 = PTR__S_empty_rep_storage_00311ff0;
  while (rea_bind(__x) != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_right);
    pcVar2 = (rea_bind(__x)->_M_value_field).first._M_dataplus._M_p;
    p_Var3 = (_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_left;
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
// @@@ END IDX 49
// @@@ BEGIN IDX 51 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_unique_pos
// ------------------------------------------------------------------
// IDX 51  00105220  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_unique_pos(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, key_type * __k) {
  rea_adr p_Var1;
  int iVar2;
  _Rb_tree_color _Var3;
  rea_adr p_Var4;
  rea_adr p_Var5;
  rea_v pVar6;
  
  p_Var1 = (rea_bind(this_ptr)->_M_impl)._M_header._M_parent;
  if (p_Var1 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = &(rea_bind(this_ptr)->_M_impl)._M_header;
LAB_0010d3f0:
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
    if ((rea_bind(this_ptr)->_M_impl)._M_header._M_left == p_Var5) goto LAB_0010d3df;
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var5);
    iVar2 = (int)rea_iv(*__k);
    _Var3 = p_Var1[1]._M_color;
  }
  else {
    iVar2 = (int)rea_iv(*__k);
    do {
      p_Var5 = p_Var1;
      _Var3 = p_Var5[1]._M_color;
      if (iVar2 < (int)_Var3) {
        p_Var1 = p_Var5->_M_left;
      }
      else {
        p_Var1 = p_Var5->_M_right;
      }
    } while (rea_bind(p_Var1) != (_Base_ptr)0x0);
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
// @@@ END IDX 51
// @@@ BEGIN IDX 52 rea_SecInfo__getClosePrice
// ------------------------------------------------------------------
// IDX 52  00105230  SecInfo__getClosePrice
// ------------------------------------------------------------------
double rea_SecInfo__getClosePrice(SecInfo * this_ptr, string * gid, int date) {
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  long long lVar5;
  int iVar6;
  size_t __n;
  long long lVar7;
  int *piVar8;
  long long lVar9;
  undefined1 auStack_68 [16];
  char acStack_58 [16];
  undefined8 uStack_48;
  
  piVar8 = *(int **)PTR_data_00311fc8;
  if (*(ulong *)(rea_bind((gid->_M_dataplus))._M_p + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar4 = rea_bind((gid->_M_dataplus))._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar4 + -0x18);
    }
    rea_memcpy(auStack_68,pcVar4,__n);
    lVar7 = (long long)*piVar8;
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
    if (((pcVar1 != pcVar4) && (iVar6 = rea_strcmp(pcVar4,acStack_58), iVar6 == 0)) && (pcVar4 != (char *)0x0)) {
      piVar8 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + (long long)*(int *)(pcVar4 + 0x10) * 0x18);
      piVar2 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + ((long long)*(int *)(pcVar4 + 0x10) + (long long)*(int *)(pcVar4 + 0x14)) * 0x18);
      for (lVar7 = ((long long)piVar2 - (long long)piVar8 >> 3) * -0x5555555555555555; 0 < lVar7;
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
  return (double)rea_iv(DAT_0010fd10);
}
// @@@ END IDX 52
// @@@ BEGIN IDX 53 rea_SecInfo__getPreDate
// ------------------------------------------------------------------
// IDX 53  00105240  SecInfo__getPreDate
// ------------------------------------------------------------------
int rea_SecInfo__getPreDate(SecInfo * this_ptr, string * gid, int date) {
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  long long lVar7;
  int iVar8;
  size_t __n;
  long long lVar9;
  int *piVar10;
  long long lVar11;
  undefined8 auStack_68 [2];
  char acStack_58 [16];
  undefined8 uStack_48;
  
  piVar10 = *(int **)PTR_data_00311fc8;
  iVar8 = 0;
  if (*(ulong *)(rea_bind((gid->_M_dataplus))._M_p + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar6 = rea_bind((gid->_M_dataplus))._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar6 + -0x18);
    }
    rea_memcpy(auStack_68,pcVar6,__n);
    lVar9 = (long long)*piVar10;
    *(undefined1 *)((long long)auStack_68 + __n) = 0;
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
      piVar2 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + (long long)*(int *)(pcVar6 + 0x10) * 0x18);
      piVar3 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + ((long long)*(int *)(pcVar6 + 0x10) + (long long)*(int *)(pcVar6 + 0x14)) * 0x18);
      piVar10 = piVar2;
      for (lVar9 = ((long long)piVar3 - (long long)piVar2 >> 3) * -0x5555555555555555; 0 < lVar9;
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
// @@@ END IDX 53
// @@@ BEGIN IDX 55 rea_std__vector_double__std__allocator_double___operator__assign
// ------------------------------------------------------------------
// IDX 55  00105260  std__vector_double__std__allocator_double___operator_assign___________
// ------------------------------------------------------------------
vector_double__std__allocator_double_ * rea_std__vector_double__std__allocator_double___operator__assign(vector_double__std__allocator_double_ * this_ptr, vector_double__std__allocator_double_ * __x) {
  _Rb_tree_color _Var1;
  rea_v p_Var2;
  double dVar3;
  double dVar4;
  ulong uVar5;
  rea_v pdVar6;
  rea_v __p;
  rea_v p_Var7;
  rea_v p_Var8;
  rea_v pdVar9;
  rea_v pdVar10;
  undefined8 uVar11;
  long long lVar12;
  rea_v extraout_RDX;
  ulong uVar13;
  rea_v __src;
  rea_adr this_00;
  size_t sVar14;
  
  if (__x == this_ptr) {
    return this_ptr;
  }
  pdVar6 = rea_bind((__x->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish;
  pdVar9 = rea_bind((__x->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
  this_00 = rea_bind((_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ *)(this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
  uVar13 = (long long)pdVar6 - (long long)pdVar9 >> 3;
  if (uVar13 <= (ulong)(rea_bind((long long)(this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl. _M_end_of_storage - (long long)this_00 >> 3)) {
    pdVar10 = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish;
    uVar5 = (long long)pdVar10 - (long long)this_00 >> 3;
    if (uVar5 < uVar13) {
      __src = pdVar9 + uVar5;
      if (uVar5 == 0) {
        lVar12 = (long long)pdVar6 - (long long)__src;
        this_00 = (_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ *)((long long)&this_00->_M_impl + uVar13 * 8);
      }
      else {
        rea_memmove(this_00,pdVar9,uVar5 * 8);
        pdVar10 = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish;
        pdVar6 = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
        this_00 = (_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ *)(pdVar6 + uVar13);
        __src = (pointer)(((long long)pdVar10 - (long long)pdVar6 & 0xfffffffffffffff8U) + rea_bind((long long)(__x->super__Vector_base_double__std__allocator_double_))._M_impl. _M_start);
        lVar12 = rea_bind((long long)(__x->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish - (long long)__src;
      }
      if (lVar12 >> 3 != 0) {
        rea_memmove(pdVar10,__src,(lVar12 >> 3) * 8);
        rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start + uVar13;
        return this_ptr;
      }
    }
    else if (uVar13 != 0) {
      rea_memmove(this_00,pdVar9,uVar13 * 8);
      rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start + uVar13;
      return this_ptr;
    }
    rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish = (pointer)this_00 ;
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
        rea_std__string__string(&__p->_M_value_field, rea_bind((string *) &__x[1].super__Vector_base_double__std__allocator_double_)._M_impl. _M_finish);
        pdVar6 = rea_bind(__x[2].super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
        pdVar9 = rea_bind(__x[1].super__Vector_base_double__std__allocator_double_)._M_impl. _M_end_of_storage;
        uVar13 = 0;
        pdVar10 = (pointer)0x0;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_start = (pointer)0x0;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = (pointer)0x0;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_end_of_storage = (pointer)0x0;
        uVar5 = (long long)pdVar6 - (long long)pdVar9 >> 3;
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
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_start = pdVar10;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = pdVar10;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_end_of_storage = (pointer)(uVar13 + (long long)pdVar10);
        pdVar6 = rea_bind(__x[1].super__Vector_base_double__std__allocator_double_)._M_impl. _M_end_of_storage;
        sVar14 = 0;
        lVar12 = rea_bind((long long)__x[2].super__Vector_base_double__std__allocator_double_)._M_impl._M_start - (long long)pdVar6 >> 3;
        if (lVar12 != 0) {
          sVar14 = lVar12 * 8;
          pdVar10 = rea_memmove(pdVar10,pdVar6,sVar14);
        }
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = (pointer)((long long)pdVar10 + sVar14);
      }
      _Var1 = *(_Rb_tree_color *) rea_bind(&(__x->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
      (__p->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
      p_Var2 = rea_bind((_Const_Link_type) __x[1].super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
      (__p->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
      (__p->super__Rb_tree_node_base)._M_parent = extraout_RDX;
      (__p->super__Rb_tree_node_base)._M_color = _Var1;
      if (p_Var2 != (_Const_Link_type)0x0) {
        p_Var7 = _Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_________________________M_copy(this_00,p_Var2,__p);
        (__p->super__Rb_tree_node_base)._M_right = &p_Var7->super__Rb_tree_node_base;
      }
      pdVar6 = rea_bind((__x->super__Vector_base_double__std__allocator_double_))._M_impl._M_end_of_storage;
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
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_start = (pointer)0x0;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_finish = (pointer)0x0;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_end_of_storage = (pointer)0x0;
          uVar5 = (long long)dVar3 - (long long)dVar4 >> 3;
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
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_start = pdVar9;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_finish = pdVar9;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_end_of_storage = (pointer)(uVar13 + (long long)pdVar9);
          sVar14 = 0;
          lVar12 = (long long)pdVar6[6] - (long long)pdVar6[5] >> 3;
          if (lVar12 != 0) {
            sVar14 = lVar12 * 8;
            pdVar9 = rea_memmove(pdVar9,(void *)pdVar6[5],sVar14);
          }
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_finish = (pointer)((long long)pdVar9 + sVar14);
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
      pdVar9 = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
      goto joined_r0x0010e356;
    }
  }
  pdVar9 = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
joined_r0x0010e356:
  if (pdVar9 != (pointer)0x0) {
    rea_operator_delete(pdVar9);
  }
  rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start = pdVar6;
  rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_end_of_storage = (pointer)((long long)pdVar6 + uVar5);
  rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish = (pointer)((long long)pdVar6 + uVar5);
  return this_ptr;
}
// @@@ END IDX 55
// @@@ BEGIN IDX 56 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_copy
// ------------------------------------------------------------------
// IDX 56  00105270  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_copy
// ------------------------------------------------------------------
_Link_type rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_copy(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * this_ptr, _Const_Link_type __x, _Link_type __p) {
  _Rb_tree_color _Var1;
  rea_v pdVar2;
  rea_v p_Var3;
  rea_v p_Var4;
  rea_v p_Var5;
  rea_v p_Var6;
  rea_v __p_00;
  rea_v p_Var7;
  rea_v p_Var8;
  rea_v pdVar9;
  rea_v __dest;
  undefined8 uVar10;
  ulong uVar11;
  long long lVar12;
  ulong uVar13;
  size_t sVar14;
  
  __p_00 = rea_operator_new(0x40);
  if (__p_00 != (_Link_type)0x0) {
    (__p_00->super__Rb_tree_node_base)._M_color = _S_red;
    (__p_00->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    rea_std__string__string(&__p_00->_M_value_field,&(rea_bind(__x)->_M_value_field).first);
    pdVar9 = (rea_bind(__x)->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_finish;
    pdVar2 = (rea_bind(__x)->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_start;
    uVar13 = 0;
    __dest = (pointer)0x0;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_start = (pointer)0x0;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = (pointer)0x0;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_end_of_storage = (pointer)0x0;
    uVar11 = (long long)pdVar9 - (long long)pdVar2 >> 3;
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
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_start = __dest;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = __dest;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_end_of_storage = (pointer)(uVar13 + (long long)__dest);
    pdVar9 = (rea_bind(__x)->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_start;
    sVar14 = 0;
    lVar12 = (long long)(rea_bind(__x)->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_finish - (long long)pdVar9 >> 3;
    if (lVar12 != 0) {
      sVar14 = lVar12 * 8;
      __dest = rea_memmove(__dest,pdVar9,sVar14);
    }
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = (pointer)((long long)__dest + sVar14);
  }
  _Var1 = (rea_bind(__x)->super__Rb_tree_node_base)._M_color;
  (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
  p_Var3 = (_Const_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_right;
  (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
  (__p_00->super__Rb_tree_node_base)._M_parent = rea_bind(&__p)->super__Rb_tree_node_base;
  (__p_00->super__Rb_tree_node_base)._M_color = _Var1;
  if (p_Var3 != (_Const_Link_type)0x0) {
    p_Var7 = _M_copy(this_ptr,p_Var3,__p_00);
    (__p_00->super__Rb_tree_node_base)._M_right = &p_Var7->super__Rb_tree_node_base;
  }
  p_Var4 = (rea_bind(__x)->super__Rb_tree_node_base)._M_left;
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
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_start = (pointer)0x0;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = (pointer)0x0;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_end_of_storage = (pointer)0x0;
      uVar11 = (long long)p_Var5 - (long long)p_Var6 >> 3;
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
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_start = pdVar9;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = pdVar9;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_end_of_storage = (pointer)(uVar13 + (long long)pdVar9);
      sVar14 = 0;
      lVar12 = (long long)p_Var4[1]._M_left - (long long)p_Var4[1]._M_parent >> 3;
      if (lVar12 != 0) {
        sVar14 = lVar12 * 8;
        pdVar9 = rea_memmove(pdVar9,p_Var4[1]._M_parent,sVar14);
      }
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = (pointer)((long long)pdVar9 + sVar14);
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
// @@@ END IDX 56
// @@@ BEGIN IDX 57 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_insert_node
// ------------------------------------------------------------------
// IDX 57  00105280  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_insert_node
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_insert_node(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, _Base_ptr __x, _Base_ptr __p, _Link_type __z) {
  rea_adr p_Var1;
  size_type *psVar2;
  bool bVar3;
  
  p_Var1 = &(rea_bind(this_ptr)->_M_impl)._M_header;
  if ((rea_bind(__x) == (_Base_ptr)0x0) && (rea_bind(p_Var1) != __p)) {
    bVar3 = (rea_bind(__z)->_M_value_field).first < rea_bind(rea_cast<int >(__p))[1]._M_color;
  }
  else {
    bVar3 = true;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar3,rea_bind(&__z)->super__Rb_tree_node_base,__p,p_Var1);
  psVar2 = &(rea_bind(this_ptr)->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)rea_bind(&__z)->super__Rb_tree_node_base;
}
// @@@ END IDX 57
// @@@ BEGIN IDX 58 rea_SecInfo__find_data2
// ------------------------------------------------------------------
// IDX 58  00105290  SecInfo__find_data2
// ------------------------------------------------------------------
Data2 * rea_SecInfo__find_data2(SecInfo * this_ptr, int date) {
  rea_adr pp_Var1;
  int *piVar2;
  rea_v this_00;
  undefined *this_01;
  undefined *puVar3;
  int iVar4;
  rea_v p_Var5;
  rea_v __position;
  long long *plVar6;
  rea_v _Var7;
  FILE *__stream;
  size_t sVar8;
  void *pvVar9;
  rea_v p_Var10;
  rea_v p_Var11;
  rea_v p_Var12;
  rea_v p_Var13;
  ulong uVar14;
  rea_v pVar15;
  long long alStack_68 [2];
  long long alStack_58 [2];
  rea_v asStack_48 [3];
  
  this_01 = PTR_data_store2_00311f70;
  p_Var12 = *(_Base_ptr *)(PTR_data_store2_00311f70 + 0x10);
  if (p_Var12 == (_Base_ptr)0x0) {
LAB_00107720:
    rea___gnu_cxx____to_xstring_std__basic_string_char__char ((code *) alStack_68,(size_t)PTR_vsnprintf_00311fd0,(char *)0x10,(void *)&DAT_0010fc03,date);
    plVar6 = (long long *)rea_std__string__insert((ulong)alStack_68,(char *)0x0,0x10fc06);
    puVar3 = PTR__S_empty_rep_storage_00311ff0;
    alStack_58[0] = *plVar6;
    *plVar6 = (long long)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    plVar6 = (long long *)rea_std__string__append((char *)alStack_58,0x10fbfd);
    asStack_48[0]._M_dataplus._M_p = (_Alloc_hider)*plVar6;
    *plVar6 = (long long)(puVar3 + 0x18);
    _Var7 = rea_cast<_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_ >( rea_operator_new(0x18));
    *(int *)_Var7 = 0;
    *(int *)((long long)_Var7 + 4) = 0;
    ((int *)((long long)_Var7 + 8))[0] = 0;
    ((int *)((long long)_Var7 + 8))[1] = 0;
    ((int *)((long long)_Var7 + 0x10))[0] = 0;
    ((int *)((long long)_Var7 + 0x10))[1] = 0;
    __stream = rea_open_file((string*)rea_pv(asStack_48));
    if (__stream != (FILE *)0x0) {
      sVar8 = rea_fread((void *)_Var7,4,1,(FILE *)__stream);
      if ((sVar8 == 1) && (sVar8 = rea_fread((int *)((long long)_Var7 + 4),4,1,(FILE *)__stream), sVar8 == 1) ) {
        uVar14 = 0xffffffffffffffff;
        if ((ulong)(long long)*(int *)_Var7 < 0x550000000000001) {
          uVar14 = (long long)*(int *)_Var7 * 0x18;
        }
        pvVar9 = (void*)rea_pv(rea_operator_new(uVar14));
        *(void **)((long long)_Var7 + 8) = pvVar9;
        uVar14 = 0xffffffffffffffff;
        if ((ulong)(long long)*(int *)((long long)_Var7 + 4) < 0x1c4000000000001) {
          uVar14 = (long long)*(int *)((long long)_Var7 + 4) * 0x48;
        }
        pvVar9 = (void*)rea_pv(rea_operator_new(uVar14));
        *(void **)((long long)_Var7 + 0x10) = pvVar9;
        sVar8 = rea_fread(*(void **)((long long)_Var7 + 8),0x18,(long long)*(int *)_Var7,(FILE *)__stream);
        if ((sVar8 != (long long)*(int *)_Var7) || (sVar8 = rea_fread(*(void **)((long long)_Var7 + 0x10),0x48,(long long)*(int *)((long long)_Var7 + 4), (FILE *)__stream), sVar8 != (long long)*(int *)((long long)_Var7 + 4))) goto LAB_001077f4;
      }
      else {
LAB_001077f4:
        *(int *)_Var7 = 0;
        *(int *)((long long)_Var7 + 4) = 0;
        if (*(void **)((long long)_Var7 + 8) != (void *)0x0) {
          rea_operator_delete(*(void **)((long long)_Var7 + 8));
          ((int *)((long long)_Var7 + 8))[0] = 0;
          ((int *)((long long)_Var7 + 8))[1] = 0;
        }
        if (*(void **)((long long)_Var7 + 0x10) != (void *)0x0) {
          rea_operator_delete(*(void **)((long long)_Var7 + 0x10));
          ((int *)((long long)_Var7 + 0x10))[0] = 0;
          ((int *)((long long)_Var7 + 0x10))[1] = 0;
        }
      }
      rea_fclose((FILE *)__stream);
    }
    p_Var5 = rea_operator_new(0x30);
    if (p_Var5 != (_Link_type)0x0) {
      (p_Var5->_M_value_field).second._M_t. super__Tuple_impl = _Var7;
      (p_Var5->super__Rb_tree_node_base)._M_color = _S_red;
      _Var7 = (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
      (p_Var5->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
      (p_Var5->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
      (p_Var5->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
      (p_Var5->_M_value_field).first = date;
    }
    pVar15 = std_________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____________________M_get_insert_unique_pos________________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ *)this_01,&(p_Var5->_M_value_field).first);
    if (pVar15.second == (_Base_ptr)0x0) {
      this_00 = (p_Var5->_M_value_field).second._M_t. super__Tuple_impl;
      if (this_00 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
        rea_IndexedData_GIDKey__Item2__free((IndexedData_GIDKey__Item2 *)this_00);
        rea_operator_delete((void *)this_00);
      }
      (p_Var5->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
      rea_operator_delete(p_Var5);
    }
    else {
      std__________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2______________M_insert_node((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ *)this_01,pVar15.first,pVar15.second,p_Var5);
    }
    if (_Var7 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
      *(int *)_Var7 = 0;
      *(int *)((long long)_Var7 + 4) = 0;
      if (*(void **)((long long)_Var7 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var7 + 8));
        ((int *)((long long)_Var7 + 8))[0] = 0;
        ((int *)((long long)_Var7 + 8))[1] = 0;
      }
      if (*(void **)((long long)_Var7 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var7 + 0x10));
        ((int *)((long long)_Var7 + 0x10))[0] = 0;
        ((int *)((long long)_Var7 + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)_Var7);
    }
    if ((allocator *)((long long)asStack_48[0]._M_dataplus._M_p + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)((long long)asStack_48[0]._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
        iVar4 = *(int *)((long long)asStack_48[0]._M_dataplus._M_p + -8);
        *(int *)((long long)asStack_48[0]._M_dataplus._M_p + -8) = iVar4 + -1;
      }
      else {
        LOCK();
        iVar4 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar4 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long long)asStack_48[0]._M_dataplus._M_p + -0x18));
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
    if ((p_Var11 == (_Base_ptr)(PTR_data_store2_00311f70 + 8)) || (date < (int)p_Var11[1]._M_color)) goto LAB_00107720;
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
    if ((__position._M_node != (_Base_ptr)(this_01 + 8)) && ((int)__position._M_node[1]._M_color <= date)) goto LAB_00107703;
  }
  p_Var5 = rea_operator_new(0x30);
  if (p_Var5 != (_Link_type)0x0) {
    (p_Var5->super__Rb_tree_node_base)._M_color = _S_red;
    (p_Var5->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (p_Var5->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (p_Var5->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (p_Var5->_M_value_field).first = date;
    (p_Var5->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
  }
  pVar15 = std_______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2___________________M_get_insert_hint_unique_pos______________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ *)this_01,(const_iterator)__position._M_node,&(p_Var5->_M_value_field).first) ;
  __position._M_node = pVar15.first;
  if (pVar15.second == (_Base_ptr)0x0) {
    _Var7 = (p_Var5->_M_value_field).second._M_t. super__Tuple_impl;
    if (_Var7 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
      rea_IndexedData_GIDKey__Item2__free((IndexedData_GIDKey__Item2 *)_Var7);
      rea_operator_delete((void *)_Var7);
    }
    (p_Var5->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
    rea_operator_delete(p_Var5);
  }
  else {
    __position = std_____________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_________________________M_insert_node((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ *)this_01,__position._M_node,pVar15.second,p_Var5);
  }
LAB_00107703:
  return (Data2 *)__position._M_node[1]._M_parent;
}
// @@@ END IDX 58
// @@@ BEGIN IDX 60 rea_IndexedData_GroupKey__GroupForwardItem__free
// ------------------------------------------------------------------
// IDX 60  001052b0  IndexedData_GroupKey__GroupForwardItem__free
// ------------------------------------------------------------------
void rea_IndexedData_GroupKey__GroupForwardItem__free(IndexedData_GroupKey__GroupForwardItem * this_ptr) {
  rea_bind(this_ptr)->num_idxs = 0;
  rea_bind(this_ptr)->num_items = 0;
  if (rea_bind(this_ptr)->idxs != (Index *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->idxs);
    rea_bind(this_ptr)->idxs = (Index *)0x0;
  }
  if (rea_bind(this_ptr)->items != (GroupForwardItem *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->items);
    rea_bind(this_ptr)->items = (GroupForwardItem *)0x0;
  }
  return;
}
// @@@ END IDX 60
// @@@ BEGIN IDX 63 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2
// ------------------------------------------------------------------
// IDX 63  001052e0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____________
// ------------------------------------------------------------------
pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____bool rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr) {
  rea_v _Var1;
  rea_v __z;
  rea_adr in_RDX;
  int *in_RSI;
  rea_v pVar2;
  rea_v pVar3;
  rea_v pVar4;
  
  __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->_M_value_field).first = *in_RSI;
    _Var1 = *in_RDX;
    *in_RDX = (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0 ;
    (__z->_M_value_field).second._M_t. super__Tuple_impl = _Var1;
  }
  pVar2 = _M_get_insert_unique_pos(this_ptr,&(__z->_M_value_field).first);
  pVar4.first._M_node = pVar2.first;
  if (pVar2.second == (_Base_ptr)0x0) {
    _Var1 = (__z->_M_value_field).second._M_t. super__Tuple_impl;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_) 0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long long)_Var1 + 4) = 0;
      if (*(void **)((long long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 8));
        *(undefined8 *)((long long)_Var1 + 8) = 0;
      }
      if (*(void **)((long long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 0x10));
        *(undefined8 *)((long long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (__z->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
    rea_operator_delete(__z);
    (*(undefined8 *)((uint8_t *)&pVar4 + 0x8)) = 0;
    return pVar4;
  }
  pVar3.first._M_node = _M_insert_node(this_ptr,pVar4.first._M_node,pVar2.second,__z);
  (*(undefined8 *)((uint8_t *)&pVar3 + 0x8)) = 1;
  return pVar3;
}
// @@@ END IDX 63
// @@@ BEGIN IDX 65 rea_SecInfo__getPreClosePrice
// ------------------------------------------------------------------
// IDX 65  00105300  SecInfo__getPreClosePrice
// ------------------------------------------------------------------
double rea_SecInfo__getPreClosePrice(SecInfo * this_ptr, string * gid, int date) {
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  long long lVar5;
  int iVar6;
  size_t __n;
  long long lVar7;
  int *piVar8;
  long long lVar9;
  undefined1 auStack_68 [16];
  char acStack_58 [16];
  undefined8 uStack_48;
  
  piVar8 = *(int **)PTR_data_00311fc8;
  if (*(ulong *)(rea_bind((gid->_M_dataplus))._M_p + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar4 = rea_bind((gid->_M_dataplus))._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar4 + -0x18);
    }
    rea_memcpy(auStack_68,pcVar4,__n);
    lVar7 = (long long)*piVar8;
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
    if (((pcVar1 != pcVar4) && (iVar6 = rea_strcmp(pcVar4,acStack_58), iVar6 == 0)) && (pcVar4 != (char *)0x0)) {
      piVar8 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + (long long)*(int *)(pcVar4 + 0x10) * 0x18);
      piVar2 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + ((long long)*(int *)(pcVar4 + 0x10) + (long long)*(int *)(pcVar4 + 0x14)) * 0x18);
      for (lVar7 = ((long long)piVar2 - (long long)piVar8 >> 3) * -0x5555555555555555; 0 < lVar7;
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
  return (double)rea_iv(DAT_0010fd10);
}
// @@@ END IDX 65
// @@@ BEGIN IDX 66 rea_pinot_close
// ------------------------------------------------------------------
// IDX 66  00105310  pinot_close
// ------------------------------------------------------------------
void rea_pinot_close(void * fp) {
  long long *plVar1;
  
  if (fp == (void *)0x0) {
    return;
  }
  plVar1 = *(long long **)fp;
  if (pinot_reader_handle == (void *)0x0) {
    if (plVar1 != (long long *)0x0) {
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
// @@@ END IDX 66
// @@@ BEGIN IDX 69 rea_pinot_getline
// ------------------------------------------------------------------
// IDX 69  00105340  pinot_getline
// ------------------------------------------------------------------
pair_int__std__basic_string_char__std__char_traits_char__std__allocator_char__ rea_pinot_getline(void * fp) {
  long long *plVar1;
  undefined *puVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  rea_adr piVar6;
  undefined8 uVar7;
  rea_v extraout_RDX;
  rea_v extraout_RDX_00;
  rea_v bVar8;
  undefined8 *in_RSI;
  rea_v pVar9;
  rea_v asStack_38 [3];
  
  puVar2 = PTR__S_empty_rep_storage_00311ff0;
  asStack_38[0]._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
  if (pinot_reader_handle == (void *)0x0) {
    piVar6 = (istream *)*in_RSI;
    plVar1 = *(long long **)(piVar6 + *(long long *)(*(long long *)piVar6 + -0x18) + 0xf0);
    if (plVar1 == (long long *)0x0) {
      uVar7 = rea_std____throw_bad_cast();
      rea_std__string___Rep___M_dispose((allocator *)((long long)asStack_38[0]._M_dataplus._M_p + -0x18));
                    /* WARNING: Subroutine does not return */ rea__Unwind_Resume(uVar7);
    }
    if ((char)plVar1[7] == '\0') {
      rea_std__ctype_char___M_widen_init();
      cVar4 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
    }
    else {
      cVar4 = *(char *)((long long)plVar1 + 0x43);
    }
    piVar6 = rea_std__getline_char_std__char_traits_char_std__allocator_char(piVar6,(string*)rea_pv(asStack_38),cVar4) ;
    bVar3 = ((byte)piVar6[*(long long *)(*(long long *)piVar6 + -0x18) + 0x20] & 5) == 0;
  }
  else {
    bVar3 = (*pinot_reader_getline)((void *)*in_RSI,asStack_38);
  }
  *(uint *)fp = (uint)bVar3;
  rea_std__string__string((void *)((long long)fp + 8),asStack_38);
  bVar8._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)extraout_RDX._M_p;
  if ((allocator *)((long long)asStack_38[0]._M_dataplus._M_p + -0x18) != (allocator *)puVar2) {
    bVar8._M_dataplus._M_p = (_Alloc_hider)((long long)asStack_38[0]._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
      uVar5 = *(uint *)((long long)asStack_38[0]._M_dataplus._M_p + -8);
      bVar8._M_dataplus._M_p = (_Alloc_hider)(ulong)uVar5;
      *(uint *)((long long)asStack_38[0]._M_dataplus._M_p + -8) = uVar5 - 1;
    }
    else {
      LOCK();
      uVar5 = *(uint *)bVar8._M_dataplus._M_p;
      *(uint *)bVar8._M_dataplus._M_p = *(uint *)bVar8._M_dataplus._M_p - 1;
      UNLOCK();
    }
    if ((int)uVar5 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long long)asStack_38[0]._M_dataplus._M_p + -0x18));
      bVar8._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)extraout_RDX_00._M_p;
    }
  }
  pVar9.second._M_dataplus._M_p = bVar8._M_dataplus._M_p;
  (*(undefined8 *)((uint8_t *)&pVar9 + 0x0)) = (undefined8)rea_iv(fp);
  return pVar9;
}
// @@@ END IDX 69
// @@@ BEGIN IDX 70 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_hint_unique_pos
// ------------------------------------------------------------------
// IDX 70  00105350  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_hint_unique_pos(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, const_iterator __position, key_type * __k) {
  void *__s2;
  char *pcVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  rea_v cVar7;
  rea_v p_Var8;
  ulong uVar9;
  long long lVar10;
  rea_v pVar11;
  rea_v pVar12;
  
  if (rea_bind(__position)._M_node == &(rea_bind(this_ptr)->_M_impl)._M_header) {
    if ((rea_bind(this_ptr)->_M_impl)._M_node_count == 0) goto LAB_0010e000;
    rea_bind(__position)._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_right;
    pcVar1 = rea_bind((__k->_M_dataplus))._M_p;
    uVar2 = *(ulong *)(pcVar1 + -0x18);
    uVar3 = *(ulong *)((long long)*(void **)(rea_bind(__position)._M_node + 1) + -0x18);
    uVar9 = uVar3;
    if (uVar2 <= uVar3) {
      uVar9 = uVar2;
    }
    iVar5 = rea_memcmp(*(void **)(rea_bind(__position)._M_node + 1),pcVar1,uVar9);
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
  __s2 = *(void **)(rea_bind(__position)._M_node + 1);
  pcVar1 = rea_bind((__k->_M_dataplus))._M_p;
  uVar2 = *(ulong *)((long long)__s2 + -0x18);
  uVar3 = *(ulong *)(pcVar1 + -0x18);
  uVar9 = uVar3;
  if (uVar2 <= uVar3) {
    uVar9 = uVar2;
  }
  uVar4 = rea_memcmp(pcVar1,__s2,uVar9);
  uVar6 = (ulong)uVar4;
  cVar7._M_node = rea_bind(__position)._M_node;
  if (uVar4 == 0) {
    uVar6 = uVar3 - uVar2;
    if ((long long)uVar6 < 0x80000000) {
      if (-0x80000001 < (long long)uVar6) goto LAB_0010dfa0;
      goto LAB_0010df1c;
    }
  }
  else {
LAB_0010dfa0:
    if ((int)uVar6 < 0) {
LAB_0010df1c:
      if ((rea_bind(this_ptr)->_M_impl)._M_header._M_left != rea_bind(__position)._M_node) {
        p_Var8 = (_Base_ptr)rea_std___Rb_tree_decrement(rea_bind(__position)._M_node);
        uVar2 = *(ulong *)((long long)*(void **)(p_Var8 + 1) + -0x18);
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
            rea_bind(__position)._M_node = p_Var8;
            cVar7._M_node = (_Base_ptr)0x0;
          }
          pVar12.second = rea_bind(__position)._M_node;
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
      if ((rea_bind(this_ptr)->_M_impl)._M_header._M_right == rea_bind(__position)._M_node) goto LAB_0010e069;
      p_Var8 = (_Base_ptr)rea_std___Rb_tree_increment(rea_bind(__position)._M_node);
      uVar2 = *(ulong *)((long long)*(void **)(p_Var8 + 1) + -0x18);
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
      if ((rea_bind(__position)._M_node)->_M_right != (_Base_ptr)0x0) {
        cVar7._M_node = p_Var8;
        rea_bind(__position)._M_node = p_Var8;
      }
      goto LAB_0010deff;
    }
  }
  rea_bind(__position)._M_node = (_Base_ptr)0x0;
LAB_0010deff:
  pVar11.second = rea_bind(__position)._M_node;
  pVar11.first = cVar7._M_node;
  return pVar11;
}
// @@@ END IDX 70
// @@@ BEGIN IDX 73 rea_std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______pair
// ------------------------------------------------------------------
// IDX 73  00105380  std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______pair
// ------------------------------------------------------------------
void rea_std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______pair(pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__ * this_ptr, int __in_chrg) {
  int *piVar1;
  rea_v pdVar2;
  char *pcVar3;
  int iVar4;
  
  pdVar2 = rea_bind((this_ptr->second)).super__Vector_base_double__std__allocator_double_._M_impl._M_start;
  if (pdVar2 != (pointer)0x0) {
    rea_operator_delete(pdVar2);
  }
  pcVar3 = rea_bind((this_ptr->first))._M_dataplus._M_p;
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
// @@@ END IDX 73
// @@@ BEGIN IDX 74 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_unique_pos
// ------------------------------------------------------------------
// IDX 74  00105390  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_unique_pos(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, key_type * __k) {
  undefined1 auVar1 [16];
  bool bVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  rea_adr p_Var6;
  size_t __n;
  rea_adr p_Var7;
  ulong uVar8;
  long long lVar9;
  char *__s1;
  void *__s2;
  ulong uVar10;
  rea_v pVar11;
  
  p_Var6 = (rea_bind(this_ptr)->_M_impl)._M_header._M_parent;
  if (p_Var6 == (_Rb_tree_node_base *)0x0) {
    p_Var7 = &(rea_bind(this_ptr)->_M_impl)._M_header;
LAB_0010de00:
    if ((rea_bind(this_ptr)->_M_impl)._M_header._M_left == p_Var7) {
      p_Var6 = (_Rb_tree_node_base *)0x0;
      goto LAB_0010ddbd;
    }
    p_Var6 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var7);
    __s2 = *(void **)(p_Var6 + 1);
    __s1 = rea_bind((__k->_M_dataplus))._M_p;
    uVar8 = *(ulong *)((long long)__s2 + -0x18);
    uVar10 = *(ulong *)(__s1 + -0x18);
    __n = uVar10;
    if (uVar8 <= uVar10) {
      __n = uVar8;
    }
  }
  else {
    __s1 = rea_bind((__k->_M_dataplus))._M_p;
    uVar10 = *(ulong *)(__s1 + -0x18);
    do {
      p_Var7 = p_Var6;
      __s2 = *(void **)(p_Var7 + 1);
      uVar8 = *(ulong *)((long long)__s2 + -0x18);
      __n = uVar8;
      if (uVar10 <= uVar8) {
        __n = uVar10;
      }
      uVar3 = rea_memcmp(__s1,__s2,__n);
      uVar5 = (ulong)uVar3;
      if (uVar3 == 0) {
        uVar5 = uVar10 - uVar8;
        if ((long long)uVar5 < 0x80000000) {
          if (-0x80000001 < (long long)uVar5) goto LAB_0010dd40;
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
    } while (rea_bind(p_Var6) != (_Base_ptr)0x0);
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
      return (pair_std___Rb_tree_node_base___std___Rb_tree_node_base_)(rea_bind(auVar1) << 0x40);
    }
  }
  p_Var7 = (_Rb_tree_node_base *)0x0;
LAB_0010ddbd:
  pVar11.second = p_Var7;
  pVar11.first = p_Var6;
  return pVar11;
}
// @@@ END IDX 74
// @@@ BEGIN IDX 76 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_hint_unique_pos
// ------------------------------------------------------------------
// IDX 76  001053b0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_hint_unique_pos(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, const_iterator __position, key_type * __k) {
  int iVar1;
  rea_v p_Var2;
  rea_v cVar3;
  rea_v cVar4;
  rea_v pVar5;
  rea_v pVar6;
  rea_v pVar7;
  
  if (rea_bind(__position)._M_node == &(rea_bind(this_ptr)->_M_impl)._M_header) {
    if (((rea_bind(this_ptr)->_M_impl)._M_node_count == 0) || (cVar3._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_right, rea_bind(*__k) <= (int)cVar3._M_node[1]._M_color)) {
LAB_0010db08:
      pVar7 = _M_get_insert_unique_pos(this_ptr,__k);
      return pVar7;
    }
  }
  else {
    iVar1 = (int)rea_iv(*__k);
    if (iVar1 < rea_bind((int)__position)._M_node[1]._M_color) {
      cVar4._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_left;
      cVar3._M_node = cVar4._M_node;
      if (cVar4._M_node != rea_bind(__position)._M_node) {
        cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_decrement(rea_bind(__position)._M_node);
        if (iVar1 <= (int)cVar3._M_node[1]._M_color) goto LAB_0010db08;
        cVar4._M_node = (_Base_ptr)0x0;
        if ((cVar3._M_node)->_M_right != (_Base_ptr)0x0) {
          cVar4._M_node = rea_bind(__position)._M_node;
          cVar3._M_node = rea_bind(__position)._M_node;
        }
      }
      goto LAB_0010daa5;
    }
    if (iVar1 <= rea_bind((int)__position)._M_node[1]._M_color) {
      pVar7.second = (_Rb_tree_node_base *)0x0;
      pVar7.first = rea_bind(__position)._M_node;
      return pVar7;
    }
    cVar3._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_right;
    if (cVar3._M_node != rea_bind(__position)._M_node) {
      cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_increment(rea_bind(__position)._M_node);
      if (iVar1 < (int)cVar3._M_node[1]._M_color) {
        p_Var2 = cVar3._M_node;
        if ((rea_bind(__position)._M_node)->_M_right == (_Base_ptr)0x0) {
          cVar3._M_node = rea_bind(__position)._M_node;
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
// @@@ END IDX 76
// @@@ BEGIN IDX 78 rea_std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______M_emplace_back_aux_const_std__basic_string_char__std__char_traits_char__std__allocator_char
// ------------------------------------------------------------------
// IDX 78  001053d0  std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______M_emplace_back_aux_const_std__basic_string_char__std__char_traits_char__std__allocator_char_____________
// ------------------------------------------------------------------
void rea_std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______M_emplace_back_aux_const_std__basic_string_char__std__char_traits_char__std__allocator_char(vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___ * this_ptr) {
  char *pcVar1;
  int *piVar2;
  undefined *puVar3;
  ulong uVar4;
  int iVar5;
  ulong uVar6;
  rea_v pbVar7;
  void *this_00;
  rea_v pbVar8;
  rea_v pbVar9;
  rea_v pbVar10;
  rea_adr in_RSI;
  rea_v pbVar11;
  ulong uVar12;
  rea_v pbVar13;
  
  uVar6 = (long long)(rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_finish - (long long)(rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start >> 3;
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
  pbVar13 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_finish;
  pbVar11 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start;
  this_00 = (void *)((long long)&(pbVar7->_M_dataplus)._M_p + ((long long)pbVar13 - (long long)pbVar11 & 0xfffffffffffffff8U));
  if (this_00 != (void *)0x0) {
    rea_std__string__string(this_00,in_RSI);
    pbVar13 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_finish;
    pbVar11 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start;
  }
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
  if (pbVar11 == pbVar13) {
    pbVar8 = pbVar7 + 1;
  }
  else {
    pcVar1 = (char*)rea_pv(PTR__S_empty_rep_storage_00311ff0 + 0x18);
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
    pbVar8 = (pointer)((long long)&pbVar7[2]._M_dataplus._M_p + ((long long)pbVar13 - (long long)(pbVar11 + 1) & 0xfffffffffffffff8U));
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
    pbVar11 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start;
  }
  if (pbVar11 != (pointer)0x0) {
    rea_operator_delete(pbVar11);
  }
  (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start = pbVar7;
  (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_finish = pbVar8;
  (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_end_of_storage = pbVar7 + uVar12;
  return;
}
// @@@ END IDX 78
// @@@ BEGIN IDX 79 rea_detail__P_std__basic_string_char__std__char_traits_char__std__allocator_char____parse
// ------------------------------------------------------------------
// IDX 79  001053e0  detail__P_std__basic_string_char__std__char_traits_char__std__allocator_char____parse__________________
// ------------------------------------------------------------------
size_t rea_detail__P_std__basic_string_char__std__char_traits_char__std__allocator_char____parse(vector_unsigned_char__std__allocator_unsigned_char_ * b, size_t p, string * ps) {
  ulong uVar1;
  int iVar2;
  ulong *puVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  rea_adr paVar7;
  rea_v puVar8;
  rea_v aStack_49;
  ulong *apuStack_48 [3];
  
  uVar5 = p + 8;
  puVar8 = rea_bind((b->super__Vector_base))._M_impl._M_start;
  uVar6 = rea_bind((long long)(b->super__Vector_base))._M_impl. _M_finish - (long long)puVar8;
  if (uVar5 <= uVar6) {
    rea_memcpy(apuStack_48,puVar8 + p,8);
    uVar1 = uVar5 + (long long)apuStack_48[0];
    if (uVar1 <= uVar6) {
      if (ps != (string *)0x0) {
        puVar8 = puVar8 + uVar5;
        if (puVar8 == puVar8 + (long long)apuStack_48[0]) {
          apuStack_48[0] = (ulong *)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
          paVar7 = (allocator *)PTR__S_empty_rep_storage_00311ff0;
        }
        else {
          uVar6 = (long long)(puVar8 + (long long)apuStack_48[0]) - (long long)puVar8;
          puVar3 = (ulong *)rea_std__string___Rep___S_create(uVar6,0,&aStack_49);
          apuStack_48[0] = puVar3 + 3;
          uVar5 = 0;
          do {
            uVar4 = uVar5;
            *(uchar *)((long long)apuStack_48[0] + uVar4) = puVar8[uVar4];
            paVar7 = (allocator *)PTR__S_empty_rep_storage_00311ff0;
            uVar5 = uVar4 + 1;
          } while (uVar5 != uVar6);
          if (puVar3 != (ulong *)PTR__S_empty_rep_storage_00311ff0) {
            *(undefined4 *)(puVar3 + 2) = 0;
            *puVar3 = uVar5;
            *(undefined1 *)((long long)puVar3 + uVar4 + 0x19) = 0;
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
// @@@ END IDX 79
// @@@ BEGIN IDX 80 rea_std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char_______pair
// ------------------------------------------------------------------
// IDX 80  001053f0  std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char_______pair
// ------------------------------------------------------------------
void rea_std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char_______pair(pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___ * this_ptr, int __in_chrg) {
  int *piVar1;
  char *pcVar2;
  undefined *puVar3;
  int iVar4;
  rea_v pbVar5;
  rea_v pbVar6;
  
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
  pcVar2 = (rea_bind(this_ptr)->second).second._M_dataplus._M_p;
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
  pbVar6 = (rea_bind(this_ptr)->second).first. super__Vector_base ._M_impl._M_finish;
  pbVar5 = (rea_bind(this_ptr)->second).first. super__Vector_base ._M_impl._M_start;
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
    pbVar6 = (rea_bind(this_ptr)->second).first. super__Vector_base ._M_impl._M_start;
  }
  if (pbVar6 != (pointer)0x0) {
    rea_operator_delete(pbVar6);
  }
  pcVar2 = (rea_bind(this_ptr)->first)._M_dataplus._M_p;
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
// @@@ END IDX 80
// @@@ BEGIN IDX 83 rea_std___vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double_______vector
// ------------------------------------------------------------------
// IDX 83  00105420  std___vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double_______vector
// ------------------------------------------------------------------
void rea_std___vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double_______vector(vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double___ * this_ptr, int __in_chrg) {
  rea_v pdVar1;
  rea_v pvVar2;
  rea_v pvVar3;
  
  pvVar3 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_finish;
  pvVar2 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start;
  if (pvVar3 != pvVar2) {
    do {
      pdVar1 = (pvVar2->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
      if (pdVar1 != (pointer)0x0) {
        rea_operator_delete(pdVar1);
      }
      pvVar2 = pvVar2 + 1;
    } while (pvVar3 != pvVar2);
    pvVar3 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start;
  }
  if (pvVar3 == (pointer)0x0) {
    return;
  }
  rea_operator_delete(pvVar3);
  return;
}
// @@@ END IDX 83
// @@@ BEGIN IDX 88 rea_IndexedData_GIDKey__Item2__free
// ------------------------------------------------------------------
// IDX 88  00105470  IndexedData_GIDKey__Item2__free
// ------------------------------------------------------------------
void rea_IndexedData_GIDKey__Item2__free(IndexedData_GIDKey__Item2 * this_ptr) {
  rea_bind(this_ptr)->num_idxs = 0;
  rea_bind(this_ptr)->num_items = 0;
  if (rea_bind(this_ptr)->idxs != (Index *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->idxs);
    rea_bind(this_ptr)->idxs = (Index *)0x0;
  }
  if (rea_bind(this_ptr)->items != (Item2 *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->items);
    rea_bind(this_ptr)->items = (Item2 *)0x0;
  }
  return;
}
// @@@ END IDX 88
// @@@ BEGIN IDX 92 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_______find
// ------------------------------------------------------------------
// IDX 92  001054b0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_______find
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_______find(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, int * __k) {
  rea_adr p_Var1;
  rea_adr pp_Var2;
  rea_v p_Var3;
  rea_v p_Var4;
  rea_v iVar5;
  
  p_Var3 = (rea_bind(this_ptr)->_M_impl)._M_header._M_parent;
  p_Var1 = &(rea_bind(this_ptr)->_M_impl)._M_header;
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
// @@@ END IDX 92
// @@@ BEGIN IDX 93 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_erase
// ------------------------------------------------------------------
// IDX 93  001054c0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_erase(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, _Link_type __x) {
  rea_v _Var1;
  rea_v p_Var2;
  
  while (rea_bind(__x) != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_right);
    _Var1 = (rea_bind(__x)->_M_value_field).second._M_t. super__Tuple_impl;
    p_Var2 = (_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_left;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_) 0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long long)_Var1 + 4) = 0;
      if (*(void **)((long long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 8));
        *(undefined8 *)((long long)_Var1 + 8) = 0;
      }
      if (*(void **)((long long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 0x10));
        *(undefined8 *)((long long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (rea_bind(__x)->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
    rea_operator_delete(__x);
    __x = p_Var2;
  }
  return;
}
// @@@ END IDX 93
// @@@ BEGIN IDX 103 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_____find
// ------------------------------------------------------------------
// IDX 103  00105560  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_____find
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_____find(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, basic_string_char__std__char_traits_char__std__allocator_char_ * __k) {
  rea_adr p_Var1;
  rea_adr pp_Var2;
  rea_v p_Var3;
  char *__s2;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  ulong uVar7;
  long long lVar8;
  rea_v p_Var9;
  rea_v p_Var10;
  
  p_Var1 = &(rea_bind(this_ptr)->_M_impl)._M_header;
  p_Var3 = (rea_bind(this_ptr)->_M_impl)._M_header._M_parent;
  if (p_Var3 != (_Base_ptr)0x0) {
    __s2 = rea_bind((__k->_M_dataplus))._M_p;
    uVar4 = *(ulong *)(__s2 + -0x18);
    p_Var9 = p_Var1;
    do {
      while( true ) {
        p_Var10 = p_Var3;
        uVar5 = *(ulong *)((long long)*(void **)(p_Var10 + 1) + -0x18);
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
    uVar5 = *(ulong *)((long long)*(void **)(p_Var10 + 1) + -0x18);
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
// @@@ END IDX 103
// @@@ BEGIN IDX 104 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_hint_unique_pos
// ------------------------------------------------------------------
// IDX 104  00105570  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_hint_unique_pos(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, const_iterator __position, key_type * __k) {
  int iVar1;
  rea_v p_Var2;
  rea_v cVar3;
  rea_v cVar4;
  rea_v pVar5;
  rea_v pVar6;
  rea_v pVar7;
  
  if (rea_bind(__position)._M_node == &(rea_bind(this_ptr)->_M_impl)._M_header) {
    if (((rea_bind(this_ptr)->_M_impl)._M_node_count == 0) || (cVar3._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_right, rea_bind(*__k) <= (int)cVar3._M_node[1]._M_color)) {
LAB_0010d528:
      pVar7 = _M_get_insert_unique_pos(this_ptr,__k);
      return pVar7;
    }
  }
  else {
    iVar1 = (int)rea_iv(*__k);
    if (iVar1 < rea_bind((int)__position)._M_node[1]._M_color) {
      cVar4._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_left;
      cVar3._M_node = cVar4._M_node;
      if (cVar4._M_node != rea_bind(__position)._M_node) {
        cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_decrement(rea_bind(__position)._M_node);
        if (iVar1 <= (int)cVar3._M_node[1]._M_color) goto LAB_0010d528;
        cVar4._M_node = (_Base_ptr)0x0;
        if ((cVar3._M_node)->_M_right != (_Base_ptr)0x0) {
          cVar4._M_node = rea_bind(__position)._M_node;
          cVar3._M_node = rea_bind(__position)._M_node;
        }
      }
      goto LAB_0010d4c5;
    }
    if (iVar1 <= rea_bind((int)__position)._M_node[1]._M_color) {
      pVar7.second = (_Rb_tree_node_base *)0x0;
      pVar7.first = rea_bind(__position)._M_node;
      return pVar7;
    }
    cVar3._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_right;
    if (cVar3._M_node != rea_bind(__position)._M_node) {
      cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_increment(rea_bind(__position)._M_node);
      if (iVar1 < (int)cVar3._M_node[1]._M_color) {
        p_Var2 = cVar3._M_node;
        if ((rea_bind(__position)._M_node)->_M_right == (_Base_ptr)0x0) {
          cVar3._M_node = rea_bind(__position)._M_node;
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
// @@@ END IDX 104
// @@@ BEGIN IDX 105 rea_std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______vector
// ------------------------------------------------------------------
// IDX 105  00105580  std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______vector
// ------------------------------------------------------------------
void rea_std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______vector(vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___ * this_ptr, int __in_chrg) {
  int *piVar1;
  char *pcVar2;
  undefined *puVar3;
  int iVar4;
  rea_v pbVar5;
  rea_v pbVar6;
  
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
  pbVar6 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_finish;
  pbVar5 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start;
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
    pbVar6 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start;
  }
  if (pbVar6 != (pointer)0x0) {
    rea_operator_delete(pbVar6);
  }
  return;
}
// @@@ END IDX 105
// @@@ BEGIN IDX 106 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_erase
// ------------------------------------------------------------------
// IDX 106  00105590  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_erase(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * this_ptr, _Link_type __x) {
  int *piVar1;
  rea_v pdVar2;
  rea_v p_Var3;
  char *pcVar4;
  undefined *puVar5;
  int iVar6;
  
  puVar5 = PTR__S_empty_rep_storage_00311ff0;
  while (rea_bind(__x) != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_right);
    pdVar2 = (rea_bind(__x)->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_start;
    p_Var3 = (_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_left;
    if (pdVar2 != (pointer)0x0) {
      rea_operator_delete(pdVar2);
    }
    pcVar4 = (rea_bind(__x)->_M_value_field).first._M_dataplus._M_p;
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
// @@@ END IDX 106
// @@@ BEGIN IDX 114 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_hint_unique_pos
// ------------------------------------------------------------------
// IDX 114  00105610  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_hint_unique_pos(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, const_iterator __position, key_type * __k) {
  int iVar1;
  rea_v p_Var2;
  rea_v cVar3;
  rea_v cVar4;
  rea_v pVar5;
  rea_v pVar6;
  rea_v pVar7;
  
  if (rea_bind(__position)._M_node == &(rea_bind(this_ptr)->_M_impl)._M_header) {
    if (((rea_bind(this_ptr)->_M_impl)._M_node_count == 0) || (cVar3._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_right, rea_bind(*__k) <= (int)cVar3._M_node[1]._M_color)) {
LAB_0010da18:
      pVar7 = _M_get_insert_unique_pos(this_ptr,__k);
      return pVar7;
    }
  }
  else {
    iVar1 = (int)rea_iv(*__k);
    if (iVar1 < rea_bind((int)__position)._M_node[1]._M_color) {
      cVar4._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_left;
      cVar3._M_node = cVar4._M_node;
      if (cVar4._M_node != rea_bind(__position)._M_node) {
        cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_decrement(rea_bind(__position)._M_node);
        if (iVar1 <= (int)cVar3._M_node[1]._M_color) goto LAB_0010da18;
        cVar4._M_node = (_Base_ptr)0x0;
        if ((cVar3._M_node)->_M_right != (_Base_ptr)0x0) {
          cVar4._M_node = rea_bind(__position)._M_node;
          cVar3._M_node = rea_bind(__position)._M_node;
        }
      }
      goto LAB_0010d9b5;
    }
    if (iVar1 <= rea_bind((int)__position)._M_node[1]._M_color) {
      pVar7.second = (_Rb_tree_node_base *)0x0;
      pVar7.first = rea_bind(__position)._M_node;
      return pVar7;
    }
    cVar3._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_right;
    if (cVar3._M_node != rea_bind(__position)._M_node) {
      cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_increment(rea_bind(__position)._M_node);
      if (iVar1 < (int)cVar3._M_node[1]._M_color) {
        p_Var2 = cVar3._M_node;
        if ((rea_bind(__position)._M_node)->_M_right == (_Base_ptr)0x0) {
          cVar3._M_node = rea_bind(__position)._M_node;
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
// @@@ END IDX 114
// @@@ BEGIN IDX 115 rea_SecInfo__SecInfo
// ------------------------------------------------------------------
// IDX 115  00105620  SecInfo__SecInfo
// ------------------------------------------------------------------
void rea_SecInfo__SecInfo(SecInfo * this_ptr) {
  undefined4 *puVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  FILE *__stream;
  size_t sVar5;
  void *pvVar6;
  ulong uVar7;
  rea_v aaStack_3a [2];
  rea_v asStack_38 [3];
  
  puVar2 = (undefined*)rea_pv(PTR_data_00311fc8);
  if (*(long long *)PTR_data_00311fc8 != 0) goto LAB_0010728a;
  rea_std__string__string(asStack_38,"SecInfo.dump",aaStack_3a);
  piVar4 = (int*)rea_pv(rea_operator_new(0x18));
  *piVar4 = 0;
  piVar4[1] = 0;
  piVar4[2] = 0;
  piVar4[3] = 0;
  piVar4[4] = 0;
  piVar4[5] = 0;
  __stream = rea_open_file((string*)rea_pv(asStack_38));
  if (__stream != (FILE *)0x0) {
    sVar5 = rea_fread(piVar4,4,1,(FILE *)__stream);
    if ((sVar5 == 1) && (sVar5 = rea_fread(piVar4 + 1,4,1,(FILE *)__stream), sVar5 == 1)) {
      uVar7 = 0xffffffffffffffff;
      if ((ulong)(long long)*piVar4 < 0x550000000000001) {
        uVar7 = (long long)*piVar4 * 0x18;
      }
      pvVar6 = (void*)rea_pv(rea_operator_new(uVar7));
      *(void **)(piVar4 + 2) = pvVar6;
      uVar7 = 0xffffffffffffffff;
      if ((ulong)(long long)piVar4[1] < 0x550000000000001) {
        uVar7 = (long long)piVar4[1] * 0x18;
      }
      pvVar6 = (void*)rea_pv(rea_operator_new(uVar7));
      *(void **)(piVar4 + 4) = pvVar6;
      sVar5 = rea_fread(*(void **)(piVar4 + 2),0x18,(long long)*piVar4,(FILE *)__stream);
      if ((sVar5 != (long long)*piVar4) || (sVar5 = rea_fread(*(void **)(piVar4 + 4),0x18,(long long)piVar4[1],(FILE *)__stream), sVar5 != (long long)piVar4[1])) goto LAB_00107312;
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
  if ((allocator *)((long long)asStack_38[0]._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar4 = (int *)((long long)asStack_38[0]._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
      iVar3 = *(int *)((long long)asStack_38[0]._M_dataplus._M_p + -8);
      *(int *)((long long)asStack_38[0]._M_dataplus._M_p + -8) = iVar3 + -1;
    }
    else {
      LOCK();
      iVar3 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
    }
    if (iVar3 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long long)asStack_38[0]._M_dataplus._M_p + -0x18));
    }
  }
LAB_0010728a:
  rea_bind(this_ptr)->no_check = false;
  return;
}
// @@@ END IDX 115
// @@@ BEGIN IDX 116 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_copy
// ------------------------------------------------------------------
// IDX 116  00105630  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_copy
// ------------------------------------------------------------------
_Link_type rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_copy(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, _Const_Link_type __x, _Link_type __p) {
  _Rb_tree_color _Var1;
  rea_v p_Var2;
  rea_v p_Var3;
  rea_v __p_00;
  rea_v p_Var4;
  rea_v __p_01;
  
  __p_00 = rea_operator_new(0x30);
  if (__p_00 != (_Link_type)0x0) {
    (__p_00->super__Rb_tree_node_base)._M_color = _S_red;
    (__p_00->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    rea_std__string__string(&__p_00->_M_value_field,&(rea_bind(__x)->_M_value_field).first);
    (__p_00->_M_value_field).second = (rea_bind(__x)->_M_value_field).second;
  }
  _Var1 = (rea_bind(__x)->super__Rb_tree_node_base)._M_color;
  (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
  p_Var2 = (_Const_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_right;
  (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
  (__p_00->super__Rb_tree_node_base)._M_parent = rea_bind(&__p)->super__Rb_tree_node_base;
  (__p_00->super__Rb_tree_node_base)._M_color = _Var1;
  if (p_Var2 != (_Const_Link_type)0x0) {
    p_Var4 = _M_copy(this_ptr,p_Var2,__p_00);
    (__p_00->super__Rb_tree_node_base)._M_right = &p_Var4->super__Rb_tree_node_base;
  }
  p_Var4 = __p_00;
  for (p_Var3 = (rea_bind(__x)->super__Rb_tree_node_base)._M_left; p_Var3 != (_Base_ptr)0x0;
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
// @@@ END IDX 116
// @@@ BEGIN IDX 117 rea___gnu_cxx____to_xstring_std__basic_string_char__char
// ------------------------------------------------------------------
// IDX 117  00105640  __gnu_cxx____to_xstring_std__basic_string_char__char
// ------------------------------------------------------------------
basic_string_char__std__char_traits_char__std__allocator_char_ rea___gnu_cxx____to_xstring_std__basic_string_char__char(code * __convf, size_t __n, char * __fmt, undefined8 param_x3) {
  undefined8 stack0x00000008;
  undefined1 *__src;
  long long lVar1;
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
  rea_v aStack_f1;
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
  puStack_e8 = (undefined1*)rea_pv((void *)&stack0x00000008);
  lVar1 = -((ulong)(__fmt + 0x1e) & 0xfffffffffffffff0);
  puStack_e0 = auStack_d8;
  __src = (undefined1 *)((long long)&uStack_f0 + lVar1);
  uStack_f0 = 0x20;
  uStack_ec = 0x30;
  uStack_b8 = in_R8;
  uStack_b0 = in_R9;
  *(undefined8 *)((long long)&uStack_100 + lVar1) = 0x10c604;
  iVar2 = (*(code *)__n)(__src,__fmt,in_RCX,&uStack_f0);
  if (__src == __src + iVar2) {
    __dest = (ulong *)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
  }
  else {
    __n_00 = (long long)(__src + iVar2) - (long long)__src;
    *(undefined8 *)((long long)&uStack_100 + lVar1) = 0x10c623;
    puVar3 = (ulong *)rea_std__string___Rep___S_create(__n_00,0,&aStack_f1);
    __dest = puVar3 + 3;
    if (__n_00 == 1) {
      *(undefined1 *)(puVar3 + 3) = *__src;
    }
    else {
      *(undefined8 *)((long long)&uStack_100 + lVar1) = 0x10c63e;
      __dest = (ulong*)rea_pv(rea_memcpy(__dest,__src,__n_00));
    }
    if (puVar3 != (ulong *)PTR__S_empty_rep_storage_00311ff0) {
      *(undefined4 *)(puVar3 + 2) = 0;
      *puVar3 = __n_00;
      *(undefined1 *)((long long)puVar3 + __n_00 + 0x18) = 0;
    }
  }
  *(ulong **)__convf = __dest;
  return (basic_string_char__std__char_traits_char__std__allocator_char_)(_Alloc_hider)__convf;
}
// @@@ END IDX 117
// @@@ BEGIN IDX 125 rea___do_global_dtors_aux
// ------------------------------------------------------------------
// IDX 125  00105850  __do_global_dtors_aux
// ------------------------------------------------------------------
void rea___do_global_dtors_aux(void) {
  if (completed_6355 == '\0') {
    if (rea_bind(PTR___cxa_finalize_00311fb8) != (undefined *)0x0) {
      rea___cxa_finalize((void *)&__dso_handle);
    }
    rea_deregister_tm_clones();
    completed_6355 = '\x01';
  }
  return;
}
// @@@ END IDX 125
// @@@ BEGIN IDX 126 rea_frame_dummy
// ------------------------------------------------------------------
// IDX 126  00105890  frame_dummy
// ------------------------------------------------------------------
void rea_frame_dummy(void) {
  if ((__JCR_END__ != 0) && (rea_bind(PTR__Jv_RegisterClasses_00311f80) != (undefined *)0x0)) {
    (*(code *)PTR__Jv_RegisterClasses_00311f80)((void *)&__JCR_END__);
    rea_register_tm_clones();
    return;
  }
  rea_register_tm_clones();
  return;
}
// @@@ END IDX 126
// @@@ BEGIN IDX 127 rea_open_file
// ------------------------------------------------------------------
// IDX 127  001058d0  open_file
// ------------------------------------------------------------------
FILE * rea_open_file(string * path) {
  int *piVar1;
  char *pcVar2;
  long long *plVar3;
  FILE *pFVar4;
  int iVar5;
  rea_adr paVar6;
  rea_v local_4a [2];
  long long local_48 [2];
  rea_v local_38 [3];
  
                    /* Unresolved local var: char * prefix@[???] Unresolved local var: FILE * fp@[???] */ pcVar2 = rea_getenv("SECINFO_PREFIX");
  paVar6 = (allocator *)PTR__S_empty_rep_storage_00311ff0;
  if (pcVar2 != (char *)0x0) {
    rea_std__string__string(local_48,pcVar2,local_4a);
    plVar3 = (long long *)rea_std__string__append((char *)local_48,0x10fb8d);
    paVar6 = (allocator *)PTR__S_empty_rep_storage_00311ff0;
    local_38[0]._M_dataplus._M_p = (_Alloc_hider)*plVar3;
    *plVar3 = (long long)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    plVar3 = (long long *)rea_std__string__append(local_38);
    pcVar2 = (char *)*plVar3;
    *plVar3 = (long long)(paVar6 + 0x18);
    pFVar4 = rea_fopen(pcVar2,"rb");
    if ((allocator *)(pcVar2 + -0x18) != paVar6) {
      piVar1 = (int *)(pcVar2 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar5 = *(int *)(pcVar2 + -8);
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
    if ((allocator *)((long long)local_38[0]._M_dataplus._M_p + -0x18) != paVar6) {
      piVar1 = (int *)((long long)local_38[0]._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar5 = *(int *)((long long)local_38[0]._M_dataplus._M_p + -8);
        *(int *)((long long)local_38[0]._M_dataplus._M_p + -8) = iVar5 + -1;
      }
      else {
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar5 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long long)local_38[0]._M_dataplus._M_p + -0x18));
      }
    }
    if ((allocator *)(local_48[0] + -0x18) != paVar6) {
      piVar1 = (int *)(local_48[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar5 = *(int *)(local_48[0] + -8);
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
                    /* Unresolved local var: __size_type __len@[???] Unresolved local var: __string_type __str@[???] */ local_38[0]._M_dataplus._M_p = (_Alloc_hider)(paVar6 + 0x18);
  rea_std__string__reserve((ulong)local_38);
  rea_std__string__append((char *)local_38,0x10fb7a);
  rea_std__string__append(local_38);
  pFVar4 = rea_fopen((char *)local_38[0]._M_dataplus._M_p,"rb");
  if ((allocator *)((long long)local_38[0]._M_dataplus._M_p + -0x18) != paVar6) {
    paVar6 = (allocator *)((long long)local_38[0]._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg2(RCX)] */ iVar5 = *(int *)((long long)local_38[0]._M_dataplus._M_p + -8);
      *(int *)((long long)local_38[0]._M_dataplus._M_p + -8) = iVar5 + -1;
    }
    else {
      LOCK();
      iVar5 = *(int *)paVar6;
      *(int *)paVar6 = *(int *)paVar6 + -1;
      UNLOCK();
    }
    if (iVar5 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long long)local_38[0]._M_dataplus._M_p + -0x18));
    }
  }
  return (FILE *)pFVar4;
}
// @@@ END IDX 127
// @@@ BEGIN IDX 128 rea_SecInfo__getPreClosePrice__dup2
// ------------------------------------------------------------------
// IDX 128  00105bb0  SecInfo__getPreClosePrice
// ------------------------------------------------------------------
double rea_SecInfo__getPreClosePrice__dup2(SecInfo * this_ptr, string * gid, int date) {
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  long long lVar5;
  int iVar6;
  size_t __n;
  long long lVar7;
  int *piVar8;
  long long lVar9;
  rea_v key;
  rea_v idx;
  
                    /* Unresolved local var: Index * idx@[???] */ piVar8 = *(int **)PTR_data_00311fc8;
                    /* Unresolved local var: ulong pos@[???] */ if (*(ulong *)(rea_bind((gid->_M_dataplus))._M_p + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar4 = rea_bind((gid->_M_dataplus))._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar4 + -0x18);
    }
    rea_memcpy(&key,pcVar4,__n);
    lVar7 = (long long)*piVar8;
    key.gid[__n] = '\0';
                    /* Unresolved local var: Index * it@[???] */ pcVar4 = *(char **)(piVar8 + 2);
    idx.start = 0;
    idx.size = 0;
                    /* Unresolved local var: _DistanceType __len@[???] */ pcVar1 = pcVar4 + lVar7 * 0x18;
    for (; 0 < lVar7; lVar7 = (lVar7 - lVar9) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Index * __middle@[???] */ lVar9 = lVar7 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */ iVar6 = rea_strcmp(pcVar4 + lVar9 * 0x18,(char *)&idx);
        if (iVar6 < 0) break;
        lVar7 = lVar9;
        if (lVar9 == 0) goto LAB_00105cab;
      }
      pcVar4 = pcVar4 + lVar9 * 0x18 + 0x18;
    }
LAB_00105cab:
    if (((pcVar1 != pcVar4) && (iVar6 = rea_strcmp(pcVar4,(char *)&idx), iVar6 == 0)) && (pcVar4 != (char *)0x0)) {
                    /* Unresolved local var: Item * item@[???] Unresolved local var: Item key@[???] Unresolved local var: Item * begin@[???] Unresolved local var: Item * end@[???] Unresolved local var: Item * it@[???] */ piVar8 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + (long long)*(int *)(pcVar4 + 0x10) * 0x18);
      piVar2 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + ((long long)*(int *)(pcVar4 + 0x10) + (long long)*(int *)(pcVar4 + 0x14)) * 0x18);
                    /* Unresolved local var: _DistanceType __len@[???] */ for (lVar7 = ((long long)piVar2 - (long long)piVar8 >> 3) * -0x5555555555555555; 0 < lVar7;
          lVar7 = (lVar7 - lVar5) + -1) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Item * __middle@[???] */ /* Unresolved local var: difference_type __d@[???] */ piVar3 = piVar8 + (lVar7 >> 1) * 6;
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
  return (double)rea_iv(DAT_0010fd10);
}
// @@@ END IDX 128
// @@@ BEGIN IDX 129 rea_SecInfo__getLastClosePrice__dup2
// ------------------------------------------------------------------
// IDX 129  00105db0  SecInfo__getLastClosePrice
// ------------------------------------------------------------------
double rea_SecInfo__getLastClosePrice__dup2(SecInfo * this_ptr, string * gid, int date) {
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  long long lVar4;
  int iVar5;
  size_t __n;
  long long lVar6;
  int *piVar7;
  char *pcVar8;
  long long lVar9;
  double dVar10;
  rea_v key;
  rea_v idx;
  
                    /* Unresolved local var: double preclose@[???] */ dVar10 = rea_getPreClosePrice(this_ptr,gid,date);
                    /* Unresolved local var: Index * idx@[???] */ /* Unresolved local var: ulong pos@[???] */ if ((NAN(dVar10)) && (piVar7 = *(int **)PTR_data_00311fc8, dVar10 = (double)rea_iv(DAT_0010fd10), *(ulong *)(rea_bind((gid->_M_dataplus))._M_p + -0x18) < 0x10)) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar8 = rea_bind((gid->_M_dataplus))._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar8 + -0x18);
    }
    rea_memcpy(&key,pcVar8,__n);
    lVar6 = (long long)*piVar7;
    key.gid[__n] = '\0';
                    /* Unresolved local var: Index * it@[???] */ pcVar8 = *(char **)(piVar7 + 2);
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
                    /* Unresolved local var: _DistanceType __len@[???] */ idx.key.gid[8] = key.gid[8];
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
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Index * __middle@[???] */ lVar9 = lVar6 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */ iVar5 = rea_strcmp(pcVar8 + lVar9 * 0x18,(char *)&idx);
        if (iVar5 < 0) break;
        lVar6 = lVar9;
        if (lVar9 == 0) goto LAB_00105ec0;
      }
      pcVar8 = pcVar8 + lVar9 * 0x18 + 0x18;
    }
LAB_00105ec0:
    dVar10 = (double)rea_iv(DAT_0010fd10);
    if (((pcVar1 != pcVar8) && (iVar5 = rea_strcmp(pcVar8,(char *)&idx), dVar10 = (double)rea_iv(DAT_0010fd10), iVar5 == 0)) && (pcVar8 != (char *)0x0)) {
                    /* Unresolved local var: Item * item@[???] Unresolved local var: Item key@[???] Unresolved local var: Item * begin@[???] Unresolved local var: Item * end@[???] Unresolved local var: Item * it@[???] */ piVar2 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + (long long)*(int *)(pcVar8 + 0x10) * 0x18);
                    /* Unresolved local var: _DistanceType __len@[???] */ piVar7 = piVar2;
      for (lVar6 = ((*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + ((long long)*(int *)(pcVar8 + 0x10) + (long long)*(int *)(pcVar8 + 0x14)) * 0x18) - (long long)piVar2 >> 3) * -0x5555555555555555; 0 < lVar6;
          lVar6 = (lVar6 - lVar4) + -1) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Item * __middle@[???] */ /* Unresolved local var: difference_type __d@[???] */ piVar3 = piVar7 + (lVar6 >> 1) * 6;
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
// @@@ END IDX 129
// @@@ BEGIN IDX 130 rea_SecInfo__getClosePrice__dup2
// ------------------------------------------------------------------
// IDX 130  00105fb0  SecInfo__getClosePrice
// ------------------------------------------------------------------
double rea_SecInfo__getClosePrice__dup2(SecInfo * this_ptr, string * gid, int date) {
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  long long lVar5;
  int iVar6;
  size_t __n;
  long long lVar7;
  int *piVar8;
  long long lVar9;
  rea_v key;
  rea_v idx;
  
                    /* Unresolved local var: Index * idx@[???] */ piVar8 = *(int **)PTR_data_00311fc8;
                    /* Unresolved local var: ulong pos@[???] */ if (*(ulong *)(rea_bind((gid->_M_dataplus))._M_p + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar4 = rea_bind((gid->_M_dataplus))._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar4 + -0x18);
    }
    rea_memcpy(&key,pcVar4,__n);
    lVar7 = (long long)*piVar8;
    key.gid[__n] = '\0';
                    /* Unresolved local var: Index * it@[???] */ pcVar4 = *(char **)(piVar8 + 2);
    idx.start = 0;
    idx.size = 0;
                    /* Unresolved local var: _DistanceType __len@[???] */ pcVar1 = pcVar4 + lVar7 * 0x18;
    for (; 0 < lVar7; lVar7 = (lVar7 - lVar9) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Index * __middle@[???] */ lVar9 = lVar7 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */ iVar6 = rea_strcmp(pcVar4 + lVar9 * 0x18,(char *)&idx);
        if (iVar6 < 0) break;
        lVar7 = lVar9;
        if (lVar9 == 0) goto LAB_001060ab;
      }
      pcVar4 = pcVar4 + lVar9 * 0x18 + 0x18;
    }
LAB_001060ab:
    if (((pcVar1 != pcVar4) && (iVar6 = rea_strcmp(pcVar4,(char *)&idx), iVar6 == 0)) && (pcVar4 != (char *)0x0)) {
                    /* Unresolved local var: Item * item@[???] Unresolved local var: Item key@[???] Unresolved local var: Item * begin@[???] Unresolved local var: Item * end@[???] Unresolved local var: Item * it@[???] */ piVar8 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + (long long)*(int *)(pcVar4 + 0x10) * 0x18);
      piVar2 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + ((long long)*(int *)(pcVar4 + 0x10) + (long long)*(int *)(pcVar4 + 0x14)) * 0x18);
                    /* Unresolved local var: _DistanceType __len@[???] */ for (lVar7 = ((long long)piVar2 - (long long)piVar8 >> 3) * -0x5555555555555555; 0 < lVar7;
          lVar7 = (lVar7 - lVar5) + -1) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Item * __middle@[???] */ /* Unresolved local var: difference_type __d@[???] */ piVar3 = piVar8 + (lVar7 >> 1) * 6;
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
  return (double)rea_iv(DAT_0010fd10);
}
// @@@ END IDX 130
// @@@ BEGIN IDX 131 rea_SecInfo__getPreDate__dup2
// ------------------------------------------------------------------
// IDX 131  001061b0  SecInfo__getPreDate
// ------------------------------------------------------------------
int rea_SecInfo__getPreDate__dup2(SecInfo * this_ptr, string * gid, int date) {
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  long long lVar7;
  int iVar8;
  size_t __n;
  long long lVar9;
  int *piVar10;
  long long lVar11;
  rea_v key;
  rea_v idx;
  
                    /* Unresolved local var: Index * idx@[???] */ /* Unresolved local var: ulong pos@[???] */ piVar10 = *(int **)PTR_data_00311fc8;
  iVar8 = 0;
  if (*(ulong *)(rea_bind((gid->_M_dataplus))._M_p + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar6 = rea_bind((gid->_M_dataplus))._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar6 + -0x18);
    }
    rea_memcpy(&key,pcVar6,__n);
    lVar9 = (long long)*piVar10;
    key.gid[__n] = '\0';
                    /* Unresolved local var: Index * it@[???] */ pcVar6 = *(char **)(piVar10 + 2);
    idx.start = 0;
    idx.size = 0;
                    /* Unresolved local var: _DistanceType __len@[???] */ pcVar1 = pcVar6 + lVar9 * 0x18;
    for (; 0 < lVar9; lVar9 = (lVar9 - lVar11) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Index * __middle@[???] */ lVar11 = lVar9 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */ iVar8 = rea_strcmp(pcVar6 + lVar11 * 0x18,(char *)&idx);
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
                    /* Unresolved local var: Item * item@[???] Unresolved local var: Item key@[???] Unresolved local var: Item * begin@[???] Unresolved local var: Item * end@[???] Unresolved local var: Item * it@[???] */ piVar2 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + (long long)*(int *)(pcVar6 + 0x10) * 0x18);
                    /* Unresolved local var: _DistanceType __len@[???] */ piVar3 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + ((long long)*(int *)(pcVar6 + 0x10) + (long long)*(int *)(pcVar6 + 0x14)) * 0x18);
      piVar10 = piVar2;
      for (lVar9 = ((long long)piVar3 - (long long)piVar2 >> 3) * -0x5555555555555555; 0 < lVar9;
          lVar9 = (lVar9 - lVar7) + -1) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Item * __middle@[???] */ /* Unresolved local var: difference_type __d@[???] */ piVar4 = piVar10 + (lVar9 >> 1) * 6;
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
// @@@ END IDX 131
// @@@ BEGIN IDX 132 rea_SecInfo__getNextDate
// ------------------------------------------------------------------
// IDX 132  001063c0  SecInfo__getNextDate
// ------------------------------------------------------------------
int rea_SecInfo__getNextDate(SecInfo * this_ptr, string * gid, int date) {
  char *pcVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  long long lVar6;
  int iVar7;
  size_t __n;
  long long lVar8;
  int *piVar9;
  long long lVar10;
  rea_v key;
  rea_v idx;
  
                    /* Unresolved local var: Index * idx@[???] */ /* Unresolved local var: ulong pos@[???] */ piVar9 = *(int **)PTR_data_00311fc8;
  iVar7 = 0;
  if (*(ulong *)(rea_bind((gid->_M_dataplus))._M_p + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    pcVar5 = rea_bind((gid->_M_dataplus))._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(pcVar5 + -0x18);
    }
    rea_memcpy(&key,pcVar5,__n);
    lVar8 = (long long)*piVar9;
    key.gid[__n] = '\0';
                    /* Unresolved local var: Index * it@[???] */ pcVar5 = *(char **)(piVar9 + 2);
    idx.start = 0;
    idx.size = 0;
                    /* Unresolved local var: _DistanceType __len@[???] */ pcVar1 = pcVar5 + lVar8 * 0x18;
    for (; 0 < lVar8; lVar8 = (lVar8 - lVar10) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Index * __middle@[???] */ lVar10 = lVar8 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */ iVar7 = rea_strcmp(pcVar5 + lVar10 * 0x18,(char *)&idx);
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
                    /* Unresolved local var: Item * item@[???] Unresolved local var: Item key@[???] Unresolved local var: Item * begin@[???] Unresolved local var: Item * end@[???] Unresolved local var: Item * it@[???] */ piVar9 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + (long long)*(int *)(pcVar5 + 0x10) * 0x18);
      piVar2 = (int *)(*(long long *)(*(long long *)PTR_data_00311fc8 + 0x10) + ((long long)*(int *)(pcVar5 + 0x10) + (long long)*(int *)(pcVar5 + 0x14)) * 0x18);
                    /* Unresolved local var: _DistanceType __len@[???] */ for (lVar8 = ((long long)piVar2 - (long long)piVar9 >> 3) * -0x5555555555555555; 0 < lVar8;
          lVar8 = (lVar8 - lVar6) + -1) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Item * __middle@[???] */ /* Unresolved local var: difference_type __d@[???] */ piVar3 = piVar9 + (lVar8 >> 1) * 6;
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
// @@@ END IDX 132
// @@@ BEGIN IDX 133 rea_SecInfo__getRescale__dup2
// ------------------------------------------------------------------
// IDX 133  001065c0  SecInfo__getRescale
// ------------------------------------------------------------------
double rea_SecInfo__getRescale__dup2(SecInfo * this_ptr, string * gid, int date) {
  int date_00;
  double dVar1;
  double dVar2;
  
                    /* Unresolved local var: double preclose@[???] Unresolved local var: int predate@[???] Unresolved local var: double preclose0@[???] */ dVar1 = rea_getPreClosePrice(this_ptr,gid,date);
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
// @@@ END IDX 133
// @@@ BEGIN IDX 134 rea_SecInfo__GroupsIterator__deref
// ------------------------------------------------------------------
// IDX 134  00106640  SecInfo__GroupsIterator__deref
// ------------------------------------------------------------------
char * rea_SecInfo__GroupsIterator__deref(GroupsIterator * this_ptr) {
                    /* Unresolved local var: Index * idxs@[DW_OP_breg5(RDI): 0] Unresolved local var: GroupBackwardItem * p@[DW_OP_breg5(RDI): +8] */ return (char *)((long long)(rea_bind(this_ptr)->super_Iterator).idxbase + (long long)*(short *)((long long)(rea_bind(this_ptr)->super_Iterator).base + (long long)(rea_bind(this_ptr)->super_Iterator).curr * 2) * 0x18);
}
// @@@ END IDX 134
// @@@ BEGIN IDX 135 rea_SecInfo__Set_SecInfo__GroupsIterator__contains
// ------------------------------------------------------------------
// IDX 135  00106660  SecInfo__Set_SecInfo__GroupsIterator__contains
// ------------------------------------------------------------------
bool rea_SecInfo__Set_SecInfo__GroupsIterator__contains(Set_SecInfo__GroupsIterator * this_ptr, char * member) {
  int *piVar1;
  short *psVar2;
  short *psVar3;
  short sVar4;
  rea_adr pGVar5;
  rea_adr __s1;
  short sVar6;
  long long lVar7;
  int iVar8;
  long long lVar9;
  short *psVar10;
  long long lVar11;
  rea_adr pIVar12;
  rea_v local_79;
  char *local_78 [2];
  rea_v key;
  rea_v idx;
  
  if ((rea_bind(this_ptr)->data1 != (GroupData1 *)0x0) && (rea_bind(this_ptr)->data2 != (GroupData2 *)0x0)) {
                    /* Unresolved local var: Index * group_idx@[???] Unresolved local var: GroupBackwardItem key@[???] Unresolved local var: GroupBackwardItem * begin@[???] Unresolved local var: GroupBackwardItem * end@[???] Unresolved local var: GroupBackwardItem * it@[???] */ rea_std__string__string(local_78,member,&local_79);
    pGVar5 = rea_bind(this_ptr)->data1;
    pIVar12 = (Index *)0x0;
    if (*(ulong *)(local_78[0] + -0x18) < 0x10) {
      rea_strcpy(key.group_name,local_78[0]);
      lVar9 = (long long)(pGVar5->super_IndexedData).num_idxs;
                    /* Unresolved local var: Index * it@[???] */ __s1 = (pGVar5->super_IndexedData).idxs;
      idx.start = 0;
      idx.size = 0;
                    /* Unresolved local var: _DistanceType __len@[???] */ pIVar12 = __s1 + lVar9;
      for (; 0 < lVar9; lVar9 = (lVar9 - lVar11) + -1) {
        while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Index * __middle@[???] */ lVar11 = lVar9 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */ iVar8 = rea_strcmp((char *)(__s1 + lVar11),(char *)&idx);
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
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg0(RAX)] */ iVar8 = *(int *)(local_78[0] + -8);
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
      lVar9 = rea_bind((long long)this_ptr)->size_;
      psVar10 = rea_bind(this_ptr)->base;
                    /* Unresolved local var: _DistanceType __len@[???] */ psVar2 = psVar10 + lVar9;
      sVar6 = (short)((long long)pIVar12 - (long long)(rea_bind(this_ptr)->data1->super_IndexedData).idxs >> 3) * -0x5555;
      for (; 0 < lVar9; lVar9 = (lVar9 - lVar7) + -1) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: GroupBackwardItem * __middle@[???] */ /* Unresolved local var: difference_type __d@[???] */ psVar3 = psVar10 + (lVar9 >> 1);
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
// @@@ END IDX 135
// @@@ BEGIN IDX 136 rea_SecInfo__MembersIterator__deref
// ------------------------------------------------------------------
// IDX 136  00106890  SecInfo__MembersIterator__deref
// ------------------------------------------------------------------
char * rea_SecInfo__MembersIterator__deref(MembersIterator * this_ptr) {
                    /* Unresolved local var: Index * idxs@[DW_OP_breg5(RDI): 0] Unresolved local var: GroupForwardItem * p@[DW_OP_breg5(RDI): +8] */ return (char *)((long long)(rea_bind(this_ptr)->super_Iterator).idxbase + (long long)*(int *)((long long)(rea_bind(this_ptr)->super_Iterator).base + (long long)(rea_bind(this_ptr)->super_Iterator).curr * 0xc) * 0x18);
}
// @@@ END IDX 136
// @@@ BEGIN IDX 137 rea_SecInfo__MembersIterator__getForecastWeight
// ------------------------------------------------------------------
// IDX 137  001068b0  SecInfo__MembersIterator__getForecastWeight
// ------------------------------------------------------------------
double rea_SecInfo__MembersIterator__getForecastWeight(MembersIterator * this_ptr) {
                    /* Unresolved local var: Index * idxs@[DW_OP_breg5(RDI): 0] Unresolved local var: GroupForwardItem * p@[DW_OP_breg5(RDI): +8] */ return (double)*(float *)((long long)(rea_bind(this_ptr)->super_Iterator).base + (long long)(rea_bind(this_ptr)->super_Iterator).curr * 0xc + 4);
}
// @@@ END IDX 137
// @@@ BEGIN IDX 138 rea_SecInfo__MembersIterator__getWeight
// ------------------------------------------------------------------
// IDX 138  001068d0  SecInfo__MembersIterator__getWeight
// ------------------------------------------------------------------
double rea_SecInfo__MembersIterator__getWeight(MembersIterator * this_ptr) {
                    /* Unresolved local var: Index * idxs@[???] Unresolved local var: GroupForwardItem * p@[???] */ if (rea_bind(this_ptr)->mask_eod_values == false) {
    return (double)*(float *)((long long)(rea_bind(this_ptr)->super_Iterator).base + (long long)(rea_bind(this_ptr)->super_Iterator).curr * 0xc + 8);
  }
  return (double)rea_iv(DAT_0010fd10);
}
// @@@ END IDX 138
// @@@ BEGIN IDX 139 rea_SecInfo__Set_SecInfo__MembersIterator__contains
// ------------------------------------------------------------------
// IDX 139  00106900  SecInfo__Set_SecInfo__MembersIterator__contains
// ------------------------------------------------------------------
bool rea_SecInfo__Set_SecInfo__MembersIterator__contains(Set_SecInfo__MembersIterator * this_ptr, char * member) {
  int *piVar1;
  int *piVar2;
  int iVar3;
  rea_adr pGVar4;
  rea_adr __s1;
  long long lVar5;
  int iVar6;
  size_t __n;
  long long lVar7;
  rea_adr pIVar8;
  int *piVar9;
  long long lVar10;
  void *local_98;
  rea_v local_79;
  void *local_78 [2];
  rea_v key;
  rea_v idx;
  
  if (rea_bind(this_ptr)->data1 == (GroupData1 *)0x0) {
    return false;
  }
  if (rea_bind(this_ptr)->data2 == (GroupData2 *)0x0) {
    return false;
  }
                    /* Unresolved local var: Index * gid_idx@[???] Unresolved local var: GroupForwardItem key@[???] Unresolved local var: GroupForwardItem * begin@[???] Unresolved local var: GroupForwardItem * end@[???] Unresolved local var: GroupForwardItem * it@[???] */ rea_std__string__string(local_78,member,&local_79);
                    /* Unresolved local var: ulong pos@[???] */ pGVar4 = rea_bind(this_ptr)->data2;
  local_98 = local_78[0];
  if (*(ulong *)((long long)local_78[0] + -0x18) < 0x10) {
    __n = rea_std__string__find((char *)local_78,0x10fb8f,0);
    local_98 = local_78[0];
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)((long long)local_78[0] + -0x18);
    }
    rea_memcpy(&key,local_78[0],__n);
    lVar7 = (long long)(pGVar4->super_IndexedData).num_idxs;
    key.gid[__n] = '\0';
                    /* Unresolved local var: Index * it@[???] */ __s1 = (pGVar4->super_IndexedData).idxs;
    idx.start = 0;
    idx.size = 0;
                    /* Unresolved local var: _DistanceType __len@[???] */ pIVar8 = __s1 + lVar7;
    for (; 0 < lVar7; lVar7 = (lVar7 - lVar10) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Index * __middle@[???] */ lVar10 = lVar7 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */ iVar6 = rea_strcmp((char *)(__s1 + lVar10),(char *)&idx);
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
  if ((allocator *)((long long)local_98 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar9 = (int *)((long long)local_98 + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg0(RAX)] */ iVar6 = *(int *)((long long)local_98 + -8);
      *(int *)((long long)local_98 + -8) = iVar6 + -1;
    }
    else {
      LOCK();
      iVar6 = *piVar9;
      *piVar9 = *piVar9 + -1;
      UNLOCK();
    }
    if (iVar6 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long long)local_98 + -0x18));
    }
  }
  if (pIVar8 != (Index *)0x0) {
    lVar7 = rea_bind((long long)this_ptr)->size_;
    piVar9 = rea_bind(this_ptr)->base;
                    /* Unresolved local var: _DistanceType __len@[???] */ piVar1 = piVar9 + lVar7 * 3;
    iVar6 = (int)((long long)pIVar8 - (long long)(rea_bind(this_ptr)->data2->super_IndexedData).idxs >> 3) * -0x55555555;
    for (; 0 < lVar7; lVar7 = (lVar7 - lVar5) + -1) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: GroupForwardItem * __middle@[???] */ /* Unresolved local var: difference_type __d@[???] */ piVar2 = piVar9 + (lVar7 >> 1) * 3;
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
// @@@ END IDX 139
// @@@ BEGIN IDX 140 rea_pinot_open__dup2
// ------------------------------------------------------------------
// IDX 140  00106ba0  pinot_open
// ------------------------------------------------------------------
void * rea_pinot_open__dup2(string file) {
  undefined *puVar1;
  char *pcVar2;
  undefined8 uVar3;
  long long lVar4;
  undefined8 *puVar5;
  void *pvVar6;
  long long *plVar7;
  long long lVar8;
  
  pcVar2 = rea_bind(*(char **)file._M_dataplus)._M_p;
  puVar5 = (undefined8*)rea_pv(rea_operator_new(8));
  if (pinot_reader_handle == (void *)0x0) {
                    /* Unresolved local var: void * l@[???] */ pvVar6 = (void *)rea_dlopen("/opt/bbcluster/alpha/pinot/bin/libpinot_reader.so",2);
    if (pvVar6 != (void *)0x0) {
      pinot_reader_handle = pvVar6;
      pinot_reader_open = (code *)rea_dlsym(pvVar6,"pinot_reader_open");
      pinot_reader_close = (code *)rea_dlsym(pvVar6,"pinot_reader_close");
      pinot_reader_is_open = (code *)rea_dlsym(pvVar6,"pinot_reader_is_open");
      pinot_reader_getline = (code *)rea_dlsym(pvVar6,"pinot_reader_getline");
      pinot_reader_read = (code *)rea_dlsym(pvVar6,"pinot_reader_read");
    }
    if (pinot_reader_handle == (void *)0x0) {
      plVar7 = (long long int*)rea_pv(rea_operator_new(0x208));
      rea_std__ios_base__ios_base((ios_base *)(plVar7 + 0x20));
      puVar1 = PTR_vtable_00311f68;
      *(undefined1 *)(plVar7 + 0x3c) = 0;
      plVar7[0x3b] = 0;
      *(undefined1 *)((long long)plVar7 + 0x1e1) = 0;
      plVar7[0x3d] = 0;
      plVar7[0x3e] = 0;
      plVar7[0x3f] = 0;
      plVar7[0x40] = 0;
      plVar7[0x20] = (long long)(puVar1 + 0x10);
      lVar8 = *(long long *)(PTR_VTT_00311fe0 + 8);
      uVar3 = *(undefined8 *)(PTR_VTT_00311fe0 + 0x10);
      lVar4 = *(long long *)(lVar8 + -0x18);
      *plVar7 = lVar8;
      *(undefined8 *)((long long)plVar7 + lVar4) = uVar3;
      plVar7[1] = 0;
      rea_std__ios__init((streambuf *)((long long)plVar7 + *(long long *)(lVar8 + -0x18)));
      puVar1 = PTR_vtable_00311fb0 + 0x18;
      plVar7[0x20] = (long long)(PTR_vtable_00311fb0 + 0x40);
      *plVar7 = (long long)puVar1;
      rea_std__filebuf__filebuf((filebuf *)(plVar7 + 2));
      rea_std__ios__init((streambuf *)(plVar7 + 0x20));
      lVar8 = rea_std__filebuf__open((char *)(plVar7 + 2),rea_cast<_Ios_Openmode >(pcVar2));
      if (lVar8 == 0) {
        rea_std__ios__clear(rea_cast<int >(plVar7) + (int)*(undefined8 *)(*plVar7 + -0x18));
      }
      else {
        rea_std__ios__clear(rea_cast<int >(plVar7) + (int)*(undefined8 *)(*plVar7 + -0x18));
      }
      *puVar5 = (undefined8)rea_iv(plVar7);
      return puVar5;
    }
  }
  pvVar6 = (void*)rea_pv((*pinot_reader_open)(pcVar2));
  *puVar5 = (undefined8)rea_iv(pvVar6);
  return puVar5;
}
// @@@ END IDX 140
// @@@ BEGIN IDX 141 rea_pinot_close__dup2
// ------------------------------------------------------------------
// IDX 141  00106e30  pinot_close
// ------------------------------------------------------------------
void rea_pinot_close__dup2(void * fp) {
  long long *plVar1;
  
  if (fp == (void *)0x0) {
    return;
  }
  plVar1 = *(long long **)fp;
  if (pinot_reader_handle == (void *)0x0) {
    if (plVar1 != (long long *)0x0) {
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
// @@@ END IDX 141
// @@@ BEGIN IDX 142 rea_pinot_getline__dup2
// ------------------------------------------------------------------
// IDX 142  00106e80  pinot_getline
// ------------------------------------------------------------------
pair_int__std__basic_string_char__std__char_traits_char__std__allocator_char__ rea_pinot_getline__dup2(void * fp) {
  long long *plVar1;
  undefined *puVar2;
  bool bVar3;
  char cVar4;
  uint uVar5;
  rea_adr piVar6;
  undefined8 uVar7;
  rea_v extraout_RDX;
  rea_v extraout_RDX_00;
  rea_v bVar8;
  undefined8 *in_RSI;
  rea_v pVar9;
  rea_v line;
  
  puVar2 = PTR__S_empty_rep_storage_00311ff0;
                    /* Unresolved local var: int b@[???] */ line._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
  if (pinot_reader_handle == (void *)0x0) {
    piVar6 = (istream *)*in_RSI;
    plVar1 = *(long long **)(piVar6 + *(long long *)(*(long long *)piVar6 + -0x18) + 0xf0);
    if (plVar1 == (long long *)0x0) {
      uVar7 = rea_std____throw_bad_cast();
      rea_std__string___Rep___M_dispose((allocator *)((long long)line._M_dataplus._M_p + -0x18));
                    /* WARNING: Subroutine does not return */ rea__Unwind_Resume(uVar7);
    }
    if ((char)plVar1[7] == '\0') {
      rea_std__ctype_char___M_widen_init();
      cVar4 = (**(code **)(*plVar1 + 0x30))(plVar1,10);
    }
    else {
      cVar4 = *(char *)((long long)plVar1 + 0x43);
    }
    piVar6 = rea_std__getline_char_std__char_traits_char_std__allocator_char(piVar6,&line,cVar4);
    bVar3 = ((byte)piVar6[*(long long *)(*(long long *)piVar6 + -0x18) + 0x20] & 5) == 0;
  }
  else {
    bVar3 = (*pinot_reader_getline)((void *)*in_RSI,&line);
  }
  *(uint *)fp = (uint)bVar3;
  rea_std__string__string((void *)((long long)fp + 8),&line);
  bVar8._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)extraout_RDX._M_p;
  if ((allocator *)((long long)line._M_dataplus._M_p + -0x18) != (allocator *)puVar2) {
    bVar8._M_dataplus._M_p = (_Alloc_hider)((long long)line._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ uVar5 = *(uint *)((long long)line._M_dataplus._M_p + -8);
      bVar8._M_dataplus._M_p = (_Alloc_hider)(ulong)uVar5;
      *(uint *)((long long)line._M_dataplus._M_p + -8) = uVar5 - 1;
    }
    else {
      LOCK();
      uVar5 = *(uint *)bVar8._M_dataplus._M_p;
      *(uint *)bVar8._M_dataplus._M_p = *(uint *)bVar8._M_dataplus._M_p - 1;
      UNLOCK();
    }
    if ((int)uVar5 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long long)line._M_dataplus._M_p + -0x18));
      bVar8._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)extraout_RDX_00._M_p;
    }
  }
  pVar9.second._M_dataplus._M_p = bVar8._M_dataplus._M_p;
  (*(undefined8 *)((uint8_t *)&pVar9 + 0x0)) = (undefined8)rea_iv(fp);
  return pVar9;
}
// @@@ END IDX 142
// @@@ BEGIN IDX 144 rea_SecInfo__SecInfo__dup2
// ------------------------------------------------------------------
// IDX 144  00106fe0  SecInfo__SecInfo
// ------------------------------------------------------------------
void rea_SecInfo__SecInfo__dup2(SecInfo * this_ptr, Mode m) {
  undefined4 *puVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  FILE *__stream;
  size_t sVar5;
  void *pvVar6;
  ulong uVar7;
  rea_v local_3a [2];
  rea_v local_38 [3];
  
  puVar2 = (undefined*)rea_pv(PTR_data_00311fc8);
  if (*(long long *)PTR_data_00311fc8 != 0) goto LAB_00106ffa;
  rea_std__string__string(local_38,"SecInfo.dump",local_3a);
  piVar4 = (int*)rea_pv(rea_operator_new(0x18));
  *piVar4 = 0;
  piVar4[1] = 0;
                    /* Unresolved local var: _IO_FILE * fp@[???] */ piVar4[2] = 0;
  piVar4[3] = 0;
  piVar4[4] = 0;
  piVar4[5] = 0;
  __stream = rea_open_file((string*)rea_pv(local_38));
  if (__stream != (FILE *)0x0) {
                    /* Unresolved local var: bool fail@[???] */ sVar5 = rea_fread(piVar4,4,1,(FILE *)__stream);
    if ((sVar5 == 1) && (sVar5 = rea_fread(piVar4 + 1,4,1,(FILE *)__stream), sVar5 == 1)) {
      uVar7 = 0xffffffffffffffff;
      if ((ulong)(long long)*piVar4 < 0x550000000000001) {
        uVar7 = (long long)*piVar4 * 0x18;
      }
      pvVar6 = (void*)rea_pv(rea_operator_new(uVar7));
      *(void **)(piVar4 + 2) = pvVar6;
      uVar7 = 0xffffffffffffffff;
      if ((ulong)(long long)piVar4[1] < 0x550000000000001) {
        uVar7 = (long long)piVar4[1] * 0x18;
      }
      pvVar6 = (void*)rea_pv(rea_operator_new(uVar7));
      *(void **)(piVar4 + 4) = pvVar6;
      sVar5 = rea_fread(*(void **)(piVar4 + 2),0x18,(long long)*piVar4,(FILE *)__stream);
      if ((sVar5 != (long long)*piVar4) || (sVar5 = rea_fread(*(void **)(piVar4 + 4),0x18,(long long)piVar4[1],(FILE *)__stream), sVar5 != (long long)piVar4[1])) goto LAB_00107082;
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
                    /* Unresolved local var: Data * __tmp@[???] */ puVar1 = *(undefined4 **)puVar2;
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
  if ((allocator *)((long long)local_38[0]._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar4 = (int *)((long long)local_38[0]._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar3 = *(int *)((long long)local_38[0]._M_dataplus._M_p + -8);
      *(int *)((long long)local_38[0]._M_dataplus._M_p + -8) = iVar3 + -1;
    }
    else {
      LOCK();
      iVar3 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
    }
    if (iVar3 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long long)local_38[0]._M_dataplus._M_p + -0x18));
    }
  }
LAB_00106ffa:
  rea_bind(this_ptr)->no_check = true;
  return;
}
// @@@ END IDX 144
// @@@ BEGIN IDX 145 rea_SecInfo__SecInfo__dup3
// ------------------------------------------------------------------
// IDX 145  00107270  SecInfo__SecInfo
// ------------------------------------------------------------------
void rea_SecInfo__SecInfo__dup3(SecInfo * this_ptr) {
  undefined4 *puVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  FILE *__stream;
  size_t sVar5;
  void *pvVar6;
  ulong uVar7;
  rea_v local_3a [2];
  rea_v local_38 [3];
  
  puVar2 = (undefined*)rea_pv(PTR_data_00311fc8);
  if (*(long long *)PTR_data_00311fc8 != 0) goto LAB_0010728a;
  rea_std__string__string(local_38,"SecInfo.dump",local_3a);
  piVar4 = (int*)rea_pv(rea_operator_new(0x18));
  *piVar4 = 0;
  piVar4[1] = 0;
                    /* Unresolved local var: _IO_FILE * fp@[???] */ piVar4[2] = 0;
  piVar4[3] = 0;
  piVar4[4] = 0;
  piVar4[5] = 0;
  __stream = rea_open_file((string*)rea_pv(local_38));
  if (__stream != (FILE *)0x0) {
                    /* Unresolved local var: bool fail@[???] */ sVar5 = rea_fread(piVar4,4,1,(FILE *)__stream);
    if ((sVar5 == 1) && (sVar5 = rea_fread(piVar4 + 1,4,1,(FILE *)__stream), sVar5 == 1)) {
      uVar7 = 0xffffffffffffffff;
      if ((ulong)(long long)*piVar4 < 0x550000000000001) {
        uVar7 = (long long)*piVar4 * 0x18;
      }
      pvVar6 = (void*)rea_pv(rea_operator_new(uVar7));
      *(void **)(piVar4 + 2) = pvVar6;
      uVar7 = 0xffffffffffffffff;
      if ((ulong)(long long)piVar4[1] < 0x550000000000001) {
        uVar7 = (long long)piVar4[1] * 0x18;
      }
      pvVar6 = (void*)rea_pv(rea_operator_new(uVar7));
      *(void **)(piVar4 + 4) = pvVar6;
      sVar5 = rea_fread(*(void **)(piVar4 + 2),0x18,(long long)*piVar4,(FILE *)__stream);
      if ((sVar5 != (long long)*piVar4) || (sVar5 = rea_fread(*(void **)(piVar4 + 4),0x18,(long long)piVar4[1],(FILE *)__stream), sVar5 != (long long)piVar4[1])) goto LAB_00107312;
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
                    /* Unresolved local var: Data * __tmp@[???] */ puVar1 = *(undefined4 **)puVar2;
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
  if ((allocator *)((long long)local_38[0]._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar4 = (int *)((long long)local_38[0]._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar3 = *(int *)((long long)local_38[0]._M_dataplus._M_p + -8);
      *(int *)((long long)local_38[0]._M_dataplus._M_p + -8) = iVar3 + -1;
    }
    else {
      LOCK();
      iVar3 = *piVar4;
      *piVar4 = *piVar4 + -1;
      UNLOCK();
    }
    if (iVar3 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long long)local_38[0]._M_dataplus._M_p + -0x18));
    }
  }
LAB_0010728a:
  rea_bind(this_ptr)->no_check = false;
  return;
}
// @@@ END IDX 145
// @@@ BEGIN IDX 150 rea_SecInfo__find_data2__dup2
// ------------------------------------------------------------------
// IDX 150  00107600  SecInfo__find_data2
// ------------------------------------------------------------------
Data2 * rea_SecInfo__find_data2__dup2(SecInfo * this_ptr, int date) {
  rea_adr pp_Var1;
  int *piVar2;
  rea_v this_00;
  undefined *this_01;
  undefined *puVar3;
  int iVar4;
  rea_v p_Var5;
  rea_v __position;
  long long *plVar6;
  rea_v _Var7;
  FILE *__stream;
  size_t sVar8;
  void *pvVar9;
  rea_v p_Var10;
  rea_v p_Var11;
  rea_v p_Var12;
  rea_v p_Var13;
  ulong uVar14;
  rea_v pVar15;
  long long local_68 [2];
  long long local_58 [2];
  rea_v local_48 [3];
  
  this_01 = PTR_data_store2_00311f70;
  p_Var12 = *(_Base_ptr *)(PTR_data_store2_00311f70 + 0x10);
                    /* Unresolved local var: iterator __j@[???] */ if (p_Var12 == (_Base_ptr)0x0) {
LAB_00107720:
    rea___gnu_cxx____to_xstring_std__basic_string_char__char ((code *) local_68,(size_t)PTR_vsnprintf_00311fd0,(char *)0x10,(void *)&DAT_0010fc03,date);
    plVar6 = (long long *)rea_std__string__insert((ulong)local_68,(char *)0x0,0x10fc06);
    puVar3 = PTR__S_empty_rep_storage_00311ff0;
    local_58[0] = *plVar6;
    *plVar6 = (long long)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    plVar6 = (long long *)rea_std__string__append((char *)local_58,0x10fbfd);
    local_48[0]._M_dataplus._M_p = (_Alloc_hider)*plVar6;
    *plVar6 = (long long)(puVar3 + 0x18);
    _Var7 = rea_cast<_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_ >( rea_operator_new(0x18));
                    /* Unresolved local var: _IO_FILE * fp@[???] */ *(int *)_Var7 = 0;
    *(int *)((long long)_Var7 + 4) = 0;
    ((int *)((long long)_Var7 + 8))[0] = 0;
    ((int *)((long long)_Var7 + 8))[1] = 0;
    ((int *)((long long)_Var7 + 0x10))[0] = 0;
    ((int *)((long long)_Var7 + 0x10))[1] = 0;
    __stream = rea_open_file((string*)rea_pv(local_48));
    if (__stream != (FILE *)0x0) {
                    /* Unresolved local var: bool fail@[???] */ sVar8 = rea_fread((void *)_Var7,4,1,(FILE *)__stream);
      if ((sVar8 == 1) && (sVar8 = rea_fread((int *)((long long)_Var7 + 4),4,1,(FILE *)__stream), sVar8 == 1) ) {
        uVar14 = 0xffffffffffffffff;
        if ((ulong)(long long)*(int *)_Var7 < 0x550000000000001) {
          uVar14 = (long long)*(int *)_Var7 * 0x18;
        }
        pvVar9 = (void*)rea_pv(rea_operator_new(uVar14));
        *(void **)((long long)_Var7 + 8) = pvVar9;
        uVar14 = 0xffffffffffffffff;
        if ((ulong)(long long)*(int *)((long long)_Var7 + 4) < 0x1c4000000000001) {
          uVar14 = (long long)*(int *)((long long)_Var7 + 4) * 0x48;
        }
        pvVar9 = (void*)rea_pv(rea_operator_new(uVar14));
        *(void **)((long long)_Var7 + 0x10) = pvVar9;
        sVar8 = rea_fread(*(void **)((long long)_Var7 + 8),0x18,(long long)*(int *)_Var7,(FILE *)__stream);
        if ((sVar8 != (long long)*(int *)_Var7) || (sVar8 = rea_fread(*(void **)((long long)_Var7 + 0x10),0x48,(long long)*(int *)((long long)_Var7 + 4), (FILE *)__stream), sVar8 != (long long)*(int *)((long long)_Var7 + 4))) goto LAB_001077f4;
      }
      else {
LAB_001077f4:
        *(int *)_Var7 = 0;
        *(int *)((long long)_Var7 + 4) = 0;
        if (*(void **)((long long)_Var7 + 8) != (void *)0x0) {
          rea_operator_delete(*(void **)((long long)_Var7 + 8));
          ((int *)((long long)_Var7 + 8))[0] = 0;
          ((int *)((long long)_Var7 + 8))[1] = 0;
        }
        if (*(void **)((long long)_Var7 + 0x10) != (void *)0x0) {
          rea_operator_delete(*(void **)((long long)_Var7 + 0x10));
          ((int *)((long long)_Var7 + 0x10))[0] = 0;
          ((int *)((long long)_Var7 + 0x10))[1] = 0;
        }
      }
      rea_fclose((FILE *)__stream);
    }
                    /* Unresolved local var: _Link_type __z@[???] Unresolved local var: _Link_type __tmp@[???] */ p_Var5 = rea_operator_new(0x30);
    if (p_Var5 != (_Link_type)0x0) {
      (p_Var5->_M_value_field).second._M_t. super__Tuple_impl = _Var7;
      (p_Var5->super__Rb_tree_node_base)._M_color = _S_red;
                    /* Unresolved local var: pointer __p@[???] */ _Var7 = (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
      (p_Var5->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
      (p_Var5->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
      (p_Var5->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
      (p_Var5->_M_value_field).first = date;
    }
                    /* Unresolved local var:
                       pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ __res@[???] */
    pVar15 = std_________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____________________M_get_insert_unique_pos________________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ *)this_01,&(p_Var5->_M_value_field).first);
    if (pVar15.second == (_Base_ptr)0x0) {
                    /* Unresolved local var: Data2 * * __ptr@[???] */ this_00 = (p_Var5->_M_value_field).second._M_t. super__Tuple_impl;
      if (this_00 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
        rea_IndexedData_GIDKey__Item2__free((IndexedData_GIDKey__Item2 *)this_00);
        rea_operator_delete((void *)this_00);
      }
      (p_Var5->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
      rea_operator_delete(p_Var5);
    }
    else {
      std__________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2______________M_insert_node((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ *)this_01,pVar15.first,pVar15.second,p_Var5);
    }
                    /* Unresolved local var: Data2 * * __ptr@[???] */ if (_Var7 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
      *(int *)_Var7 = 0;
      *(int *)((long long)_Var7 + 4) = 0;
      if (*(void **)((long long)_Var7 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var7 + 8));
        ((int *)((long long)_Var7 + 8))[0] = 0;
        ((int *)((long long)_Var7 + 8))[1] = 0;
      }
      if (*(void **)((long long)_Var7 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var7 + 0x10));
        ((int *)((long long)_Var7 + 0x10))[0] = 0;
        ((int *)((long long)_Var7 + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)_Var7);
    }
    if ((allocator *)((long long)local_48[0]._M_dataplus._M_p + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)((long long)local_48[0]._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar4 = *(int *)((long long)local_48[0]._M_dataplus._M_p + -8);
        *(int *)((long long)local_48[0]._M_dataplus._M_p + -8) = iVar4 + -1;
      }
      else {
        LOCK();
        iVar4 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar4 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long long)local_48[0]._M_dataplus._M_p + -0x18));
      }
    }
    if ((allocator *)(local_58[0] + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)(local_58[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar4 = *(int *)(local_58[0] + -8);
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
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar4 = *(int *)(local_68[0] + -8);
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
    if ((p_Var11 == (_Base_ptr)(PTR_data_store2_00311f70 + 8)) || (date < (int)p_Var11[1]._M_color)) goto LAB_00107720;
LAB_00107661:
    p_Var13 = (_Base_ptr)(this_01 + 8);
    do {
      while (__position._M_node = p_Var12, date <= (int)__position._M_node[1]._M_color) {
                    /* Unresolved local var: iterator __i@[???] */ p_Var12 = (__position._M_node)->_M_left;
        p_Var13 = __position._M_node;
        if ((__position._M_node)->_M_left == (_Base_ptr)0x0) goto LAB_0010768a;
      }
      pp_Var1 = &(__position._M_node)->_M_right;
      p_Var12 = *pp_Var1;
      __position._M_node = p_Var13;
    } while (*pp_Var1 != (_Base_ptr)0x0);
LAB_0010768a:
    if ((__position._M_node != (_Base_ptr)(this_01 + 8)) && ((int)__position._M_node[1]._M_color <= date)) goto LAB_00107703;
  }
                    /* Unresolved local var: _Link_type __z@[???] Unresolved local var: _Link_type __tmp@[???] */ p_Var5 = rea_operator_new(0x30);
  if (p_Var5 != (_Link_type)0x0) {
    (p_Var5->super__Rb_tree_node_base)._M_color = _S_red;
    (p_Var5->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (p_Var5->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (p_Var5->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (p_Var5->_M_value_field).first = date;
    (p_Var5->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
  }
                    /* Unresolved local var:
                       pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ __res@[???] */
  pVar15 = std_______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2___________________M_get_insert_hint_unique_pos______________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ *)this_01,(const_iterator)__position._M_node,&(p_Var5->_M_value_field).first) ;
  __position._M_node = pVar15.first;
  if (pVar15.second == (_Base_ptr)0x0) {
                    /* Unresolved local var: Data2 * * __ptr@[???] */ _Var7 = (p_Var5->_M_value_field).second._M_t. super__Tuple_impl;
    if (_Var7 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
      rea_IndexedData_GIDKey__Item2__free((IndexedData_GIDKey__Item2 *)_Var7);
      rea_operator_delete((void *)_Var7);
    }
    (p_Var5->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
    rea_operator_delete(p_Var5);
  }
  else {
    __position = std_____________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_________________________M_insert_node((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ *)this_01,__position._M_node,pVar15.second,p_Var5);
  }
LAB_00107703:
  return (Data2 *)__position._M_node[1]._M_parent;
}
// @@@ END IDX 150
// @@@ BEGIN IDX 151 rea_SecInfo__getMarketValue
// ------------------------------------------------------------------
// IDX 151  00107bc0  SecInfo__getMarketValue
// ------------------------------------------------------------------
double rea_SecInfo__getMarketValue(SecInfo * this_ptr, string * gid, int date) {
  rea_adr pIVar1;
  rea_adr pIVar2;
  char *__src;
  rea_adr __s1;
  int iVar3;
  rea_adr pDVar4;
  size_t __n;
  long long lVar5;
  long long lVar6;
  rea_v key;
  rea_v idx;
  
                    /* Unresolved local var: Data2 * data2@[???] */ pDVar4 = find_data2(this_ptr,date);
                    /* Unresolved local var: Item2 * item@[???] Unresolved local var: Index * idx@[???] Unresolved local var: ulong pos@[???] */ if ((pDVar4 != (Data2 *)0x0) && (*(ulong *)(rea_bind((gid->_M_dataplus))._M_p + -0x18) < 0x10)) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    __src = rea_bind((gid->_M_dataplus))._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(__src + -0x18);
    }
    rea_memcpy(&key,__src,__n);
    lVar5 = (long long)(pDVar4->super_IndexedData).num_idxs;
    __s1 = (pDVar4->super_IndexedData).idxs;
                    /* Unresolved local var: Index * it@[???] Unresolved local var: _DistanceType __len@[???] */ key.gid[__n] = '\0';
    idx.start = 0;
    idx.size = 0;
    pIVar1 = __s1 + lVar5;
    for (; 0 < lVar5; lVar5 = (lVar5 - lVar6) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Index * __middle@[???] */ lVar6 = lVar5 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */ iVar3 = rea_strcmp((char *)(__s1 + lVar6),(char *)&idx);
        if (iVar3 < 0) break;
        lVar5 = lVar6;
        if (lVar6 == 0) goto LAB_00107cc3;
      }
      __s1 = __s1 + lVar6 + 1;
    }
LAB_00107cc3:
                    /* Unresolved local var: int i@[???] */ if ((((pIVar1 != __s1) && (iVar3 = rea_strcmp((char *)__s1,(char *)&idx), iVar3 == 0)) && (__s1 != (Index *)0x0)) && (pIVar2 = (pDVar4->super_IndexedData).items + __s1->start, pIVar2 != (Item2 *)0x0)) {
      return pIVar2->marketvalue;
    }
  }
  return (double)rea_iv(DAT_0010fd10);
}
// @@@ END IDX 151
// @@@ BEGIN IDX 152 rea_SecInfo__get30DayIntradayAmplitude
// ------------------------------------------------------------------
// IDX 152  00107d40  SecInfo__get30DayIntradayAmplitude
// ------------------------------------------------------------------
double rea_SecInfo__get30DayIntradayAmplitude(SecInfo * this_ptr, string * gid, int date) {
  rea_adr pIVar1;
  rea_adr pIVar2;
  char *__src;
  rea_adr __s1;
  int iVar3;
  rea_adr pDVar4;
  size_t __n;
  long long lVar5;
  long long lVar6;
  rea_v key;
  rea_v idx;
  
                    /* Unresolved local var: Data2 * data2@[???] */ pDVar4 = find_data2(this_ptr,date);
                    /* Unresolved local var: Item2 * item@[???] Unresolved local var: Index * idx@[???] Unresolved local var: ulong pos@[???] */ if ((pDVar4 != (Data2 *)0x0) && (*(ulong *)(rea_bind((gid->_M_dataplus))._M_p + -0x18) < 0x10)) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    __src = rea_bind((gid->_M_dataplus))._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(__src + -0x18);
    }
    rea_memcpy(&key,__src,__n);
    lVar5 = (long long)(pDVar4->super_IndexedData).num_idxs;
    __s1 = (pDVar4->super_IndexedData).idxs;
                    /* Unresolved local var: Index * it@[???] Unresolved local var: _DistanceType __len@[???] */ key.gid[__n] = '\0';
    idx.start = 0;
    idx.size = 0;
    pIVar1 = __s1 + lVar5;
    for (; 0 < lVar5; lVar5 = (lVar5 - lVar6) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Index * __middle@[???] */ lVar6 = lVar5 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */ iVar3 = rea_strcmp((char *)(__s1 + lVar6),(char *)&idx);
        if (iVar3 < 0) break;
        lVar5 = lVar6;
        if (lVar6 == 0) goto LAB_00107e43;
      }
      __s1 = __s1 + lVar6 + 1;
    }
LAB_00107e43:
                    /* Unresolved local var: int i@[???] */ if ((((pIVar1 != __s1) && (iVar3 = rea_strcmp((char *)__s1,(char *)&idx), iVar3 == 0)) && (__s1 != (Index *)0x0)) && (pIVar2 = (pDVar4->super_IndexedData).items + __s1->start, pIVar2 != (Item2 *)0x0)) {
      return pIVar2->intradayamplitude_30day;
    }
  }
  return (double)rea_iv(DAT_0010fd10);
}
// @@@ END IDX 152
// @@@ BEGIN IDX 153 rea_SecInfo__get30DayTurnoverRate
// ------------------------------------------------------------------
// IDX 153  00107ec0  SecInfo__get30DayTurnoverRate
// ------------------------------------------------------------------
double rea_SecInfo__get30DayTurnoverRate(SecInfo * this_ptr, string * gid, int date) {
  rea_adr pIVar1;
  rea_adr pIVar2;
  char *__src;
  rea_adr __s1;
  int iVar3;
  rea_adr pDVar4;
  size_t __n;
  long long lVar5;
  long long lVar6;
  rea_v key;
  rea_v idx;
  
                    /* Unresolved local var: Data2 * data2@[???] */ pDVar4 = find_data2(this_ptr,date);
                    /* Unresolved local var: Item2 * item@[???] Unresolved local var: Index * idx@[???] Unresolved local var: ulong pos@[???] */ if ((pDVar4 != (Data2 *)0x0) && (*(ulong *)(rea_bind((gid->_M_dataplus))._M_p + -0x18) < 0x10)) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    __src = rea_bind((gid->_M_dataplus))._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(__src + -0x18);
    }
    rea_memcpy(&key,__src,__n);
    lVar5 = (long long)(pDVar4->super_IndexedData).num_idxs;
    __s1 = (pDVar4->super_IndexedData).idxs;
                    /* Unresolved local var: Index * it@[???] Unresolved local var: _DistanceType __len@[???] */ key.gid[__n] = '\0';
    idx.start = 0;
    idx.size = 0;
    pIVar1 = __s1 + lVar5;
    for (; 0 < lVar5; lVar5 = (lVar5 - lVar6) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Index * __middle@[???] */ lVar6 = lVar5 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */ iVar3 = rea_strcmp((char *)(__s1 + lVar6),(char *)&idx);
        if (iVar3 < 0) break;
        lVar5 = lVar6;
        if (lVar6 == 0) goto LAB_00107fc3;
      }
      __s1 = __s1 + lVar6 + 1;
    }
LAB_00107fc3:
                    /* Unresolved local var: int i@[???] */ if ((((pIVar1 != __s1) && (iVar3 = rea_strcmp((char *)__s1,(char *)&idx), iVar3 == 0)) && (__s1 != (Index *)0x0)) && (pIVar2 = (pDVar4->super_IndexedData).items + __s1->start, pIVar2 != (Item2 *)0x0)) {
      return pIVar2->turnoverrate_30day;
    }
  }
  return (double)rea_iv(DAT_0010fd10);
}
// @@@ END IDX 153
// @@@ BEGIN IDX 154 rea_SecInfo__get30DayRmbVolume
// ------------------------------------------------------------------
// IDX 154  00108040  SecInfo__get30DayRmbVolume
// ------------------------------------------------------------------
double rea_SecInfo__get30DayRmbVolume(SecInfo * this_ptr, string * gid, int date) {
  rea_adr pIVar1;
  rea_adr pIVar2;
  char *__src;
  rea_adr __s1;
  int iVar3;
  rea_adr pDVar4;
  size_t __n;
  long long lVar5;
  long long lVar6;
  rea_v key;
  rea_v idx;
  
                    /* Unresolved local var: Data2 * data2@[???] */ pDVar4 = find_data2(this_ptr,date);
                    /* Unresolved local var: Item2 * item@[???] Unresolved local var: Index * idx@[???] Unresolved local var: ulong pos@[???] */ if ((pDVar4 != (Data2 *)0x0) && (*(ulong *)(rea_bind((gid->_M_dataplus))._M_p + -0x18) < 0x10)) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    __src = rea_bind((gid->_M_dataplus))._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(__src + -0x18);
    }
    rea_memcpy(&key,__src,__n);
    lVar5 = (long long)(pDVar4->super_IndexedData).num_idxs;
    __s1 = (pDVar4->super_IndexedData).idxs;
                    /* Unresolved local var: Index * it@[???] Unresolved local var: _DistanceType __len@[???] */ key.gid[__n] = '\0';
    idx.start = 0;
    idx.size = 0;
    pIVar1 = __s1 + lVar5;
    for (; 0 < lVar5; lVar5 = (lVar5 - lVar6) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Index * __middle@[???] */ lVar6 = lVar5 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */ iVar3 = rea_strcmp((char *)(__s1 + lVar6),(char *)&idx);
        if (iVar3 < 0) break;
        lVar5 = lVar6;
        if (lVar6 == 0) goto LAB_00108143;
      }
      __s1 = __s1 + lVar6 + 1;
    }
LAB_00108143:
                    /* Unresolved local var: int i@[???] */ if ((((pIVar1 != __s1) && (iVar3 = rea_strcmp((char *)__s1,(char *)&idx), iVar3 == 0)) && (__s1 != (Index *)0x0)) && (pIVar2 = (pDVar4->super_IndexedData).items + __s1->start, pIVar2 != (Item2 *)0x0)) {
      return pIVar2->rmbvolume_30day;
    }
  }
  return (double)rea_iv(DAT_0010fd10);
}
// @@@ END IDX 154
// @@@ BEGIN IDX 155 rea_SecInfo__find_group_data1__dup2
// ------------------------------------------------------------------
// IDX 155  001081c0  SecInfo__find_group_data1
// ------------------------------------------------------------------
GroupData1 * rea_SecInfo__find_group_data1__dup2(SecInfo * this_ptr, int date) {
  rea_adr pp_Var1;
  int *piVar2;
  rea_v this_00;
  undefined *this_01;
  undefined *puVar3;
  rea_v sVar4;
  rea_v p_Var5;
  int iVar6;
  rea_v iVar7;
  rea_v __z;
  long long *plVar8;
  FILE *__stream;
  size_t sVar9;
  rea_v _Var10;
  void *pvVar11;
  rea_v p_Var12;
  ulong uVar13;
  rea_v pVar14;
  uint local_7c [5];
  long long local_68 [2];
  int version;
  rea_v local_48 [3];
  
  this_01 = PTR_group_data_store1_00311fc0;
  local_7c[0] = date;
  iVar7 = std______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________find((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ *)PTR_group_data_store1_00311fc0,(int *)local_7c);
  if (iVar7._M_node == (_Base_ptr)(this_01 + 8)) {
                    /* Unresolved local var: FILE * fp@[???] */ rea___gnu_cxx____to_xstring_std__basic_string_char__char ((code *) local_68,(size_t)PTR_vsnprintf_00311fd0,(char *)0x10,(void *)&DAT_0010fc03,(ulong)local_7c[0] );
    plVar8 = (long long *)rea_std__string__insert((ulong)local_68,(char *)0x0,0x10fc13);
    puVar3 = PTR__S_empty_rep_storage_00311ff0;
    _version = *plVar8;
    *plVar8 = (long long)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    plVar8 = (long long *)rea_std__string__append((char *)&version,0x10fbfd);
    local_48[0]._M_dataplus._M_p = (_Alloc_hider)*plVar8;
    *plVar8 = (long long)(puVar3 + 0x18);
    __stream = rea_open_file((string*)rea_pv(local_48));
    if ((allocator *)((long long)local_48[0]._M_dataplus._M_p + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)((long long)local_48[0]._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar6 = *(int *)((long long)local_48[0]._M_dataplus._M_p + -8);
        *(int *)((long long)local_48[0]._M_dataplus._M_p + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long long)local_48[0]._M_dataplus._M_p + -0x18));
      }
    }
    if ((allocator *)(_version + -0x18) != (allocator *)puVar3) {
      piVar2 = (int *)(_version + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar6 = *(int *)(_version + -8);
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
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar6 = *(int *)(local_68[0] + -8);
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
    if (((__stream == (FILE *)0x0) || (sVar9 = rea_fread(&version,4,1,(FILE *)__stream), sVar9 != 1)) || (version != 0)) {
      return (GroupData1 *)0x0;
    }
    _Var10._M_p = rea_operator_new(0x18);
                    /* Unresolved local var: bool fail@[???] */ _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)(_Var10._M_p + 4) < 0xaa0000000000001) {
        uVar13 = (long long)*(int *)(_Var10._M_p + 4) * 0xc;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long long)*(int *)_Var10._M_p) || (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),0xc,(long long)*(int *)(_Var10._M_p + 4), (FILE *)__stream), sVar9 != (long long)*(int *)(_Var10._M_p + 4))) goto LAB_00108410;
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
        *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    local_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ *)this_01);
    sVar4._M_dataplus._M_p = local_48[0]._M_dataplus._M_p;
                    /* Unresolved local var: GroupData1 * * __ptr@[???] */ if (local_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)local_48[0]._M_dataplus._M_p = 0;
      *(int *)((long long)local_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long long)local_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)local_48[0]._M_dataplus._M_p + 8));
        ((int *)((long long)sVar4._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long long)sVar4._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long long)sVar4._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)sVar4._M_dataplus._M_p + 0x10));
        ((int *)((long long)sVar4._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long long)sVar4._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar4._M_dataplus._M_p);
    }
    _Var10._M_p = rea_operator_new(0x18);
                    /* Unresolved local var: bool fail@[???] */ _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)(_Var10._M_p + 4) < 0x3f80000000000001) {
        uVar13 = (long long)*(int *)(_Var10._M_p + 4) * 2;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long long)*(int *)_Var10._M_p) || (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),2,(long long)*(int *)(_Var10._M_p + 4), (FILE *)__stream), sVar9 != (long long)*(int *)(_Var10._M_p + 4))) goto LAB_00108500;
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
        *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    local_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ *)PTR_group_data_store2_00311ff8);
    sVar4._M_dataplus._M_p = local_48[0]._M_dataplus._M_p;
                    /* Unresolved local var: GroupData2 * * __ptr@[???] */ if (local_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)local_48[0]._M_dataplus._M_p = 0;
      *(int *)((long long)local_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long long)local_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)local_48[0]._M_dataplus._M_p + 8));
        ((int *)((long long)sVar4._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long long)sVar4._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long long)sVar4._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)sVar4._M_dataplus._M_p + 0x10));
        ((int *)((long long)sVar4._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long long)sVar4._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar4._M_dataplus._M_p);
    }
    rea_fclose((FILE *)__stream);
  }
                    /* Unresolved local var: iterator __i@[???] */ if (rea_bind(*(_Base_ptr *)(this_01 + 0x10)) == (_Base_ptr)0x0) {
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
    if ((iVar7._M_node != (_Base_ptr)(this_01 + 8)) && ((int)iVar7._M_node[1]._M_color <= (int)local_7c[0])) goto LAB_00108238;
  }
                    /* Unresolved local var: _Link_type __z@[???] Unresolved local var: _Link_type __tmp@[???] */ __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
    (__z->_M_value_field).first = local_7c[0];
  }
                    /* Unresolved local var:
                       pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ __res@[???] */
  pVar14 = std_______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1___________________M_get_insert_hint_unique_pos______________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ *)this_01,(const_iterator)iVar7._M_node,&(__z->_M_value_field).first);
  iVar7._M_node = pVar14.first;
  if (pVar14.second == (_Base_ptr)0x0) {
                    /* Unresolved local var: GroupData1 * * __ptr@[???] */ this_00 = (__z->_M_value_field).second._M_t. super__Tuple_impl ;
    if (this_00 != (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0) {
      IndexedData_GroupKey__GroupForwardItem__free_________________((IndexedData_GroupKey__GroupForwardItem *)this_00);
      rea_operator_delete((void *)this_00);
    }
    (__z->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
    rea_operator_delete(__z);
  }
  else {
    iVar7 = std________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____________________M_insert_node((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ *)this_01,iVar7._M_node,pVar14.second,__z);
  }
LAB_00108238:
  return (GroupData1 *)iVar7._M_node[1]._M_parent;
}
// @@@ END IDX 155
// @@@ BEGIN IDX 156 rea_SecInfo__find_group_data2__dup2
// ------------------------------------------------------------------
// IDX 156  001088e0  SecInfo__find_group_data2
// ------------------------------------------------------------------
GroupData2 * rea_SecInfo__find_group_data2__dup2(SecInfo * this_ptr, int date) {
  rea_adr pp_Var1;
  int *piVar2;
  rea_v p_Var3;
  rea_v this_00;
  undefined *this_01;
  undefined *puVar4;
  rea_v sVar5;
  int iVar6;
  rea_v iVar7;
  rea_v __z;
  rea_v __position;
  long long *plVar8;
  FILE *__stream;
  size_t sVar9;
  rea_v _Var10;
  void *pvVar11;
  rea_v p_Var12;
  rea_adr this_02;
  ulong uVar13;
  rea_v pVar14;
  uint local_7c [5];
  long long local_68 [2];
  int version;
  rea_v local_48 [3];
  
  this_01 = PTR_group_data_store1_00311fc0;
  local_7c[0] = date;
  iVar7 = std______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________find((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ *)PTR_group_data_store1_00311fc0,(int *)local_7c);
  this_02 = (_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ *)PTR_group_data_store2_00311ff8;
  if (iVar7._M_node == (_Base_ptr)(this_01 + 8)) {
                    /* Unresolved local var: FILE * fp@[???] */ rea___gnu_cxx____to_xstring_std__basic_string_char__char ((code *) local_68,(size_t)PTR_vsnprintf_00311fd0,(char *)0x10,(void *)&DAT_0010fc03,(ulong)local_7c[0] );
    plVar8 = (long long *)rea_std__string__insert((ulong)local_68,(char *)0x0,0x10fc13);
    puVar4 = PTR__S_empty_rep_storage_00311ff0;
    _version = *plVar8;
    *plVar8 = (long long)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    plVar8 = (long long *)rea_std__string__append((char *)&version,0x10fbfd);
    local_48[0]._M_dataplus._M_p = (_Alloc_hider)*plVar8;
    *plVar8 = (long long)(puVar4 + 0x18);
    __stream = rea_open_file((string*)rea_pv(local_48));
    if ((allocator *)((long long)local_48[0]._M_dataplus._M_p + -0x18) != (allocator *)puVar4) {
      piVar2 = (int *)((long long)local_48[0]._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar6 = *(int *)((long long)local_48[0]._M_dataplus._M_p + -8);
        *(int *)((long long)local_48[0]._M_dataplus._M_p + -8) = iVar6 + -1;
      }
      else {
        LOCK();
        iVar6 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar6 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long long)local_48[0]._M_dataplus._M_p + -0x18));
      }
    }
    if ((allocator *)(_version + -0x18) != (allocator *)puVar4) {
      piVar2 = (int *)(_version + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar6 = *(int *)(_version + -8);
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
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar6 = *(int *)(local_68[0] + -8);
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
    if (((__stream == (FILE *)0x0) || (sVar9 = rea_fread(&version,4,1,(FILE *)__stream), sVar9 != 1)) || (version != 0)) {
      return (GroupData2 *)0x0;
    }
    _Var10._M_p = rea_operator_new(0x18);
                    /* Unresolved local var: bool fail@[???] */ _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)(_Var10._M_p + 4) < 0xaa0000000000001) {
        uVar13 = (long long)*(int *)(_Var10._M_p + 4) * 0xc;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long long)*(int *)_Var10._M_p) || (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),0xc,(long long)*(int *)(_Var10._M_p + 4), (FILE *)__stream), sVar9 != (long long)*(int *)(_Var10._M_p + 4))) goto LAB_00108b30;
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
        *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    local_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ *)this_01);
    sVar5._M_dataplus._M_p = local_48[0]._M_dataplus._M_p;
                    /* Unresolved local var: GroupData1 * * __ptr@[???] */ if (local_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)local_48[0]._M_dataplus._M_p = 0;
      *(int *)((long long)local_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long long)local_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)local_48[0]._M_dataplus._M_p + 8));
        ((int *)((long long)sVar5._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long long)sVar5._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long long)sVar5._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)sVar5._M_dataplus._M_p + 0x10));
        ((int *)((long long)sVar5._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long long)sVar5._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar5._M_dataplus._M_p);
    }
    _Var10._M_p = rea_operator_new(0x18);
                    /* Unresolved local var: bool fail@[???] */ _Var10._M_p[0] = '\0';
    _Var10._M_p[1] = '\0';
    _Var10._M_p[2] = '\0';
    _Var10._M_p[3] = '\0';
    *(int *)(_Var10._M_p + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
    *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
    sVar9 = rea_fread(_Var10._M_p,4,1,(FILE *)__stream);
    if ((sVar9 == 1) && (sVar9 = rea_fread(_Var10._M_p + 4,4,1,(FILE *)__stream), sVar9 == 1)) {
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)_Var10._M_p < 0x550000000000001) {
        uVar13 = (long long)*(int *)_Var10._M_p * 0x18;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 8) = pvVar11;
      uVar13 = 0xffffffffffffffff;
      if ((ulong)(long long)*(int *)(_Var10._M_p + 4) < 0x3f80000000000001) {
        uVar13 = (long long)*(int *)(_Var10._M_p + 4) * 2;
      }
      pvVar11 = (void*)rea_pv(rea_operator_new(uVar13));
      *(void **)(_Var10._M_p + 0x10) = pvVar11;
      sVar9 = rea_fread(*(void **)(_Var10._M_p + 8),0x18,(long long)*(int *)_Var10._M_p,(FILE *)__stream);
      if ((sVar9 != (long long)*(int *)_Var10._M_p) || (sVar9 = rea_fread(*(void **)(_Var10._M_p + 0x10),2,(long long)*(int *)(_Var10._M_p + 4), (FILE *)__stream), sVar9 != (long long)*(int *)(_Var10._M_p + 4))) goto LAB_00108c18;
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
        *(int *)((long long)(_Var10._M_p + 8) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 8) + 4) = 0;
      }
      if (*(void **)(_Var10._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)(_Var10._M_p + 0x10));
        *(int *)((long long)(_Var10._M_p + 0x10) + 0) = 0;
        *(int *)((long long)(_Var10._M_p + 0x10) + 4) = 0;
      }
    }
    this_02 = (_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ *)PTR_group_data_store2_00311ff8;
    local_48[0]._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var10._M_p;
    std________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________((_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ *)PTR_group_data_store2_00311ff8);
    sVar5._M_dataplus._M_p = local_48[0]._M_dataplus._M_p;
                    /* Unresolved local var: GroupData2 * * __ptr@[???] */ if (local_48[0]._M_dataplus._M_p != (char *)0x0) {
      *(int *)local_48[0]._M_dataplus._M_p = 0;
      *(int *)((long long)local_48[0]._M_dataplus._M_p + 4) = 0;
      if (*(void **)((long long)local_48[0]._M_dataplus._M_p + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)local_48[0]._M_dataplus._M_p + 8));
        ((int *)((long long)sVar5._M_dataplus._M_p + 8))[0] = 0;
        ((int *)((long long)sVar5._M_dataplus._M_p + 8))[1] = 0;
      }
      if (*(void **)((long long)sVar5._M_dataplus._M_p + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)sVar5._M_dataplus._M_p + 0x10));
        ((int *)((long long)sVar5._M_dataplus._M_p + 0x10))[0] = 0;
        ((int *)((long long)sVar5._M_dataplus._M_p + 0x10))[1] = 0;
      }
      rea_operator_delete((void *)sVar5._M_dataplus._M_p);
    }
    rea_fclose((FILE *)__stream);
  }
  p_Var3 = (this_02->_M_impl)._M_header._M_parent;
                    /* Unresolved local var: iterator __i@[???] */ if (p_Var3 == (_Base_ptr)0x0) {
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
    if ((__position._M_node != &(this_02->_M_impl)._M_header) && ((int)__position._M_node[1]._M_color <= (int)local_7c[0])) goto LAB_00108958;
  }
                    /* Unresolved local var: _Link_type __z@[???] Unresolved local var: _Link_type __tmp@[???] */ __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
    (__z->_M_value_field).first = local_7c[0];
  }
                    /* Unresolved local var:
                       pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ __res@[???] */
  pVar14 = std_______________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2___________________M_get_insert_hint_unique_pos______________________(this_02,(const_iterator)__position._M_node,&(__z->_M_value_field).first);
  __position._M_node = pVar14.first;
  if (pVar14.second == (_Base_ptr)0x0) {
                    /* Unresolved local var: GroupData2 * * __ptr@[???] */ this_00 = (__z->_M_value_field).second._M_t. super__Tuple_impl ;
    if (this_00 != (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0) {
      IndexedData_GIDKey__GroupBackwardItem__free_________________((IndexedData_GIDKey__GroupBackwardItem *)this_00);
      rea_operator_delete((void *)this_00);
    }
    (__z->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
    rea_operator_delete(__z);
  }
  else {
    __position = std_____________________Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________________________M_insert_node(this_02,__position._M_node,pVar14.second,__z);
  }
LAB_00108958:
  return (GroupData2 *)__position._M_node[1]._M_parent;
}
// @@@ END IDX 156
// @@@ BEGIN IDX 157 rea_SecInfo__getGroups
// ------------------------------------------------------------------
// IDX 157  00108ff0  SecInfo__getGroups
// ------------------------------------------------------------------
Set_SecInfo__GroupsIterator * rea_SecInfo__getGroups(Set_SecInfo__GroupsIterator * __return_storage_ptr__, SecInfo * this_ptr, string * gid, int date) {
  rea_adr pIVar1;
  int iVar2;
  char *__src;
  rea_adr pGVar3;
  rea_adr pIVar4;
  int iVar5;
  rea_adr pGVar6;
  rea_adr pGVar7;
  size_t __n;
  long long lVar8;
  rea_adr __s1;
  long long lVar9;
  rea_v key;
  rea_v res;
  rea_v idx;
  
                    /* Unresolved local var: GroupData1 * data1@[???] Unresolved local var: GroupData2 * data2@[???] */ pGVar6 = find_group_data1(this_ptr,date);
  pGVar7 = find_group_data2(this_ptr,date);
                    /* Unresolved local var: Index * idx@[???] Unresolved local var: ulong pos@[???] */ if (((pGVar7 != (GroupData2 *)0x0) && (pGVar6 != (GroupData1 *)0x0)) && (*(ulong *)(rea_bind((gid->_M_dataplus))._M_p + -0x18) < 0x10)) {
    __n = rea_std__string__find((char *)gid,0x10fb8f,0);
    __src = rea_bind((gid->_M_dataplus))._M_p;
    if (__n == 0xffffffffffffffff) {
      __n = *(size_t *)(__src + -0x18);
    }
    rea_memcpy(&key,__src,__n);
    lVar8 = (long long)(pGVar7->super_IndexedData).num_idxs;
    key.gid[__n] = '\0';
                    /* Unresolved local var: Index * it@[???] */ __s1 = (pGVar7->super_IndexedData).idxs;
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
                    /* Unresolved local var: _DistanceType __len@[???] */ idx.key.gid[8] = key.gid[8];
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
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Index * __middle@[???] */ lVar9 = lVar8 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */ iVar5 = rea_strcmp((char *)(__s1 + lVar9),(char *)&idx);
        if (iVar5 < 0) break;
        lVar8 = lVar9;
        if (lVar9 == 0) goto LAB_001091c0;
      }
      __s1 = __s1 + lVar9 + 1;
    }
LAB_001091c0:
    if (((pIVar1 != __s1) && (iVar5 = rea_strcmp((char *)__s1,(char *)&idx), iVar5 == 0)) && (__s1 != (Index *)0x0)) {
      iVar5 = __s1->start;
      pGVar3 = (pGVar7->super_IndexedData).items;
      iVar2 = __s1->size;
      rea_bind(__return_storage_ptr__)->data2 = pGVar7;
      rea_bind(__return_storage_ptr__)->mask_eod_values = false;
      rea_bind(__return_storage_ptr__)->data1 = pGVar6;
      pIVar4 = (pGVar6->super_IndexedData).idxs;
      rea_bind(__return_storage_ptr__)->size_ = iVar2;
      rea_bind(__return_storage_ptr__)->base = pGVar3 + iVar5;
      rea_bind(__return_storage_ptr__)->idxbase = pIVar4;
      return __return_storage_ptr__;
    }
  }
  rea_bind(__return_storage_ptr__)->data1 = (GroupData1 *)0x0;
  rea_bind(__return_storage_ptr__)->data2 = (GroupData2 *)0x0;
  rea_bind(__return_storage_ptr__)->idxbase = (void *)0x0;
  rea_bind(__return_storage_ptr__)->base = (void *)0x0;
  rea_bind(__return_storage_ptr__)->size_ = 0;
  rea_bind(__return_storage_ptr__)->mask_eod_values = false;
  return __return_storage_ptr__;
}
// @@@ END IDX 157
// @@@ BEGIN IDX 158 rea_SecInfo__getMembers
// ------------------------------------------------------------------
// IDX 158  00109280  SecInfo__getMembers
// ------------------------------------------------------------------
Set_SecInfo__MembersIterator * rea_SecInfo__getMembers(Set_SecInfo__MembersIterator * __return_storage_ptr__, SecInfo * this_ptr, string * group, int date) {
  rea_adr pIVar1;
  int iVar2;
  char *__src;
  rea_adr pGVar3;
  rea_adr pIVar4;
  int iVar5;
  rea_adr pGVar6;
  rea_adr pGVar7;
  long long lVar8;
  rea_adr __s1;
  long long lVar9;
  rea_v key;
  rea_v res;
  rea_v idx;
  
                    /* Unresolved local var: GroupData1 * data1@[???] Unresolved local var: GroupData2 * data2@[???] */ pGVar6 = find_group_data1(this_ptr,date);
  pGVar7 = find_group_data2(this_ptr,date);
                    /* Unresolved local var: Index * idx@[???] */ if (((pGVar7 != (GroupData2 *)0x0) && (pGVar6 != (GroupData1 *)0x0)) && (__src = rea_bind((group->_M_dataplus))._M_p, *(ulong *)(__src + -0x18) < 0x10)) {
    rea_strcpy(key.group_name,__src);
                    /* Unresolved local var: Index * it@[???] */ lVar8 = (long long)(pGVar6->super_IndexedData).num_idxs;
    __s1 = (pGVar6->super_IndexedData).idxs;
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
                    /* Unresolved local var: _DistanceType __len@[???] */ pIVar1 = __s1 + lVar8;
    for (; 0 < lVar8; lVar8 = (lVar8 - lVar9) + -1) {
      while( true ) {
                    /* Unresolved local var: _DistanceType __half@[???] Unresolved local var: Index * __middle@[???] */ lVar9 = lVar8 >> 1;
                    /* Unresolved local var: difference_type __d@[???] */ iVar5 = rea_strcmp((char *)(__s1 + lVar9),(char *)&idx);
        if (iVar5 < 0) break;
        lVar8 = lVar9;
        if (lVar9 == 0) goto LAB_00109420;
      }
      __s1 = __s1 + lVar9 + 1;
    }
LAB_00109420:
    if (((pIVar1 != __s1) && (iVar5 = rea_strcmp((char *)__s1,(char *)&idx), iVar5 == 0)) && (__s1 != (Index *)0x0)) {
      iVar5 = __s1->start;
      iVar2 = __s1->size;
      rea_bind(__return_storage_ptr__)->data2 = pGVar7;
      rea_bind(__return_storage_ptr__)->mask_eod_values = false;
      rea_bind(__return_storage_ptr__)->data1 = pGVar6;
      pGVar3 = (pGVar6->super_IndexedData).items;
      rea_bind(__return_storage_ptr__)->size_ = iVar2;
      pIVar4 = (pGVar7->super_IndexedData).idxs;
      rea_bind(__return_storage_ptr__)->base = pGVar3 + iVar5;
      rea_bind(__return_storage_ptr__)->idxbase = pIVar4;
      return __return_storage_ptr__;
    }
  }
  rea_bind(__return_storage_ptr__)->data1 = (GroupData1 *)0x0;
  rea_bind(__return_storage_ptr__)->data2 = (GroupData2 *)0x0;
  rea_bind(__return_storage_ptr__)->idxbase = (void *)0x0;
  rea_bind(__return_storage_ptr__)->base = (void *)0x0;
  rea_bind(__return_storage_ptr__)->size_ = 0;
  rea_bind(__return_storage_ptr__)->mask_eod_values = false;
  return __return_storage_ptr__;
}
// @@@ END IDX 158
// @@@ BEGIN IDX 159 rea_PyWrapper_std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char
// ------------------------------------------------------------------
// IDX 159  001094e0  PyWrapper<std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char____
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char(undefined8 * pyargs) {
  rea_adr __k;
  rea_adr pp_Var1;
  rea_adr ppbVar2;
  int *piVar3;
  uchar *puVar4;
  uchar uVar5;
  void *pvVar6;
  rea_v p_Var7;
  rea_adr psVar8;
  rea_adr psVar9;
  rea_adr psVar10;
  rea_v pbVar11;
  rea_v pbVar12;
  double dVar13;
  rea_v pbVar14;
  int iVar15;
  char *pcVar16;
  rea_v puVar17;
  rea_v p;
  rea_v iVar18;
  rea_adr p_Var19;
  rea_adr p_Var20;
  undefined8 uVar21;
  undefined8 uVar22;
  rea_v sVar23;
  rea_v __src;
  rea_v pbVar24;
  rea_adr psVar25;
  char *pcVar26;
  rea_v bVar27;
  ulong uVar28;
  uchar *puVar29;
  rea_v p_Var30;
  rea_v p_Var31;
  ulong uVar32;
  rea_adr psVar33;
  rea_adr pPVar34;
  ulong uVar35;
  rea_adr ppVar36;
  long long lVar37;
  bool bVar38;
  undefined1 local_280 [2];
  rea_v local_27e [3];
  undefined1 local_27b [2];
  rea_v local_279;
  rea_v t;
  uchar *local_268 [2];
  rea_v ts;
  rea_v buf;
  rea_v fmt;
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
  rea_v index;
  rea_v rv;
  double prc;
  rea_adr local_190;
  undefined8 local_188;
  rea_v local_180;
  double volume;
  rea_adr local_170;
  long long local_168;
  rea_v local_160;
  rea_v r;
  rea_v se_prc;
  rea_v se_volume;
  rea_v se_alphas;
  rea_v hold;
  rea_v usable;
  rea_adr pa;
  
  usable._M_t._M_impl._M_key_compare. super_binary_function = (binary_function )0x4f;
  (*(undefined1 *)((uint8_t *)&rea_bind(usable._M_t)._M_impl + 0x1)) = 0;
  iVar15 = rea_PyArg_ParseTuple(pyargs,(allocator *)&usable,&t);
  if (iVar15 == 0) {
    return (undefined8)(PyObject *)0x0;
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
  index. super__Vector_base ._M_impl._M_start = (pointer)0x0;
  index. super__Vector_base ._M_impl._M_finish = (pointer)0x0;
                    /* Unresolved local var: size_type __n@[???] */ __src = (pointer)0x0;
  index. super__Vector_base ._M_impl._M_end_of_storage = (pointer)0x0;
  uVar35 = *(ulong *)(local_268[0] + -0x18);
  rv.super__Vector_base._M_impl._M_start = (pointer)0x0;
  rv.super__Vector_base._M_impl._M_finish = (pointer)0x0;
  rv.super__Vector_base._M_impl._M_end_of_storage = (pointer)0x0;
  buf._M_dataplus._M_p = ts._M_dataplus._M_p;
  se_prc._M_t._M_impl._M_header._M_right = se_prc._M_t._M_impl._M_header._M_left;
  se_volume._M_t._M_impl._M_header._M_right = se_volume._M_t._M_impl._M_header._M_left;
  se_alphas._M_t._M_impl._M_header._M_right = se_alphas._M_t._M_impl._M_header._M_left;
  hold._M_t._M_impl._M_header._M_right = hold._M_t._M_impl._M_header._M_left;
  usable._M_t._M_impl._M_header._M_right = usable._M_t._M_impl._M_header._M_left;
  if (uVar35 != 0) {
    __src = rea_operator_new(uVar35);
  }
  rv.super__Vector_base._M_impl._M_end_of_storage = __src + uVar35;
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: _Distance __n@[???] */ puVar4 = puVar29 + uVar35;
  puVar17 = __src;
  rv.super__Vector_base._M_impl._M_start = __src;
  if ((long long)uVar35 < 1) {
    fmt._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    rv.super__Vector_base._M_impl._M_finish = __src;
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
                    /* Unresolved local var: size_t l@[???] Unresolved local var: size_t np@[???] Unresolved local var: size_t p@[???] */ fmt._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
                    /* Unresolved local var: uint8_t * s@[???] */ rv.super__Vector_base._M_impl._M_finish = rv.super__Vector_base._M_impl. _M_end_of_storage;
    if ((ulong)((long long)rv.super__Vector_base._M_impl. _M_end_of_storage - (long long)__src) < 8) goto LAB_0010a170;
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ rea_memcpy(&r,__src,8);
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
      if (*(size_t *)((long long)fmt._M_dataplus._M_p + -0x18) != *(size_t *)((long long)hv + -0x18)) {
        rea_std__string___Rep___M_dispose((allocator *)((long long)hv + -0x18));
        goto LAB_001098d9;
      }
      iVar15 = rea_memcmp((void *)fmt._M_dataplus._M_p,rea_cast<void* >(hv), *(size_t *)((long long)fmt._M_dataplus._M_p + -0x18));
      rea_std__string___Rep___M_dispose((allocator *)((long long)dVar13 + -0x18));
      if (iVar15 != 0) goto LAB_001098d9;
                    /* Unresolved local var: size_t np@[???] */ pcVar16 = (char *)detail___________________________P_std__basic_string_char__std__char_traits_char__std__allocator_char_____________________________parse(&rv,(size_t)p._M_p,&ts);
                    /* Unresolved local var: size_t np@[???] */ /* Unresolved local var: size_t np@[???] */ /* Unresolved local var: size_t np@[???] */ /* Unresolved local var: size_t np@[???] */ if ((((p._M_p != pcVar16) && (pcVar26 = (char *)
                              rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse(&rv,(size_t)pcVar16, (map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ *)&se_prc._M_t), p._M_p = pcVar16, pcVar16 != pcVar26)) && (pcVar16 = (char *)
                             rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse(&rv,(size_t)pcVar26, (map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ *)&se_volume._M_t), p._M_p = pcVar26, pcVar26 != pcVar16)) && ((pcVar26 = (char *)
                             rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____M___parse(&rv,(size_t)pcVar16, (map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ *)&se_alphas._M_t), p._M_p = pcVar16, pcVar16 != pcVar26 && (pcVar16 = (char *)
                             rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse(&rv,(size_t)pcVar26, (map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ *)&hold._M_t), p._M_p = pcVar26, pcVar26 != pcVar16)))) {
                    /* Unresolved local var: size_t np@[???] */ p._M_p = (char *)
                         rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse(&rv,(size_t)pcVar16,&usable);
      }
      bVar38 = bVar27._M_dataplus._M_p == (_Alloc_hider)p._M_p;
      sVar23._M_dataplus._M_p = fmt._M_dataplus._M_p;
    }
  }
  if ((allocator *)((long long)sVar23._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar3 = (int *)((long long)sVar23._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar15 = *(int *)((long long)sVar23._M_dataplus._M_p + -8);
      *(int *)((long long)sVar23._M_dataplus._M_p + -8) = iVar15 + -1;
    }
    else {
      LOCK();
      iVar15 = *piVar3;
      *piVar3 = *piVar3 + -1;
      UNLOCK();
    }
    if (iVar15 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long long)sVar23._M_dataplus._M_p + -0x18));
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
        if (index. super__Vector_base ._M_impl._M_finish == index. super__Vector_base ._M_impl._M_end_of_storage) {
          std_____________vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char____________________________M_emplace_back_aux_const_std__basic_string_char__std__char_traits_char__std__allocator_char_______________________(&index);
        }
        else {
          if (index. super__Vector_base ._M_impl._M_finish == (pointer)0x0) {
            index. super__Vector_base ._M_impl._M_finish = (pointer)0x0;
          }
          else {
            rea_std__string__string(index. super__Vector_base ._M_impl._M_finish,(string *)__k);
          }
          index. super__Vector_base ._M_impl._M_finish = index. super__Vector_base ._M_impl._M_finish + 1;
        }
        hv = 0.0;
        iVar18 = std_____________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______________________find(&hold._M_t, (basic_string_char__std__char_traits_char__std__allocator_char_ *)__k);
        if (iVar18._M_node != &hold._M_t._M_impl._M_header) {
          hv = (double)iVar18._M_node[1]._M_parent;
        }
        uv = 0.0;
        iVar18 = std_____________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______________________find((_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ *)&usable, (basic_string_char__std__char_traits_char__std__allocator_char_ *)__k);
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
          uVar35 = *(ulong *)((long long)pvVar6 + -0x18);
          p_Var30 = &se_prc._M_t._M_impl._M_header;
          p_Var7 = se_prc._M_t._M_impl._M_header._M_parent;
          do {
            while( true ) {
              iVar18._M_node = p_Var7;
              uVar32 = *(ulong *)((long long)*(void **)(iVar18._M_node + 1) + -0x18);
              uVar28 = uVar32;
              if (uVar35 <= uVar32) {
                uVar28 = uVar35;
              }
              iVar15 = rea_memcmp(*(void **)(iVar18._M_node + 1),pvVar6,uVar28);
              if (iVar15 != 0) break;
              lVar37 = uVar32 - uVar35;
              if (0x7fffffff < lVar37) goto LAB_00109a27;
              if (-0x80000001 < lVar37) {
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] Unresolved local var: difference_type __d@[???] */ iVar15 = (int)lVar37;
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
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] */ uVar32 = *(ulong *)((long long)*(void **)(iVar18._M_node + 1) + -0x18);
          uVar28 = uVar32;
          if (uVar35 <= uVar32) {
            uVar28 = uVar35;
          }
          iVar15 = rea_memcmp(pvVar6,*(void **)(iVar18._M_node + 1),uVar28);
          if (iVar15 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */ lVar37 = uVar35 - uVar32;
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
          uVar35 = *(ulong *)((long long)pvVar6 + -0x18);
          p_Var30 = &se_volume._M_t._M_impl._M_header;
          p_Var7 = se_volume._M_t._M_impl._M_header._M_parent;
          do {
            while( true ) {
              iVar18._M_node = p_Var7;
              uVar32 = *(ulong *)((long long)*(void **)(iVar18._M_node + 1) + -0x18);
              uVar28 = uVar32;
              if (uVar35 <= uVar32) {
                uVar28 = uVar35;
              }
              iVar15 = rea_memcmp(*(void **)(iVar18._M_node + 1),pvVar6,uVar28);
              if (iVar15 != 0) break;
              lVar37 = uVar32 - uVar35;
              if (0x7fffffff < lVar37) goto LAB_00109b07;
              if (-0x80000001 < lVar37) {
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] Unresolved local var: difference_type __d@[???] */ iVar15 = (int)lVar37;
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
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] */ uVar32 = *(ulong *)((long long)*(void **)(iVar18._M_node + 1) + -0x18);
          uVar28 = uVar32;
          if (uVar35 <= uVar32) {
            uVar28 = uVar35;
          }
          iVar15 = rea_memcmp(pvVar6,*(void **)(iVar18._M_node + 1),uVar28);
          if (iVar15 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */ lVar37 = uVar35 - uVar32;
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
                    /* Unresolved local var: vector_double__std__allocator_double_ * __for_range@[???] Unresolved local var: iterator __for_begin@[???] Unresolved local var: iterator __for_end@[???] */ p_Var7 = p_Var19[1]._M_left;
        for (p_Var31 = p_Var19[1]._M_parent; p_Var31 != p_Var7;
            p_Var31 = (_Base_ptr)&p_Var31->_M_parent) {
          r.first._M_dataplus._M_p = *(_Alloc_hider *)p_Var31;
          rea_std__string__append((char *)&buf,(ulong)&r);
        }
        p_Var19 = (_Rb_tree_node_base *)rea_std___Rb_tree_increment(p_Var19);
      } while (p_Var19 != &se_alphas._M_t._M_impl._M_header);
    }
    pbVar24 = index. super__Vector_base ._M_impl._M_finish;
    psVar25 = (string *)0x0;
    volume = 0.0;
    local_170 = (string *)0x0;
    local_168 = 0;
    uVar32 = (long long)index. super__Vector_base ._M_impl._M_finish - (long long)index. super__Vector_base ._M_impl._M_start >> 3;
    uVar35 = 0;
    if (uVar32 != 0) {
      if (0x1fffffffffffffff < uVar32) {
        uVar21 = rea_std____throw_bad_alloc();
        iVar15 = rea_cast<int >(local_27b);
        rea_std__string___Rep___M_dispose((allocator *)((long long)r.first._M_dataplus._M_p + -0x18));
        std___________pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char______________pair((pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char__ *)pbVar24,iVar15);
        if (rv.super__Vector_base._M_impl._M_start != (pointer)0x0) {
          rea_operator_delete(rv.super__Vector_base. _M_impl._M_start);
        }
        iVar15 = rea_cast<int >(local_280);
        rea_std__string___Rep___M_dispose((allocator *)((long long)buf._M_dataplus._M_p + -0x18));
        std___________vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______________vector(&index,iVar15);
        std____________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______________M_erase((_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ *)&usable,(_Link_type)usable._M_t._M_impl._M_header._M_parent);
        std____________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______________M_erase(&hold._M_t,(_Link_type)hold._M_t._M_impl._M_header._M_parent);
        std____________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________________M_erase(&se_alphas._M_t,(_Link_type)se_alphas._M_t._M_impl._M_header._M_parent);
        std____________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______________M_erase(&se_volume._M_t,(_Link_type)se_volume._M_t._M_impl._M_header._M_parent);
        std____________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______________M_erase(&se_prc._M_t,(_Link_type)se_prc._M_t._M_impl._M_header._M_parent);
        rea_std__string___Rep___M_dispose((allocator *)((long long)ts._M_dataplus._M_p + -0x18));
        rea_std__string___Rep___M_dispose((allocator *)(local_268[0] + -0x18));
                    /* WARNING: Subroutine does not return */ rea__Unwind_Resume(uVar21);
      }
      uVar35 = uVar32 << 3;
      psVar25 = rea_operator_new(uVar35);
    }
    pbVar24 = index. super__Vector_base ._M_impl._M_finish;
    local_168 = (long long)&(psVar25->_M_dataplus)._M_p + uVar35;
    volume = (double)psVar25;
    local_170 = psVar25;
                    /* Unresolved local var:
                       basic_string_char__std__char_traits_char__std__allocator_char_ *
                       __cur@[???] */
    for (psVar33 = index. super__Vector_base ._M_impl._M_start; pbVar24 != psVar33; psVar33 = psVar33 + 1) {
      if (psVar25 != (string *)0x0) {
        rea_std__string__string(psVar25,psVar33);
      }
      psVar25 = psVar25 + 1;
    }
    local_170 = psVar25;
    rea_std__string__string(&local_160,&buf);
    ppVar36 = &r;
    rea_std__string__string(ppVar36,&ts);
    r.second.first. super__Vector_base ._M_impl._M_start = (pointer)0x0;
    r.second.first. super__Vector_base ._M_impl._M_finish = (pointer)0x0;
    r.second.first. super__Vector_base ._M_impl._M_end_of_storage = (pointer)0x0;
    pPVar34 = (PyObject *)((long long)local_170 - (long long)volume >> 3);
    if (pPVar34 == (PyObject *)0x0) {
      uVar35 = 0;
      pbVar24 = (pointer)0x0;
LAB_00109db2:
      psVar33 = local_170;
      r.second.first. super__Vector_base ._M_impl._M_end_of_storage = (pointer)((long long)&(pbVar24->_M_dataplus)._M_p + uVar35);
      r.second.first. super__Vector_base ._M_impl._M_start = pbVar24;
      r.second.first. super__Vector_base ._M_impl._M_finish = pbVar24;
                    /* Unresolved local var:
                       basic_string_char__std__char_traits_char__std__allocator_char_ *
                       __cur@[???] */
      for (psVar25 = rea_cast<string* >(volume); psVar25 != psVar33; psVar25 = psVar25 + 1) {
        if (pbVar24 != (pointer)0x0) {
          rea_std__string__string(pbVar24,psVar25);
        }
        pbVar24 = pbVar24 + 1;
      }
      r.second.first. super__Vector_base ._M_impl._M_finish = pbVar24;
      rea_std__string__string(&r.second.second,&local_160);
      psVar25 = rea_cast<string* >(volume);
      psVar33 = local_170;
      psVar8 = local_170;
      if ((allocator *)((long long)local_160._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar3 = (int *)((long long)local_160._M_dataplus._M_p + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar15 = *(int *)((long long)local_160._M_dataplus._M_p + -8);
          *(int *)((long long)local_160._M_dataplus._M_p + -8) = iVar15 + -1;
        }
        else {
          LOCK();
          iVar15 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        if (iVar15 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)((long long)local_160._M_dataplus._M_p + -0x18));
          psVar25 = rea_cast<string* >(volume);
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
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar15 = *(int *)(pcVar16 + -8);
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
        psVar33 = rea_cast<string* >(volume);
        psVar8 = local_170;
        local_170 = psVar9;
      }
      local_170 = psVar8;
      if (psVar33 != (string *)0x0) {
        rea_operator_delete(psVar33);
      }
LAB_00109e74:
      if (rv.super__Vector_base._M_impl._M_start != (pointer)0x0) {
        rea_operator_delete(rv.super__Vector_base._M_impl ._M_start);
      }
      pbVar24 = index. super__Vector_base ._M_impl._M_start;
      pbVar11 = index. super__Vector_base ._M_impl._M_finish;
      pbVar12 = index. super__Vector_base ._M_impl._M_finish;
      if ((allocator *)((long long)buf._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar3 = (int *)((long long)buf._M_dataplus._M_p + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar15 = *(int *)((long long)buf._M_dataplus._M_p + -8);
          *(int *)((long long)buf._M_dataplus._M_p + -8) = iVar15 + -1;
        }
        else {
          LOCK();
          iVar15 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        if (iVar15 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)((long long)buf._M_dataplus._M_p + -0x18));
          pbVar24 = index. super__Vector_base ._M_impl._M_start;
          pbVar11 = index. super__Vector_base ._M_impl._M_finish;
          pbVar12 = index. super__Vector_base ._M_impl._M_finish;
        }
      }
      for (; pbVar14 = index. super__Vector_base ._M_impl._M_finish, index. super__Vector_base ._M_impl._M_finish != pbVar24; pbVar24 = pbVar24 + 1) {
        pcVar16 = (pbVar24->_M_dataplus)._M_p;
        index. super__Vector_base ._M_impl._M_finish = pbVar12;
        if ((allocator *)(pcVar16 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
          piVar3 = (int *)(pcVar16 + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar15 = *(int *)(pcVar16 + -8);
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
        pbVar11 = index. super__Vector_base ._M_impl._M_start;
        pbVar12 = index. super__Vector_base ._M_impl._M_finish;
        index. super__Vector_base ._M_impl._M_finish = pbVar14;
      }
      index. super__Vector_base ._M_impl._M_finish = pbVar12;
      if (pbVar11 != (pointer)0x0) {
        rea_operator_delete(pbVar11);
      }
      std__________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____________M_erase((_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ *)&usable,(_Link_type)usable._M_t._M_impl._M_header._M_parent);
      std__________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____________M_erase(&hold._M_t,(_Link_type)hold._M_t._M_impl._M_header._M_parent);
      std__________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______________M_erase(&se_alphas._M_t,(_Link_type)se_alphas._M_t._M_impl._M_header._M_parent);
      std__________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____________M_erase(&se_volume._M_t,(_Link_type)se_volume._M_t._M_impl._M_header._M_parent);
      std__________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____________M_erase(&se_prc._M_t,(_Link_type)se_prc._M_t._M_impl._M_header._M_parent);
      if ((allocator *)((long long)ts._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar3 = (int *)((long long)ts._M_dataplus._M_p + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar15 = *(int *)((long long)ts._M_dataplus._M_p + -8);
          *(int *)((long long)ts._M_dataplus._M_p + -8) = iVar15 + -1;
        }
        else {
          LOCK();
          iVar15 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        if (iVar15 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)((long long)ts._M_dataplus._M_p + -0x18));
        }
      }
      if ((allocator *)(local_268[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar3 = (int *)(local_268[0] + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar15 = *(int *)(local_268[0] + -8);
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
                    /* Unresolved local var: _object * pa@[???] Unresolved local var: _object * pb@[DW_OP_reg3(RBX)] Unresolved local var: PyObject * tup@[???] */ p_Var20 = (_typeobject *) rea_PyBytes_FromStringAndSize (r.first._M_dataplus._M_p, *(undefined8 *)((long long)r.first._M_dataplus._M_p + -0x18));
                    /* Unresolved local var: _object * pb@[???] Unresolved local var: PyObject * tup@[???] Unresolved local var: int size@[???] Unresolved local var: PyObject * o@[???] */ iVar15 = (int)((long long)r.second.first. super__Vector_base ._M_impl._M_finish - (long long)r.second.first. super__Vector_base ._M_impl._M_start >> 3);
      uVar21 = rea_PyList_New((long long)iVar15);
                    /* Unresolved local var: int i@[???] */ lVar37 = 0;
      if (0 < iVar15) {
        do {
          pcVar16 = r.second.first. super__Vector_base ._M_impl._M_start[lVar37]._M_dataplus._M_p;
          uVar22 = rea_PyBytes_FromStringAndSize(pcVar16,*(undefined8 *)(pcVar16 + -0x18));
          rea_PyList_SetItem(uVar21,lVar37,uVar22);
          lVar37 = lVar37 + 1;
        } while ((int)lVar37 < iVar15);
      }
      uVar22 = rea_PyBytes_FromStringAndSize (r.second.second._M_dataplus._M_p, *(undefined8 *)((long long)r.second.second._M_dataplus._M_p + -0x18));
      lVar37 = rea_PyTuple_New(2);
      *(undefined8 *)(lVar37 + 0x18) = uVar21;
      *(undefined8 *)(lVar37 + 0x20) = uVar22;
      pPVar34 = (PyObject *)rea_PyTuple_New(2);
      pPVar34[1].ob_type = p_Var20;
      pPVar34[2].ob_refcnt = lVar37;
      ppVar36 = (pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___ *)((long long)r.second.second._M_dataplus._M_p + -0x18);
      pbVar24 = r.second.first. super__Vector_base ._M_impl._M_start;
      pbVar11 = r.second.first. super__Vector_base ._M_impl._M_finish;
      pbVar12 = r.second.first. super__Vector_base ._M_impl._M_finish;
      if (ppVar36 != (pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___ *)PTR__S_empty_rep_storage_00311ff0) goto LAB_0010aa4d;
    }
    else {
      if (pPVar34 < (PyObject *)0x2000000000000000) {
        uVar35 = (long long)pPVar34 << 3;
        pbVar24 = rea_operator_new(uVar35);
        goto LAB_00109db2;
      }
      r.second.second._M_dataplus._M_p = (_Alloc_hider)rea_std____throw_bad_alloc();
LAB_0010aa4d:
      ppbVar2 = &(ppVar36->second).first. super__Vector_base ._M_impl._M_finish;
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar15 = *(int *)((long long)r.second.second._M_dataplus._M_p + -8);
        *(int *)((long long)r.second.second._M_dataplus._M_p + -8) = iVar15 + -1;
      }
      else {
        LOCK();
        iVar15 = *(int *)ppbVar2;
        *(int *)ppbVar2 = *(int *)ppbVar2 + -1;
        UNLOCK();
      }
      pbVar24 = r.second.first. super__Vector_base ._M_impl._M_start;
      pbVar11 = r.second.first. super__Vector_base ._M_impl._M_finish;
      pbVar12 = r.second.first. super__Vector_base ._M_impl._M_finish;
      if (iVar15 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)ppVar36);
        pbVar24 = r.second.first. super__Vector_base ._M_impl._M_start;
        pbVar11 = r.second.first. super__Vector_base ._M_impl._M_finish;
        pbVar12 = r.second.first. super__Vector_base ._M_impl._M_finish;
      }
    }
    for (; pbVar14 = r.second.first. super__Vector_base ._M_impl._M_finish, r.second.first. super__Vector_base ._M_impl._M_finish != pbVar24; pbVar24 = pbVar24 + 1) {
      pcVar16 = (pbVar24->_M_dataplus)._M_p;
      r.second.first. super__Vector_base ._M_impl._M_finish = pbVar12;
      if ((allocator *)(pcVar16 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar3 = (int *)(pcVar16 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar15 = *(int *)(pcVar16 + -8);
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
      pbVar11 = r.second.first. super__Vector_base ._M_impl._M_start;
      pbVar12 = r.second.first. super__Vector_base ._M_impl._M_finish;
      r.second.first. super__Vector_base ._M_impl._M_finish = pbVar14;
    }
    r.second.first. super__Vector_base ._M_impl._M_finish = pbVar12;
    if (pbVar11 != (pointer)0x0) {
      rea_operator_delete(pbVar11);
    }
    ppVar36 = (pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___ *)((long long)r.first._M_dataplus._M_p + -0x18);
    if (ppVar36 == (pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___ *)PTR__S_empty_rep_storage_00311ff0) {
      return pPVar34;
    }
    piVar3 = (int *)((long long)r.first._M_dataplus._M_p + -8);
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
    uv = rea_cast<double >((PTR__S_empty_rep_storage_00311ff0 + 0x18));
    local_188 = 0;
    local_190 = (string *)0x0;
    rea_std__string__string(&local_180,(string *)&uv);
    ppVar36 = &r;
    rea_std__string__string(ppVar36,"",&local_279);
    r.second.first. super__Vector_base ._M_impl._M_start = (pointer)0x0;
    r.second.first. super__Vector_base ._M_impl._M_finish = (pointer)0x0;
    r.second.first. super__Vector_base ._M_impl._M_end_of_storage = (pointer)0x0;
    pPVar34 = (PyObject *)((long long)local_190 - (long long)prc >> 3);
    if (pPVar34 == (PyObject *)0x0) {
      uVar35 = 0;
      pbVar24 = (pointer)0x0;
LAB_0010a30d:
      psVar33 = local_190;
      r.second.first. super__Vector_base ._M_impl._M_end_of_storage = (pointer)((long long)&(pbVar24->_M_dataplus)._M_p + uVar35);
      r.second.first. super__Vector_base ._M_impl._M_start = pbVar24;
      r.second.first. super__Vector_base ._M_impl._M_finish = pbVar24;
                    /* Unresolved local var:
                       basic_string_char__std__char_traits_char__std__allocator_char_ *
                       __cur@[???] */
      for (psVar25 = rea_cast<string* >(prc); psVar25 != psVar33; psVar25 = psVar25 + 1) {
        if (pbVar24 != (pointer)0x0) {
          rea_std__string__string(pbVar24,psVar25);
        }
        pbVar24 = pbVar24 + 1;
      }
      r.second.first. super__Vector_base ._M_impl._M_finish = pbVar24;
      rea_std__string__string(&r.second.second,&local_180);
      psVar25 = rea_cast<string* >(prc);
      psVar33 = local_190;
      psVar8 = local_190;
      if ((allocator *)((long long)local_180._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar3 = (int *)((long long)local_180._M_dataplus._M_p + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar15 = *(int *)((long long)local_180._M_dataplus._M_p + -8);
          *(int *)((long long)local_180._M_dataplus._M_p + -8) = iVar15 + -1;
        }
        else {
          LOCK();
          iVar15 = *piVar3;
          *piVar3 = *piVar3 + -1;
          UNLOCK();
        }
        if (iVar15 < 1) {
          rea_std__string___Rep___M_destroy((allocator *)((long long)local_180._M_dataplus._M_p + -0x18));
          psVar25 = rea_cast<string* >(prc);
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
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar15 = *(int *)(pcVar16 + -8);
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
        psVar33 = rea_cast<string* >(prc);
        psVar8 = local_190;
        local_190 = psVar9;
      }
      local_190 = psVar8;
      psVar25 = rea_cast<string* >(volume);
      psVar9 = local_170;
      psVar10 = local_170;
      if (psVar33 != (string *)0x0) {
        rea_operator_delete(psVar33);
        psVar25 = rea_cast<string* >(volume);
        psVar9 = local_170;
        psVar10 = local_170;
      }
      for (; psVar33 = local_170, local_170 != psVar25; psVar25 = psVar25 + 1) {
        pcVar16 = (psVar25->_M_dataplus)._M_p;
        local_170 = psVar10;
        if ((allocator *)(pcVar16 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
          piVar3 = (int *)(pcVar16 + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar15 = *(int *)(pcVar16 + -8);
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
        psVar9 = rea_cast<string* >(volume);
        psVar10 = local_170;
        local_170 = psVar33;
      }
      local_170 = psVar10;
      if (psVar9 != (string *)0x0) {
        rea_operator_delete(psVar9);
      }
      rea_std__string___Rep___M_dispose((allocator *)((long long)uv + -0x18));
      goto LAB_00109e74;
    }
    if (pPVar34 < (PyObject *)0x2000000000000000) {
      uVar35 = (long long)pPVar34 << 3;
      pbVar24 = rea_operator_new(uVar35);
      goto LAB_0010a30d;
    }
    bVar27._M_dataplus._M_p = (_Alloc_hider)rea_std____throw_bad_alloc();
  }
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar15 = *(int *)((long long)bVar27._M_dataplus._M_p + -8);
  *(int *)((long long)bVar27._M_dataplus._M_p + -8) = iVar15 + -1;
LAB_0010ab48:
  if (iVar15 < 1) {
    rea_std__string___Rep___M_destroy((allocator *)ppVar36);
  }
  return pPVar34;
}
// @@@ END IDX 159
// @@@ BEGIN IDX 160 rea_PyWrapper_std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char__dup2
// ------------------------------------------------------------------
// IDX 160  0010ab80  PyWrapper<std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char____
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char__dup2(undefined8 * pyargs) {
  rea_v puVar1;
  int *piVar2;
  uchar *puVar3;
  uchar uVar4;
  rea_v p_Var5;
  rea_v pdVar6;
  rea_adr psVar7;
  rea_v pvVar8;
  rea_v pvVar9;
  rea_v pvVar10;
  rea_v pbVar11;
  rea_v pbVar12;
  rea_v pbVar13;
  rea_v pvVar14;
  rea_v bVar15;
  int iVar16;
  int iVar17;
  char *pcVar18;
  ulong *puVar19;
  rea_v p;
  rea_v sVar20;
  rea_adr p_Var21;
  rea_v p_Var22;
  rea_adr p_Var23;
  undefined8 uVar24;
  undefined8 uVar25;
  rea_adr pPVar26;
  rea_adr psVar27;
  rea_v puVar28;
  rea_v pbVar29;
  uchar *puVar30;
  rea_v p_Var31;
  long long lVar32;
  rea_adr psVar33;
  void *pvVar34;
  rea_adr p_Var35;
  rea_v __src;
  rea_adr ppVar36;
  rea_adr ppVar37;
  rea_v puVar38;
  ulong uVar39;
  rea_v puVar40;
  bool bVar41;
  undefined1 local_1e0 [2];
  rea_v local_1de [2];
  rea_v local_1dc;
  undefined1 local_1db [2];
  rea_v local_1d9;
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
  rea_v t;
  uchar *local_198 [2];
  rea_v ts;
  rea_v buf;
  rea_v fmt;
  void *local_158 [2];
  rea_v s_1;
  rea_v index;
  rea_v values;
  rea_v rv;
  rea_v local_c0;
  rea_v local_b8;
  rea_v r;
  rea_v s;
  rea_adr pa;
  
  s._M_t._M_impl._M_key_compare. super_binary_function = (binary_function )0x4f;
  (*(undefined1 *)((uint8_t *)&rea_bind(s._M_t)._M_impl + 0x1)) = 0;
  iVar16 = rea_PyArg_ParseTuple(pyargs,(allocator *)&s,&t);
  if (iVar16 == 0) {
    return (undefined8)(PyObject *)0x0;
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
                    /* Unresolved local var: size_type __n@[???] */ puVar28 = (pointer)0x0;
  index. super__Vector_base ._M_impl._M_start = (pointer)0x0;
  index. super__Vector_base ._M_impl._M_finish = (pointer)0x0;
  index. super__Vector_base ._M_impl._M_end_of_storage = (pointer)0x0;
  values. super__Vector_base ._M_impl._M_start = (pointer)0x0;
  values. super__Vector_base ._M_impl._M_finish = (pointer)0x0;
  values. super__Vector_base ._M_impl._M_end_of_storage = (pointer)0x0;
  rv.super__Vector_base._M_impl._M_start = (pointer)0x0;
  rv.super__Vector_base._M_impl._M_finish = (pointer)0x0;
  rv.super__Vector_base._M_impl._M_end_of_storage = (pointer)0x0;
  buf._M_dataplus._M_p = ts._M_dataplus._M_p;
  s._M_t._M_impl._M_header._M_right = s._M_t._M_impl._M_header._M_left;
  if (uVar39 != 0) {
    puVar28 = rea_operator_new(uVar39);
  }
  puVar40 = puVar28 + uVar39;
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: _Distance __n@[???] */ puVar3 = puVar30 + uVar39;
  puVar38 = puVar28;
  rv.super__Vector_base._M_impl._M_start = puVar28;
  rv.super__Vector_base._M_impl._M_end_of_storage = puVar40;
  if ((long long)uVar39 < 1) {
    fmt._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    rv.super__Vector_base._M_impl._M_finish = puVar28 ;
LAB_0010af6e:
    iVar16 = (int)puVar40;
    sVar20._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18) ;
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
                    /* Unresolved local var: size_t l@[???] Unresolved local var: size_t np@[???] Unresolved local var: size_t p@[???] */ puVar38 = puVar40 + -(long long)puVar28;
    fmt._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
                    /* Unresolved local var: uint8_t * s@[???] */ rv.super__Vector_base._M_impl._M_finish = puVar40 ;
    if (puVar38 < (pointer)0x8) goto LAB_0010af6e;
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ ppVar36 = &r;
    __src = puVar28 + 8;
    puVar40 = puVar28;
    rea_memcpy(ppVar36,puVar28,8);
    bVar15 = r.first;
                    /* Unresolved local var: size_t l@[???] Unresolved local var: size_t np@[???] Unresolved local var: uint8_t * s@[???] */ if (puVar38 < (pointer)0x10) goto LAB_0010af6e;
    puVar1 = puVar28 + 0x10;
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ if ((long long)puVar1 - (long long)__src != 0) {
      rea_memcpy(ppVar36,__src,(long long)puVar1 - (long long)__src);
      puVar40 = __src;
    }
    p = r.first._M_dataplus._M_p + 0x10;
    if (puVar38 < p._M_p) goto LAB_0010af6e;
    puVar40 = puVar1 + (long long)r.first._M_dataplus._M_p;
                    /* Unresolved local var: size_type __dnew@[???] Unresolved local var: _Rep * __r@[???] */ if (puVar1 == puVar40) {
      s_1._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    }
    else {
      uVar39 = (long long)puVar40 - (long long)puVar1;
      puVar19 = (ulong *)rea_std__string___Rep___S_create(uVar39,0,(allocator*)rea_pv(local_1de));
      s_1._M_dataplus._M_p = (_Alloc_hider)(puVar19 + 3);
      puVar38 = (pointer)0x0;
      do {
        *(uchar *)((long long)s_1._M_dataplus._M_p + (long long)puVar38) = puVar28[(long long)(puVar38 + 0x10)];
        puVar38 = puVar38 + 1;
      } while (puVar38 != puVar40 + (-0x10 - (long long)puVar28));
      if (puVar19 != (ulong *)PTR__S_empty_rep_storage_00311ff0) {
        *(undefined4 *)(puVar19 + 2) = 0;
        *puVar19 = uVar39;
        *(undefined1 *)((long long)puVar19 + uVar39 + 0x18) = 0;
      }
    }
    iVar16 = (int)&s_1;
    rea_std__string__assign(&fmt);
    if ((allocator *)((long long)s_1._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar2 = (int *)((long long)s_1._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar17 = *(int *)((long long)s_1._M_dataplus._M_p + -8);
        *(int *)((long long)s_1._M_dataplus._M_p + -8) = iVar17 + -1;
      }
      else {
        LOCK();
        iVar17 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar17 < 1) {
        ppVar37 = ppVar36;
        rea_std__string___Rep___M_destroy((allocator *)((long long)s_1._M_dataplus._M_p + -0x18));
        iVar16 = (int)ppVar37;
      }
    }
    sVar20._M_dataplus._M_p = fmt._M_dataplus._M_p;
    if (rea_bind((pointer)p._M_p) == (pointer)0x8) goto LAB_0010af79;
    local_1c8 = 0x73504d73;
    pcVar18 = (char *)&local_1b8;
    local_1c4 = 0x6456;
    local_1b8 = 0x73504d73;
    r.first._M_dataplus._M_p = (_Alloc_hider) (CONCAT26((*(undefined2 *)((uint8_t *)&rea_bind(r.first._M_dataplus)._M_p + 0x6)),0x645673504d73) & 0xff00ffffffffffff);
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
    iVar16 = rea_cast<int >(pcVar18);
    bVar41 = true;
    if (*(size_t *)((long long)fmt._M_dataplus._M_p + -0x18) == *(size_t *)((long long)local_158[0] + -0x18)) {
      pvVar34 = local_158[0];
      iVar17 = rea_memcmp((void *)fmt._M_dataplus._M_p,local_158[0], *(size_t *)((long long)fmt._M_dataplus._M_p + -0x18));
      iVar16 = rea_cast<int >(pvVar34);
      bVar41 = iVar17 != 0;
    }
    if ((allocator *)((long long)local_158[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar2 = (int *)((long long)local_158[0] + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar17 = *(int *)((long long)local_158[0] + -8);
        *(int *)((long long)local_158[0] + -8) = iVar17 + -1;
      }
      else {
        LOCK();
        iVar17 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar17 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long long)local_158[0] + -0x18));
        iVar16 = (int)ppVar36;
      }
    }
    if (bVar41) {
      bVar41 = false;
      sVar20._M_dataplus._M_p = fmt._M_dataplus._M_p;
    }
    else {
                    /* Unresolved local var: size_t np@[???] */ puVar28 = (pointer)p._M_p;
      puVar40 = (pointer)detail____________________________P_std__basic_string_char__std__char_traits_char__std__allocator_char______________________________parse(&rv,(size_t)p._M_p,&ts);
      iVar16 = (int)puVar28;
      if (rea_bind((pointer)p._M_p) != puVar40) {
                    /* Unresolved local var: size_t np@[???] */ p._M_p = (char *)
                         rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____M___parse(&rv,(size_t)puVar40, (map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ *)&s);
        iVar16 = (int)puVar40;
      }
      bVar41 = bVar15._M_dataplus._M_p == (_Alloc_hider)p._M_p;
      sVar20._M_dataplus._M_p = fmt._M_dataplus._M_p;
    }
  }
  if ((allocator *)((long long)sVar20._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar2 = (int *)((long long)sVar20._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar17 = *(int *)((long long)sVar20._M_dataplus._M_p + -8);
      *(int *)((long long)sVar20._M_dataplus._M_p + -8) = iVar17 + -1;
    }
    else {
      LOCK();
      iVar17 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar17 < 1) {
      iVar16 = (int)&r;
      rea_std__string___Rep___M_destroy((allocator *)((long long)sVar20._M_dataplus._M_p + -0x18));
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
        if (index. super__Vector_base ._M_impl._M_finish == index. super__Vector_base ._M_impl._M_end_of_storage) {
          std_____________vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char____________________________M_emplace_back_aux_const_std__basic_string_char__std__char_traits_char__std__allocator_char_______________________(&index);
          iVar16 = (int)p_Var35;
        }
        else {
          if (index. super__Vector_base ._M_impl._M_finish == (pointer)0x0) {
            index. super__Vector_base ._M_impl._M_finish = (pointer)0x0;
          }
          else {
            rea_std__string__string(index. super__Vector_base ._M_impl._M_finish,(string *)p_Var35);
          }
          iVar16 = (int)p_Var35;
          index. super__Vector_base ._M_impl._M_finish = index. super__Vector_base ._M_impl._M_finish + 1;
        }
                    /* Unresolved local var: vector_double__std__allocator_double_ * __for_range@[???] Unresolved local var: iterator __for_begin@[???] Unresolved local var: iterator __for_end@[???] */ p_Var5 = p_Var22[1]._M_left;
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
    local_b8.first. super__Vector_base ._M_impl._M_start = (string *)0x0;
    local_b8.first. super__Vector_base ._M_impl._M_finish = (string *)0x0;
    local_b8.first. super__Vector_base ._M_impl._M_end_of_storage = (pointer)0x0;
    uVar39 = (long long)index. super__Vector_base ._M_impl._M_finish - (long long)index. super__Vector_base ._M_impl._M_start >> 3;
    if (uVar39 == 0) {
      uVar39 = 0;
      psVar27 = (string *)0x0;
    }
    else {
      if (0x1fffffffffffffff < uVar39) {
        uVar24 = rea_std____throw_bad_alloc();
        if (rv.super__Vector_base._M_impl._M_start != (pointer)0x0) {
          rea_operator_delete(rv.super__Vector_base. _M_impl._M_start);
        }
        goto LAB_0010b98f;
      }
      uVar39 = uVar39 * 8;
      psVar27 = rea_operator_new(uVar39);
    }
    pbVar29 = index. super__Vector_base ._M_impl._M_finish;
    local_b8.first. super__Vector_base ._M_impl._M_end_of_storage = (pointer)((long long)&(psVar27->_M_dataplus)._M_p + uVar39);
    local_b8.first. super__Vector_base ._M_impl._M_start = psVar27;
    local_b8.first. super__Vector_base ._M_impl._M_finish = psVar27;
                    /* Unresolved local var:
                       basic_string_char__std__char_traits_char__std__allocator_char_ *
                       __cur@[???] */
    for (psVar33 = index. super__Vector_base ._M_impl._M_start; psVar33 != pbVar29; psVar33 = psVar33 + 1) {
      if (psVar27 != (string *)0x0) {
        rea_std__string__string(psVar27,psVar33);
      }
      psVar27 = psVar27 + 1;
    }
    local_b8.first. super__Vector_base ._M_impl._M_finish = psVar27;
    rea_std__string__string(&local_b8.second,&buf);
    rea_std__string__string(&r,&ts);
    r.second.first. super__Vector_base ._M_impl._M_start = (pointer)0x0;
    r.second.first. super__Vector_base ._M_impl._M_finish = (pointer)0x0;
    r.second.first. super__Vector_base ._M_impl._M_end_of_storage = (pointer)0x0;
    uVar39 = (long long)local_b8.first. super__Vector_base ._M_impl._M_finish - (long long)local_b8.first. super__Vector_base ._M_impl._M_start >> 3;
    if (uVar39 == 0) {
      uVar39 = 0;
      pbVar29 = (pointer)0x0;
    }
    else {
      if (0x1fffffffffffffff < uVar39) {
        uVar24 = rea_std____throw_bad_alloc();
        iVar16 = rea_cast<int >(local_1db);
        rea_std__string___Rep___M_dispose((allocator *)((long long)r.first._M_dataplus._M_p + -0x18));
        std___________pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char______________pair(&local_b8,iVar16);
        if (rv.super__Vector_base._M_impl._M_start != (pointer)0x0) {
          rea_operator_delete(rv.super__Vector_base. _M_impl._M_start);
        }
LAB_0010b98f:
        iVar17 = rea_cast<int >(local_1e0);
        std___________vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double_______________vector(&values,iVar16);
        rea_std__string___Rep___M_dispose((allocator *)((long long)buf._M_dataplus._M_p + -0x18));
        std___________vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______________vector(&index,iVar17);
        std____________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________________M_erase((_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ *)&s,(_Link_type)s._M_t._M_impl._M_header._M_parent);
        rea_std__string___Rep___M_dispose((allocator *)((long long)ts._M_dataplus._M_p + -0x18));
        rea_std__string___Rep___M_dispose((allocator *)(local_198[0] + -0x18));
                    /* WARNING: Subroutine does not return */ rea__Unwind_Resume(uVar24);
      }
      uVar39 = uVar39 << 3;
      pbVar29 = rea_operator_new(uVar39);
    }
    pbVar11 = local_b8.first. super__Vector_base ._M_impl._M_finish;
    r.second.first. super__Vector_base ._M_impl._M_end_of_storage = (pointer)((long long)&(pbVar29->_M_dataplus)._M_p + uVar39);
    r.second.first. super__Vector_base ._M_impl._M_start = pbVar29;
    r.second.first. super__Vector_base ._M_impl._M_finish = pbVar29;
                    /* Unresolved local var:
                       basic_string_char__std__char_traits_char__std__allocator_char_ *
                       __cur@[???] */
    for (psVar27 = local_b8.first. super__Vector_base ._M_impl._M_start; psVar27 != pbVar11; psVar27 = psVar27 + 1) {
      if (pbVar29 != (pointer)0x0) {
        rea_std__string__string(pbVar29,psVar27);
      }
      pbVar29 = pbVar29 + 1;
    }
    r.second.first. super__Vector_base ._M_impl._M_finish = pbVar29;
    rea_std__string__string(&r.second.second,&local_b8.second);
    psVar27 = local_b8.first. super__Vector_base ._M_impl._M_start;
    psVar33 = local_b8.first. super__Vector_base ._M_impl._M_finish;
    psVar7 = local_b8.first. super__Vector_base ._M_impl._M_finish;
    if ((allocator *)((long long)local_b8.second._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar2 = (int *)((long long)local_b8.second._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar16 = *(int *)((long long)local_b8.second._M_dataplus._M_p + -8);
        *(int *)((long long)local_b8.second._M_dataplus._M_p + -8) = iVar16 + -1;
      }
      else {
        LOCK();
        iVar16 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar16 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long long)local_b8.second._M_dataplus._M_p + -0x18)) ;
        psVar27 = local_b8.first. super__Vector_base ._M_impl._M_start;
        psVar33 = local_b8.first. super__Vector_base ._M_impl._M_finish;
        psVar7 = local_b8.first. super__Vector_base ._M_impl._M_finish;
      }
    }
    for (; pbVar29 = local_b8.first. super__Vector_base ._M_impl._M_finish, local_b8.first. super__Vector_base ._M_impl._M_finish != psVar27; psVar27 = psVar27 + 1) {
      pcVar18 = (psVar27->_M_dataplus)._M_p;
      local_b8.first. super__Vector_base ._M_impl._M_finish = psVar7;
      if ((allocator *)(pcVar18 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar2 = (int *)(pcVar18 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar16 = *(int *)(pcVar18 + -8);
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
      psVar33 = local_b8.first. super__Vector_base ._M_impl._M_start;
      psVar7 = local_b8.first. super__Vector_base ._M_impl._M_finish;
      local_b8.first. super__Vector_base ._M_impl._M_finish = pbVar29;
    }
    local_b8.first. super__Vector_base ._M_impl._M_finish = psVar7;
    if (psVar33 != (string *)0x0) {
      rea_operator_delete(psVar33);
    }
  }
  else {
    local_b8.first. super__Vector_base ._M_impl._M_start = (string *)0x0;
    local_b8.first. super__Vector_base ._M_impl._M_finish = (string *)0x0;
    local_b8.first. super__Vector_base ._M_impl._M_end_of_storage = (pointer)0x0;
    s_1._M_dataplus._M_p = (_Alloc_hider)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
    rea_std__string__string(&local_c0,&s_1);
    rea_std__string__string(&r,"",&local_1d9);
    r.second.first. super__Vector_base ._M_impl._M_end_of_storage = (pointer)0x0;
    r.second.first. super__Vector_base ._M_impl._M_start = (pointer)0x0;
                    /* Unresolved local var:
                       basic_string_char__std__char_traits_char__std__allocator_char_ *
                       __cur@[???] */
    r.second.first. super__Vector_base ._M_impl._M_finish = (pointer)0x0;
    rea_std__string__string(&r.second.second,&local_c0);
    psVar27 = local_b8.first. super__Vector_base ._M_impl._M_start;
    psVar33 = local_b8.first. super__Vector_base ._M_impl._M_finish;
    psVar7 = local_b8.first. super__Vector_base ._M_impl._M_finish;
    if ((allocator *)((long long)local_c0._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar2 = (int *)((long long)local_c0._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar16 = *(int *)((long long)local_c0._M_dataplus._M_p + -8);
        *(int *)((long long)local_c0._M_dataplus._M_p + -8) = iVar16 + -1;
      }
      else {
        LOCK();
        iVar16 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar16 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long long)local_c0._M_dataplus._M_p + -0x18));
        psVar27 = local_b8.first. super__Vector_base ._M_impl._M_start;
        psVar33 = local_b8.first. super__Vector_base ._M_impl._M_finish;
        psVar7 = local_b8.first. super__Vector_base ._M_impl._M_finish;
      }
    }
    for (; pbVar29 = local_b8.first. super__Vector_base ._M_impl._M_finish, local_b8.first. super__Vector_base ._M_impl._M_finish != psVar27; psVar27 = psVar27 + 1) {
      pcVar18 = (psVar27->_M_dataplus)._M_p;
      local_b8.first. super__Vector_base ._M_impl._M_finish = psVar7;
      if ((allocator *)(pcVar18 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
        piVar2 = (int *)(pcVar18 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar16 = *(int *)(pcVar18 + -8);
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
      psVar33 = local_b8.first. super__Vector_base ._M_impl._M_start;
      psVar7 = local_b8.first. super__Vector_base ._M_impl._M_finish;
      local_b8.first. super__Vector_base ._M_impl._M_finish = pbVar29;
    }
    local_b8.first. super__Vector_base ._M_impl._M_finish = psVar7;
    if (psVar33 != (string *)0x0) {
      rea_operator_delete(psVar33);
    }
    if ((allocator *)((long long)s_1._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar2 = (int *)((long long)s_1._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar16 = *(int *)((long long)s_1._M_dataplus._M_p + -8);
        *(int *)((long long)s_1._M_dataplus._M_p + -8) = iVar16 + -1;
      }
      else {
        LOCK();
        iVar16 = *piVar2;
        *piVar2 = *piVar2 + -1;
        UNLOCK();
      }
      if (iVar16 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long long)s_1._M_dataplus._M_p + -0x18));
      }
    }
  }
  pvVar8 = values. super__Vector_base ._M_impl._M_start;
  pvVar9 = values. super__Vector_base ._M_impl._M_finish;
  pvVar10 = values. super__Vector_base ._M_impl._M_finish;
  if (rv.super__Vector_base._M_impl._M_start != (pointer)0x0) {
    rea_operator_delete(rv.super__Vector_base._M_impl. _M_start);
    pvVar8 = values. super__Vector_base ._M_impl._M_start;
    pvVar9 = values. super__Vector_base ._M_impl._M_finish;
    pvVar10 = values. super__Vector_base ._M_impl._M_finish;
  }
  for (; pvVar14 = values. super__Vector_base ._M_impl._M_finish, values. super__Vector_base ._M_impl._M_finish != pvVar8; pvVar8 = pvVar8 + 1) {
    pdVar6 = (pvVar8->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
    values. super__Vector_base ._M_impl._M_finish = pvVar10;
    if (pdVar6 != (pointer)0x0) {
      rea_operator_delete(pdVar6);
    }
    pvVar9 = values. super__Vector_base ._M_impl._M_start;
    pvVar10 = values. super__Vector_base ._M_impl._M_finish;
    values. super__Vector_base ._M_impl._M_finish = pvVar14;
  }
  values. super__Vector_base ._M_impl._M_finish = pvVar10;
  if (pvVar9 != (pointer)0x0) {
    rea_operator_delete(pvVar9);
  }
  pbVar29 = index. super__Vector_base ._M_impl._M_start;
  pbVar11 = index. super__Vector_base ._M_impl._M_finish;
  pbVar12 = index. super__Vector_base ._M_impl._M_finish;
  if ((allocator *)((long long)buf._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar2 = (int *)((long long)buf._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar16 = *(int *)((long long)buf._M_dataplus._M_p + -8);
      *(int *)((long long)buf._M_dataplus._M_p + -8) = iVar16 + -1;
    }
    else {
      LOCK();
      iVar16 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar16 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long long)buf._M_dataplus._M_p + -0x18));
      pbVar29 = index. super__Vector_base ._M_impl._M_start;
      pbVar11 = index. super__Vector_base ._M_impl._M_finish;
      pbVar12 = index. super__Vector_base ._M_impl._M_finish;
    }
  }
  for (; pbVar13 = index. super__Vector_base ._M_impl._M_finish, index. super__Vector_base ._M_impl._M_finish != pbVar29; pbVar29 = pbVar29 + 1) {
    pcVar18 = (pbVar29->_M_dataplus)._M_p;
    index. super__Vector_base ._M_impl._M_finish = pbVar12;
    if ((allocator *)(pcVar18 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar2 = (int *)(pcVar18 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar16 = *(int *)(pcVar18 + -8);
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
    pbVar11 = index. super__Vector_base ._M_impl._M_start;
    pbVar12 = index. super__Vector_base ._M_impl._M_finish;
    index. super__Vector_base ._M_impl._M_finish = pbVar13;
  }
  index. super__Vector_base ._M_impl._M_finish = pbVar12;
  if (pbVar11 != (pointer)0x0) {
    rea_operator_delete(pbVar11);
  }
  std______Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__________M_erase((_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ *)&s,(_Link_type)s._M_t._M_impl._M_header._M_parent);
  if ((allocator *)((long long)ts._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar2 = (int *)((long long)ts._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar16 = *(int *)((long long)ts._M_dataplus._M_p + -8);
      *(int *)((long long)ts._M_dataplus._M_p + -8) = iVar16 + -1;
    }
    else {
      LOCK();
      iVar16 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar16 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long long)ts._M_dataplus._M_p + -0x18));
    }
  }
  if ((allocator *)(local_198[0] + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar2 = (int *)(local_198[0] + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar16 = *(int *)(local_198[0] + -8);
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
                    /* Unresolved local var: _object * pa@[???] Unresolved local var: _object * pb@[DW_OP_reg3(RBX)] Unresolved local var: PyObject * tup@[???] */ p_Var23 = (_typeobject *) rea_PyBytes_FromStringAndSize (r.first._M_dataplus._M_p, *(undefined8 *)((long long)r.first._M_dataplus._M_p + -0x18));
                    /* Unresolved local var: _object * pb@[???] Unresolved local var: PyObject * tup@[???] Unresolved local var: int size@[???] Unresolved local var: PyObject * o@[???] */ iVar16 = (int)((long long)r.second.first. super__Vector_base ._M_impl._M_finish - (long long)r.second.first. super__Vector_base ._M_impl._M_start >> 3);
  uVar24 = rea_PyList_New((long long)iVar16);
                    /* Unresolved local var: int i@[???] */ lVar32 = 0;
  if (0 < iVar16) {
    do {
      pcVar18 = r.second.first. super__Vector_base ._M_impl._M_start[lVar32]._M_dataplus._M_p;
      uVar25 = rea_PyBytes_FromStringAndSize(pcVar18,*(undefined8 *)(pcVar18 + -0x18));
      rea_PyList_SetItem(uVar24,lVar32,uVar25);
      lVar32 = lVar32 + 1;
    } while ((int)lVar32 < iVar16);
  }
  uVar25 = rea_PyBytes_FromStringAndSize (r.second.second._M_dataplus._M_p, *(undefined8 *)((long long)r.second.second._M_dataplus._M_p + -0x18));
  lVar32 = rea_PyTuple_New(2);
  *(undefined8 *)(lVar32 + 0x18) = uVar24;
  *(undefined8 *)(lVar32 + 0x20) = uVar25;
  pPVar26 = (PyObject *)rea_PyTuple_New(2);
  pPVar26[1].ob_type = p_Var23;
  pPVar26[2].ob_refcnt = lVar32;
  pbVar29 = r.second.first. super__Vector_base ._M_impl._M_start;
  pbVar11 = r.second.first. super__Vector_base ._M_impl._M_finish;
  pbVar12 = r.second.first. super__Vector_base ._M_impl._M_finish;
  if ((allocator *)((long long)r.second.second._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar2 = (int *)((long long)r.second.second._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar16 = *(int *)((long long)r.second.second._M_dataplus._M_p + -8);
      *(int *)((long long)r.second.second._M_dataplus._M_p + -8) = iVar16 + -1;
    }
    else {
      LOCK();
      iVar16 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar16 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long long)r.second.second._M_dataplus._M_p + -0x18));
      pbVar29 = r.second.first. super__Vector_base ._M_impl._M_start;
      pbVar11 = r.second.first. super__Vector_base ._M_impl._M_finish;
      pbVar12 = r.second.first. super__Vector_base ._M_impl._M_finish;
    }
  }
  for (; pbVar13 = r.second.first. super__Vector_base ._M_impl._M_finish, r.second.first. super__Vector_base ._M_impl._M_finish != pbVar29; pbVar29 = pbVar29 + 1) {
    pcVar18 = (pbVar29->_M_dataplus)._M_p;
    r.second.first. super__Vector_base ._M_impl._M_finish = pbVar12;
    if ((allocator *)(pcVar18 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar2 = (int *)(pcVar18 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar16 = *(int *)(pcVar18 + -8);
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
    pbVar11 = r.second.first. super__Vector_base ._M_impl._M_start;
    pbVar12 = r.second.first. super__Vector_base ._M_impl._M_finish;
    r.second.first. super__Vector_base ._M_impl._M_finish = pbVar13;
  }
  r.second.first. super__Vector_base ._M_impl._M_finish = pbVar12;
  if (pbVar11 != (pointer)0x0) {
    rea_operator_delete(pbVar11);
  }
  if ((allocator *)((long long)r.first._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar2 = (int *)((long long)r.first._M_dataplus._M_p + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar16 = *(int *)((long long)r.first._M_dataplus._M_p + -8);
      *(int *)((long long)r.first._M_dataplus._M_p + -8) = iVar16 + -1;
    }
    else {
      LOCK();
      iVar16 = *piVar2;
      *piVar2 = *piVar2 + -1;
      UNLOCK();
    }
    if (iVar16 < 1) {
      rea_std__string___Rep___M_destroy((allocator *)((long long)r.first._M_dataplus._M_p + -0x18));
    }
  }
  return pPVar26;
}
// @@@ END IDX 160
// @@@ BEGIN IDX 161 rea_std__unique_ptr_SecInfo__Data__std__default_delete_SecInfo__Data____unique_ptr
// ------------------------------------------------------------------
// IDX 161  0010bef0  std__unique_ptr_SecInfo__Data__std__default_delete_SecInfo__Data____unique_ptr___________
// ------------------------------------------------------------------
void rea_std__unique_ptr_SecInfo__Data__std__default_delete_SecInfo__Data____unique_ptr(unique_ptr_SecInfo__Data__std__default_delete_SecInfo__Data_ * this_ptr, int __in_chrg) {
  rea_v _Var1;
  
                    /* Unresolved local var: Data * * __ptr@[???] */ _Var1 = (rea_bind(this_ptr)->_M_t).super__Tuple_impl;
  if (_Var1 != (_Tuple_impl_0ul__SecInfo__Data___std__default_delete_SecInfo__Data_)0x0) {
    *(undefined4 *)_Var1 = 0;
    *(undefined4 *)((long long)_Var1 + 4) = 0;
    if (*(void **)((long long)_Var1 + 8) != (void *)0x0) {
      rea_operator_delete(*(void **)((long long)_Var1 + 8));
      *(undefined8 *)((long long)_Var1 + 8) = 0;
    }
    if (*(void **)((long long)_Var1 + 0x10) != (void *)0x0) {
      rea_operator_delete(*(void **)((long long)_Var1 + 0x10));
      *(undefined8 *)((long long)_Var1 + 0x10) = 0;
    }
    rea_operator_delete((void *)_Var1);
  }
  (rea_bind(this_ptr)->_M_t).super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__Data___std__default_delete_SecInfo__Data_)0x0;
  return;
}
// @@@ END IDX 161
// @@@ BEGIN IDX 162 rea_PyWrapper_void
// ------------------------------------------------------------------
// IDX 162  0010bf60  PyWrapper<void*_
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_void(undefined8 * pyargs) {
  int *piVar1;
  long long lVar2;
  int iVar3;
  char *pcVar4;
  void *pvVar5;
  rea_adr pPVar6;
  ulong uVar7;
  rea_v local_39;
  rea_v t;
  undefined2 local_28;
  undefined6 uStack_26;
  
                    /* Unresolved local var: void * r@[???] */ local_28 = 0x4f;
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
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar3 = *(int *)(lVar2 + -8);
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
  return (undefined8)(PyObject *)0x0;
}
// @@@ END IDX 162
// @@@ BEGIN IDX 163 rea_pydetail__PyWrapper_void
// ------------------------------------------------------------------
// IDX 163  0010c090  pydetail__PyWrapper<void_
// ------------------------------------------------------------------
PyObject * rea_pydetail__PyWrapper_void(undefined8 * pyargs) {
  int iVar1;
  void *fp;
  rea_adr pPVar2;
  undefined2 local_28 [8];
  rea_v t;
  
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
// @@@ END IDX 163
// @@@ BEGIN IDX 164 rea_PyWrapper_std__pair_int__std__basic_string_char__std__char_traits_char__std__allocator_char
// ------------------------------------------------------------------
// IDX 164  0010c0e0  PyWrapper<std__pair_int__std__basic_string_char__std__char_traits_char__std__allocator_char___
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_std__pair_int__std__basic_string_char__std__char_traits_char__std__allocator_char(undefined8 * pyargs) {
  int *piVar1;
  int iVar2;
  rea_adr p_Var3;
  Py_ssize_t PVar4;
  rea_adr pPVar5;
  rea_v pVar6;
  rea_v t;
  rea_v r;
  
  r.first = CONCAT22((*(undefined2 *)((uint8_t *)&rea_bind(r).first + 0x2)),0x4f);
  iVar2 = rea_PyArg_ParseTuple(pyargs,&r,&t);
  if (iVar2 != 0) {
    rea_PyLong_AsVoidPtr(t.v);
    pVar6 = rea_pinot_getline(&r);
                    /* Unresolved local var: _object * pa@[???] Unresolved local var: _object * pb@[???] Unresolved local var: PyObject * tup@[???] */ p_Var3 = (_typeobject *) rea_Py_BuildValue((void *)&DAT_0010fbf4,(long long)r.first,pVar6.second._M_dataplus._M_p._M_dataplus);
    PVar4 = rea_PyBytes_FromStringAndSize (r.second._M_dataplus._M_p, *(undefined8 *)((long long)r.second._M_dataplus._M_p + -0x18));
    pPVar5 = (PyObject *)rea_PyTuple_New(2);
    pPVar5[1].ob_type = p_Var3;
    pPVar5[2].ob_refcnt = PVar4;
    if ((allocator *)((long long)r.second._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar1 = (int *)((long long)r.second._M_dataplus._M_p + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar2 = *(int *)((long long)r.second._M_dataplus._M_p + -8);
        *(int *)((long long)r.second._M_dataplus._M_p + -8) = iVar2 + -1;
      }
      else {
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
      }
      if (iVar2 < 1) {
        rea_std__string___Rep___M_destroy((allocator *)((long long)r.second._M_dataplus._M_p + -0x18));
      }
    }
    return pPVar5;
  }
  return (undefined8)(PyObject *)0x0;
}
// @@@ END IDX 164
// @@@ BEGIN IDX 165 rea_detail__P_std__basic_string_char__std__char_traits_char__std__allocator_char____parse__dup2
// ------------------------------------------------------------------
// IDX 165  0010c1e0  detail__P_std__basic_string_char__std__char_traits_char__std__allocator_char____parse__________________
// ------------------------------------------------------------------
size_t rea_detail__P_std__basic_string_char__std__char_traits_char__std__allocator_char____parse__dup2(vector_unsigned_char__std__allocator_unsigned_char_ * b, size_t p, string * ps) {
  int *piVar1;
  ulong uVar2;
  int iVar3;
  ulong *puVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  rea_adr paVar8;
  rea_v puVar9;
  rea_v local_49;
  ulong o;
  
                    /* Unresolved local var: size_t l@[???] Unresolved local var: size_t np@[???] Unresolved local var: uint8_t * s@[???] */ uVar6 = p + 8;
  puVar9 = rea_bind((b->super__Vector_base))._M_impl._M_start;
  uVar7 = rea_bind((long long)(b->super__Vector_base))._M_impl. _M_finish - (long long)puVar9;
  if (uVar6 <= uVar7) {
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ rea_memcpy(&o,puVar9 + p,8);
    uVar2 = uVar6 + o;
    if (uVar2 <= uVar7) {
      if (ps != (string *)0x0) {
        puVar9 = puVar9 + uVar6;
                    /* Unresolved local var: size_type __dnew@[???] Unresolved local var: _Rep * __r@[???] */ if (puVar9 == puVar9 + o) {
          o = (ulong)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
          paVar8 = (allocator *)PTR__S_empty_rep_storage_00311ff0;
        }
        else {
          uVar7 = (long long)(puVar9 + o) - (long long)puVar9;
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
            *(undefined1 *)((long long)puVar4 + uVar5 + 0x19) = 0;
          }
        }
        rea_std__string__assign(ps);
        if ((allocator *)(o - 0x18) != paVar8) {
          piVar1 = (int *)(o - 8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar3 = *(int *)(o - 8);
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
// @@@ END IDX 165
// @@@ BEGIN IDX 166 rea_std___pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char______pair__dup2
// ------------------------------------------------------------------
// IDX 166  0010c360  std___pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char______pair
// ------------------------------------------------------------------
void rea_std___pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char______pair__dup2(pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char__ * this_ptr, int __in_chrg) {
  int *piVar1;
  char *pcVar2;
  undefined *puVar3;
  int iVar4;
  rea_v pbVar5;
  rea_v pbVar6;
  
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
  pcVar2 = (rea_bind(this_ptr)->second)._M_dataplus._M_p;
  if ((allocator *)(pcVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar1 = (int *)(pcVar2 + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar4 = *(int *)(pcVar2 + -8);
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
  pbVar6 = (rea_bind(this_ptr)->first). super__Vector_base ._M_impl._M_finish;
  pbVar5 = (rea_bind(this_ptr)->first). super__Vector_base ._M_impl._M_start;
  if (pbVar6 != pbVar5) {
    do {
      pcVar2 = (pbVar5->_M_dataplus)._M_p;
      if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar3) {
        piVar1 = (int *)(pcVar2 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar4 = *(int *)(pcVar2 + -8);
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
    pbVar6 = (rea_bind(this_ptr)->first). super__Vector_base ._M_impl._M_start;
  }
  if (pbVar6 != (pointer)0x0) {
    rea_operator_delete(pbVar6);
  }
  return;
}
// @@@ END IDX 166
// @@@ BEGIN IDX 167 rea_std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char_______pair__dup2
// ------------------------------------------------------------------
// IDX 167  0010c440  std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char_______pair
// ------------------------------------------------------------------
void rea_std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char_______pair__dup2(pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_std__vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_____std__basic_string_char__std__char_traits_char__std__allocator_char___ * this_ptr, int __in_chrg) {
  int *piVar1;
  char *pcVar2;
  undefined *puVar3;
  int iVar4;
  rea_v pbVar5;
  rea_v pbVar6;
  
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
  pcVar2 = (rea_bind(this_ptr)->second).second._M_dataplus._M_p;
  if ((allocator *)(pcVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar1 = (int *)(pcVar2 + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar4 = *(int *)(pcVar2 + -8);
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
  pbVar6 = (rea_bind(this_ptr)->second).first. super__Vector_base ._M_impl._M_finish;
  pbVar5 = (rea_bind(this_ptr)->second).first. super__Vector_base ._M_impl._M_start;
  if (pbVar6 != pbVar5) {
    do {
      pcVar2 = (pbVar5->_M_dataplus)._M_p;
      if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar3) {
        piVar1 = (int *)(pcVar2 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar4 = *(int *)(pcVar2 + -8);
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
    pbVar6 = (rea_bind(this_ptr)->second).first. super__Vector_base ._M_impl._M_start;
  }
  if (pbVar6 != (pointer)0x0) {
    rea_operator_delete(pbVar6);
  }
  pcVar2 = (rea_bind(this_ptr)->first)._M_dataplus._M_p;
  if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar3) {
    piVar1 = (int *)(pcVar2 + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar4 = *(int *)(pcVar2 + -8);
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
// @@@ END IDX 167
// @@@ BEGIN IDX 168 rea___gnu_cxx____to_xstring_std__basic_string_char__char__dup2
// ------------------------------------------------------------------
// IDX 168  0010c560  __gnu_cxx____to_xstring_std__basic_string_char__char
// ------------------------------------------------------------------
basic_string_char__std__char_traits_char__std__allocator_char_ rea___gnu_cxx____to_xstring_std__basic_string_char__char__dup2(code * __convf, size_t __n, char * __fmt, undefined8 param_x3) {
  undefined8 stack0x00000008;
  undefined1 *__src;
  long long lVar1;
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
  rea_v local_f1;
  rea_v __args [1];
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
                    /* Unresolved local var: char * __s@[???] Unresolved local var: int __len@[???] */ __args[0].overflow_arg_area = (void *)&stack0x00000008;
  lVar1 = -((ulong)(__fmt + 0x1e) & 0xfffffffffffffff0);
  __args[0].reg_save_area = local_d8;
  __src = (undefined1 *)((long long)__args + lVar1);
  __args[0].gp_offset = 0x20;
  __args[0].fp_offset = 0x30;
  local_b8 = in_R8;
  local_b0 = in_R9;
  *(undefined8 *)((long long)&uStack_100 + lVar1) = 0x10c604;
  iVar2 = (*(code *)__n)(__src,__fmt,in_RCX,__args);
                    /* Unresolved local var: size_type __dnew@[???] Unresolved local var: _Rep * __r@[???] */ if (__src == __src + iVar2) {
    __dest = (ulong *)(PTR__S_empty_rep_storage_00311ff0 + 0x18);
  }
  else {
    __n_00 = (long long)(__src + iVar2) - (long long)__src;
    *(undefined8 *)((long long)&uStack_100 + lVar1) = 0x10c623;
    puVar3 = (ulong *)rea_std__string___Rep___S_create(__n_00,0,&local_f1);
    __dest = puVar3 + 3;
    if (__n_00 == 1) {
      *(undefined1 *)(puVar3 + 3) = *__src;
    }
    else {
      *(undefined8 *)((long long)&uStack_100 + lVar1) = 0x10c63e;
      __dest = (ulong*)rea_pv(rea_memcpy(__dest,__src,__n_00));
    }
    if (puVar3 != (ulong *)PTR__S_empty_rep_storage_00311ff0) {
      *(undefined4 *)(puVar3 + 2) = 0;
      *puVar3 = __n_00;
      *(undefined1 *)((long long)puVar3 + __n_00 + 0x18) = 0;
    }
  }
  *(ulong **)__convf = __dest;
  return (basic_string_char__std__char_traits_char__std__allocator_char_)(_Alloc_hider)__convf;
}
// @@@ END IDX 168
// @@@ BEGIN IDX 169 rea_std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______vector__dup2
// ------------------------------------------------------------------
// IDX 169  0010c690  std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______vector
// ------------------------------------------------------------------
void rea_std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______vector__dup2(vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___ * this_ptr, int __in_chrg) {
  int *piVar1;
  char *pcVar2;
  undefined *puVar3;
  int iVar4;
  rea_v pbVar5;
  rea_v pbVar6;
  
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
  pbVar6 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_finish;
  pbVar5 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start;
  if (pbVar6 != pbVar5) {
    do {
      pcVar2 = (pbVar5->_M_dataplus)._M_p;
      if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar3) {
        piVar1 = (int *)(pcVar2 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg2(RCX)] */ iVar4 = *(int *)(pcVar2 + -8);
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
    pbVar6 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start;
  }
  if (pbVar6 != (pointer)0x0) {
    rea_operator_delete(pbVar6);
  }
  return;
}
// @@@ END IDX 169
// @@@ BEGIN IDX 170 rea_std___vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double_______vector__dup2
// ------------------------------------------------------------------
// IDX 170  0010c730  std___vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double_______vector
// ------------------------------------------------------------------
void rea_std___vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double_______vector__dup2(vector_std__vector_double__std__allocator_double___std__allocator_std__vector_double__std__allocator_double___ * this_ptr, int __in_chrg) {
  rea_v pdVar1;
  rea_v pvVar2;
  rea_v pvVar3;
  
  pvVar3 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_finish;
  pvVar2 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start;
  if (pvVar3 != pvVar2) {
    do {
      pdVar1 = (pvVar2->super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
      if (pdVar1 != (pointer)0x0) {
        rea_operator_delete(pdVar1);
      }
      pvVar2 = pvVar2 + 1;
    } while (pvVar3 != pvVar2);
    pvVar3 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start;
  }
  if (pvVar3 == (pointer)0x0) {
    return;
  }
  rea_operator_delete(pvVar3);
  return;
}
// @@@ END IDX 170
// @@@ BEGIN IDX 171 rea_IndexedData_GIDKey__Item__free__dup2
// ------------------------------------------------------------------
// IDX 171  0010c780  IndexedData_GIDKey__Item__free
// ------------------------------------------------------------------
void rea_IndexedData_GIDKey__Item__free__dup2(IndexedData_GIDKey__Item * this_ptr) {
  rea_bind(this_ptr)->num_idxs = 0;
  rea_bind(this_ptr)->num_items = 0;
  if (rea_bind(this_ptr)->idxs != (Index *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->idxs);
    rea_bind(this_ptr)->idxs = (Index *)0x0;
  }
  if (rea_bind(this_ptr)->items != (Item *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->items);
    rea_bind(this_ptr)->items = (Item *)0x0;
  }
  return;
}
// @@@ END IDX 171
// @@@ BEGIN IDX 172 rea_PyWrapper_double
// ------------------------------------------------------------------
// IDX 172  0010c7c0  PyWrapper<double_
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_double(undefined8 param_x0, undefined8 * pyargs) {
  int *piVar1;
  long long lVar2;
  int iVar3;
  char *pcVar4;
  rea_adr pPVar5;
  ulong uVar6;
  double dVar7;
  rea_v local_79;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined2 local_68;
  undefined1 local_66;
  rea_v t;
  rea_v t_1;
  rea_v local_38 [3];
  
                    /* Unresolved local var: double r@[???] */ local_68 = 0x4f4f;
  local_76 = 0;
  local_78 = 0x4f;
  local_77 = 0x4f;
  local_66 = 0;
  (*(undefined1 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x2)) = 0;
  (*(undefined2 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x0)) = 0x4f4f;
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
    lVar2 = CONCAT53((*(arr_undefined1_5 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x3)), CONCAT12((*(undefined1 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x2)),(*(undefined2 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x0))) );
    if ((allocator *)(lVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar1 = (int *)(lVar2 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar3 = *(int *)(lVar2 + -8);
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
  return (undefined8)(PyObject *)0x0;
}
// @@@ END IDX 172
// @@@ BEGIN IDX 173 rea_PyWrapper_double__dup2
// ------------------------------------------------------------------
// IDX 173  0010c930  PyWrapper<double_
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_double__dup2(undefined8 param_x0, undefined8 * pyargs) {
  int *piVar1;
  long long lVar2;
  int iVar3;
  char *pcVar4;
  rea_adr pPVar5;
  ulong uVar6;
  double dVar7;
  rea_v local_79;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined2 local_68;
  undefined1 local_66;
  rea_v t;
  rea_v t_1;
  rea_v local_38 [3];
  
                    /* Unresolved local var: double r@[???] */ local_68 = 0x4f4f;
  local_76 = 0;
  local_78 = 0x4f;
  local_77 = 0x4f;
  local_66 = 0;
  (*(undefined1 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x2)) = 0;
  (*(undefined2 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x0)) = 0x4f4f;
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
    dVar7 = rea_getLastClosePrice((string*)rea_pv(local_38),iVar3);
    lVar2 = CONCAT53((*(arr_undefined1_5 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x3)), CONCAT12((*(undefined1 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x2)),(*(undefined2 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x0))) );
    if ((allocator *)(lVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar1 = (int *)(lVar2 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar3 = *(int *)(lVar2 + -8);
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
  return (undefined8)(PyObject *)0x0;
}
// @@@ END IDX 173
// @@@ BEGIN IDX 174 rea_PyWrapper_double__dup3
// ------------------------------------------------------------------
// IDX 174  0010caa0  PyWrapper<double_
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_double__dup3(undefined8 param_x0, undefined8 * pyargs) {
  int *piVar1;
  long long lVar2;
  int iVar3;
  char *pcVar4;
  rea_adr pPVar5;
  ulong uVar6;
  double dVar7;
  rea_v local_79;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined2 local_68;
  undefined1 local_66;
  rea_v t;
  rea_v t_1;
  rea_v local_38 [3];
  
                    /* Unresolved local var: double r@[???] */ local_68 = 0x4f4f;
  local_76 = 0;
  local_78 = 0x4f;
  local_77 = 0x4f;
  local_66 = 0;
  (*(undefined1 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x2)) = 0;
  (*(undefined2 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x0)) = 0x4f4f;
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
    lVar2 = CONCAT53((*(arr_undefined1_5 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x3)), CONCAT12((*(undefined1 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x2)),(*(undefined2 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x0))) );
    if ((allocator *)(lVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar1 = (int *)(lVar2 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar3 = *(int *)(lVar2 + -8);
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
  return (undefined8)(PyObject *)0x0;
}
// @@@ END IDX 174
// @@@ BEGIN IDX 175 rea_PyWrapper_double__dup4
// ------------------------------------------------------------------
// IDX 175  0010cc10  PyWrapper<double_
// ------------------------------------------------------------------
undefined8 rea_PyWrapper_double__dup4(undefined8 param_x0, undefined8 * pyargs) {
  int *piVar1;
  long long lVar2;
  int iVar3;
  char *pcVar4;
  rea_adr pPVar5;
  ulong uVar6;
  double dVar7;
  rea_v local_79;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined2 local_68;
  undefined1 local_66;
  rea_v t;
  rea_v t_1;
  rea_v local_38 [3];
  
                    /* Unresolved local var: double r@[???] */ local_68 = 0x4f4f;
  local_76 = 0;
  local_78 = 0x4f;
  local_77 = 0x4f;
  local_66 = 0;
  (*(undefined1 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x2)) = 0;
  (*(undefined2 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x0)) = 0x4f4f;
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
    dVar7 = rea_getRescale((string*)rea_pv(local_38),iVar3);
    lVar2 = CONCAT53((*(arr_undefined1_5 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x3)), CONCAT12((*(undefined1 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x2)),(*(undefined2 *)((uint8_t *)&rea_bind(local_38[0]._M_dataplus)._M_p + 0x0))) );
    if ((allocator *)(lVar2 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar1 = (int *)(lVar2 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar3 = *(int *)(lVar2 + -8);
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
  return (undefined8)(PyObject *)0x0;
}
// @@@ END IDX 175
// @@@ BEGIN IDX 176 rea_IndexedData_GIDKey__Item2__free__dup2
// ------------------------------------------------------------------
// IDX 176  0010cd80  IndexedData_GIDKey__Item2__free
// ------------------------------------------------------------------
void rea_IndexedData_GIDKey__Item2__free__dup2(IndexedData_GIDKey__Item2 * this_ptr) {
  rea_bind(this_ptr)->num_idxs = 0;
  rea_bind(this_ptr)->num_items = 0;
  if (rea_bind(this_ptr)->idxs != (Index *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->idxs);
    rea_bind(this_ptr)->idxs = (Index *)0x0;
  }
  if (rea_bind(this_ptr)->items != (Item2 *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->items);
    rea_bind(this_ptr)->items = (Item2 *)0x0;
  }
  return;
}
// @@@ END IDX 176
// @@@ BEGIN IDX 177 rea_IndexedData_GroupKey__GroupForwardItem__free__dup2
// ------------------------------------------------------------------
// IDX 177  0010cdc0  IndexedData_GroupKey__GroupForwardItem__free
// ------------------------------------------------------------------
void rea_IndexedData_GroupKey__GroupForwardItem__free__dup2(IndexedData_GroupKey__GroupForwardItem * this_ptr) {
  rea_bind(this_ptr)->num_idxs = 0;
  rea_bind(this_ptr)->num_items = 0;
  if (rea_bind(this_ptr)->idxs != (Index *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->idxs);
    rea_bind(this_ptr)->idxs = (Index *)0x0;
  }
  if (rea_bind(this_ptr)->items != (GroupForwardItem *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->items);
    rea_bind(this_ptr)->items = (GroupForwardItem *)0x0;
  }
  return;
}
// @@@ END IDX 177
// @@@ BEGIN IDX 178 rea_IndexedData_GIDKey__GroupBackwardItem__free__dup2
// ------------------------------------------------------------------
// IDX 178  0010ce00  IndexedData_GIDKey__GroupBackwardItem__free
// ------------------------------------------------------------------
void rea_IndexedData_GIDKey__GroupBackwardItem__free__dup2(IndexedData_GIDKey__GroupBackwardItem * this_ptr) {
  rea_bind(this_ptr)->num_idxs = 0;
  rea_bind(this_ptr)->num_items = 0;
  if (rea_bind(this_ptr)->idxs != (Index *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->idxs);
    rea_bind(this_ptr)->idxs = (Index *)0x0;
  }
  if (rea_bind(this_ptr)->items != (GroupBackwardItem *)0x0) {
    rea_operator_delete(rea_bind(this_ptr)->items);
    rea_bind(this_ptr)->items = (GroupBackwardItem *)0x0;
  }
  return;
}
// @@@ END IDX 178
// @@@ BEGIN IDX 179 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_______find__dup2
// ------------------------------------------------------------------
// IDX 179  0010ce40  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_______find
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_______find__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, int * __k) {
  rea_adr p_Var1;
  rea_adr pp_Var2;
  rea_v p_Var3;
  rea_v p_Var4;
  rea_v iVar5;
  
  p_Var3 = (rea_bind(this_ptr)->_M_impl)._M_header._M_parent;
                    /* Unresolved local var: iterator __j@[???] */ p_Var1 = &(rea_bind(this_ptr)->_M_impl)._M_header;
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
// @@@ END IDX 179
// @@@ BEGIN IDX 180 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_erase__dup2
// ------------------------------------------------------------------
// IDX 180  0010ce90  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_erase__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * this_ptr, _Link_type __x) {
  int *piVar1;
  rea_v pdVar2;
  rea_v p_Var3;
  char *pcVar4;
  undefined *puVar5;
  int iVar6;
  
  puVar5 = PTR__S_empty_rep_storage_00311ff0;
  while (rea_bind(__x) != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_right);
    pdVar2 = (rea_bind(__x)->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_start;
    p_Var3 = (_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_left;
    if (pdVar2 != (pointer)0x0) {
      rea_operator_delete(pdVar2);
    }
    pcVar4 = (rea_bind(__x)->_M_value_field).first._M_dataplus._M_p;
    if ((allocator *)(pcVar4 + -0x18) != (allocator *)puVar5) {
      piVar1 = (int *)(pcVar4 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar6 = *(int *)(pcVar4 + -8);
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
// @@@ END IDX 180
// @@@ BEGIN IDX 181 rea_std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______M_emplace_back_aux_const_std__basic_string_char__std__char_traits_char__std__allocator_char__dup2
// ------------------------------------------------------------------
// IDX 181  0010cf40  std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______M_emplace_back_aux_const_std__basic_string_char__std__char_traits_char__std__allocator_char_____________
// ------------------------------------------------------------------
void rea_std___vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char_______M_emplace_back_aux_const_std__basic_string_char__std__char_traits_char__std__allocator_char__dup2(vector_std__basic_string_char__std__char_traits_char__std__allocator_char___std__allocator_std__basic_string_char__std__char_traits_char__std__allocator_char___ * this_ptr) {
  char *pcVar1;
  int *piVar2;
  undefined *puVar3;
  ulong uVar4;
  int iVar5;
  ulong uVar6;
  rea_v pbVar7;
  void *this_00;
  rea_v pbVar8;
  rea_v pbVar9;
  rea_v pbVar10;
  rea_adr in_RSI;
  rea_v pbVar11;
  ulong uVar12;
  rea_v pbVar13;
  
                    /* Unresolved local var: size_type __len@[???] Unresolved local var: pointer __new_start@[???] Unresolved local var: pointer __new_finish@[???] */ uVar6 = (long long)(rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_finish - (long long)(rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start >> 3;
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
  pbVar13 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_finish;
  pbVar11 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start;
  this_00 = (void *)((long long)&(pbVar7->_M_dataplus)._M_p + ((long long)pbVar13 - (long long)pbVar11 & 0xfffffffffffffff8U));
  if (this_00 != (void *)0x0) {
    rea_std__string__string(this_00,in_RSI);
    pbVar13 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_finish;
    pbVar11 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start;
  }
  puVar3 = PTR__S_empty_rep_storage_00311ff0;
                    /* Unresolved local var:
                       basic_string_char__std__char_traits_char__std__allocator_char_ *
                       __cur@[???] */
  if (pbVar11 == pbVar13) {
    pbVar8 = pbVar7 + 1;
  }
  else {
    pcVar1 = (char*)rea_pv(PTR__S_empty_rep_storage_00311ff0 + 0x18);
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
    pbVar8 = (pointer)((long long)&pbVar7[2]._M_dataplus._M_p + ((long long)pbVar13 - (long long)(pbVar11 + 1) & 0xfffffffffffffff8U));
    pbVar9 = pbVar11 + 1;
    while( true ) {
      pbVar10 = pbVar9;
      pcVar1 = (pbVar11->_M_dataplus)._M_p;
      if ((allocator *)(pcVar1 + -0x18) != (allocator *)puVar3) {
        piVar2 = (int *)(pcVar1 + -8);
        if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar5 = *(int *)(pcVar1 + -8);
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
    pbVar11 = (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start;
  }
  if (pbVar11 != (pointer)0x0) {
    rea_operator_delete(pbVar11);
  }
  (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_start = pbVar7;
  (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_finish = pbVar8;
  (rea_bind(this_ptr)-> super__Vector_base )._M_impl._M_end_of_storage = pbVar7 + uVar12;
  return;
}
// @@@ END IDX 181
// @@@ BEGIN IDX 182 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_erase__dup2
// ------------------------------------------------------------------
// IDX 182  0010d140  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_erase__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, _Link_type __x) {
  int *piVar1;
  char *pcVar2;
  rea_v p_Var3;
  undefined *puVar4;
  int iVar5;
  
  puVar4 = PTR__S_empty_rep_storage_00311ff0;
  while (rea_bind(__x) != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_right);
    pcVar2 = (rea_bind(__x)->_M_value_field).first._M_dataplus._M_p;
    p_Var3 = (_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_left;
    if ((allocator *)(pcVar2 + -0x18) != (allocator *)puVar4) {
      piVar1 = (int *)(pcVar2 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg2(RCX)] */ iVar5 = *(int *)(pcVar2 + -8);
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
// @@@ END IDX 182
// @@@ BEGIN IDX 183 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_____find__dup2
// ------------------------------------------------------------------
// IDX 183  0010d1e0  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_____find
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_____find__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, basic_string_char__std__char_traits_char__std__allocator_char_ * __k) {
  rea_adr p_Var1;
  rea_adr pp_Var2;
  rea_v p_Var3;
  char *__s2;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  ulong uVar7;
  long long lVar8;
  rea_v p_Var9;
  rea_v p_Var10;
  
                    /* Unresolved local var: iterator __j@[???] */ p_Var1 = &(rea_bind(this_ptr)->_M_impl)._M_header;
  p_Var3 = (rea_bind(this_ptr)->_M_impl)._M_header._M_parent;
  if (p_Var3 != (_Base_ptr)0x0) {
    __s2 = rea_bind((__k->_M_dataplus))._M_p;
    uVar4 = *(ulong *)(__s2 + -0x18);
    p_Var9 = p_Var1;
    do {
      while( true ) {
        p_Var10 = p_Var3;
        uVar5 = *(ulong *)((long long)*(void **)(p_Var10 + 1) + -0x18);
        uVar7 = uVar5;
        if (uVar4 <= uVar5) {
          uVar7 = uVar4;
        }
        iVar6 = rea_memcmp(*(void **)(p_Var10 + 1),__s2,uVar7);
        if (iVar6 != 0) break;
        lVar8 = uVar5 - uVar4;
        if (0x7fffffff < lVar8) goto LAB_0010d216;
        if (-0x80000001 < lVar8) {
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] Unresolved local var: difference_type __d@[???] */ iVar6 = (int)lVar8;
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
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] */ uVar5 = *(ulong *)((long long)*(void **)(p_Var10 + 1) + -0x18);
    uVar7 = uVar5;
    if (uVar4 <= uVar5) {
      uVar7 = uVar4;
    }
    iVar6 = rea_memcmp(__s2,*(void **)(p_Var10 + 1),uVar7);
    if (iVar6 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */ lVar8 = uVar4 - uVar5;
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
// @@@ END IDX 183
// @@@ BEGIN IDX 184 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_erase__dup2
// ------------------------------------------------------------------
// IDX 184  0010d2d0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_erase__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, _Link_type __x) {
  rea_v _Var1;
  rea_v p_Var2;
  
  while (rea_bind(__x) != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_right);
                    /* Unresolved local var: Data2 * * __ptr@[???] */ _Var1 = (rea_bind(__x)->_M_value_field).second._M_t. super__Tuple_impl;
    p_Var2 = (_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_left;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long long)_Var1 + 4) = 0;
      if (*(void **)((long long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 8));
        *(undefined8 *)((long long)_Var1 + 8) = 0;
      }
      if (*(void **)((long long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 0x10));
        *(undefined8 *)((long long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (rea_bind(__x)->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__Data2___std__default_delete_SecInfo__Data2_)0x0;
    rea_operator_delete(__x);
    __x = p_Var2;
  }
  return;
}
// @@@ END IDX 184
// @@@ BEGIN IDX 185 rea_std___map_int__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________map
// ------------------------------------------------------------------
// IDX 185  0010d370  std___map_int__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________map
// ------------------------------------------------------------------
void rea_std___map_int__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________map(map_int__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, int __in_chrg) {
  _Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2__________M_erase(rea_bind(&this_ptr)->_M_t,(_Link_type)(rea_bind(this_ptr)->_M_t)._M_impl._M_header._M_parent);
  return;
}
// @@@ END IDX 185
// @@@ BEGIN IDX 186 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_unique_pos__dup2
// ------------------------------------------------------------------
// IDX 186  0010d380  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_unique_pos__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, key_type * __k) {
  rea_adr p_Var1;
  int iVar2;
  _Rb_tree_color _Var3;
  rea_adr p_Var4;
  rea_adr p_Var5;
  rea_v pVar6;
  
  p_Var1 = (rea_bind(this_ptr)->_M_impl)._M_header._M_parent;
                    /* Unresolved local var: _Link_type __x@[???] Unresolved local var: _Link_type __y@[???] Unresolved local var: bool __comp@[???] Unresolved local var: iterator __j@[???] */ if (p_Var1 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = &(rea_bind(this_ptr)->_M_impl)._M_header;
LAB_0010d3f0:
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
    if ((rea_bind(this_ptr)->_M_impl)._M_header._M_left == p_Var5) goto LAB_0010d3df;
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var5);
    iVar2 = (int)rea_iv(*__k);
    _Var3 = p_Var1[1]._M_color;
  }
  else {
    iVar2 = (int)rea_iv(*__k);
    do {
      p_Var5 = p_Var1;
      _Var3 = p_Var5[1]._M_color;
      if (iVar2 < (int)_Var3) {
        p_Var1 = p_Var5->_M_left;
      }
      else {
        p_Var1 = p_Var5->_M_right;
      }
    } while (rea_bind(p_Var1) != (_Base_ptr)0x0);
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
// @@@ END IDX 186
// @@@ BEGIN IDX 187 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_insert_node__dup2
// ------------------------------------------------------------------
// IDX 187  0010d420  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_insert_node
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_insert_node__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, _Base_ptr __x, _Base_ptr __p, _Link_type __z) {
  rea_adr p_Var1;
  size_type *psVar2;
  bool bVar3;
  
  p_Var1 = &(rea_bind(this_ptr)->_M_impl)._M_header;
                    /* Unresolved local var: bool __insert_left@[???] */ if ((rea_bind(__x) == (_Base_ptr)0x0) && (rea_bind(p_Var1) != __p)) {
    bVar3 = (rea_bind(__z)->_M_value_field).first < rea_bind(rea_cast<int >(__p))[1]._M_color;
  }
  else {
    bVar3 = true;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar3,rea_bind(&__z)->super__Rb_tree_node_base,__p,p_Var1);
  psVar2 = &(rea_bind(this_ptr)->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)rea_bind(&__z)->super__Rb_tree_node_base;
}
// @@@ END IDX 187
// @@@ BEGIN IDX 188 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_hint_unique_pos__dup2
// ------------------------------------------------------------------
// IDX 188  0010d470  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2________M_get_insert_hint_unique_pos__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__Data2__std__default_delete_SecInfo__Data2____ * this_ptr, const_iterator __position, key_type * __k) {
  int iVar1;
  rea_v p_Var2;
  rea_v cVar3;
  rea_v cVar4;
  rea_v pVar5;
  rea_v pVar6;
  rea_v pVar7;
  
                    /* Unresolved local var: iterator __pos@[DW_OP_reg4(RSI); DW_OP_piece: 8] */ if (rea_bind(__position)._M_node == &(rea_bind(this_ptr)->_M_impl)._M_header) {
    if (((rea_bind(this_ptr)->_M_impl)._M_node_count == 0) || (cVar3._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_right, rea_bind(*__k) <= (int)cVar3._M_node[1]._M_color)) {
LAB_0010d528:
      pVar7 = _M_get_insert_unique_pos(this_ptr,__k);
      return pVar7;
    }
  }
  else {
    iVar1 = (int)rea_iv(*__k);
    if (iVar1 < rea_bind((int)__position)._M_node[1]._M_color) {
                    /* Unresolved local var: iterator __before@[???] */ cVar4._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_left;
      cVar3._M_node = cVar4._M_node;
      if (cVar4._M_node != rea_bind(__position)._M_node) {
        cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_decrement(rea_bind(__position)._M_node);
        if (iVar1 <= (int)cVar3._M_node[1]._M_color) goto LAB_0010d528;
        cVar4._M_node = (_Base_ptr)0x0;
        if ((cVar3._M_node)->_M_right != (_Base_ptr)0x0) {
          cVar4._M_node = rea_bind(__position)._M_node;
          cVar3._M_node = rea_bind(__position)._M_node;
        }
      }
      goto LAB_0010d4c5;
    }
    if (iVar1 <= rea_bind((int)__position)._M_node[1]._M_color) {
      pVar7.second = (_Rb_tree_node_base *)0x0;
      pVar7.first = rea_bind(__position)._M_node;
      return pVar7;
    }
                    /* Unresolved local var: iterator __after@[???] */ cVar3._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_right;
    if (cVar3._M_node != rea_bind(__position)._M_node) {
      cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_increment(rea_bind(__position)._M_node);
      if (iVar1 < (int)cVar3._M_node[1]._M_color) {
        p_Var2 = cVar3._M_node;
        if ((rea_bind(__position)._M_node)->_M_right == (_Base_ptr)0x0) {
          cVar3._M_node = rea_bind(__position)._M_node;
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
// @@@ END IDX 188
// @@@ BEGIN IDX 189 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_unique_pos__dup2
// ------------------------------------------------------------------
// IDX 189  0010d560  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_unique_pos__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, key_type * __k) {
  rea_adr p_Var1;
  int iVar2;
  _Rb_tree_color _Var3;
  rea_adr p_Var4;
  rea_adr p_Var5;
  rea_v pVar6;
  
  p_Var1 = (rea_bind(this_ptr)->_M_impl)._M_header._M_parent;
                    /* Unresolved local var: _Link_type __x@[???] Unresolved local var: _Link_type __y@[???] Unresolved local var: bool __comp@[???] Unresolved local var: iterator __j@[???] */ if (p_Var1 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = &(rea_bind(this_ptr)->_M_impl)._M_header;
LAB_0010d5d0:
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
    if ((rea_bind(this_ptr)->_M_impl)._M_header._M_left == p_Var5) goto LAB_0010d5bf;
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var5);
    iVar2 = (int)rea_iv(*__k);
    _Var3 = p_Var1[1]._M_color;
  }
  else {
    iVar2 = (int)rea_iv(*__k);
    do {
      p_Var5 = p_Var1;
      _Var3 = p_Var5[1]._M_color;
      if (iVar2 < (int)_Var3) {
        p_Var1 = p_Var5->_M_left;
      }
      else {
        p_Var1 = p_Var5->_M_right;
      }
    } while (rea_bind(p_Var1) != (_Base_ptr)0x0);
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
// @@@ END IDX 189
// @@@ BEGIN IDX 190 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_insert_node__dup2
// ------------------------------------------------------------------
// IDX 190  0010d600  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_insert_node
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_insert_node__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, _Base_ptr __x, _Base_ptr __p, _Link_type __z) {
  rea_adr p_Var1;
  size_type *psVar2;
  bool bVar3;
  
  p_Var1 = &(rea_bind(this_ptr)->_M_impl)._M_header;
                    /* Unresolved local var: bool __insert_left@[???] */ if ((rea_bind(__x) == (_Base_ptr)0x0) && (rea_bind(p_Var1) != __p)) {
    bVar3 = (rea_bind(__z)->_M_value_field).first < rea_bind(rea_cast<int >(__p))[1]._M_color;
  }
  else {
    bVar3 = true;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar3,rea_bind(&__z)->super__Rb_tree_node_base,__p,p_Var1);
  psVar2 = &(rea_bind(this_ptr)->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)rea_bind(&__z)->super__Rb_tree_node_base;
}
// @@@ END IDX 190
// @@@ BEGIN IDX 191 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1__dup2
// ------------------------------------------------------------------
// IDX 191  0010d650  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____________
// ------------------------------------------------------------------
pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____bool rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr) {
  rea_v _Var1;
  rea_v __z;
  rea_adr in_RDX;
  int *in_RSI;
  rea_v pVar2;
  rea_v pVar3;
  rea_v pVar4;
  
                    /* Unresolved local var: _Link_type __z@[???] Unresolved local var: _Link_type __tmp@[???] */ __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->_M_value_field).first = *in_RSI;
                    /* Unresolved local var: pointer __p@[???] */ _Var1 = *in_RDX;
    *in_RDX = (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0 ;
    (__z->_M_value_field).second._M_t. super__Tuple_impl = _Var1;
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
                    /* Unresolved local var: GroupData1 * * __ptr@[???] */ _Var1 = (__z->_M_value_field).second._M_t. super__Tuple_impl;
  if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_) 0x0) {
    *(undefined4 *)_Var1 = 0;
    *(undefined4 *)((long long)_Var1 + 4) = 0;
    if (*(void **)((long long)_Var1 + 8) != (void *)0x0) {
      rea_operator_delete(*(void **)((long long)_Var1 + 8));
      *(undefined8 *)((long long)_Var1 + 8) = 0;
    }
    if (*(void **)((long long)_Var1 + 0x10) != (void *)0x0) {
      rea_operator_delete(*(void **)((long long)_Var1 + 0x10));
      *(undefined8 *)((long long)_Var1 + 0x10) = 0;
    }
    rea_operator_delete((void *)_Var1);
  }
  (__z->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
  rea_operator_delete(__z);
  (*(undefined8 *)((uint8_t *)&pVar4 + 0x8)) = 0;
  return pVar4;
}
// @@@ END IDX 191
// @@@ BEGIN IDX 192 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_unique_pos__dup2
// ------------------------------------------------------------------
// IDX 192  0010d760  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_unique_pos__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, key_type * __k) {
  rea_adr p_Var1;
  int iVar2;
  _Rb_tree_color _Var3;
  rea_adr p_Var4;
  rea_adr p_Var5;
  rea_v pVar6;
  
  p_Var1 = (rea_bind(this_ptr)->_M_impl)._M_header._M_parent;
                    /* Unresolved local var: _Link_type __x@[???] Unresolved local var: _Link_type __y@[???] Unresolved local var: bool __comp@[???] Unresolved local var: iterator __j@[???] */ if (p_Var1 == (_Rb_tree_node_base *)0x0) {
    p_Var5 = &(rea_bind(this_ptr)->_M_impl)._M_header;
LAB_0010d7d0:
    p_Var1 = (_Rb_tree_node_base *)0x0;
    p_Var4 = p_Var5;
    if ((rea_bind(this_ptr)->_M_impl)._M_header._M_left == p_Var5) goto LAB_0010d7bf;
    p_Var1 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var5);
    iVar2 = (int)rea_iv(*__k);
    _Var3 = p_Var1[1]._M_color;
  }
  else {
    iVar2 = (int)rea_iv(*__k);
    do {
      p_Var5 = p_Var1;
      _Var3 = p_Var5[1]._M_color;
      if (iVar2 < (int)_Var3) {
        p_Var1 = p_Var5->_M_left;
      }
      else {
        p_Var1 = p_Var5->_M_right;
      }
    } while (rea_bind(p_Var1) != (_Base_ptr)0x0);
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
// @@@ END IDX 192
// @@@ BEGIN IDX 193 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_insert_node__dup2
// ------------------------------------------------------------------
// IDX 193  0010d800  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_insert_node
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_insert_node__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, _Base_ptr __x, _Base_ptr __p, _Link_type __z) {
  rea_adr p_Var1;
  size_type *psVar2;
  bool bVar3;
  
  p_Var1 = &(rea_bind(this_ptr)->_M_impl)._M_header;
                    /* Unresolved local var: bool __insert_left@[???] */ if ((rea_bind(__x) == (_Base_ptr)0x0) && (rea_bind(p_Var1) != __p)) {
    bVar3 = (rea_bind(__z)->_M_value_field).first < rea_bind(rea_cast<int >(__p))[1]._M_color;
  }
  else {
    bVar3 = true;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar3,rea_bind(&__z)->super__Rb_tree_node_base,__p,p_Var1);
  psVar2 = &(rea_bind(this_ptr)->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)rea_bind(&__z)->super__Rb_tree_node_base;
}
// @@@ END IDX 193
// @@@ BEGIN IDX 194 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2__dup2
// ------------------------------------------------------------------
// IDX 194  0010d850  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____________
// ------------------------------------------------------------------
pair_std___Rb_tree_iterator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____bool rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_________M_emplace_unique_int___std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr) {
  rea_v _Var1;
  rea_v __z;
  rea_adr in_RDX;
  int *in_RSI;
  rea_v pVar2;
  rea_v pVar3;
  rea_v pVar4;
  
                    /* Unresolved local var: _Link_type __z@[???] Unresolved local var: _Link_type __tmp@[???] */ __z = rea_operator_new(0x30);
  if (__z != (_Link_type)0x0) {
    (__z->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    (__z->super__Rb_tree_node_base)._M_color = _S_red;
    (__z->_M_value_field).first = *in_RSI;
                    /* Unresolved local var: pointer __p@[???] */ _Var1 = *in_RDX;
    *in_RDX = (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0 ;
    (__z->_M_value_field).second._M_t. super__Tuple_impl = _Var1;
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
                    /* Unresolved local var: GroupData2 * * __ptr@[???] */ _Var1 = (__z->_M_value_field).second._M_t. super__Tuple_impl;
  if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_) 0x0) {
    *(undefined4 *)_Var1 = 0;
    *(undefined4 *)((long long)_Var1 + 4) = 0;
    if (*(void **)((long long)_Var1 + 8) != (void *)0x0) {
      rea_operator_delete(*(void **)((long long)_Var1 + 8));
      *(undefined8 *)((long long)_Var1 + 8) = 0;
    }
    if (*(void **)((long long)_Var1 + 0x10) != (void *)0x0) {
      rea_operator_delete(*(void **)((long long)_Var1 + 0x10));
      *(undefined8 *)((long long)_Var1 + 0x10) = 0;
    }
    rea_operator_delete((void *)_Var1);
  }
  (__z->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
  rea_operator_delete(__z);
  (*(undefined8 *)((uint8_t *)&pVar4 + 0x8)) = 0;
  return pVar4;
}
// @@@ END IDX 194
// @@@ BEGIN IDX 195 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_hint_unique_pos__dup2
// ------------------------------------------------------------------
// IDX 195  0010d960  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_get_insert_hint_unique_pos__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, const_iterator __position, key_type * __k) {
  int iVar1;
  rea_v p_Var2;
  rea_v cVar3;
  rea_v cVar4;
  rea_v pVar5;
  rea_v pVar6;
  rea_v pVar7;
  
                    /* Unresolved local var: iterator __pos@[DW_OP_reg4(RSI); DW_OP_piece: 8] */ if (rea_bind(__position)._M_node == &(rea_bind(this_ptr)->_M_impl)._M_header) {
    if (((rea_bind(this_ptr)->_M_impl)._M_node_count == 0) || (cVar3._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_right, rea_bind(*__k) <= (int)cVar3._M_node[1]._M_color)) {
LAB_0010da18:
      pVar7 = _M_get_insert_unique_pos(this_ptr,__k);
      return pVar7;
    }
  }
  else {
    iVar1 = (int)rea_iv(*__k);
    if (iVar1 < rea_bind((int)__position)._M_node[1]._M_color) {
                    /* Unresolved local var: iterator __before@[???] */ cVar4._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_left;
      cVar3._M_node = cVar4._M_node;
      if (cVar4._M_node != rea_bind(__position)._M_node) {
        cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_decrement(rea_bind(__position)._M_node);
        if (iVar1 <= (int)cVar3._M_node[1]._M_color) goto LAB_0010da18;
        cVar4._M_node = (_Base_ptr)0x0;
        if ((cVar3._M_node)->_M_right != (_Base_ptr)0x0) {
          cVar4._M_node = rea_bind(__position)._M_node;
          cVar3._M_node = rea_bind(__position)._M_node;
        }
      }
      goto LAB_0010d9b5;
    }
    if (iVar1 <= rea_bind((int)__position)._M_node[1]._M_color) {
      pVar7.second = (_Rb_tree_node_base *)0x0;
      pVar7.first = rea_bind(__position)._M_node;
      return pVar7;
    }
                    /* Unresolved local var: iterator __after@[???] */ cVar3._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_right;
    if (cVar3._M_node != rea_bind(__position)._M_node) {
      cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_increment(rea_bind(__position)._M_node);
      if (iVar1 < (int)cVar3._M_node[1]._M_color) {
        p_Var2 = cVar3._M_node;
        if ((rea_bind(__position)._M_node)->_M_right == (_Base_ptr)0x0) {
          cVar3._M_node = rea_bind(__position)._M_node;
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
// @@@ END IDX 195
// @@@ BEGIN IDX 196 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_hint_unique_pos__dup2
// ------------------------------------------------------------------
// IDX 196  0010da50  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_get_insert_hint_unique_pos__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, const_iterator __position, key_type * __k) {
  int iVar1;
  rea_v p_Var2;
  rea_v cVar3;
  rea_v cVar4;
  rea_v pVar5;
  rea_v pVar6;
  rea_v pVar7;
  
                    /* Unresolved local var: iterator __pos@[DW_OP_reg4(RSI); DW_OP_piece: 8] */ if (rea_bind(__position)._M_node == &(rea_bind(this_ptr)->_M_impl)._M_header) {
    if (((rea_bind(this_ptr)->_M_impl)._M_node_count == 0) || (cVar3._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_right, rea_bind(*__k) <= (int)cVar3._M_node[1]._M_color)) {
LAB_0010db08:
      pVar7 = _M_get_insert_unique_pos(this_ptr,__k);
      return pVar7;
    }
  }
  else {
    iVar1 = (int)rea_iv(*__k);
    if (iVar1 < rea_bind((int)__position)._M_node[1]._M_color) {
                    /* Unresolved local var: iterator __before@[???] */ cVar4._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_left;
      cVar3._M_node = cVar4._M_node;
      if (cVar4._M_node != rea_bind(__position)._M_node) {
        cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_decrement(rea_bind(__position)._M_node);
        if (iVar1 <= (int)cVar3._M_node[1]._M_color) goto LAB_0010db08;
        cVar4._M_node = (_Base_ptr)0x0;
        if ((cVar3._M_node)->_M_right != (_Base_ptr)0x0) {
          cVar4._M_node = rea_bind(__position)._M_node;
          cVar3._M_node = rea_bind(__position)._M_node;
        }
      }
      goto LAB_0010daa5;
    }
    if (iVar1 <= rea_bind((int)__position)._M_node[1]._M_color) {
      pVar7.second = (_Rb_tree_node_base *)0x0;
      pVar7.first = rea_bind(__position)._M_node;
      return pVar7;
    }
                    /* Unresolved local var: iterator __after@[???] */ cVar3._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_right;
    if (cVar3._M_node != rea_bind(__position)._M_node) {
      cVar3._M_node = (_Base_ptr)rea_std___Rb_tree_increment(rea_bind(__position)._M_node);
      if (iVar1 < (int)cVar3._M_node[1]._M_color) {
        p_Var2 = cVar3._M_node;
        if ((rea_bind(__position)._M_node)->_M_right == (_Base_ptr)0x0) {
          cVar3._M_node = rea_bind(__position)._M_node;
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
// @@@ END IDX 196
// @@@ BEGIN IDX 197 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_erase__dup2
// ------------------------------------------------------------------
// IDX 197  0010db40  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________M_erase__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, _Link_type __x) {
  rea_v _Var1;
  rea_v p_Var2;
  
  while (rea_bind(__x) != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_right);
                    /* Unresolved local var: GroupData1 * * __ptr@[???] */ _Var1 = (rea_bind(__x)->_M_value_field).second._M_t. super__Tuple_impl;
    p_Var2 = (_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_left;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_) 0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long long)_Var1 + 4) = 0;
      if (*(void **)((long long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 8));
        *(undefined8 *)((long long)_Var1 + 8) = 0;
      }
      if (*(void **)((long long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 0x10));
        *(undefined8 *)((long long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (rea_bind(__x)->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData1___std__default_delete_SecInfo__GroupData1_)0x0;
    rea_operator_delete(__x);
    __x = p_Var2;
  }
  return;
}
// @@@ END IDX 197
// @@@ BEGIN IDX 198 rea_std___map_int__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________map
// ------------------------------------------------------------------
// IDX 198  0010dbe0  std___map_int__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________map
// ------------------------------------------------------------------
void rea_std___map_int__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1________map(map_int__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____ * this_ptr, int __in_chrg) {
  _Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData1__std__default_delete_SecInfo__GroupData1__________M_erase(rea_bind(&this_ptr)->_M_t,(_Link_type)(rea_bind(this_ptr)->_M_t)._M_impl._M_header._M_parent);
  return;
}
// @@@ END IDX 198
// @@@ BEGIN IDX 199 rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_erase__dup2
// ------------------------------------------------------------------
// IDX 199  0010dbf0  std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_erase
// ------------------------------------------------------------------
void rea_std____Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________M_erase__dup2(_Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, _Link_type __x) {
  rea_v _Var1;
  rea_v p_Var2;
  
  while (rea_bind(__x) != (_Link_type)0x0) {
    _M_erase(this_ptr,(_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_right);
                    /* Unresolved local var: GroupData2 * * __ptr@[???] */ _Var1 = (rea_bind(__x)->_M_value_field).second._M_t. super__Tuple_impl;
    p_Var2 = (_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_left;
    if (_Var1 != (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_) 0x0) {
      *(undefined4 *)_Var1 = 0;
      *(undefined4 *)((long long)_Var1 + 4) = 0;
      if (*(void **)((long long)_Var1 + 8) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 8));
        *(undefined8 *)((long long)_Var1 + 8) = 0;
      }
      if (*(void **)((long long)_Var1 + 0x10) != (void *)0x0) {
        rea_operator_delete(*(void **)((long long)_Var1 + 0x10));
        *(undefined8 *)((long long)_Var1 + 0x10) = 0;
      }
      rea_operator_delete((void *)_Var1);
    }
    (rea_bind(__x)->_M_value_field).second._M_t. super__Tuple_impl = (_Tuple_impl_0ul__SecInfo__GroupData2___std__default_delete_SecInfo__GroupData2_)0x0;
    rea_operator_delete(__x);
    __x = p_Var2;
  }
  return;
}
// @@@ END IDX 199
// @@@ BEGIN IDX 200 rea_std___map_int__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________map
// ------------------------------------------------------------------
// IDX 200  0010dc90  std___map_int__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________map
// ------------------------------------------------------------------
void rea_std___map_int__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2________map(map_int__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2___std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____ * this_ptr, int __in_chrg) {
  _Rb_tree_int__std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2____std___Select1st_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2_____std__less_int__std__allocator_std__pair_int_const__std__unique_ptr_SecInfo__GroupData2__std__default_delete_SecInfo__GroupData2__________M_erase(rea_bind(&this_ptr)->_M_t,(_Link_type)(rea_bind(this_ptr)->_M_t)._M_impl._M_header._M_parent);
  return;
}
// @@@ END IDX 200
// @@@ BEGIN IDX 201 rea_std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______pair__dup2
// ------------------------------------------------------------------
// IDX 201  0010dca0  std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______pair
// ------------------------------------------------------------------
void rea_std___pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______pair__dup2(pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__ * this_ptr, int __in_chrg) {
  int *piVar1;
  rea_v pdVar2;
  char *pcVar3;
  int iVar4;
  
  pdVar2 = rea_bind((this_ptr->second)).super__Vector_base_double__std__allocator_double_._M_impl._M_start;
  if (pdVar2 != (pointer)0x0) {
    rea_operator_delete(pdVar2);
  }
  pcVar3 = rea_bind((this_ptr->first))._M_dataplus._M_p;
  if ((allocator *)(pcVar3 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
    piVar1 = (int *)(pcVar3 + -8);
    if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar4 = *(int *)(pcVar3 + -8);
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
// @@@ END IDX 201
// @@@ BEGIN IDX 202 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_unique_pos__dup2
// ------------------------------------------------------------------
// IDX 202  0010dd00  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_unique_pos__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, key_type * __k) {
  undefined1 auVar1 [16];
  bool bVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  rea_adr p_Var6;
  size_t __n;
  rea_adr p_Var7;
  ulong uVar8;
  long long lVar9;
  char *__s1;
  void *__s2;
  ulong uVar10;
  rea_v pVar11;
  
  p_Var6 = (rea_bind(this_ptr)->_M_impl)._M_header._M_parent;
                    /* Unresolved local var: _Link_type __x@[???] Unresolved local var: _Link_type __y@[???] Unresolved local var: bool __comp@[???] Unresolved local var: iterator __j@[???] */ if (p_Var6 == (_Rb_tree_node_base *)0x0) {
    p_Var7 = &(rea_bind(this_ptr)->_M_impl)._M_header;
LAB_0010de00:
    if ((rea_bind(this_ptr)->_M_impl)._M_header._M_left == p_Var7) {
      p_Var6 = (_Rb_tree_node_base *)0x0;
      goto LAB_0010ddbd;
    }
    p_Var6 = (_Rb_tree_node_base *)rea_std___Rb_tree_decrement(p_Var7);
    __s2 = *(void **)(p_Var6 + 1);
    __s1 = rea_bind((__k->_M_dataplus))._M_p;
    uVar8 = *(ulong *)((long long)__s2 + -0x18);
    uVar10 = *(ulong *)(__s1 + -0x18);
    __n = uVar10;
    if (uVar8 <= uVar10) {
      __n = uVar8;
    }
  }
  else {
    __s1 = rea_bind((__k->_M_dataplus))._M_p;
    uVar10 = *(ulong *)(__s1 + -0x18);
    do {
      p_Var7 = p_Var6;
      __s2 = *(void **)(p_Var7 + 1);
      uVar8 = *(ulong *)((long long)__s2 + -0x18);
      __n = uVar8;
      if (uVar10 <= uVar8) {
        __n = uVar10;
      }
      uVar3 = rea_memcmp(__s1,__s2,__n);
      uVar5 = (ulong)uVar3;
      if (uVar3 == 0) {
        uVar5 = uVar10 - uVar8;
        if ((long long)uVar5 < 0x80000000) {
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] Unresolved local var: difference_type __d@[???] */ if (-0x80000001 < (long long)uVar5) goto LAB_0010dd40;
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
    } while (rea_bind(p_Var6) != (_Base_ptr)0x0);
    p_Var6 = p_Var7;
    if (bVar2) goto LAB_0010de00;
  }
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] */ iVar4 = rea_memcmp(__s2,__s1,__n);
  if (iVar4 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */ lVar9 = uVar8 - uVar10;
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
      return (pair_std___Rb_tree_node_base___std___Rb_tree_node_base_)(rea_bind(auVar1) << 0x40);
    }
  }
  p_Var7 = (_Rb_tree_node_base *)0x0;
LAB_0010ddbd:
  pVar11.second = p_Var7;
  pVar11.first = p_Var6;
  return pVar11;
}
// @@@ END IDX 202
// @@@ BEGIN IDX 203 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_hint_unique_pos__dup2
// ------------------------------------------------------------------
// IDX 203  0010de50  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_hint_unique_pos___________
// ------------------------------------------------------------------
pair_std___Rb_tree_node_base___std___Rb_tree_node_base_ rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_get_insert_hint_unique_pos__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, const_iterator __position, key_type * __k) {
  void *__s2;
  char *pcVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  rea_v cVar7;
  rea_v p_Var8;
  ulong uVar9;
  long long lVar10;
  rea_v pVar11;
  rea_v pVar12;
  
                    /* Unresolved local var: iterator __pos@[DW_OP_reg4(RSI); DW_OP_piece: 8] */ if (rea_bind(__position)._M_node == &(rea_bind(this_ptr)->_M_impl)._M_header) {
    if ((rea_bind(this_ptr)->_M_impl)._M_node_count == 0) goto LAB_0010e000;
    rea_bind(__position)._M_node = (rea_bind(this_ptr)->_M_impl)._M_header._M_right;
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] */ pcVar1 = rea_bind((__k->_M_dataplus))._M_p;
    uVar2 = *(ulong *)(pcVar1 + -0x18);
    uVar3 = *(ulong *)((long long)*(void **)(rea_bind(__position)._M_node + 1) + -0x18);
    uVar9 = uVar3;
    if (uVar2 <= uVar3) {
      uVar9 = uVar2;
    }
    iVar5 = rea_memcmp(*(void **)(rea_bind(__position)._M_node + 1),pcVar1,uVar9);
    if (iVar5 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */ lVar10 = uVar3 - uVar2;
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
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] */ __s2 = *(void **)(rea_bind(__position)._M_node + 1);
  pcVar1 = rea_bind((__k->_M_dataplus))._M_p;
  uVar2 = *(ulong *)((long long)__s2 + -0x18);
  uVar3 = *(ulong *)(pcVar1 + -0x18);
  uVar9 = uVar3;
  if (uVar2 <= uVar3) {
    uVar9 = uVar2;
  }
  uVar4 = rea_memcmp(pcVar1,__s2,uVar9);
  uVar6 = (ulong)uVar4;
  cVar7._M_node = rea_bind(__position)._M_node;
  if (uVar4 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */ uVar6 = uVar3 - uVar2;
    if ((long long)uVar6 < 0x80000000) {
      if (-0x80000001 < (long long)uVar6) goto LAB_0010dfa0;
      goto LAB_0010df1c;
    }
  }
  else {
LAB_0010dfa0:
    if ((int)uVar6 < 0) {
LAB_0010df1c:
                    /* Unresolved local var: iterator __before@[???] */ if ((rea_bind(this_ptr)->_M_impl)._M_header._M_left != rea_bind(__position)._M_node) {
        p_Var8 = (_Base_ptr)rea_std___Rb_tree_decrement(rea_bind(__position)._M_node);
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] */ uVar2 = *(ulong *)((long long)*(void **)(p_Var8 + 1) + -0x18);
        uVar9 = uVar3;
        if (uVar2 <= uVar3) {
          uVar9 = uVar2;
        }
        iVar5 = rea_memcmp(*(void **)(p_Var8 + 1),pcVar1,uVar9);
        if (iVar5 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */ lVar10 = uVar2 - uVar3;
          if (0x7fffffff < lVar10) goto LAB_0010e000;
          if (lVar10 < -0x80000000) goto LAB_0010df7c;
          iVar5 = (int)lVar10;
        }
        if (iVar5 < 0) {
LAB_0010df7c:
          if (p_Var8->_M_right == (_Base_ptr)0x0) {
            rea_bind(__position)._M_node = p_Var8;
            cVar7._M_node = (_Base_ptr)0x0;
          }
          pVar12.second = rea_bind(__position)._M_node;
          pVar12.first = cVar7._M_node;
          return pVar12;
        }
        goto LAB_0010e000;
      }
      goto LAB_0010deff;
    }
  }
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] */ iVar5 = rea_memcmp(__s2,pcVar1,uVar9);
  if (iVar5 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */ lVar10 = uVar2 - uVar3;
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
                    /* Unresolved local var: iterator __after@[???] */ if ((rea_bind(this_ptr)->_M_impl)._M_header._M_right == rea_bind(__position)._M_node) goto LAB_0010e069;
      p_Var8 = (_Base_ptr)rea_std___Rb_tree_increment(rea_bind(__position)._M_node);
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] */ uVar2 = *(ulong *)((long long)*(void **)(p_Var8 + 1) + -0x18);
      uVar9 = uVar3;
      if (uVar2 <= uVar3) {
        uVar9 = uVar2;
      }
      iVar5 = rea_memcmp(pcVar1,*(void **)(p_Var8 + 1),uVar9);
      if (iVar5 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */ lVar10 = uVar3 - uVar2;
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
      if ((rea_bind(__position)._M_node)->_M_right != (_Base_ptr)0x0) {
        cVar7._M_node = p_Var8;
        rea_bind(__position)._M_node = p_Var8;
      }
      goto LAB_0010deff;
    }
  }
  rea_bind(__position)._M_node = (_Base_ptr)0x0;
LAB_0010deff:
  pVar11.second = rea_bind(__position)._M_node;
  pVar11.first = cVar7._M_node;
  return pVar11;
}
// @@@ END IDX 203
// @@@ BEGIN IDX 204 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_______M_emplace_hint_unique_const_std__piecewise_construct_t___std__tuple_const_std__basic_string_char__std__char_traits_char__std__allocator_char____std__tuple__dup2
// ------------------------------------------------------------------
// IDX 204  0010e0b0  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_______M_emplace_hint_unique_const_std__piecewise_construct_t___std__tuple_const_std__basic_string_char__std__char_traits_char__std__allocator_char____std__tuple_____________
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double_______M_emplace_hint_unique_const_std__piecewise_construct_t___std__tuple_const_std__basic_string_char__std__char_traits_char__std__allocator_char____std__tuple__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, const_iterator __pos) {
  rea_adr p_Var1;
  size_type *psVar2;
  int *piVar3;
  rea_adr psVar4;
  ulong uVar5;
  ulong uVar6;
  int iVar7;
  rea_adr p_Var8;
  undefined8 *in_RCX;
  ulong __n;
  bool bVar9;
  rea_adr p_Var10;
  long long lVar11;
  rea_v pVar12;
  
  p_Var10 = (_Rb_tree_node_base *)0x20;
                    /* Unresolved local var: _Link_type __z@[???] Unresolved local var: _Link_type __tmp@[???] */ p_Var8 = rea_operator_new(0x30);
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
    lVar11 = *(long long *)(p_Var8 + 1);
    if ((allocator *)(lVar11 + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
      piVar3 = (int *)(lVar11 + -8);
      if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar7 = *(int *)(lVar11 + -8);
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
                    /* Unresolved local var: bool __insert_left@[???] */ p_Var1 = &(rea_bind(this_ptr)->_M_impl)._M_header;
  if ((pVar12.first == (_Base_ptr)0x0) && (p_Var10 != p_Var1)) {
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] */ uVar5 = *(ulong *)((long long)*(void **)(p_Var8 + 1) + -0x18);
    uVar6 = *(ulong *)((long long)*(void **)(p_Var10 + 1) + -0x18);
    __n = uVar5;
    if (uVar6 <= uVar5) {
      __n = uVar6;
    }
    iVar7 = rea_memcmp(*(void **)(p_Var8 + 1),*(void **)(p_Var10 + 1),__n);
    if (iVar7 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */ lVar11 = uVar5 - uVar6;
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
  psVar2 = &(rea_bind(this_ptr)->_M_impl)._M_node_count;
  *psVar2 = *psVar2 + 1;
  return (iterator)p_Var8;
}
// @@@ END IDX 204
// @@@ BEGIN IDX 205 rea_std__vector_double__std__allocator_double___operator__assign__dup2
// ------------------------------------------------------------------
// IDX 205  0010e270  std__vector_double__std__allocator_double___operator_assign___________
// ------------------------------------------------------------------
vector_double__std__allocator_double_ * rea_std__vector_double__std__allocator_double___operator__assign__dup2(vector_double__std__allocator_double_ * this_ptr, vector_double__std__allocator_double_ * __x) {
  _Rb_tree_color _Var1;
  rea_v p_Var2;
  double dVar3;
  double dVar4;
  ulong uVar5;
  rea_v pdVar6;
  rea_v __p;
  rea_v p_Var7;
  rea_v p_Var8;
  rea_v pdVar9;
  rea_v pdVar10;
  undefined8 uVar11;
  long long lVar12;
  rea_v extraout_RDX;
  ulong uVar13;
  rea_v __src;
  rea_adr this_00;
  size_t sVar14;
  
  if (__x == this_ptr) {
    return this_ptr;
  }
                    /* Unresolved local var: size_type __xlen@[???] */ pdVar6 = rea_bind((__x->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish;
  pdVar9 = rea_bind((__x->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
  this_00 = rea_bind((_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ *)(this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
  uVar13 = (long long)pdVar6 - (long long)pdVar9 >> 3;
  if (uVar13 <= (ulong)(rea_bind((long long)(this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl. _M_end_of_storage - (long long)this_00 >> 3)) {
    pdVar10 = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish;
    uVar5 = (long long)pdVar10 - (long long)this_00 >> 3;
    if (uVar5 < uVar13) {
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ __src = pdVar9 + uVar5;
      if (uVar5 == 0) {
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ lVar12 = (long long)pdVar6 - (long long)__src;
        this_00 = (_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ *)((long long)&this_00->_M_impl + uVar13 * 8);
      }
      else {
        rea_memmove(this_00,pdVar9,uVar5 * 8);
        pdVar10 = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish;
        pdVar6 = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
        this_00 = (_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ *)(pdVar6 + uVar13);
        __src = (pointer)(((long long)pdVar10 - (long long)pdVar6 & 0xfffffffffffffff8U) + rea_bind((long long)(__x->super__Vector_base_double__std__allocator_double_))._M_impl. _M_start);
        lVar12 = rea_bind((long long)(__x->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish - (long long)__src;
      }
      if (lVar12 >> 3 != 0) {
        rea_memmove(pdVar10,__src,(lVar12 >> 3) * 8);
        rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start + uVar13;
        return this_ptr;
      }
    }
    else {
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ if (uVar13 != 0) {
        rea_memmove(this_00,pdVar9,uVar13 * 8);
        rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start + uVar13;
        return this_ptr;
      }
    }
    rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish = (pointer)this_00 ;
    return this_ptr;
  }
                    /* Unresolved local var: pointer __tmp@[???] Unresolved local var: pointer __result@[???] */ if (uVar13 == 0) {
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
        rea_std__string__string(&__p->_M_value_field, rea_bind((string *) &__x[1].super__Vector_base_double__std__allocator_double_)._M_impl. _M_finish);
        pdVar6 = rea_bind(__x[2].super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
        pdVar9 = rea_bind(__x[1].super__Vector_base_double__std__allocator_double_)._M_impl. _M_end_of_storage;
        uVar13 = 0;
        pdVar10 = (pointer)0x0;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_start = (pointer)0x0;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = (pointer)0x0;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_end_of_storage = (pointer)0x0;
        uVar5 = (long long)pdVar6 - (long long)pdVar9 >> 3;
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
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_start = pdVar10;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = pdVar10;
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_end_of_storage = (pointer)(uVar13 + (long long)pdVar10);
        pdVar6 = rea_bind(__x[1].super__Vector_base_double__std__allocator_double_)._M_impl. _M_end_of_storage;
        sVar14 = 0;
        lVar12 = rea_bind((long long)__x[2].super__Vector_base_double__std__allocator_double_)._M_impl._M_start - (long long)pdVar6 >> 3;
        if (lVar12 != 0) {
          sVar14 = lVar12 * 8;
          pdVar10 = rea_memmove(pdVar10,pdVar6,sVar14);
        }
        (__p->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = (pointer)((long long)pdVar10 + sVar14);
      }
      _Var1 = *(_Rb_tree_color *) rea_bind(&(__x->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
      (__p->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
      p_Var2 = rea_bind((_Const_Link_type) __x[1].super__Vector_base_double__std__allocator_double_)._M_impl._M_start;
      (__p->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
      (__p->super__Rb_tree_node_base)._M_parent = extraout_RDX;
      (__p->super__Rb_tree_node_base)._M_color = _Var1;
      if (p_Var2 != (_Const_Link_type)0x0) {
        p_Var7 = _Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_________________________M_copy(this_00,p_Var2,__p);
        (__p->super__Rb_tree_node_base)._M_right = &p_Var7->super__Rb_tree_node_base;
      }
      pdVar6 = rea_bind((__x->super__Vector_base_double__std__allocator_double_))._M_impl._M_end_of_storage;
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
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_start = (pointer)0x0;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_finish = (pointer)0x0;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_end_of_storage = (pointer)0x0;
          uVar5 = (long long)dVar3 - (long long)dVar4 >> 3;
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
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_start = pdVar9;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_finish = pdVar9;
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_end_of_storage = (pointer)(uVar13 + (long long)pdVar9);
          sVar14 = 0;
          lVar12 = (long long)pdVar6[6] - (long long)pdVar6[5] >> 3;
          if (lVar12 != 0) {
            sVar14 = lVar12 * 8;
            pdVar9 = rea_memmove(pdVar9,(void *)pdVar6[5],sVar14);
          }
          (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_finish = (pointer)((long long)pdVar9 + sVar14);
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
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ if (uVar13 != 0) {
      rea_memmove(pdVar6,pdVar9,uVar5);
      pdVar9 = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
      goto joined_r0x0010e356;
    }
  }
  pdVar9 = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
joined_r0x0010e356:
  if (pdVar9 != (pointer)0x0) {
    rea_operator_delete(pdVar9);
  }
  rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start = pdVar6;
  rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_end_of_storage = (pointer)((long long)pdVar6 + uVar5);
  rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish = (pointer)((long long)pdVar6 + uVar5);
  return this_ptr;
}
// @@@ END IDX 205
// @@@ BEGIN IDX 206 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_copy__dup2
// ------------------------------------------------------------------
// IDX 206  0010e430  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_copy
// ------------------------------------------------------------------
_Link_type rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_copy__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * this_ptr, _Const_Link_type __x, _Link_type __p) {
  _Rb_tree_color _Var1;
  rea_v pdVar2;
  rea_v p_Var3;
  rea_v p_Var4;
  rea_v p_Var5;
  rea_v p_Var6;
  rea_v __p_00;
  rea_v p_Var7;
  rea_v p_Var8;
  rea_v pdVar9;
  rea_v __dest;
  undefined8 uVar10;
  ulong uVar11;
  long long lVar12;
  ulong uVar13;
  size_t sVar14;
  
                    /* Unresolved local var: _Link_type __top@[???] Unresolved local var: _Link_type __tmp@[???] */ __p_00 = rea_operator_new(0x40);
  if (__p_00 != (_Link_type)0x0) {
    (__p_00->super__Rb_tree_node_base)._M_color = _S_red;
    (__p_00->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    rea_std__string__string(&__p_00->_M_value_field,&(rea_bind(__x)->_M_value_field).first);
    pdVar9 = (rea_bind(__x)->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_finish;
    pdVar2 = (rea_bind(__x)->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_start;
    uVar13 = 0;
    __dest = (pointer)0x0;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_start = (pointer)0x0;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = (pointer)0x0;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_end_of_storage = (pointer)0x0;
    uVar11 = (long long)pdVar9 - (long long)pdVar2 >> 3;
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
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_start = __dest;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = __dest;
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_end_of_storage = (pointer)(uVar13 + (long long)__dest);
    pdVar9 = (rea_bind(__x)->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_start;
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ sVar14 = 0;
    lVar12 = (long long)(rea_bind(__x)->_M_value_field).second.super__Vector_base_double__std__allocator_double_. _M_impl._M_finish - (long long)pdVar9 >> 3;
    if (lVar12 != 0) {
      sVar14 = lVar12 * 8;
      __dest = rea_memmove(__dest,pdVar9,sVar14);
    }
    (__p_00->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = (pointer)((long long)__dest + sVar14);
  }
  _Var1 = (rea_bind(__x)->super__Rb_tree_node_base)._M_color;
  (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
  p_Var3 = (_Const_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_right;
  (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
  (__p_00->super__Rb_tree_node_base)._M_parent = rea_bind(&__p)->super__Rb_tree_node_base;
  (__p_00->super__Rb_tree_node_base)._M_color = _Var1;
  if (p_Var3 != (_Const_Link_type)0x0) {
    p_Var7 = _M_copy(this_ptr,p_Var3,__p_00);
    (__p_00->super__Rb_tree_node_base)._M_right = &p_Var7->super__Rb_tree_node_base;
  }
  p_Var4 = (rea_bind(__x)->super__Rb_tree_node_base)._M_left;
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
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_start = (pointer)0x0;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = (pointer)0x0;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_end_of_storage = (pointer)0x0;
      uVar11 = (long long)p_Var5 - (long long)p_Var6 >> 3;
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
                    /* Unresolved local var: _Link_type __y@[???] Unresolved local var: _Link_type __tmp@[???] */ (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_start = pdVar9;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = pdVar9;
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_end_of_storage = (pointer)(uVar13 + (long long)pdVar9);
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ sVar14 = 0;
      lVar12 = (long long)p_Var4[1]._M_left - (long long)p_Var4[1]._M_parent >> 3;
      if (lVar12 != 0) {
        sVar14 = lVar12 * 8;
        pdVar9 = rea_memmove(pdVar9,p_Var4[1]._M_parent,sVar14);
      }
      (p_Var7->_M_value_field).second.super__Vector_base_double__std__allocator_double_._M_impl. _M_finish = (pointer)((long long)pdVar9 + sVar14);
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
// @@@ END IDX 206
// @@@ BEGIN IDX 207 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_copy__dup2
// ------------------------------------------------------------------
// IDX 207  0010e780  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_copy
// ------------------------------------------------------------------
_Link_type rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_copy__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, _Const_Link_type __x, _Link_type __p) {
  _Rb_tree_color _Var1;
  rea_v p_Var2;
  rea_v p_Var3;
  rea_v __p_00;
  rea_v p_Var4;
  rea_v __p_01;
  
                    /* Unresolved local var: _Link_type __top@[???] Unresolved local var: _Link_type __tmp@[???] */ __p_00 = rea_operator_new(0x30);
  if (__p_00 != (_Link_type)0x0) {
    (__p_00->super__Rb_tree_node_base)._M_color = _S_red;
    (__p_00->super__Rb_tree_node_base)._M_parent = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
    (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
    rea_std__string__string(&__p_00->_M_value_field,&(rea_bind(__x)->_M_value_field).first);
    (__p_00->_M_value_field).second = (rea_bind(__x)->_M_value_field).second;
  }
  _Var1 = (rea_bind(__x)->super__Rb_tree_node_base)._M_color;
  (__p_00->super__Rb_tree_node_base)._M_right = (_Base_ptr)0x0;
  p_Var2 = (_Const_Link_type)(rea_bind(__x)->super__Rb_tree_node_base)._M_right;
  (__p_00->super__Rb_tree_node_base)._M_left = (_Base_ptr)0x0;
  (__p_00->super__Rb_tree_node_base)._M_parent = rea_bind(&__p)->super__Rb_tree_node_base;
  (__p_00->super__Rb_tree_node_base)._M_color = _Var1;
  if (p_Var2 != (_Const_Link_type)0x0) {
    p_Var4 = _M_copy(this_ptr,p_Var2,__p_00);
    (__p_00->super__Rb_tree_node_base)._M_right = &p_Var4->super__Rb_tree_node_base;
  }
  p_Var4 = __p_00;
  for (p_Var3 = (rea_bind(__x)->super__Rb_tree_node_base)._M_left; p_Var3 != (_Base_ptr)0x0;
      p_Var3 = p_Var3->_M_left) {
                    /* Unresolved local var: _Link_type __y@[???] Unresolved local var: _Link_type __tmp@[???] */ __p_01 = rea_operator_new(0x30);
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
// @@@ END IDX 207
// @@@ BEGIN IDX 208 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_insert__const_std__pair_std__basic_string_char__std__vector_double__dup2
// ------------------------------------------------------------------
// IDX 208  0010e930  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_insert__const_std__pair_std__basic_string_char__std__vector_double_____________
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double________M_insert__const_std__pair_std__basic_string_char__std__vector_double__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * this_ptr, _Base_ptr __x, _Base_ptr __p, pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__ * __v) {
  size_type *psVar1;
  rea_v pdVar2;
  rea_v pdVar3;
  char *__s1;
  int iVar4;
  rea_adr p_Var5;
  rea_v __dest;
  undefined8 uVar6;
  ulong uVar7;
  long long lVar8;
  ulong __n;
  size_t __n_00;
  bool bVar9;
  ulong uVar10;
  
                    /* Unresolved local var: bool __insert_left@[???] Unresolved local var: _Link_type __z@[???] */ bVar9 = true;
  if ((rea_bind(__x) == (_Base_ptr)0x0) && (rea_bind(__p) != &(rea_bind(this_ptr)->_M_impl)._M_header)) {
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] */ __s1 = rea_bind((__v->first))._M_dataplus._M_p;
    uVar10 = *(ulong *)((long long)*(void **)(rea_bind(__p) + 1) + -0x18);
    uVar7 = *(ulong *)(__s1 + -0x18);
    __n = uVar7;
    if (uVar10 <= uVar7) {
      __n = uVar10;
    }
    iVar4 = rea_memcmp(__s1,*(void **)(rea_bind(__p) + 1),__n);
    if (iVar4 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */ lVar8 = uVar7 - uVar10;
      bVar9 = false;
      if ((0x7fffffff < lVar8) || (bVar9 = true, lVar8 < -0x80000000)) goto LAB_0010e956;
      iVar4 = (int)lVar8;
    }
    bVar9 = SUB41((uint)iVar4 >> 0x1f,0);
  }
LAB_0010e956:
                    /* Unresolved local var: _Link_type __tmp@[???] */ p_Var5 = rea_operator_new(0x40);
  if (p_Var5 != (_Rb_tree_node_base *)0x0) {
    p_Var5->_M_color = _S_red;
    p_Var5->_M_parent = (_Base_ptr)0x0;
    p_Var5->_M_left = (_Base_ptr)0x0;
    p_Var5->_M_right = (_Base_ptr)0x0;
    rea_std__string__string(p_Var5 + 1,&__v->first);
    pdVar2 = rea_bind((__v->second)).super__Vector_base_double__std__allocator_double_._M_impl._M_finish;
    pdVar3 = rea_bind((__v->second)).super__Vector_base_double__std__allocator_double_._M_impl._M_start;
    uVar10 = 0;
    __dest = (_Base_ptr)0x0;
    p_Var5[1]._M_parent = (_Base_ptr)0x0;
    p_Var5[1]._M_left = (_Base_ptr)0x0;
    p_Var5[1]._M_right = (_Base_ptr)0x0;
    uVar7 = (long long)pdVar2 - (long long)pdVar3 >> 3;
    if (uVar7 != 0) {
      if (0x1fffffffffffffff < uVar7) {
        uVar6 = rea_std____throw_bad_alloc();
        rea_std__string___Rep___M_dispose((allocator *)(*(long long *)(p_Var5 + 1) + -0x18));
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
    p_Var5[1]._M_right = (_Base_ptr)((long long)&__dest->_M_color + uVar10);
    pdVar2 = rea_bind((__v->second)).super__Vector_base_double__std__allocator_double_._M_impl._M_start;
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ __n_00 = 0;
    lVar8 = rea_bind((long long)(__v->second)).super__Vector_base_double__std__allocator_double_._M_impl. _M_finish - (long long)pdVar2 >> 3;
    if (lVar8 != 0) {
      __n_00 = lVar8 * 8;
      __dest = rea_memmove(__dest,pdVar2,__n_00);
    }
    p_Var5[1]._M_left = (_Base_ptr)((long long)&__dest->_M_color + __n_00);
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar9,p_Var5,__p,&(rea_bind(this_ptr)->_M_impl)._M_header);
  psVar1 = &(rea_bind(this_ptr)->_M_impl)._M_node_count;
  *psVar1 = *psVar1 + 1;
  return (iterator)p_Var5;
}
// @@@ END IDX 208
// @@@ BEGIN IDX 209 rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_insert__const_std__pair_std__basic_string_char__double__dup2
// ------------------------------------------------------------------
// IDX 209  0010eb20  std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_insert__const_std__pair_std__basic_string_char__double____________
// ------------------------------------------------------------------
iterator rea_std____Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______M_insert__const_std__pair_std__basic_string_char__double__dup2(_Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * this_ptr, _Base_ptr __x, _Base_ptr __p, pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double * __v) {
  size_type *psVar1;
  char *__s1;
  ulong uVar2;
  ulong uVar3;
  int iVar4;
  rea_adr p_Var5;
  ulong __n;
  bool bVar6;
  long long lVar7;
  
                    /* Unresolved local var: bool __insert_left@[???] Unresolved local var: _Link_type __z@[???] */ bVar6 = true;
  if ((rea_bind(__x) == (_Base_ptr)0x0) && (rea_bind(__p) != &(rea_bind(this_ptr)->_M_impl)._M_header)) {
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] */ __s1 = rea_bind((__v->first))._M_dataplus._M_p;
    uVar2 = *(ulong *)((long long)*(void **)(rea_bind(__p) + 1) + -0x18);
    uVar3 = *(ulong *)(__s1 + -0x18);
    __n = uVar3;
    if (uVar2 <= uVar3) {
      __n = uVar2;
    }
    iVar4 = rea_memcmp(__s1,*(void **)(rea_bind(__p) + 1),__n);
    if (iVar4 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */ lVar7 = uVar3 - uVar2;
      bVar6 = false;
      if ((0x7fffffff < lVar7) || (bVar6 = true, lVar7 < -0x80000000)) goto LAB_0010eb42;
      iVar4 = (int)lVar7;
    }
    bVar6 = SUB41((uint)iVar4 >> 0x1f,0);
  }
LAB_0010eb42:
                    /* Unresolved local var: _Link_type __tmp@[???] */ p_Var5 = rea_operator_new(0x30);
  if (p_Var5 != (_Rb_tree_node_base *)0x0) {
    p_Var5->_M_color = _S_red;
    p_Var5->_M_parent = (_Base_ptr)0x0;
    p_Var5->_M_left = (_Base_ptr)0x0;
    p_Var5->_M_right = (_Base_ptr)0x0;
    rea_std__string__string(p_Var5 + 1,&__v->first);
    p_Var5[1]._M_parent = (_Base_ptr)__v->second;
  }
  rea_std___Rb_tree_insert_and_rebalance(bVar6,p_Var5,__p,&(rea_bind(this_ptr)->_M_impl)._M_header);
  psVar1 = &(rea_bind(this_ptr)->_M_impl)._M_node_count;
  *psVar1 = *psVar1 + 1;
  return (iterator)p_Var5;
}
// @@@ END IDX 209
// @@@ BEGIN IDX 210 rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse__dup2
// ------------------------------------------------------------------
// IDX 210  0010ec40  _Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse
// ------------------------------------------------------------------
undefined8 rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double____std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___double___M___parse__dup2(vector_unsigned_char__std__allocator_unsigned_char_ * b, size_t p, map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ * v) {
  rea_adr __p;
  int *piVar1;
  ulong uVar2;
  undefined *puVar3;
  ulong uVar4;
  int iVar5;
  rea_v puVar6;
  ulong uVar7;
  ulong *puVar8;
  undefined *puVar9;
  rea_v p_Var10;
  rea_v p_Var11;
  long long lVar12;
  ulong uVar13;
  rea_v puVar14;
  rea_v p_Var15;
  rea_v _Var16;
  ulong uVar17;
  rea_v pVar18;
  ulong local_108;
  rea_v local_9a [2];
  ulong o_1;
  rea_v t;
  ulong o;
  double local_70;
  rea_v vv;
  
                    /* Unresolved local var: size_t l@[???] Unresolved local var: size_t np@[???] Unresolved local var: uint8_t * s@[???] */ uVar13 = p + 8;
  puVar6 = rea_bind((b->super__Vector_base))._M_impl._M_finish;
  puVar14 = rea_bind((b->super__Vector_base))._M_impl._M_start;
  vv._M_t._M_impl._M_header._M_color = _S_red;
  vv._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  vv._M_t._M_impl._M_header._M_left = &vv._M_t._M_impl._M_header;
  vv._M_t._M_impl._M_node_count = 0;
  vv._M_t._M_impl._M_header._M_right = vv._M_t._M_impl._M_header._M_left;
  if (uVar13 <= (ulong)((long long)puVar6 - (long long)puVar14)) {
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ rea_memcpy((string *)&o,puVar14 + p,8);
    uVar4 = o;
    puVar3 = PTR__S_empty_rep_storage_00311ff0;
                    /* Unresolved local var: size_t i@[???] */ if (o != 0) {
                    /* Unresolved local var: size_t nnp@[???] Unresolved local var: size_t p1@[???] Unresolved local var: size_t p2@[???] Unresolved local var: size_t l@[???] Unresolved local var: size_t np@[???] Unresolved local var: uint8_t * s@[???] Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ local_108 = 0;
                    /* Unresolved local var: size_type __dnew@[???] Unresolved local var: _Rep * __r@[???] */ do {
        uVar7 = uVar13 + 8;
        _Var16._M_p = puVar3 + 0x18;
        t.second = 0.0;
        local_70 = 0.0;
        t.first._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var16._M_p;
        o = (ulong)_Var16._M_p;
        uVar17 = uVar13;
        if ((ulong)((long long)puVar6 - (long long)puVar14) < uVar7) {
LAB_0010ef10:
          puVar9 = puVar3 + 0x18;
        }
        else {
          rea_memcpy(&o_1,puVar14 + uVar13,8);
          uVar2 = uVar7 + o_1;
          if ((ulong)((long long)puVar6 - (long long)puVar14) < uVar2) goto LAB_0010ef10;
          puVar14 = puVar14 + uVar7;
          puVar6 = puVar14 + o_1;
          if (puVar14 != puVar6) {
            uVar7 = (long long)puVar6 - (long long)puVar14;
            puVar8 = (ulong *)rea_std__string___Rep___S_create(uVar7,0,(allocator*)rea_pv(local_9a));
            _Var16._M_p = (char *)(puVar8 + 3);
            lVar12 = 0;
            do {
              *(uchar *)((long long)_Var16._M_p + lVar12) = puVar14[lVar12];
              lVar12 = lVar12 + 1;
            } while (lVar12 != (long long)puVar6 - (long long)puVar14);
            if (puVar8 != (ulong *)puVar3) {
              *(undefined4 *)(puVar8 + 2) = 0;
              *puVar8 = uVar7;
              *(undefined1 *)((long long)puVar8 + uVar7 + 0x18) = 0;
            }
          }
          o_1 = (ulong)_Var16._M_p;
          rea_std__string__assign((string *)&o);
          if ((allocator *)(o_1 - 0x18) != (allocator *)puVar3) {
            piVar1 = (int *)(o_1 - 8);
            if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar5 = *(int *)(o_1 - 8);
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
            puVar6 = rea_bind((b->super__Vector_base))._M_impl. _M_start;
                    /* Unresolved local var: uint8_t * s@[???] */ if (uVar2 + 8 <= (ulong)(rea_bind((long long)(b->super__Vector_base) )._M_impl._M_finish - (long long)puVar6)) {
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ rea_memcpy(&o_1,puVar6 + uVar2,8);
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
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar5 = *(int *)(puVar9 + -8);
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
          if ((allocator *)((long long)t.first._M_dataplus._M_p + -0x18) != (allocator *)puVar3) {
            piVar1 = (int *)((long long)t.first._M_dataplus._M_p + -8);
            if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar5 = *(int *)((long long)t.first._M_dataplus._M_p + -8);
              *(int *)((long long)t.first._M_dataplus._M_p + -8) = iVar5 + -1;
            }
            else {
              LOCK();
              iVar5 = *piVar1;
              *piVar1 = *piVar1 + -1;
              UNLOCK();
            }
            if (iVar5 < 1) {
              rea_std__string___Rep___M_destroy((allocator *)((long long)t.first._M_dataplus._M_p + -0x18));
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
        if ((allocator *)((long long)t.first._M_dataplus._M_p + -0x18) != (allocator *)puVar3) {
          piVar1 = (int *)((long long)t.first._M_dataplus._M_p + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar5 = *(int *)((long long)t.first._M_dataplus._M_p + -8);
            *(int *)((long long)t.first._M_dataplus._M_p + -8) = iVar5 + -1;
          }
          else {
            LOCK();
            iVar5 = *piVar1;
            *piVar1 = *piVar1 + -1;
            UNLOCK();
          }
          if (iVar5 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)((long long)t.first._M_dataplus._M_p + -0x18));
          }
        }
        local_108 = local_108 + 1;
        uVar13 = uVar17;
        if (local_108 == uVar4) break;
        puVar14 = rea_bind((b->super__Vector_base))._M_impl. _M_start;
        puVar6 = rea_bind((b->super__Vector_base))._M_impl. _M_finish;
      } while( true );
    }
    p = uVar13;
    p_Var15 = (_Link_type)vv._M_t._M_impl._M_header._M_parent;
    if (v == (map_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__ *)0x0) goto LAB_0010efd9;
    std________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__________M_erase(&v->_M_t,rea_bind((_Link_type)(v->_M_t))._M_impl._M_header._M_parent);
    __p = rea_bind(&(v->_M_t))._M_impl._M_header;
    rea_bind((v->_M_t))._M_impl._M_header._M_parent = (_Base_ptr)0x0;
    rea_bind((v->_M_t))._M_impl._M_node_count = 0;
    rea_bind((v->_M_t))._M_impl._M_header._M_left = __p;
    rea_bind((v->_M_t))._M_impl._M_header._M_right = __p;
    if (vv._M_t._M_impl._M_header._M_parent != (_Base_ptr)0x0) {
      p_Var10 = std____________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double______________________M_copy(&v->_M_t,(_Const_Link_type)vv._M_t._M_impl._M_header._M_parent, (_Link_type)__p);
      rea_bind((v->_M_t))._M_impl._M_header._M_parent = &p_Var10->super__Rb_tree_node_base;
      p_Var15 = p_Var10;
      do {
        p_Var11 = p_Var15;
        p_Var15 = (_Link_type)(p_Var11->super__Rb_tree_node_base)._M_left;
      } while (p_Var15 != (_Link_type)0x0);
      rea_bind((v->_M_t))._M_impl._M_header._M_left = &p_Var11->super__Rb_tree_node_base;
      do {
        p_Var15 = p_Var10;
        p_Var10 = (_Link_type)(p_Var15->super__Rb_tree_node_base)._M_right;
      } while (p_Var10 != (_Link_type)0x0);
      rea_bind((v->_M_t))._M_impl._M_header._M_right = &p_Var15->super__Rb_tree_node_base;
      rea_bind((v->_M_t))._M_impl._M_node_count = vv._M_t._M_impl._M_node_count;
      p_Var15 = (_Link_type)vv._M_t._M_impl._M_header._M_parent;
      goto LAB_0010efd9;
    }
  }
  p_Var15 = (_Link_type)0x0;
LAB_0010efd9:
  std______Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double__std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___double________M_erase(&vv._M_t,p_Var15);
  return p;
}
// @@@ END IDX 210
// @@@ BEGIN IDX 211 rea_std__vector_double__std__allocator_double____M_emplace_back_aux_double_const__dup2
// ------------------------------------------------------------------
// IDX 211  0010f1d0  std__vector_double__std__allocator_double____M_emplace_back_aux_double_const____________
// ------------------------------------------------------------------
void rea_std__vector_double__std__allocator_double____M_emplace_back_aux_double_const__dup2(vector_double__std__allocator_double_ * this_ptr) {
  rea_v __dest;
  long long lVar1;
  ulong uVar2;
  double *in_RSI;
  rea_v __src;
  ulong uVar3;
  rea_v pdVar4;
  
                    /* Unresolved local var: size_type __len@[???] Unresolved local var: pointer __new_start@[???] Unresolved local var: pointer __new_finish@[???] Unresolved local var: size_type __len@[DW_OP_reg0(RAX)] */ uVar2 = rea_bind((long long)(this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish - rea_bind((long long)(this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start >> 3;
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
  __src = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
  lVar1 = rea_bind((long long)(this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish - (long long)__src >> 3;
  pdVar4 = __dest + lVar1;
  if (pdVar4 != (pointer)0x0) {
    *pdVar4 = *in_RSI;
  }
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ if (lVar1 != 0) {
    rea_memmove(__dest,__src,lVar1 * 8);
    __src = rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start;
  }
  if (__src != (pointer)0x0) {
    rea_operator_delete(__src);
  }
  rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_start = __dest;
  rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_finish = pdVar4 + 1;
  rea_bind((this_ptr->super__Vector_base_double__std__allocator_double_))._M_impl._M_end_of_storage = (pointer)((long long)__dest + uVar3);
  return;
}
// @@@ END IDX 211
// @@@ BEGIN IDX 212 rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____M___parse__dup2
// ------------------------------------------------------------------
// IDX 212  0010f2b0  _Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____M___parse
// ------------------------------------------------------------------
undefined8 rea__Pv_std__map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______std__pair_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____M___parse__dup2(vector_unsigned_char__std__allocator_unsigned_char_ * b, size_t p, map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ * v) {
  ulong uVar1;
  rea_adr __p;
  int *piVar2;
  rea_v p_Var3;
  bool bVar4;
  rea_v sVar5;
  rea_v __s1;
  ulong uVar6;
  uint uVar7;
  int iVar8;
  rea_v puVar9;
  ulong *puVar10;
  rea_v p_Var11;
  rea_v p_Var12;
  ulong uVar13;
  size_t __n;
  rea_v _Var14;
  rea_v p_Var15;
  void *pvVar16;
  rea_v puVar17;
  ulong uVar18;
  long long lVar19;
  ulong uVar20;
  rea_v __p_00;
  rea_v local_148;
  ulong local_140;
  ulong local_130;
  rea_v local_e1;
  double t_1;
  rea_v s;
  ulong o_1;
  rea_adr local_c0;
  rea_adr local_b8;
  rea_v t;
  ulong o;
  rea_v local_80;
  rea_v vv;
  
  puVar9 = rea_bind((b->super__Vector_base))._M_impl._M_finish;
  puVar17 = rea_bind((b->super__Vector_base))._M_impl._M_start;
                    /* Unresolved local var: size_t l@[???] Unresolved local var: size_t np@[???] */ vv._M_t._M_impl._M_header._M_color = _S_red;
  vv._M_t._M_impl._M_header._M_parent = (_Base_ptr)0x0;
  vv._M_t._M_impl._M_header._M_left = &vv._M_t._M_impl._M_header;
  vv._M_t._M_impl._M_node_count = 0;
                    /* Unresolved local var: uint8_t * s@[???] */ local_148._M_p = (char *)(p + 8);
  vv._M_t._M_impl._M_header._M_right = vv._M_t._M_impl._M_header._M_left;
  if ((ulong)((long long)puVar9 - (long long)puVar17) < local_148._M_p) {
    p_Var15 = (_Link_type)0x0;
    local_140 = p;
  }
  else {
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ rea_memcpy((string *)&o,puVar17 + p,8);
    uVar6 = o;
                    /* Unresolved local var: size_t i@[???] */ local_140 = (ulong)local_148._M_p;
    if (o != 0) {
                    /* Unresolved local var: size_t nnp@[???] Unresolved local var: size_t p1@[???] Unresolved local var: size_t p2@[???] Unresolved local var: size_t l@[???] Unresolved local var: size_t np@[???] Unresolved local var: uint8_t * s@[???] Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ local_130 = 0;
                    /* Unresolved local var: size_type __dnew@[???] Unresolved local var: _Rep * __r@[???] */ /* Unresolved local var: size_t l@[???] Unresolved local var: size_t np@[???] Unresolved local var: size_t i@[???] Unresolved local var: size_t nnp@[???] */ do {
        t.second.super__Vector_base_double__std__allocator_double_._M_impl._M_start = (pointer)0x0 ;
        t.second.super__Vector_base_double__std__allocator_double_._M_impl._M_finish = (pointer)0x0;
        t.second.super__Vector_base_double__std__allocator_double_._M_impl._M_end_of_storage = (pointer)0x0;
        local_80.super__Vector_base_double__std__allocator_double_._M_impl._M_start = (pointer)0x0 ;
        local_80.super__Vector_base_double__std__allocator_double_._M_impl._M_finish = (pointer)0x0;
        _Var14._M_p = PTR__S_empty_rep_storage_00311ff0 + 0x18;
        local_80.super__Vector_base_double__std__allocator_double_._M_impl._M_end_of_storage = (pointer)0x0;
        uVar13 = (long long)local_148._M_p + 8;
        t.first._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var14._M_p;
        o = (ulong)_Var14._M_p;
        if ((ulong)((long long)puVar9 - (long long)puVar17) < uVar13) {
LAB_0010f7e8:
          local_140 = (ulong)local_148._M_p;
        }
        else {
          rea_memcpy((vector_double__std__allocator_double_ *)&o_1,puVar17 + (long long)local_148._M_p,8);
          uVar18 = uVar13 + o_1;
          if ((ulong)((long long)puVar9 - (long long)puVar17) < uVar18) goto LAB_0010f7e8;
          puVar17 = puVar17 + uVar13;
          if (puVar17 != puVar17 + o_1) {
            uVar20 = (long long)(puVar17 + o_1) - (long long)puVar17;
            puVar10 = (ulong *)rea_std__string___Rep___S_create(uVar20,0,&local_e1);
            _Var14._M_p = (char *)(puVar10 + 3);
            uVar13 = 0;
            do {
              *(uchar *)((long long)_Var14._M_p + uVar13) = puVar17[uVar13];
              uVar13 = uVar13 + 1;
            } while (uVar13 != uVar20);
            if (puVar10 != (ulong *)PTR__S_empty_rep_storage_00311ff0) {
              *(undefined4 *)(puVar10 + 2) = 0;
              *puVar10 = uVar20;
              *(undefined1 *)((long long)puVar10 + uVar20 + 0x18) = 0;
            }
          }
          s._M_dataplus._M_p = (_Alloc_hider)(_Alloc_hider)_Var14._M_p;
          rea_std__string__assign((string *)&o);
          if ((allocator *)((long long)s._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
            piVar2 = (int *)((long long)s._M_dataplus._M_p + -8);
            if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[DW_OP_reg1(RDX)] */ iVar8 = *(int *)((long long)s._M_dataplus._M_p + -8);
              *(int *)((long long)s._M_dataplus._M_p + -8) = iVar8 + -1;
            }
            else {
              LOCK();
              iVar8 = *piVar2;
              *piVar2 = *piVar2 + -1;
              UNLOCK();
            }
            if (iVar8 < 1) {
              rea_std__string___Rep___M_destroy((allocator *)((long long)s._M_dataplus._M_p + -0x18));
            }
          }
          if (local_148._M_p == (char *)uVar18) {
LAB_0010f880:
            local_140 = (ulong)local_148._M_p;
          }
          else {
                    /* Unresolved local var: uint8_t * s@[???] */ puVar9 = rea_bind((b->super__Vector_base))._M_impl. _M_start;
            o_1 = 0;
            local_c0 = (_Alloc_hider *)0x0;
            local_b8 = (_Alloc_hider *)0x0;
            uVar13 = uVar18 + 8;
            uVar20 = rea_bind((long long)(b->super__Vector_base)). _M_impl._M_finish - (long long)puVar9;
            if (uVar20 < uVar13) goto LAB_0010f880;
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ rea_memcpy(&s,puVar9 + uVar18,8);
            sVar5 = s;
            if (s._M_dataplus._M_p == (char *)0x0) {
LAB_0010f7c0:
              std__vector_double__std__allocator_double___operator_assign_________________________(&local_80,(vector_double__std__allocator_double_ *)&o_1);
              pvVar16 = (void *)o_1;
              local_140 = uVar13;
            }
            else {
                    /* Unresolved local var: uint8_t * s@[???] */ local_140 = uVar18;
              if (uVar20 < uVar18 + 0x10) {
                pvVar16 = (void *)0x0;
              }
              else {
                lVar19 = 0;
                uVar20 = uVar13;
                uVar13 = uVar18 + 0x10;
                do {
                    /* Unresolved local var: bool __simple@[???] Unresolved local var: ptrdiff_t _Num@[???] */ rea_memcpy(&s,puVar9 + uVar20,8);
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
                  puVar9 = rea_bind((b->super__Vector_base)). _M_impl._M_start;
                  uVar1 = uVar13 + 8;
                  uVar20 = uVar13;
                  uVar13 = uVar1;
                } while (uVar1 <= (ulong)(rea_bind((long long)(b-> super__Vector_base ))._M_impl._M_finish - (long long)puVar9));
              }
            }
            if (pvVar16 != (void *)0x0) {
              rea_operator_delete(pvVar16);
            }
            if (uVar18 == local_140) goto LAB_0010f880;
            rea_std__string__assign(&t.first);
            std__vector_double__std__allocator_double___operator_assign(&t.second,&local_80);
          }
          if (local_80.super__Vector_base_double__std__allocator_double_._M_impl._M_start != (pointer)0x0) {
            rea_operator_delete(local_80.super__Vector_base_double__std__allocator_double_._M_impl. _M_start);
          }
        }
        if ((allocator *)(o - 0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
          piVar2 = (int *)(o - 8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar8 = *(int *)(o - 8);
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
          if (t.second.super__Vector_base_double__std__allocator_double_._M_impl._M_start != (pointer)0x0) {
            rea_operator_delete(t.second.super__Vector_base_double__std__allocator_double_._M_impl. _M_start);
          }
          p_Var15 = (_Link_type)vv._M_t._M_impl._M_header._M_parent;
          local_140 = p;
          if ((allocator *)((long long)t.first._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
            piVar2 = (int *)((long long)t.first._M_dataplus._M_p + -8);
            if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar8 = *(int *)((long long)t.first._M_dataplus._M_p + -8);
              *(int *)((long long)t.first._M_dataplus._M_p + -8) = iVar8 + -1;
            }
            else {
              LOCK();
              iVar8 = *piVar2;
              *piVar2 = *piVar2 + -1;
              UNLOCK();
            }
            if (iVar8 < 1) {
              rea_std__string___Rep___M_destroy((allocator *)((long long)t.first._M_dataplus._M_p + -0x18));
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
            uVar18 = *(ulong *)((long long)pvVar16 + -0x18);
            uVar13 = *(ulong *)((long long)t.first._M_dataplus._M_p + -0x18);
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
          uVar13 = *(ulong *)((long long)t.first._M_dataplus._M_p + -0x18);
          p_Var3 = vv._M_t._M_impl._M_header._M_parent;
          do {
            __p_00 = p_Var3;
            pvVar16 = *(void **)(__p_00 + 1);
            uVar18 = *(ulong *)((long long)pvVar16 + -0x18);
            __n = uVar18;
            if (uVar13 <= uVar18) {
              __n = uVar13;
            }
            uVar7 = rea_memcmp((void *)__s1._M_dataplus._M_p,pvVar16,__n);
            uVar20 = (ulong)uVar7;
            if (uVar7 == 0) {
              uVar20 = uVar13 - uVar18;
              if ((long long)uVar20 < 0x80000000) {
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] Unresolved local var: difference_type __d@[???] */ if (-0x80000001 < (long long)uVar20) goto LAB_0010f6a8;
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
                    /* Unresolved local var: size_type __size@[???] Unresolved local var: size_type __osize@[???] Unresolved local var: size_type __len@[???] Unresolved local var: int __r@[???] */ iVar8 = rea_memcmp(pvVar16,local_148._M_p,__n);
          if (iVar8 == 0) {
                    /* Unresolved local var: difference_type __d@[???] */ lVar19 = uVar18 - uVar13;
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
        if (t.second.super__Vector_base_double__std__allocator_double_._M_impl._M_start != (pointer)0x0) {
          rea_operator_delete(t.second.super__Vector_base_double__std__allocator_double_._M_impl. _M_start);
        }
        if ((allocator *)((long long)t.first._M_dataplus._M_p + -0x18) != (allocator *)PTR__S_empty_rep_storage_00311ff0) {
          piVar2 = (int *)((long long)t.first._M_dataplus._M_p + -8);
          if (PTR___pthread_key_create_00311fd8 == (undefined *)0x0) {
                    /* Unresolved local var: _Atomic_word __result@[???] */ iVar8 = *(int *)((long long)t.first._M_dataplus._M_p + -8);
            *(int *)((long long)t.first._M_dataplus._M_p + -8) = iVar8 + -1;
          }
          else {
            LOCK();
            iVar8 = *piVar2;
            *piVar2 = *piVar2 + -1;
            UNLOCK();
          }
          if (iVar8 < 1) {
            rea_std__string___Rep___M_destroy((allocator *)((long long)t.first._M_dataplus._M_p + -0x18));
          }
        }
        local_130 = local_130 + 1;
        if (local_130 == uVar6) break;
        puVar17 = rea_bind((b->super__Vector_base))._M_impl. _M_start;
        puVar9 = rea_bind((b->super__Vector_base))._M_impl. _M_finish;
        local_148._M_p = (char *)local_140;
      } while( true );
    }
    p_Var15 = (_Link_type)vv._M_t._M_impl._M_header._M_parent;
    if (v != (map_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double___std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____ *)0x0) {
      std__________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double______________M_erase(&v->_M_t,rea_bind((_Link_type)(v->_M_t))._M_impl._M_header._M_parent);
      __p = rea_bind(&(v->_M_t))._M_impl._M_header;
      rea_bind((v->_M_t))._M_impl._M_header._M_parent = (_Base_ptr)0x0;
      rea_bind((v->_M_t))._M_impl._M_node_count = 0;
      rea_bind((v->_M_t))._M_impl._M_header._M_left = __p;
      rea_bind((v->_M_t))._M_impl._M_header._M_right = __p;
      if (vv._M_t._M_impl._M_header._M_parent == (_Base_ptr)0x0) {
        p_Var15 = (_Link_type)0x0;
      }
      else {
        p_Var11 = std______________________Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__________________________M_copy(&v->_M_t,(_Const_Link_type)vv._M_t._M_impl._M_header._M_parent, (_Link_type)__p);
        rea_bind((v->_M_t))._M_impl._M_header._M_parent = &p_Var11->super__Rb_tree_node_base;
        p_Var15 = p_Var11;
        do {
          p_Var12 = p_Var15;
          p_Var15 = (_Link_type)(p_Var12->super__Rb_tree_node_base)._M_left;
        } while (p_Var15 != (_Link_type)0x0);
        rea_bind((v->_M_t))._M_impl._M_header._M_left = &p_Var12->super__Rb_tree_node_base;
        do {
          p_Var15 = p_Var11;
          p_Var11 = (_Link_type)(p_Var15->super__Rb_tree_node_base)._M_right;
        } while (p_Var11 != (_Link_type)0x0);
        rea_bind((v->_M_t))._M_impl._M_header._M_right = &p_Var15->super__Rb_tree_node_base;
        rea_bind((v->_M_t))._M_impl._M_node_count = vv._M_t._M_impl._M_node_count;
        p_Var15 = (_Link_type)vv._M_t._M_impl._M_header._M_parent;
      }
    }
  }
LAB_0010f8d7:
  std______Rb_tree_std__basic_string_char__std__char_traits_char__std__allocator_char___std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double____std___Select1st_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double_____std__less_std__basic_string_char__std__char_traits_char__std__allocator_char____std__allocator_std__pair_const_std__basic_string_char__std__char_traits_char__std__allocator_char___std__vector_double__std__allocator_double__________M_erase(&vv._M_t,p_Var15);
  return local_140;
}
// @@@ END IDX 212
