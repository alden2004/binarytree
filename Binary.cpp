#include <iostream>
using namespace std;

// node
struct Node {
  char label;
  Node *left, *right, *parent;
};

// variabel pointer global
Node *root = NULL, *newNode = NULL;

// buat Pohon Baru
void createNewTree(char label) {
  if (root != NULL)
    cout << "\nPohon sudah dibuat" << endl;
  else {
    root = new Node();
    root->label = label;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    cout << "\nNode " << label << " berhasil dibuat menjadi root." << endl;
  }
}

// tambahkan ke Kiri
Node *insertLeft(char label, Node *node) {
  if (root == NULL) {
    cout << "\nBuat pohon terlebih dahulu!!" << endl;
    return NULL;
  } else {
    if (node->left != NULL) {
      cout << "\nNode " << node->label << " sudah ada anak kiri!!" << endl;
      return NULL;
    } else {
      newNode = new Node();
      newNode->label = label;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->left = newNode;
      cout << "\nNode " << label << " berhasil ditambahkan ke anak kiri " << newNode->parent->label << endl;
      return newNode;
    }
  }
}

// tambahkan ke Kanan
Node *insertRight(char label, Node *node) {
  if (root == NULL) {
    cout << "\nBuat pohon terlebih dahulu!!" << endl;
    return NULL;
  } else {
    if (node->right != NULL) {
      cout << "\nNode " << node->label << " sudah ada anak kanan!!" << endl;
      return NULL;
    } else {
      newNode = new Node();
      newNode->label = label;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->right = newNode;
      cout << "\nNode " << label << " berhasil ditambahkan ke anak kanan " << newNode->parent->label << endl;
      return newNode;
    }
  }
}

// Kosong
bool empty() {
  return root == NULL;
}

// update
void update(char label, Node *node) {
  if (!root) {
    cout << "\nBuat pohon terlebih dahulu!!" << endl;
  } else {
    if (!node)
      cout << "\nNode yang ingin diganti tidak ada!!" << endl;
    else {
      char temp = node->label;
      node->label = label;
      cout << "\nLabel node " << temp << " berhasil diubah menjadi " << label << endl;
    }
  }
}

// ambil
void retrieve(Node *node) {
  if (!root) {
    cout << "\nBuat pohon terlebih dahulu!!" << endl;
  } else {
    if (!node)
      cout << "\nNode yang ditunjuk tidak ada!!" << endl;
    else {
      cout << "\nLabel node : " << node->label << endl;
    }
  }
}

// Cari
void find(Node *node) {
  if (!root) {
    cout << "\nBuat pohon terlebih dahulu!!" << endl;
  } else {
    if (!node)
      cout << "\nNode yang ditunjuk tidak ada!!" << endl;
    else {
      cout << "\nLabel Node : " << node->label << endl;
      cout << "Root Node : " << root->label << endl;

      if (!node->parent)
        cout << "Parent Node : (tidak punya orang tua)" << endl;
      else
        cout << "Parent Node : " << node->parent->label << endl;

      if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
        cout << "Saudara : " << node->parent->left->label << endl;
      else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
        cout << "Saudara : " << node->parent->right->label << endl;
      else
        cout << "Saudara : (tidak punya saudara)" << endl;

      if (!node->left)
        cout << "Anak Kiri Node : (tidak punya anak kiri)" << endl;
      else
        cout << "Anak Kiri Node : " << node->left->label << endl;

      if (!node->right)
        cout << "Anak Kanan Node : (tidak punya anak kanan)" << endl;
      else
        cout << "Anak Kanan Node : " << node->right->label << endl;
    }
  }
}

// Tranversal
// preOrder
void preOrder(Node *node = root) {
  if (!root)
    cout << "\nBuat pohon terlebih dahulu!!" << endl;
  else {
    if (node != NULL) {
      cout << node->label << ", ";
      preOrder(node->left);
      preOrder(node->right);
    }
  }
}

