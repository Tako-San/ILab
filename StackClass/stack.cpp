#include "stack.h"
#include "interface.h"

/**
 * \Create stack by using dynamic memory.
 * \param [in, out] baby_stack  Pointer to stack structure.
 * \return true if stack initialisation is OK.
 * \return false otherwise.
 */
Stack::Stack()
{
#define STACK_BABYSITTER(cond, err)                                   \
if (cond)                                                             \
{                                                                     \
  err_code = err;                                                     \
  is_OK(__LINE__, __FILE__, __PRETTY_FUNCTION__);                     \
  return;                                                             \
}

  can1 = (can_type*)calloc(STARTSIZE*sizeof(my_type) + 2*sizeof(can_type), sizeof(char));

  STACK_BABYSITTER(!can1, STACK_MEM_ERROR)

  data = (my_type *)(can1 + 1);
  can2 = (can_type *)(data + STARTSIZE);

  size = STARTSIZE;
  cur_size = 0;

  eagle1 = eagle1_val;
  eagle2 = eagle2_val;

  *(can1) = can1_val;
  *(can2) = can2_val;

  err_code = STACK_NICE;

  hash_recalc();

#undef STACK_BABYSITTER
}/* End of 'init' function */


/**
 * \Destroy old stack, and free allocated memory.
 * \param [in, out] old_stack  Pointer to stack structure.
 * \return none.
*/
void Stack::destroy()
{
  err_code = STACK_DESTROYED;
  free(can1);
  size = DEADSTACK;
  cur_size = DEADSTACK;
  hash_recalc();
}/* End of 'destroy' function */


/**
 * \Pushing new element to stack.
 * \param [in, out] stack  Pointer to stack structure.
 * \param [out] new_elem Value of new stack element.
 * \return true if all is OK.
 * \return false otherwise.
*/
bool Stack::push(my_type new_elem)
{
  if(!is_OK(__LINE__, __FILE__, __PRETTY_FUNCTION__))
    return false;

  if(cur_size >= size)
  {
    resize(STACK_INCREASE);
    if(!is_OK(__LINE__, __FILE__, __PRETTY_FUNCTION__))
      return false;
  }

  size_type pos = cur_size++;
  data[pos] = new_elem;

  hash_recalc();

  if(!is_OK(__LINE__, __FILE__, __PRETTY_FUNCTION__))
    return false;

  return true;
}/* End of 'push' function */


/**
 * \Pushing new element to stack.
 * \param [in, out] stack  Pointer to stack structure.
 * \param [out] new_elem Value of new stack element.
 * \return true if all is OK.
 * \return false otherwise.
*/
my_type Stack::peek()
{
  if(cur_size == 0)
  {
    err_code = STACK_UNDERFLOW;
    hash = hash_calc(this, sizeof(Stack));
  }
  if(!is_OK(__LINE__, __FILE__, __PRETTY_FUNCTION__))
    return THE_STRASHNAYA_CONSTANTA;  // See: Pennywise et al. Murder and Nightmare. Proc. Prof. Killers conf. NY, 2019

  size_type pos = cur_size - 1;
  my_type   res = data[pos];

  if(!is_OK(__LINE__, __FILE__, __PRETTY_FUNCTION__))
    return THE_STRASHNAYA_CONSTANTA;
  else
    return res;
}/* End of 'peek' function */


/**
 * \Pop last stack element and delete it.
 * \param [in, out] stack  Pointer to stack structure.
 * \param [out] new_elem Value of new stack element.
 * \return true if all is OK.
 * \return false otherwise.
*/
my_type Stack::pop()
{
  if(cur_size == 0)
  {
    err_code = STACK_UNDERFLOW;
    hash_recalc();
    return THE_STRASHNAYA_CONSTANTA;
  }
  if(!is_OK(__LINE__, __FILE__, __PRETTY_FUNCTION__))
    return THE_STRASHNAYA_CONSTANTA;

  my_type res = data[cur_size-1];

  if(cur_size <= (size/RE_COEFF) - DELTA)
  {
    if(!resize(STACK_REDUCE))
      return THE_STRASHNAYA_CONSTANTA;
    cur_size--;
  }
  else
  {
    cur_size--;
  }

  hash_recalc();

  if(!is_OK(__LINE__, __FILE__, __PRETTY_FUNCTION__))
    return THE_STRASHNAYA_CONSTANTA;
  else
    return res;
}/* End of 'pop' function */


