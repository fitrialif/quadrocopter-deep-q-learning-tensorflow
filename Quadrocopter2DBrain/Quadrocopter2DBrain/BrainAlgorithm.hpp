//
//  BrainAlgorithm.hpp
//  Quadrocopter2DBrain
//
//  Created by anton on 13/08/16.
//  Copyright © 2016 anton. All rights reserved.
//

#ifndef BrainAlgorithm_hpp
#define BrainAlgorithm_hpp

#include "ObservationSeqLimited.hpp"

class BrainAlgorithm {
public:

	/**
		@return index of action
	*/
	virtual long control (const ObservationSeqLimited& ob, double randomness) = 0;
	
	virtual void control (const ObservationSeqLimited& ob, std::vector<float>& action, double randomness) = 0;

	/**
		@return prediction error on choosed minibatch
	*/
	virtual float trainOnMinibatch (std::vector<const ExperienceItem*> minibatch) = 0;

	virtual void setExplorationPeriod (int explorationPeriod) = 0;
	virtual void saveGraphState (const std::string fileSuffix) = 0;

};

#endif /* BrainAlgorithm_hpp */