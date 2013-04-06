#ifndef RELATIONSHIP_H_
#define RELATIONSHIP_H_

#include <utility>
#include <memory>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

namespace Individual
{
	class BaseIndividual;
	typedef std::shared_ptr<BaseIndividual> Individual_ptr;
}

namespace Relationship
{
	enum RelationshipType
	{
		CITIZEN,
		PARENT,
		CHILD,
		FRIEND,


		BIRTHPLACE,

		NUM_OF_RELATIONSHIPS
	};

	//TODO this probably shouldn't be inlined
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

	void createSymetricRelationship(Individual::Individual_ptr one, Individual::Individual_ptr two, RelationshipType rel);
	void createASymetricRelationship(Individual::Individual_ptr one, RelationshipType relOne, Individual::Individual_ptr two, RelationshipType relTwo);

	template<typename T>
	class RelationshipMap
	{
	public:
		RelationshipMap(){};

		void addRelationship(T t, RelationshipType rel)
		{
			relationshipMap[t].push_back(rel);
		}

		const std::vector<RelationshipType> & getRelationships(T t)
		{
			return relationshipMap[t];
		}


		//Warning: this is very slow, do not use often
		std::vector<T> getInstances(RelationshipType rel);


	private:
		std::map<T, std::vector<RelationshipType> > relationshipMap;
	};


}


#endif
