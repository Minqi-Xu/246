#include <iostream>
#include <string>
#include "tag.h"

Tag::Tag(const std::string &type): type{type}, id{""}, value{""}, parent{nullptr},
		children{nullptr}, childrenLength{0}, childrenCapacity{0} {}

Tag::Tag(const Tag &other): type{other.type}, id{other.id}, value{other.value},
	parent{other.parent}, children{other.children}, childrenLength{other.childrenLength},
	childrenCapacity{other.childrenCapacity} {}

Tag::Tag(Tag &&other): type{other.type}, id{other.id}, value{other.value}, parent{other.parent},
	children{other.children}, childrenLength{other.childrenLength}, 
	childrenCapacity{other.childrenCapacity} {
	other.children = nullptr;
}

Tag & Tag::operator=(const Tag &other) {
	if(this == &other) return *this;
	Tag tmp{other};
	std::swap(type, tmp.type);
	std::swap(id, tmp.id);
	std::swap(value, tmp.value);
	std::swap(parent, tmp.parent);
	std::swap(children, tmp.children);
	std::swap(childrenLength, tmp.childrenLength);
	std::swap(childrenCapacity, tmp.childrenCapacity);
	return *this;
}

Tag & Tag::operator=(Tag &&other) {
	std::swap(type, other.type);
	std::swap(id, other.id);
	std::swap(value, other.value);
	std::swap(parent, other.parent);
	std::swap(children, other.children);
	std::swap(childrenLength, other.childrenLength);
	std::swap(childrenCapacity, other.childrenCapacity);
	return *this;
}

Tag::~Tag() {
	if(children != nullptr) {
		for(int i = 0; i < childrenLength; ++i) {
			delete children[i];
		}
	}
	delete[] children;
}

const std::string & Tag::getType() const {
	return type;
}
const std::string & Tag::getId() const {
	return id;
}
void Tag::setId(const std::string &_id) {
	this->id = _id;
}
const std::string & Tag::getValue() const{
	return value;
}
void Tag::setValue(const std::string &_value) {
	this->value = _value;
}
Tag* Tag::getParent() const {
	return parent;
}
void Tag::setParent(Tag *_parent) {
	this->parent = _parent;
}

void Tag::print(std::ostream &out, int indentLevel) const {
	for(int i = 0; i < indentLevel; ++i) out << "  ";
	out << "<" << this->getType();
	if(id != "")
		out << " id=\'" << this->getId() << "\'";
	if(value != "")
		out << " value=\'" << this->getValue() << "\'";
	out << ">" << std::endl;
	for(int i = 0; i < childrenLength; ++i) {
		children[i]->print(out, indentLevel + 1);
	}
	for(int i = 0; i < indentLevel; ++i) out << "  ";
	out << "</" << this->getType() << ">" << std::endl;
}

void Tag::addChild(Tag *other) {
	if(childrenCapacity == 0) {
		childrenCapacity = 1;
		childrenLength = 1;
		children = new Tag* [1];
		children[0] = other;
		other->setParent(this);
		return;
	}
	if(childrenCapacity == childrenLength) {
		childrenCapacity = 2 * childrenCapacity;
		Tag **tmp = new Tag* [childrenCapacity];
		for(int i = 0; i < childrenLength; ++i) {
			tmp[i] = children[i];
		}
		delete[] children;
		children = tmp;
	}
	children[childrenLength] = other;
	++childrenLength;
	other->setParent(this);
}

void Tag::removeChild(Tag *other) {
	for(int i = 0; i < childrenLength; ++i) {
		if (children[i] == other) {
			for(int j = i; j < childrenLength - 1; ++j) {
				children[j] = children [j + 1];
			}
			--childrenLength;
		}
	}
	other->setParent(nullptr);
}

Tag * Tag::findChild(std::string &type) {
	for(int i = 0; i < childrenLength; ++i) {
		if (children[i]->getType() == type) {
			return children[i];
		}
	}
	return nullptr;
}

Tag * Tag::findChildId(std::string &id) {
	for(int i = 0; i < childrenLength; ++i) {
		if (children[i]->getId() == id) {
			return children[i];
		}
	}
	return nullptr;
}

TagIterator Tag::begin() const {
	return TagIterator(children);
}

TagIterator Tag::end() const {
	//TagIterator tmp {children};
	//*(tmp.t) += childrenLength * sizeof(Tag);
	//return tmp;
	return TagIterator(&children[childrenLength]);
}

TagIterator::TagIterator(Tag **t): t{t} {}

Tag* TagIterator::operator*() const {
	return *t;
}

TagIterator TagIterator::operator++() {
	//std::cout<<"iterator++ occurs"<<std::endl;
	t += 1 ;
	return *this;
}

bool TagIterator::operator==(const TagIterator &other) const {
	return *t == *(other.t);
}

bool TagIterator::operator!=(const TagIterator &other) const {
	return !(*this == other);
}

std::ostream &operator<<(std::ostream &out, const Tag &tag) {
	tag.print(out, 0);
	return out;
}
