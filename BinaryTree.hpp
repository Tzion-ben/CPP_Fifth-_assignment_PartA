/*
* AUTHORS: <Tzion Beniaminov>
* Tests for Binatree
*/

#include <algorithm>

#pragma once

namespace ariel {
    template<typename T>
    class BinaryTree {
        
        public:
            BinaryTree()
            :_root(nullptr)
            {}
            ~BinaryTree(){
               
            }

            BinaryTree& add_root(T root){
                Node rootTo(root,nullptr);
                this->_root = &rootTo;
                return *this;
            }
            
            BinaryTree& add_left(T exist_in_tree, T new_to_add){
                return *this;
            }

            BinaryTree& add_right(T exist_in_tree, T new_to_add){
                return *this;
            }

           
        
        private:
        // inner class(struct), represents each Node in th tree
        struct Node {
            T m_value;
            Node* m_next;
            Node(const T& v, Node* n)
                : m_value(v), m_next(n) {
            }
        };

            // fields
            Node* _root;

        public:	

            //-------------------------------------------------------------------
            // iterator related code:
            // inner class and methods that return instances of it)
            //-------------------------------------------------------------------
            class iterator {

            private:
                Node* pointer_to_current_node;

            public:

                iterator(Node* ptr)
                    : pointer_to_current_node(ptr) {
                }

                // Note that the method is const as this operator does not
                // allow changing of the iterator.
                // Note that it returns T& as it allows to change what it points to.
                // A const_iterator class will return const T&
                // and the method will still be const
                T& operator*() const {
                    //return *pointer_to_current_node;
                    return pointer_to_current_node->m_value;
                }

                T* operator->() const {
                    return &(pointer_to_current_node->m_value);
                }

                // ++i;
                iterator& operator++() {
                    //++pointer_to_current_node;
                    pointer_to_current_node = pointer_to_current_node->m_next;
                    return *this;
                }

                // i++;
                // Usually iterators are passed by value and not by const& as they are small.
                const iterator operator++(int) {
                    iterator tmp= *this;
                    pointer_to_current_node= pointer_to_current_node->m_next;
                    return tmp;
                }

                bool operator==(const iterator& rhs) const {
                    return pointer_to_current_node == rhs.pointer_to_current_node;
                }

                bool operator!=(const iterator& rhs) const {
                    return pointer_to_current_node != rhs.pointer_to_current_node;
                }
            };  // END OF CLASS ITERATOR


        /*begin: start of the tree, end:the end of the tree*/
        iterator begin_preorder() {return iterator{nullptr};}
        iterator end_preorder() {return iterator{nullptr};}

        iterator begin_inorder() {return iterator{nullptr};}
        iterator end_inorder() {return iterator{nullptr};}

        iterator begin_postorder() {return iterator{nullptr};}
        iterator end_postorder() {return iterator{nullptr};}

        /*
            begin: start of the tree, end:the end of the tree
            in Inorder
        */
        iterator begin() {return iterator{nullptr};}
        iterator end() {return iterator{nullptr};}
    }; 

    template<typename T>
    std::ostream& operator<< (std::ostream& output, const BinaryTree<T>& tree){
        return output;
    }
}