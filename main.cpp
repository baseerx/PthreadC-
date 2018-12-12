/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: root
 *
 * Created on December 12, 2018, 8:20 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <string.h>
#include <vector>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <net/if.h>
using namespace std;

/*
 * 
 */
vector<string>v1;
pthread_mutex_t *ptr_mutex;
string str;
int mutexvalue;
void* Thread1(void*) {
    while (1) {
//         printf("this is thread1!\n");
        mutexvalue = pthread_mutex_lock(ptr_mutex);
        cout << "Enter String: ";
        cin >> str;
        v1.push_back(str);
        mutexvalue = pthread_mutex_unlock(ptr_mutex);
        sleep(4);
       
    }


}

void* Thread2(void*) {
    while (1) {
        
        //sleep(4);
       mutexvalue =pthread_mutex_lock(ptr_mutex);
       cout << "Thread 2\n";
       string val = v1[0];
//        v1.pop_back();
         mutexvalue =pthread_mutex_unlock(ptr_mutex);
 

    }

}

int main(int argc, char** argv) {

    pthread_t thread1, thread2;
   
    ptr_mutex= (pthread_mutex_t*) malloc(sizeof (pthread_mutex_t));
    int mutx=pthread_mutex_init(ptr_mutex,NULL);

    if (mutx!=0) {
        cout << "Failure\n" << endl;
        exit(EXIT_FAILURE);
    }
         int ret = pthread_create(&thread1, NULL, &Thread1, NULL);
             ret = pthread_create(&thread2, NULL, &Thread2, NULL);
   
     if (ret!=0) {
     cout << "Failure\n" << endl;
        exit(EXIT_FAILURE);
    }

    pthread_exit(NULL);
    return 0;
}

