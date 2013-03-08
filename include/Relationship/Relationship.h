#ifndef RELATIONSHIP_H_
#define RELATIONSHIP_H_

#include <utility>
#include <memory>
#include <string>

using std::shared_ptr;

namespace Relationship
{
	enum RelationshipType
	{
		CITIZEN,
		PARENT,


		BIRTHPLACE,

		NUM_OF_RELATIONSHIPS
	};

	inline std::string getRelationshipAsString (RelationshipType r)
	{
		switch(r)
		{
		case CITIZEN:
			return "citizen";
		case BIRTHPLACE:
			return "birthplace";
		default:
			return "default";
		}
	}

	template<typename T, typename U>
	class Relationship
	{
	public:
		Relationship(shared_ptr<T>(m1), shared_ptr<U>(m2), RelationshipType r) :
			members(std::make_pair(m1, m2)),
			relType(r){}

		RelationshipType getType() {return relType;}
		std::pair<shared_ptr<T>, shared_ptr<U>> getMembers() {return members;}

	private:
		std::pair<shared_ptr<T>, shared_ptr<U>> members;
		RelationshipType relType;
	};


}


#endif
