#ifndef OPTIMIZER_MULTIMAP_HPP
#define OPTIMIZER_MULTIMAP_HPP

#include "OptimizerCoreGlobal.hpp"
#include "OptimizerMap.hpp"


namespace optimizercore
{
	enum class MultimapType {Rotated, Set};

	class OptimizerMultiMap final : public OptimizerMap
	{

	private:
		int mDimension;
		int mTightness;
		int mNumberOfMaps;
		MultimapType mMapType;

		SharedVector mTmpVector; //smart ptr for p2
		double *p2; 
		int **mRotationPlanes;

		bool mIsInitialized;

	public:
		OptimizerMultiMap();
		OptimizerMultiMap(MultimapType mapType, int n, int m, int l);
		~OptimizerMultiMap();

		int GetNumberOfMaps() const;
		void GetImage(double x, double y[]);
		int GetAllPreimages(double* p, double xp[]);

	private:
		void InitRotatedMap();
	};

}
#endif