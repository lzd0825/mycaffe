#ifndef BN_LAYER_HPP_
#define BN_LAYER_HPP_

#include <boost/shared_ptr.hpp>
#include <gflags/gflags.h>
#include <glog/logging.h>

#include <cmath>

#include "caffe/blob.hpp"
#include "caffe/common.hpp"
#include "caffe/layer.hpp"
#include "caffe/proto/caffe.pb.h"

namespace caffe {

template <typename Dtype>
class BNLayer : public Layer<Dtype> {
	
	public:
		explicit BNLayer(const LayerParameter& param)
			: Layer<Dtype>(param) {}
		virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom, 
				const vector<Blob<Dtype>*>& top);
		virtual void Reshape(const vector<Blob<Dtype>*>& bottom, 
				const vector<Blob<Dtype>*>& top);

	 	virtual inline LayerParameter_LayerType type() const {
			return LayerParameter_LayerType_DROMPNAR;
		}
	 	virtual inline int ExactNumBottomBlobs() const { return 1; }
	 	virtual inline int ExactNumTopBlobs() const { return 1; }
	  
	protected:
		virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom, 
				const vector<Blob<Dtype>*>& top);
	 	virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
			 	const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);
	 	virtual void Forward_gpu(const vector<Blob<Dtype>*>& bottom,
			 	const vector<Blob<Dtype>*>& top);
		virtual void Backward_gpu(const vector<Blob<Dtype>*>& top,
			 	const vector<bool>& propagate_down, const vector<Blob<Dtype>*>& bottom);

	 	Blob<Dtype> diffs_;
	 	Blob<Dtype> vars_;
};

}  // namespace caffe

#endif  // CAFFE_COMMON_HPP_
