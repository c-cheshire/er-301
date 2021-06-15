#pragma once

#include <od/extras/RealFFT.h>
#define MAXPARTS 512

namespace od
{

	class UniformlyPartitionedConvolution
	{
	public:
		UniformlyPartitionedConvolution();
		virtual ~UniformlyPartitionedConvolution();

		void setIR(float *data, int n, int stride = 1);
		void clearIR();
		void process(float *in, float *out);

	private:
		RealFFT fft;
		complex_float_t *irpart_fd[MAXPARTS];
		float *input_td;
		complex_float_t *input_fd;
		float *multbuf_td;
		complex_float_t *multbuf_fd;

		int fftsize;
		int nbins;
		int nparts;
		bool ir_prepared;

		float *outbuf;
		int outbufsize;
		int outbufpos;
	};

} /* namespace od */
