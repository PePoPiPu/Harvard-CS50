import './styles.css'
import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'

// Debug


// Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

window.addEventListener('resize', () =>
{
    // Update sizes
    sizes.width = window.innerWidth
    sizes.height = window.innerHeight

    // Update camera
    camera.aspect = sizes.width / sizes.height
    camera.updateProjectionMatrix()

    // Update renderer
    renderer.setSize(sizes.width, sizes.height)
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
})

const geometry = new THREE.BufferGeometry();
const positions = [];
const colors = [];
const angles = [];

geometry.setAttribute('position', new THREE.Float32BufferAttribute(positions, 3));
geometry.setAttribute('color', new THREE.Float32BufferAttribute(colors, 3));
geometry.setAttribute('angle', new THREE.Float32BufferAttribute(angles, 1));

// Vertex shader
const vertexShader = `
  attribute vec3 color;
  attribute float angle;
  varying vec3 vColor;

  void main() {
    vColor = color;
    float c = cos(angle);
    float s = sin(angle);
    mat3 rotationMatrix = mat3(
      c, -s, 0,
      s, c, 0,
      0, 0, 1
    );
    vec3 transformedPosition = position * rotationMatrix;
    gl_PointSize = 2.0; // Adjust the size of the particles
    gl_Position = projectionMatrix * modelViewMatrix * vec4(transformedPosition, 1.0);
  }
`;

// Fragment shader
const fragmentShader = `
  varying vec3 vColor;

  void main() {
    gl_FragColor = vec4(vColor, 1.0);
    gl_FragColor.a = length(gl_PointCoord - vec2(0.5)) * 2.0; // Create a fading effect towards the edges of the particles
  }
`;

const material = new THREE.ShaderMaterial({
  vertexShader: vertexShader,
  fragmentShader: fragmentShader,
  blending: THREE.AdditiveBlending, // Set the blending mode to achieve the galaxy effect
  depthTest: false,
  transparent: true
});

const points = new THREE.Points(geometry, material);
scene.add(points);


// Sizes

const sizes = {
  width: window.innerWidth,
  height: window.innerHeight
}

//Camera

// Base camera
const camera = new THREE.PerspectiveCamera(50, sizes.width / sizes.height, 0.1, 5000)
camera.position.x = 0
camera.position.y = 1000
camera.position.z = 1700
scene.add(camera)

// Controls
const controls = new OrbitControls(camera, canvas)
controls.enableDamping = true
controls.autoRotate = true
controls.autoRotateSpeed = 5.0

// Renderer
const renderer = new THREE.WebGLRenderer({
    canvas: canvas
})
renderer.setSize(sizes.width, sizes.height)
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
// Setting background color as an "spacey" color
renderer.setClearColor(new THREE.Color('#01010d'), 1)

// Animate
const clock = new THREE.Clock()
const tick = () =>
{
    const elapsedTime = clock.getElapsedTime()

    // Update Orbital Controls
    controls.update()

    // Render
    renderer.render(scene, camera)

    // Update Spiral position
    geometry.attributes.position.needsUpdate = true;
    geometry.attributes.angle.needsUpdate = true;

    // Call tick again on the next frame
    window.requestAnimationFrame(tick)
}

tick()