from setuptools import find_packages, setup

package_name = 'cobot_yolo_pc'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='yeseo',
    maintainer_email='oooiooop9988@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'yolo_detection_service=cobot_yolo_pc.yolo_detection_service:main',
            'cobot_services_server=cobot_yolo_pc.cobot_services_server:main',
            'cobot_services_client=cobot_yolo_pc.cobot_services_client:main'
        ],
    },
)
