// banking.h
#include <stdbool.h>
/*----------------------------------------------------------------------------
 * This module allows you to perform a series of banking transactions 
 * (deposits, withdrawals, and wire transfers) on one or more bank account 
 * structures, and keeps track of relevant statistics for the current 
 * active account.  
 *----------------------------------------------------------------------------*/

//You should define what a struct bank_acct is here
struct bank_acct{
	int id;
	int bal;
};

// returns a bank account (bank_acct structure) with the provided id and balance in cents.
// requires: new_id > 0, new_bal >= 0
struct bank_acct create_acct(int new_id, int new_bal);


// Sets the active account to be acct and resets the internal statistics.
// requires: acct != NULL
// effects: internal back account is set to acct
void set_active_acct(struct bank_acct *acct);


// Returns the account balance for the current active account.
// requires: There is an active account.
int get_balance();


// Returns the account id for the current active account.
// requires: There is an active account.
int get_id();


// Deposits amt cents to the active account.  
// requires: amt > 0, there is an active account
// effects: internal back acount balace is updated by amt cents
void deposit(int amt);


// Attempts to remove amt cents from the active account.  
// If the balance is not great enough, the transaction does not complete 
// (no money is withdrawn, and this does not count as a transaction).
// Returns whether or not the transaction completed succesfully.
// requires:  amt > 0, there is an active account
// effects: internal back acount balace may be reduced by amt cents
bool withdraw(int amt);


// Returns the largest successful withdrawal made since the current active account was set.  
// Returns 0 if there have been no successful withdrawals
// requires: there is an active account
int max_withdrawal(void);


// Returns the largest deposit made since the curent active account was set. 
// Returns 0 if there have been no deposits.
// requires: there is an active account
int max_deposit(void);


// Get the number of successful transactions since the current active account was set
// requires: there is an active account
int transaction_count(void);


// Transfers amt cents from from_acct to the current active account.
// if from_acct has at least amt cents, then withdraws amt cents 
// from from_acct, deposits amt cents in the current account, and 
// returns true. Otherwise, returns false and this does not count 
// as a transaction. Note that the transfered money counts as a 
// deposit for the current account. 
// requires: amt > 0, from_account != NULL, and there is an active account
//           that is not from_account.
// effect: may updated internal account and from_acct according to the value in amt
bool wire_transfer(struct bank_acct* from_acct, int amt);
