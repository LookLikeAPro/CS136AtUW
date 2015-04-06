#include "banking.h"

struct bank_acct create_acct(int new_id, int new_bal){
	struct bank_acct account = {new_id, new_bal};
	return account;
}

struct bank_acct *current_account;
int maxWithdraw = 0;
int maxDeposit = 0;
int transactionCount;

void set_active_acct(struct bank_acct *acct){
	current_account = acct;
	transactionCount = 0;
	maxWithdraw = 0;
	maxDeposit = 0;
}

int get_balance(){
	return current_account->bal;
}

int get_id(){
	return current_account->id;
}

void deposit(int amt){
	if (amt > maxDeposit){
		maxDeposit = amt;
	}
	current_account->bal +=amt;
	transactionCount++;
}

bool withdraw(int amt){
	if (current_account->bal>=amt){
		current_account->bal -=amt;
		if (amt > maxWithdraw){
			maxWithdraw = amt;
		}
		transactionCount++;
		return true;
	}
	else {
		return false;
	}
}

int max_withdrawal(void){
	return maxWithdraw;
}

int max_deposit(void){
	return maxDeposit;
}

int transaction_count(void){
	return transactionCount;
}

bool wire_transfer(struct bank_acct* from_acct, int amt){
	int tempCount = transactionCount;
	struct bank_acct *tempAccount = current_account;
	int tempMaxDeposit = maxDeposit;
	int tempMaxWithdraw = maxWithdraw;
	set_active_acct(from_acct);
	if (withdraw(amt)){
		set_active_acct(tempAccount);
		transactionCount = tempCount;
		maxWithdraw = tempMaxWithdraw;
		maxDeposit = tempMaxDeposit;
		deposit(amt);
		return true;
	}
	else {
		set_active_acct(tempAccount);
		transactionCount = tempCount;
		maxWithdraw = tempMaxDeposit;
		maxDeposit = tempMaxDeposit;
		return false;
	}
}