/**
 * \Changing stack data size.
 * \param [in, out] stack  Pointer to stack structure.
 * \param [in] relay Shows to func what to do: increase stack or reduce.
 * \param [out] new_elem Value of new stack element.
 * \return true if all is OK.
 * \return false otherwise.
*/
bool Stack::resize(STK_RESIZE relay)
{
#define STACK_CALL_THE_POLICE(err)                                    \
{                                                                     \
  err_code = err;                                                     \
  hash = hash_calc(this, sizeof(Stack));                              \
  is_OK(__LINE__, __FILE__, __PRETTY_FUNCTION__);                     \
  return false;                                                       \
}

  if(!is_OK(__LINE__, __FILE__, __PRETTY_FUNCTION__))
    return false;

  if(relay == STACK_INCREASE)
    size *= RE_COEFF;
  else if(relay == STACK_REDUCE)
    size /= RE_COEFF;
  else
    STACK_CALL_THE_POLICE(STACK_NEW_SIZE_ERROR)

  can_type can2_temp = *can2;

  can_type * temp = (can_type *)realloc(can1, size*sizeof(my_type) + 2*sizeof(can_type));
  if(!temp)
    STACK_CALL_THE_POLICE(STACK_NEW_SIZE_ERROR)

  can1 = (can_type *)temp;
  data = (my_type *)(temp + 1);
  can2 = (can_type *)(data + size);

  *can2 = can2_temp;

  hash_recalc();

  if(!is_OK(__LINE__, __FILE__, __PRETTY_FUNCTION__))
    return false;

  return true;
#undef STACK_CALL_THE_POLICE
}/* End of 'resize' function */


/**
 * \Cheking stack condition
 * \param [in, out] stack  Pointer to stack structure.
 * \return true if all is OK.
 * \return false and calling dump otherwise.
*/
bool Stack::is_OK(int line, const char * filename, const char * funcname)
{
#define STACK_COND_CHECK(cond, err)                                   \
else if(cond)                                                         \
{                                                                     \
  err_code = err;                                                     \
  hash = hash_calc(this, sizeof(Stack));                              \
  dump(line, filename, funcname);                                     \
  destroy();                                                          \
  return false;                                                       \
}                                                                     \

if(err_code == STACK_UNDERFLOW)
  return false;

STACK_COND_CHECK(err_code == STACK_NEW_SIZE_ERROR, STACK_NEW_SIZE_ERROR)

STACK_COND_CHECK(size < cur_size, STACK_SIZE_ERROR)

STACK_COND_CHECK(eagle1 != eagle1_val, STACK_EAGLE1_ERROR)

STACK_COND_CHECK(eagle2 != eagle2_val, STACK_EAGLE2_ERROR)

STACK_COND_CHECK(*can1 != can1_val, STACK_CAN1_ERROR)

STACK_COND_CHECK(*can2 != can2_val, STACK_CAN2_ERROR)

STACK_COND_CHECK(data_hash != hash_calc(data, sizeof(my_type), size), STACK_DATA_ERROR)

STACK_COND_CHECK(hash != hash_hash(), STACK_HASH_ERROR)

else
  return true;

#undef STACK_COND_CHECK
}/* End of 'is_OK' function */

/**
 * \Prin stack data if stack is not empty
 * \param [in, out] stack  Pointer to stack structure.
 * \return none
*/
void Stack::data_print()
{
  printf("\n");
  if(cur_size == 0)
  {
    printf("Stack is empty.\n");
  }
  else
  {
    for(size_type i = 0; i < cur_size; i++)
    {
      printf("stack.data[%llu] = ", i);
      std::cout << data[i] << std::endl;
    }
  }
  printf("\n");
}/* End of 'data_print' function */


/**
 * \Print all information about stack.
 * \param [in, out] stack  Pointer to stack structure.
 * \return none.
*/
void Stack::dump(int line, const char * filename, const char * funcname)
{
  fury();


  printf("File: %s\n\n", filename);
  printf("Function: %s\n\n", funcname);
  printf("Line: %d\n\n", line);

  printf("can1 =   %16llX     can1_val =  %17llX    %s\n", *(can1), can1_val, can1_val == *(can1)?"OK":"ERR");
  printf("can2 =   %16llX     can2_val =  %17llX    %s\n", *(can2), can2_val, can2_val == *(can2)?"OK":"ERR");

  printf("\n");

  printf("eagle1 = %16llX     eagle1_val =  %15llX    %s\n", eagle1, eagle1_val, eagle1_val == eagle1?"OK":"ERR");
  printf("eagle2 = %16llX     eagle2_val =  %15llX    %s\n", eagle2, eagle2_val, eagle2_val == eagle2?"OK":"ERR");

  printf("\n");

  hash_type temp = hash_calc(data, sizeof(my_type), size);
  printf("dhash =  %16llX     real dhash = %16llX    %s\n", data_hash, temp, temp == data_hash?"OK":"ERR");

  temp = hash_hash();
  printf("hash =   %16llX     real hash =  %16llX    %s\n", hash, temp, temp == hash?"OK":"ERR");

  printf("\n");

  printf("size = %llu                         \n", size);
  printf("cur_size = %llu                     \n", cur_size);

  data_print();
  split();
}/* End of 'dump' function */