// inOrder
void inOrder(Node *node = root) {
  if (!root)
    cout << "\nBuat pohon terlebih dahulu!!" << endl;
  else {
    if (node != NULL) {
      inOrder(node->left);
      cout << node->label << ", ";
      inOrder(node->right);
    }
  }
}

// postOrder
void postOrder(Node *node = root) {
  if (!root)
    cout << "\nBuat pohon terlebih dahulu!!" << endl;
  else {
    if (node != NULL) {
      postOrder(node->left);
      postOrder(node->right);
      cout << node->label << ", ";
    }
  }
}

// hapusPohon
void deleteTree(Node *node) {
  if (!root)
    cout << "\nBuat pohon terlebih dahulu!!" << endl;
  else {
    if (node != NULL) {
      if (node != root) {
        node->parent->left = NULL;
        node->parent->right = NULL;
      }
      deleteTree(node->left);
      deleteTree(node->right);

      if (node == root) {
        delete root;
        root = NULL;
      } else {
        delete node;
      }
    }
  }
}

// hapus Sub
void deleteSub(Node *node) {
  if (!root)
    cout << "\nBuat pohon terlebih dahulu!!" << endl;
  else {
    deleteTree(node->left);
    deleteTree(node->right);
    cout << "\nSubtree node " << node->label << " berhasil dihapus." << endl;
  }
}

// bersihkan
void clear() {
  if (!root)
    cout << "\nBuat pohon terlebih dahulu!!" << endl;
  else {
    deleteTree(root);
    cout << "\nPohon berhasil dihapus." << endl;
  }
}

// ukuran
int size(Node *node = root) {
  if (!root) {
    cout << "\nBuat pohon terlebih dahulu!!" << endl;
    return 0;
  } else {
    if (!node) {
      return 0;
    } else {
      return 1 + size(node->left) + size(node->right);
    }
  }
}

// tinggi
int height(Node *node = root) {
  if (!root) {
    cout << "\nBuat pohon terlebih dahulu!!" << endl;
    return 0;
  } else {
    if (!node) {
      return 0;
    } else {
      int heightKiri = height(node->left);
      int heightKanan = height(node->right);

      return (heightKiri >= heightKanan) ? heightKiri + 1 : heightKanan + 1;
    }
  }
}

// karakteristik
void characteristic() {
  cout << "\nUkuran Pohon : " << size() << endl;
  cout << "Tinggi Pohon : " << height() << endl;
  cout << "Rata-rata Node dari Pohon : " << size() / height() << endl;
}

int main() {
  createNewTree('A');

  Node *nodeSupraX, *nodeNinja, *nodeKharisma, *nodeSugomi, *nodeJupiter, *nodeAstrea, *nodeBlade, *nodeMegapro, *nodeTiger;

  nodeSupraX = insertLeft('B', root);
  nodeNinja = insertRight('C', root);
  nodeKharisma = insertLeft('D', nodeSupraX);
  nodeSugomi = insertRight('E', nodeSupraX);
  nodeJupiter = insertLeft('F', nodeNinja);
  nodeAstrea = insertLeft('G', nodeSugomi);
  nodeBlade = insertRight('H', nodeSugomi);
  nodeMegapro = insertLeft('I', nodeAstrea);
  nodeTiger = insertRight('J', nodeAstrea);

  cout << "Pohon kosong? : " << empty() << endl;

  update('Z', nodeNinja);
  update('C', nodeNinja);

  retrieve(nodeNinja);

  find(nodeNinja);

  cout << "\nPreOrder :" << endl;
  preOrder();
  cout << "\n" << endl;
  cout << "InOrder :" << endl;
  inOrder();
  cout << "\n" << endl;
  cout << "PostOrder :" << endl;
  postOrder();
  cout << "\n" << endl;

  characteristic();

  deleteSub(nodeSugomi);
  cout << "\nPreOrder :" << endl;
  preOrder();
  cout << "\n" << endl;

  characteristic();

  return 0;
}
