#ifndef STANISLAUS_H
#define STANISLAUS_H

#include "stack.h"
#include <vector>

class Stanislaus {

    private:

      std::vector <stack<char>> levelStacks;
      stack <int> arityStack;
      stack <bool> booleanStack;

      void negation() {

          std::cout << "Negating " << booleanStack.top() << std::endl;
          if( booleanStack.top() == false )
            booleanStack.top() = true;
          else
            booleanStack.top() = false;
      }

      void implication() {

          bool p = booleanStack.top();
          booleanStack.pop();
          bool q = booleanStack.top();
          booleanStack.pop();

          std::cout << "Implication of ";
          std::cout << p << " and " << q << std::endl;

          if( !p )
            booleanStack.push(true);
          else
            booleanStack.push(q);
      }

      void conjunction() {
        bool p = booleanStack.top();
        booleanStack.pop();
        bool q = booleanStack.top();
        booleanStack.pop();

        std::cout << "Disjunction of ";
        std::cout << p << " and " << q << std::endl;

        booleanStack.push(p || q);
      }

      void disjunction() {
          bool p = booleanStack.top();
          booleanStack.pop();
          bool q = booleanStack.top();
          booleanStack.pop();

          std::cout << "Disjuction of ";
          std::cout << p << " and " << q << std::endl;

          booleanStack.push(p || q);
      }

    public:

      //Constructor
      Stanislaus() : levelStacks(), arityStack(), booleanStack() {

          levelStacks.resize(9);
      }

      void push (char formVal, int arityVal) {

          levelStacks.at( arityVal ).push( formVal );
          arityStack.push( arityVal );

      }

      bool runALGOL() {

        //Step 1
        bool solution = true;

        //Step 2
        while( !arityStack.empty() ) {

          int stackVal = arityStack.top();
          std::cout << "Acessing " << stackVal << ".";
          char levelVal = levelStacks.at( stackVal ).top();
          std::cout << "Top value is " << levelVal << std::endl;


          switch (levelVal) {

              case'0':
                booleanStack.push(false);
                break;
              case '1':
                booleanStack.push(true);
                break;
              case 'N':
                negation();
                break;
              case 'I':
                implication();
                break;
              case 'C':
                conjunction();
                break;
              case 'D':
                disjunction();
                break;
          };

          arityStack.pop();
          levelStacks.at(stackVal).pop();

        }

        solution = booleanStack.top();
        booleanStack.pop();

        return solution;
      }
};

#endif