/**
 * \Calculating hash.
 * \param [in] data  Pointer we need to hash.
 * \param [in] size_of Size of massive element.
 * \param [in] num Number of massive elements.
 * \return Calculated hash value.
*/
hash_type Stack::hash_calc(void *data, size_t size_of, size_t num)
{
  const unsigned char* bytes = (unsigned char*)data;
  size_t bytes_len = size_of * num;

  hash_type hash = 0;

  for (size_t i = 0; i < bytes_len; i++)
  {
    hash +=  bytes[i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);

  return hash;
}/* End of 'hash_calc' function */


/**
 * Calculating hash for all stack structure.
 * \param [in] stack  Pointer to stack structure.
 * \return Calculated hash value.
*/
hash_type Stack::hash_hash()
{
  hash_type temp = hash;
  hash = 0;

  hash_type result = hash_calc(this, sizeof(Stack));
  hash = temp;

  return result;
}/* End of 'hash_hash' function */


/**
 * Writing to stack hash for data and all stack structure.
 * \param [in] stack  Pointer to stack structure.
 * \return Calculated hash value.
*/
bool Stack::hash_recalc()
{
  hash = data_hash = 0;

  data_hash = hash_calc(data, sizeof(my_type), size);
  hash = hash_calc(this, sizeof(Stack));

  return true;
}/* End of 'hash_recalc' function */


/**
 * Being angry to bad user.
 * \param [in] err_code  Error code.
 * \return None.
*/
void Stack::fury()
{
  char rage[MAGICNUM] = {};
  char reason[MAGICNUM] = {};

  #define STACK_PHRASE_CHOISE(err, str1, str2)           \
  case err:          strcpy(rage, str1);                 \
                     strcpy(reason, str2);               \
                     break;                              \

  switch(err_code)
  {
    STACK_PHRASE_CHOISE(STACK_NICE, "idk what, why r u called me", "Error code is STACK_NICE.")

    STACK_PHRASE_CHOISE(STACK_OVERFLOW, "STACK", "Stack overflow.")

    STACK_PHRASE_CHOISE(STACK_CAN1_ERROR, "FIRST CANARY", "Canary1 value changed.")

    STACK_PHRASE_CHOISE(STACK_CAN2_ERROR, "SECOND CANARY", "Canary2 value changed.")

    STACK_PHRASE_CHOISE(STACK_HASH_ERROR, "HASH", "Real hash and calced hash doesn't match.")

    STACK_PHRASE_CHOISE(STACK_SIZE_ERROR, "STACK SIZE", "):(")

    STACK_PHRASE_CHOISE(STACK_DATA_ERROR, "DATA", "Data changed.")

    STACK_PHRASE_CHOISE(STACK_MEM_ERROR, "MEMORY", "Memory error.")

    STACK_PHRASE_CHOISE(STACK_NEW_SIZE_ERROR, "NEW SIZE OF STACK", "Memory reallocation error.")

    STACK_PHRASE_CHOISE(STACK_EAGLE1_ERROR, "FIRST EAGLE", "Eagle1 value changed.")

    STACK_PHRASE_CHOISE(STACK_EAGLE2_ERROR, "SECOND EAGLE", "Eagle2 value changed.")

    STACK_PHRASE_CHOISE(STACK_DESTROYED, "DEADSTACK", "Stack is already dead, don't touch it.")

    STACK_PHRASE_CHOISE(STACK_UNDERFLOW, "EMPTY STACK", "How dare you call me to underflow stack?")

    STACK_PHRASE_CHOISE(STACK_NULLPTR_ERROR, "YOU DON'T EVEN KNOW WHAT", "Yor stack has nullptr.")
  }

  for(int i = 0; i < 2; i++)
    split();
  printf("YOU WANNA FUCK MY %s? FUCK YOU.\n\n", rage);
  printf("%s\n", reason);
  for(int i = 0; i < 2; i++)
    split();

  #undef STACK_PHRASE_CHOISE
}/* End of 'fury' function */
